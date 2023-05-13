#include <stdint.h> 
#include "tm4c123gh6pm.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "GPS.h"
#include "GPIO.h"
#define M_PI 3.14159265358979323846

char GPS_firstdata[]="$GPRMC,";
char lat[20] ;
char lon[20] ;
char valid ;
char eros ;
char nors ;
char speed[10] ;
double Current_Lat ;
double Current_Long ;


// intelization of UART(1), PORT C //


void UART2_initialization(void){
 
	SYSCTL_RCGCUART_R|=0x04;                 //enable uart2
  SYSCTL_RCGCGPIO_R|=0x08;                //enable gpio clk
  while((SYSCTL_PRGPIO_R & 0x08)==0);
  UART2_CTL_R&=~0x0001;                    //disable uart2 at beginning
  UART2_IBRD_R=104;
  UART2_FBRD_R=11;
  UART2_LCRH_R=0x0070;
  UART2_CTL_R=0x0301;
  GPIO_PORTD_LOCK_R=0x4C4F434B;
  GPIO_PORTD_CR_R|=0xC0;
  GPIO_PORTD_AFSEL_R|=0xC0;
  GPIO_PORTD_PCTL_R=0x11000000;
  GPIO_PORTD_DEN_R|=0xC0;
	GPIO_PORTD_DIR_R&=~0x40;
	GPIO_PORTD_DIR_R|=0x80;
  GPIO_PORTD_AMSEL_R&=~0xC0;

	}
	



char data_avilable(void) {
	return ((UART2_FR_R & 0x10) != 0) ? 0 : 1;
}


//Get Char

char UART_InCHAR(void){

   while((UART2_FR_R&0x10) !=0 );
   return (char)(UART2_DR_R&0XFF);
}
 void UART_InSTRING(char *data, char stopbit){
int i=0 ;
	 
	 data[i]=UART_InCHAR(); 
	 while(data[i]!=stopbit){
	 
	 i++ ;
	 data[i]=UART_InCHAR(); 
	 
	 }
	 
	 
	 data[i]='\0';
 }
		 
	 
	 
	
  




	



double GPS_getdistance(double lat1, double lon1, double lat2, double lon2)
{
return 6371000 * 2 * asin(sqrt((pow(sin(((lat2 - lat1) * M_PI / 180.0) / 2), 2) + pow(sin(((lon2 - lon1) * M_PI / 180.0) / 2), 2) * cos(((lat1)*M_PI / 180.0)) * cos(((lat2)*M_PI / 180.0)))));
}



void GPS_READ(void){
char flag =1 ;
	char counter =0 ;
		char i=0 ;
	char recievedchar ;
do{
	while (UART_InCHAR()!=GPS_firstdata[i]) {i=0;}
	i++ ;
}while(i!=7);
while (1){ if (flag){
	recievedchar=UART_InCHAR() ;
	if (	recievedchar==',')
	{counter ++ ;
	}
}
		switch (counter){
			case 1:valid=UART_InCHAR() ;  break ; 
			
		
      case 2:UART_InSTRING(lat,','); counter++ ;  flag =0 ; break ; 
	
			
				case 3: nors=UART_InCHAR() ;  flag =1 ; break ;
			
			
					case 4:  UART_InSTRING(lon,','); counter++ ; flag =0 ; break ;

			
						case 5:eros=UART_InCHAR() ;flag=1 ; break ;

			
			case 6: UART_InSTRING(speed,',');counter++ ; flag =0 ; break ; 
		}
		if (counter==7) break ;

if(valid=='A'){

Current_Lat=atof(lat);
Current_Lat =Current_Lat /100;
			
		
Current_Long=atof(lon);
	Current_Long=Current_Long/100;
}
}


		}

