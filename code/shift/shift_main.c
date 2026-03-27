#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer.c"
#include "shift.c"

#define SHIFT_TIME_MS 50

int main(void) {
    uint32_t last_shift_time = 0;
    uint8_t shift_counter = 0;
    
    shift_init();
    timer_init();
    
    for (;;) {
        uint32_t current_time;
        
        current_time = timer_get_ms();
        
        if (current_time - last_shift_time >= SHIFT_TIME_MS) {
            shift_out_byte(shift_counter++);
            shift_enable_output();
            last_shift_time = current_time;
        }
        
    }
    
    return 0;
}