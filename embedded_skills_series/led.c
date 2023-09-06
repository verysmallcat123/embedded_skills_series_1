#include "led.h"
#include <msp430.h>


void init_led()
{
    P1DIR |= red_LED; // direct pin as output
    P9DIR |= green_LED; // direct pin as output
    P1OUT &= ~red_LED; // turn LED Off
    P9OUT |= green_LED; // turn LED on
}
