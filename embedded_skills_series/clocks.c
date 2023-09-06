#include <msp430.h>

void config_ACLK_to_32KHz() {
    PJSEL1 &= ~BIT4;
    PJSEL0 |= BIT4;

    // wait until the oscillator fault flags remain cleared
    CSCTL0 = CSKEY; // unlock CS registers

    do {
        CSCTL5 &= ~LFXTOFFG; // local fault flag
        SFRIFG1 &= ~OFIFG; // global fault flag
    } while((CSCTL5 & LFXTOFFG) != 0);
    CSCTL0_H = 0; // lock CS registers
    return;
}
