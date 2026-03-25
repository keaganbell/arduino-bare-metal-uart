#define F_CPU 16000000UL
#define BAUD 9600
#include <util/setbaud.h>

#include <avr/io.h>
#include <util/delay.h>

#include "base_core.h"

int main(void) {
    
    DDRB = BIT_SET(DDRB, DDB5);
    
    for (;;) {
        PORTB = BIT_SET(PORTB, PORTB5);
        _delay_ms(5000);
        PORTB = BIT_UNSET(PORTB, PORTB5);
        _delay_ms(5000);
    }
    
    return 0;
}