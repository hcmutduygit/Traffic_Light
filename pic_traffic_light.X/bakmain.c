//#include <xc.h>
//#include "lcd.h"
//#include "pic16f887.h"
//#include "traffic.h"
//#include <stdint.h>
//#include "74hc595.h"
//#define _XTAL_FREQ 4000000
//
//void setup() {
//    // I/O setup
//    ANSELH = 0; // All I/O pins are configured as digital
//    TRISB = 0b00110001; // RB0 and RB4 and RB5 are input
//    PORTB = 0; // All PORTB pins are cleared
//    TRISE = 0b00000000;
//    PORTE = 0;
//    TRISC = 0x00;
//    PORTC = 0;
//    OPTION_REGbits.nRBPU = 0; // Pull-up resistors are enabled
//    WPUB0 = 1; // Enable pull-up on B0
//    WPUB4 = 1; // Enable pull-up on B4
//    WPUB5 = 1; // Enable pull-up on B5
//    
//    // Interrupt setup
//    GIE = 1; //Allow all kind of interrupt work (GIE: Global interrupt enable) 
//    INTE = 1; //Enable external interrupt on RB0 because only RB0 has it (INTE: External interrupt enable)
//    INTEDG = 1; // Set Rising Edge Trigger for INT, in this case interrupt when release the button
//    
//    // Timer setup
//    
//}
//
//
//void main(void) {
//    // TRAFFIC LIGHT SETUP
//    TRISD = 0x00; // PORTD output
//    PORTD = 0x00;
//    RED1 = 0;
//    RED2 = 0;
//    GREEN1 = 0;
//    GREEN2 = 0;
//    YELLOW1 = 0;
//    YELLOW2 = 0;
//
//    /////////////////
//    // COUNTING TIME SETUP
//    TRISB=0X00;
//    TRISE = 0x00; // RE0, RE1, RE2 output
//    digit1 = 0;
//    digit2 = 0;     
//    ////////////////
//    setup();
//    while (1) {
//        if (mode % 3 == 0) {
//            RE0 = 1; 
//            Auto_Mode();     
//        }
//        else if (mode % 3 == 1) {
//            RE0 = 0;
//            Midnight_Mode();
//        }
//        else {
//            RE0 = 1;
//            Manual_Mode();
//        }
////        Display_Numb();
//    }
//}
//
//void __interrupt() ISR() {
//    if (INTCONbits.INTF) { // Check if Interrupt   
//        INTCONbits.INTF = 0; // Clear interrupt flag
//        mode += 1;
//        exitsign = 1;
//    }
////    Turn on yellow light when change mode for safety
////    PORTD = 0b00010010;
////    __delay_ms(YELLOW_TIME);
//    PORTD = 0;
//}