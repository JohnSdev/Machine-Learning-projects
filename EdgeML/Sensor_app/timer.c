#include <avr/io.h>

#include "timer.h"

void timer_init() {
	//Timer1
	DDRB |= (1 << 0);
	OCR0A = 77;
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS02) | (0 << CS01) | (1 << CS00); 
	// //Timer 2 at 10ms
	// OCR2A = 77;
	// TCCR2A |= (1 << WGM21); 
	// TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22);
	// TIMSK2 |= (1 << OCIE2A);
}

