#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "adc.h"
#include "serial.h"
#include "timer.h"
#include "temp.h"
#include "predict.h"


static uint16_t counter = 0;
float old = 0;
float new = 0;

ISR(TIMER2_COMPA_vect){
 counter++;
}

void main (void) {
	uint8_t counterPrediction = 0;
	uart_init();
	adc_init();
	timer_init();
	sei();

// 	while(1){
// 		// old = getTemp();
// 		// new = getTemp();
// 		// new = 0.1 * new + 0.9 * old;
// 		float tmp = getLight();
// 		if (tmp > 2.45){
// 			printf("2 ");
// 			for (uint8_t i = 1; i <= 100; i++){
// 				printf("%i:%f ", i, getLight());
// 			}
// 			printf("\n");
// 		}
// 		//printf("%f,", getLight());
// 	}
// }

	printf("Start. Current light value: %f", getLight());
	static int16_t *p;
	static int16_t series[101];
	p = series;
	uint8_t counter = 0;
	int16_t three[101] = { 11451, 11491, 11511, 11511, 11491, 11491, 11491, 11491, 11511, 11511, 11491, 11491, 11491, 11511, 11491, 11491, 11491, 11511, 11491, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11491, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11491, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11511, 11511, 11491, 11491, 11491, 11511, 11491, 11491, 11511, 11451, 11411, 11391, 11451, 11451, 11391, 11391, 11451, 11451, 11391, 11391, 11451, 12011, 12011, 4096};

	
	while(1){
		
		if (TIFR0 & (1 << OCF0A)){
			TIFR0 |= (0 << OCF0A);
			float tmp = getLight();
		//printf("Start. Current light value: %f", tmp);
		if ( tmp > 2.9 ){
			while(counter <= 99){
				float tempLight = getLight();
				_delay_ms(10);
				series[counter] =  tempLight * 4096;
				counter ++;
			}
			series[100] = 4096;
			printf("{\"p\": %d}\n", predictTemp(series));
			counter = 0;
			for (uint8_t i = 0; i <=100; i++){
			}
		}
    }
	}
}