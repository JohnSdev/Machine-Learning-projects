#include <avr/io.h>
#include "adc.h"

static volatile uint8_t adc_value = 0;

void adc_init(void) {
	/*
	 * - Reference voltage = AVcc (5V) (REFS[1:0]=0b01)
	 * - Left adjusted data (ADLAR=1)
	 * - Using channel ADC0 (MUX[3:0]=0b0000)
	 */
	ADMUX = (1 << REFS0 | 0 << ADLAR);
	ADMUX |= (0 << MUX3 | 0 << MUX2 | 0 << MUX1 | 0 << MUX0);

	/*
	 * - ADC enabled
	 * - Interrupts enabled
	 * - Prescaler set to 8 (ADPS[2:0]=0b011)
	 */
	ADCSRA = (1 << ADEN | 0 << ADPS2 | 1 << ADPS1 | 1 << ADPS0 | 1 << ADATE);
	//Start Conversion
	ADCSRA |= (1<<ADSC);
}

uint16_t getADC(void){
	uint16_t adcResult;
	adcResult = ADCL;
	adcResult |= ADCH<<8;
	return adcResult;
	}

void set_adc_value(uint8_t val) {
	adc_value = val;
}

uint8_t get_adc_value(void) {
	return adc_value;
}
