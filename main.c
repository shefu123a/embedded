#include "LCD.h"
#include "tm4c123gh6pm.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "GPS.h"
#include "GPIO.h"

 extern double Current_Lat ;

 extern double Current_Long ;
  double Distance=0;



		double Prev_Lat;
		double Prev_Long;
		
		
		

double cumlative_distance=0;
		double Final_lat =30.0382066;
//			30.0637721;
		double Final_long =  31.1667636;
			//31.2784339;
		
	int main(){

		UART2_initialization();
		initialization_port_f();

		GPS_READ();
		
			 
	   Prev_Lat=Current_Lat;
	    Prev_Long=Current_Long;
		
		
		 
		
		while(1){
		GPS_READ();
		
			 
				cumlative_distance+=GPS_getdistance(Prev_Lat,Prev_Long,Current_Lat,Current_Long);
			Distance=GPS_getdistance(Current_Lat,Current_Long,Final_lat,Final_long);
			
			
		
			if(Distance>30){
			  set_led_value(0,0);
				set_led_value(1,0);
				set_led_value(2,0);
				set_led_value(0,1);
			}
			else if(Distance>10&&Distance<20){
			 set_led_value(0,0);
				set_led_value(1,0);
				set_led_value(2,0);
				set_led_value(0,1);
				set_led_value(2,1);
			
			
			
			}
			else if(Distance<10){
		 set_led_value(0,0);
				set_led_value(1,0);
				set_led_value(2,0);
				set_led_value(2,1);
				
			}
		
		
		
		}
		
		
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		






	}
		

		
		
		
		
