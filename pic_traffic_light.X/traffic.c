#include <xc.h>
#include "traffic.h"
#include "74hc595.h"
#define _XTAL_FREQ 4000000
void Opposite_State() {
    RED2 = GREEN1;
    GREEN2 = RED1;
}
void Auto_Mode() {
//STATE1
    RED1 = 1;
    GREEN1 = 0;
    Opposite_State();
    for (uint16_t i = 0; i < ROAD1_TIME / 100; i++) {
        __delay_ms(100);
        Display_Numb(ROAD1_TIME - i*1000);
        if (exitsign) { // Exit when have exit sign
            exitsign = 0;
            return;
        }    
    } 
//STATE2
    if (GREEN1 == 1) {
        GREEN1 = 0;
        YELLOW1 = 1;
        YELLOW2 = 0;  // Ensure YELLOW2 is off
        
    } else {
        GREEN2 = 0;
        YELLOW2 = 1;
        YELLOW1 = 0;  // Ensure YELLOW1 is off
    }
    for (uint16_t i = 0; i < YELLOW_TIME / 100; i++) {
        __delay_ms(100);
//        Display_Numb(YELLOW_TIME);
        if (exitsign) { // Exit when have exit sign
            exitsign = 0;
            return;
        }    
    } 
    YELLOW1 = 0;
    YELLOW2 = 0;
//STATE3
    RED1 = 0;
    GREEN1 = 1;
    Opposite_State();
    for (uint16_t i = 0; i < ROAD2_TIME / 100; i++) {
        __delay_ms(100);
//        Display_Numb(ROAD2_TIME);
        if (exitsign) { // Exit when have exit sign
            exitsign = 0;
            return;
        }    
    } 
//STATE4
        if (GREEN1 == 1) {
        GREEN1 = 0;
        YELLOW1 = 1;
        YELLOW2 = 0;  // Ensure YELLOW2 is off
        
    } else {
        GREEN2 = 0;
        YELLOW2 = 1;
        YELLOW1 = 0;  // Ensure YELLOW1 is off
    }
    for (uint16_t i = 0; i < YELLOW_TIME / 100; i++) {
        __delay_ms(100);
//        Display_Numb(YELLOW_TIME);
        if (exitsign) { // Exit when have exit sign
            exitsign = 0;
            return;
        }    
    } 
    YELLOW1 = 0;
    YELLOW2 = 0;
}

void Midnight_Mode() {
    YELLOW1 = !YELLOW1;
    YELLOW2 = !YELLOW2;
    for (uint16_t i = 0; i < 1000 / 100; i++) {
        __delay_ms(100);
        if (exitsign) { // Exit when have exit sign
            exitsign = 0;
            return;
        }    
    }   
}

void Manual_Mode() {    
    if (RB4 == 0) {
        if (GREEN1 == 1) {
            GREEN1 = 0;
            YELLOW1 = 1;
            YELLOW2 = 0;  // Ensure YELLOW2 is off

        } else {
            GREEN2 = 0;
            YELLOW2 = 1;
            YELLOW1 = 0;  // Ensure YELLOW1 is off
        }
        for (uint16_t i = 0; i < YELLOW_TIME / 100; i++) {
            __delay_ms(100);
            if (exitsign) { // Exit when have exit sign
                exitsign = 0;
                return;
            }    
        } 
        YELLOW1 = 0;
        YELLOW2 = 0;         
        turn = 0;
    }
    else if (RB5 == 0) {
        if (GREEN1 == 1) {
            GREEN1 = 0;
            YELLOW1 = 1;
            YELLOW2 = 0;  // Ensure YELLOW2 is off
        } else {
            GREEN2 = 0;
            YELLOW2 = 1;
            YELLOW1 = 0;  // Ensure YELLOW1 is off
        }
        for (uint16_t i = 0; i < YELLOW_TIME / 100; i++) {
            __delay_ms(100);
            if (exitsign) { // Exit when have exit sign
                exitsign = 0;
                return;
            }    
        } 
        YELLOW1 = 0;
        YELLOW2 = 0;         
        turn = 1;
    }
    if (turn == 0) {
        RED1 = 0;
        GREEN1 = 1;
    }
    else if (turn == 1) {
        RED1 = 1;
        GREEN1 = 0;
    }
    Opposite_State(); 
    if (exitsign) { // Exit when have exit sign
        exitsign = 0;
        return;  
    } 
}