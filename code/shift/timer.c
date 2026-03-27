volatile static uint32_t ms_counter;

static void timer_init(void) {
    // Datasheet section 14.9
    
    // 1. Waveform settings
    // TCCR0A:
    // COM0A1 COM0A0 COM0B1 COM0B0 - - WGM01 WGM00
    //   7      6      5      4    3 2   1     0   
    
    // TCCR0B:
    // FOC0A FOC0B - - WGM02 CS02 CS01 CS00
    //   7     6   5 4   3    2    1    0   
    
    // CTC mode: Mode 2, WGM02:0, WGM01:1, WGM00:0
    TCCR0A |= (1<<WGM01);
    TCCR0A &= ~(1<<WGM00);
    TCCR0B &= ~(1<<WGM02);
    
    
    // 2. Prescaler
    // Clock speed is 16MHz
    // 16 000 000 / 64 = 250 000 / 1000ms = 250 ticks per ms
    // Prescaler set to 64: CS02:0 CS01:1 CS00:1
    TCCR0B &= ~(1<<CS02);
    TCCR0B |= (1<<CS01);
    TCCR0B |= (1<<CS00);
    
    
    // 3. Calling Interrupts
    OCR0A = 249;
    TIMSK0 |= (1<<OCIE0A);
}

ISR(TIMER0_COMPA_vect) {
    ms_counter += 1;
}

static uint32_t timer_get_ms(void) {
    volatile uint32_t time;
    cli(); // pauses interrupts
    time = ms_counter;
    sei(); // enable interrupts
    return time;
}