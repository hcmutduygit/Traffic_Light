#include <xc.h>
#define DATA_pin PORTCbits.RC1
#define LATCH_pin  PORTCbits.RC2
#define CLCOK_pin  PORTCbits.RC0
#define digit1 PORTDbits.RD6
#define digit2 PORTDbits.RD7
unsigned int counter=0;
#define _XTAL_FREQ 4000000 //Crystal Frequency, used in delay
unsigned char binary_pattern[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned int a,b;

void clock_signal(void);
void latch_enable(void);
void send_data(unsigned int data_out);
void Display_Numb();