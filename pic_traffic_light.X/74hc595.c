#include <xc.h>
#include "74hc595.h"
#include "traffic.h"
void clock_signal(void){
   CLCOK_pin = 1;
    __delay_us(500);
   CLCOK_pin = 0;
    __delay_us(500);
}

void latch_enable(void)
   {
    LATCH_pin = 1;
    __delay_us(500);
    LATCH_pin = 0;
    }

void send_data(unsigned int data_out)
{
    int i;
    for (i=0 ; i<8 ; i++)
    {
        DATA_pin = (data_out >> i) & (0x01);
        clock_signal();
    }
    latch_enable(); // Data finally submitted
}

void Display_Numb(int counter) {    //Display number on 2 digits 7 segments led
    counter /= 10;
    a = (counter / 10);  // holds 10's digit
    b = (counter % 10);  // holds unit digit value
    send_data(binary_pattern[a]);  // send 10th place data to 2nd digit
    digit1 = 1;  //  turn on 2nd display unit
    __delay_ms(10);
    digit1 = 0;   //  turn off 2nd display unit
    send_data(binary_pattern[b]);  // send unit place data to 1st digit
    digit2 = 1;  //  turn on 1st display unit
    __delay_ms(10);
    digit2 = 0;  //  turn off 1st display unit
}