#include <stdint.h> 
#include "tm4c123gh6pm.h"
#include "LCD.h"

#include "GPIO.h"
void initialization_port_f(void){
	SYSCTL_RCGCGPIO_R |= 0x20;               //initialization clk of port f
	while ((SYSCTL_PRGPIO_R&0x20)==0){}      //time delay until clk=1
	GPIO_PORTF_LOCK_R=0x4C4F434B;            //unlock GPIO port F
	GPIO_PORTF_CR_R |= 0x1F;                 //allow changes to port f
    GPIO_PORTF_AFSEL_R &= ~0x1F;             //disable alternate func
	GPIO_PORTF_PCTL_R &= ~0x000FFFFF;
	GPIO_PORTF_AMSEL_R &= ~0x1F;             //disable analog
	GPIO_PORTF_DIR_R |= 0x0E;                //3 leds output
	GPIO_PORTF_DIR_R &= ~0x11;               //sw 1&4 input
	GPIO_PORTF_DEN_R |= 0x1F;                //enable digital
    GPIO_PORTF_PUR_R |= 0x11;                //enable pullup for sw1&4 switch
    GPIO_PORTF_DATA_R &=~ 0x0E;
}

/*void systick_init(void){
	NVIC_ST_CTRL_R=0;
	NVIC_ST_RELOAD_R=16000000-1;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=5;
	
}
void delay_Num(int count){
int i=0;
	for(i=0; i<count;i++){
while	(NVIC_ST_CTRL_R&=0x10000==0){}
	}
}
*/



void set_led_value (unsigned char led_color,unsigned char led_state){   //select led color and state
switch(led_color){

  case red_led : switch(led_state){
    case led_off :clr_bit(GPIO_PORTF_DATA_R,1); break;
    case led_on  :set_bit(GPIO_PORTF_DATA_R,1); break;
    default : break;
} break;

  case blue_led : switch(led_state){
    case led_off :clr_bit(GPIO_PORTF_DATA_R,2); break;
    case led_on  :set_bit(GPIO_PORTF_DATA_R,2); break;
    default : break;
} break;

  case green_led : switch(led_state){
    case led_off :clr_bit(GPIO_PORTF_DATA_R,3); break;
    case led_on  :set_bit(GPIO_PORTF_DATA_R,3); break;
    default : break;
} break;

default : {}

}
}


 

