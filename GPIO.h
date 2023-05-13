#define   get_bit(reg,bit) ((reg>>bit)&1)
#define red_led 0
#define blue_led 1
#define green_led 2
#define led_off 0
#define led_on 1
void set_led_value (unsigned char led_color,unsigned char led_state);
unsigned char switch_value (unsigned char input);
void initialization_port_f(void);
/*void systick_init(void);
void delay_Num(int count);
*/
