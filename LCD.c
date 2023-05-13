#include "LCD.h" 
#include "tm4c123gh6pm.h"
#include "stdint.h"
#include  "string.h"
	void delay_1ms (int g) {
		NVIC_ST_CTRL_R =0 ;
		NVIC_ST_CURRENT_R =0 ;
			NVIC_ST_CTRL_R =0X05 ;
		NVIC_ST_RELOAD_R =g-1 ;
		while ((NVIC_ST_CURRENT_R&0x00010000) ==0){}
			
	}	
	void delay_ms (int delay) //  call this function when use delay 
		{ 
int i;			
		 for (i=0;i<delay ;i++)
{delay_1ms(16000) ;} }







		
		void port_intilize ( char port_name   ) 
		{ switch (port_name) {
			case 'a' :
			
			{  set_bit(SYSCTL_RCGCGPIO_R ,0 )   ;
            while((  read_bit (SYSCTL_PRGPIO_R,0)==0) ) { };
							GPIO_PORTA_DEN_R |= 0x0ff; 
				
			} break ;
			case 'b' :
			 
			{  set_bit(SYSCTL_RCGCGPIO_R ,1)   ;
            while((  read_bit (SYSCTL_PRGPIO_R,1)==0) ) { };
							GPIO_PORTB_DEN_R |= 0x0ff; 
			}break ;
case 'c' :
			 
			{  set_bit(SYSCTL_RCGCGPIO_R ,2)   ;
            while((  read_bit (SYSCTL_PRGPIO_R,2)==0) ) { };
							GPIO_PORTB_DEN_R |= 0x0ff; 
			}break ;
case 'd' :
			 
			{  set_bit(SYSCTL_RCGCGPIO_R ,3)   ;
            while((  read_bit (SYSCTL_PRGPIO_R,3)==0) ) { };
							GPIO_PORTB_DEN_R |= 0x0ff; 
			}break ;
case 'e' :
			 
			{  set_bit(SYSCTL_RCGCGPIO_R ,4)   ;
            while((  read_bit (SYSCTL_PRGPIO_R,4)==0) ) { };
							GPIO_PORTB_DEN_R |= 0x0ff; 
			}break ;
default : //port f 
			 
			{  set_bit(SYSCTL_RCGCGPIO_R ,5)   ;
            while((  read_bit (SYSCTL_PRGPIO_R,5)==0) ) { };
							GPIO_PORTB_DEN_R |= 0x0ff;
						
			}
		}}
		
		
			
			void set_pin ( char port_name , char pin ,char dir )
			{ switch (port_name) {
				case 'a' :
				{
				if (dir ==1 )
				{  set_bit(GPIO_PORTA_DIR_R ,pin) ; }
				else 
				{clr_bit(GPIO_PORTA_DIR_R ,pin) ;}
	} break ;
				case 'b' : {
				if (dir ==1 )
				{  set_bit(GPIO_PORTB_DIR_R ,pin) ; }
				else 
				{clr_bit(GPIO_PORTB_DIR_R ,pin) ;}
	} 		break ;
				case 'c' : {
				if (dir ==1 )
				{  set_bit(GPIO_PORTC_DIR_R ,pin) ; }
				else 
				{clr_bit(GPIO_PORTC_DIR_R ,pin) ;}
	} break ;
				case 'd' : {
				if (dir ==1 )
				{  set_bit(GPIO_PORTD_DIR_R ,pin) ; }
				else 
				{clr_bit(GPIO_PORTD_DIR_R ,pin) ;}
	} break ;
				case 'e' : {
				if (dir ==1 )
				{  set_bit(GPIO_PORTE_DIR_R ,pin) ; }
				else 
				{clr_bit(GPIO_PORTE_DIR_R ,pin) ;}
	} break ;
				default : {
				if (dir ==1 )
				{  set_bit(GPIO_PORTF_DIR_R ,pin) ; }
				else 
				{clr_bit(GPIO_PORTF_DIR_R ,pin) ;}
	} 		
} }
 void set_pins ( char port_name,char dir  ) { 			{ switch (port_name) {
				case 'a' :
				{ GPIO_PORTA_DIR_R = dir ;
				
	} break ;
				case 'b' : {GPIO_PORTB_DIR_R=dir ;
	
	} break ;		
				case 'c' : {GPIO_PORTC_DIR_R=dir ;
			
	} 	break ;
				case 'd' : {GPIO_PORTD_DIR_R=dir ;
				
	} break ;	
				case 'e' : {GPIO_PORTE_DIR_R=dir ;
				
	} break ;
				default : {GPIO_PORTF_DIR_R= dir ;
				
	} 		
} }
 }
 void write_pin (char port_name ,char pin,char data ){
	{ switch (port_name) {
				case 'a' : 
				{ if (data==1) {set_bit(GPIO_PORTA_DATA_R,pin ) ;}
				else {	clr_bit(GPIO_PORTA_DATA_R,pin);}
				
	} break ;
				case 'b' : {if (data==0){clr_bit (GPIO_PORTB_DATA_R,pin ) ;}
			else		{set_bit(GPIO_PORTB_DATA_R,pin) ;}
	} break ;		
				case 'c' : {if (data==0){clr_bit (GPIO_PORTC_DATA_R,pin ) ;}
				else	{set_bit(GPIO_PORTC_DATA_R,pin)  ;}
			
	}break ; 		
case 'd' :{if (data==0) {clr_bit (GPIO_PORTD_DATA_R,pin ) ;}
			else	{	set_bit(GPIO_PORTD_DATA_R,pin) ;}
				
	}break ; 		
case 'e' : {if (data==0){clr_bit (GPIO_PORTE_DATA_R,pin ) ;}
				else{	set_bit(GPIO_PORTE_DATA_R,pin) ;
				}				
	} break ;		
default : {if (data==0){clr_bit (GPIO_PORTF_DATA_R,pin ) ;}
					else{set_bit(GPIO_PORTF_DATA_R,pin) ;}
	} 		
} }
 }
	 void send_pulse() {  write_pin (ctrl_PORT_b,en,1) ; ///lazm 34an kol 4wya ab3t pulse 	
		 delay_ms ( 2) ;
		 write_pin (ctrl_PORT_b,en,0) ;
		 delay_ms ( 2) ;}
	 
		 void  write_pins (char port_name ,char dir )
		 {switch (port_name){
		 case 'a' :
				{ GPIO_PORTA_DATA_R =dir ; ;
					
				
	} break ;
				case 'b' : {GPIO_PORTB_DATA_R=dir ;
	
	} 	break ;	
				case 'c' : {GPIO_PORTC_DATA_R=dir ;
			
	} break ;
				case 'd' : {GPIO_PORTD_DATA_R=dir ;
				
	} 		break ;
				case 'e' : {GPIO_PORTE_DATA_R=dir ;
				
	}break ;
				default : {GPIO_PORTF_DATA_R= dir ;
				
	} }		}
		 void lcd_send_cmd(char cmd ) {
			 write_pins ( data_port_a,cmd) ;
			 write_pin (ctrl_PORT_b,rs,1) ;
			 send_pulse() ;
			 delay_ms (1) ; }
		 
			 void lcd_send_char(char chr ) {
			 write_pins ( data_port_a,chr) ;
			 write_pin (ctrl_PORT_b,rs,1) ;
			 send_pulse() ;
			 delay_ms (1) ; }
			 
			 
			 void lcd_send_data (char *data )  {
				 while ((*data != '0')){
					 lcd_send_char (*data) ;
data ++ ;				 }
			 }
			 void lcd_clear_scr (void) {
				 lcd_send_char (clear ) ;
			 delay_ms (1)  ;}
			 void move_cursor (char row ,char column )  {
				 char pos = 0;
				 if (row==1) 
{pos =0x80 +column -1 ;} //0x80 dh rkm row awlani w gm3na 3leh column -1 34an column bybd2 mn zero (0 / 15) f lw 3wz awl column b7ot 1 
				 else if(row==2)
				 {pos=0xc0 +column -1 ;}//nfs klam 
				 else 
				 {pos=0x80 ;}
				 lcd_send_cmd(pos) ;}
				 
			
			void lcd_intilize (void){
				port_intilize (data_port_a);
					 port_intilize (ctrl_PORT_b) ;
		set_pins (data_port_a,0xff) ;
		set_pin (ctrl_PORT_b,en ,1) ;		
		set_pin (ctrl_PORT_b,rs ,1) ;	
set_pin (ctrl_PORT_b,rw ,1) ;	
			 write_pin (ctrl_PORT_b,rw,0) ;	
				lcd_send_cmd(bits_8) ;
				delay_ms(1) ;
				lcd_send_cmd(clear);
				delay_ms(1) ;
				lcd_send_cmd(macron_disable) ;
			delay_ms(10) ;
				lcd_send_cmd(entry_mode) ;         //clr screen 0x01 entry mode 0x06        34an a4el macron   0x0c						
				delay_ms(1) ;
				 send_pulse()  ;
				
			}
