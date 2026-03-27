
#define SER_PIN   PB4
#define OE_PIN    PB3
#define SRCLK_PIN PB2
#define SRCLR_PIN PB1

static void shift_init(void) {
    // Set output pins
    DDRB |= (1<<SER_PIN);
    DDRB |= (1<<OE_PIN);
    DDRB |= (1<<SRCLK_PIN);
    DDRB |= (1<<SRCLR_PIN);
    
    PORTB |= (1<<SRCLR_PIN);
}

static void shift_out_bit(void) {
    PORTB |= (1<<SER_PIN);
    PORTB |= (1<<SRCLK_PIN);
    PORTB &= ~(1<<SRCLK_PIN);
    PORTB &= ~(1<<SER_PIN);
}

static void shift(void) {
    PORTB |= (1<<SRCLK_PIN);
    PORTB &= ~(1<<SRCLK_PIN);
}

static void shift_enable_output(void) {
    PORTB |= (1<<OE_PIN);
    PORTB &= ~(1<<OE_PIN);
}

static void shift_clear(void) {
    PORTB &= ~(1<<SRCLR_PIN);
    PORTB |=  (1<<SRCLR_PIN);
}

static void shift_out_byte(uint8_t byte) {
    uint8_t i;
    for (i = 0; i < 8; i += 1) {
        if (byte & (1<<i)) {
            shift_out_bit();
        } else {
            shift();
        }
    }
}