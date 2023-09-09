/*
 * This code is developed for the IEEE UCF Embedded Programming Skills Series.
 */

#include <msp430.h>
#include "main.h"
#include "clocks.h"
#include "led.h"


void main(void) {
    WDTCTL = WDTPW | WDTHOLD;                   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                       // enable gpio pins

    init_led();                                 // initialize LEDs
    config_ACLK_to_32KHz();                     // configure timer source

    // Configure timer A
    TA0CCR0 |= _______; // counter
    TA0CCTL0 |= CCIE; // enable CCIE bit
    TA0CCTL0 &= ~CCIFG;  // clear CCIFG bit

    // Timer_A configuration (fill the line below)
    // Use ACLK, divide by 1, up mode, clear TAR
    TA0CTL = TASSEL_1 | ID_0 | MC_1 | TACLR;

    _enable_interrupts();                       // enable global interrupt bit (intrinsic function)

    for(;;) {}
}

#pragma vector = TIMER0_A0_VECTOR // Link the ISR to the vector

__interrupt void T0A0_ISR() {
    P1OUT __ red_LED;
    P9OUT __ green_LED;
}
