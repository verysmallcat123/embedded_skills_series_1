#include "led.h"
#include <msp430.h>


void init_led()
{
    P1DIR |= red_LED; // direct pin as output
    P9DIR |= green_LED; // direct pin as output
    P1OUT ______________; // turn LED Off
    P9OUT ______________; // turn LED on
}
