// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>
#define DATA_pin PORTCbits.RC1
#define LATCH_pin  PORTCbits.RC2
#define CLCOK_pin  PORTCbits.RC0
#define digit1 PORTBbits.RB0
#define digit2 PORTBbits.RB1
#define digit3 PORTBbits.RB2
#define digit4 PORTBbits.RB3
#define _XTAL_FREQ 2000000 //Crystal Frequency, used in delay
unsigned char binary_pattern[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned int counter=0;
unsigned int a,b,c,d;
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



void main(void)
{
  TRISC0 = 0; // Set  DATA_pin as output pin
  TRISC1 = 0; // Set  CLCOK_pin as output pin
  TRISC2 = 0; // Set LATCH_pin as output pin
  TRISB=0X00;
  digit1 = 0;
  digit2 = 0; 
  digit3 = 0;
  digit4 = 0;
    while(1)
      {
        
         a = counter / 1000;   // holds 1000's digit
         b = ((counter/100)%10); // holds 100's digit
         c = ((counter/10)%10);  // holds 10th digit
         d = (counter%10);  // holds unit digit value
         send_data(binary_pattern[a]); // send 1000's place data to fourth digit
        digit1=1;   //  turn on forth display unit
        __delay_ms(10);
        digit1=0;   //  turn off forth display unit
        send_data(binary_pattern[b]);  // send 100's place data to 3rd digit
        digit2=1;    //  turn on 3rd display unit
        __delay_ms(10);
        digit2=0;  //  turn off 3rd display unit
         send_data(binary_pattern[c]);  // send 10th place data to 2nd digit
         digit3 = 1;  //  turn on 2nd display unit
         __delay_ms(10);
        digit3 = 0;   //  turn off 2nd display unit
       send_data(binary_pattern[d]);  // send unit place data to 1st digit
       digit4 = 1;  //  turn on 1st display unit
       __delay_ms(10);
       digit4 = 0;  //  turn off 1st display unit

     if(counter>=9999) //wait till flag reaches 100
         {
         counter=0; //only if flag is hundred "i" will be incremented 
         }
         counter++; //increment flag for each flag
     }
      
  return;
}