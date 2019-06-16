#include <avr/io.h>
#include <stdio.h>
#include "adc.h"
#include "predict.h"

	float getTemp(){
		uint16_t tmp = getADC();
		uint16_t tmp_new = getADC();
		//Noise filter
		tmp =  0.1 * tmp_new + 0.9 * tmp;
		//Convert to Temp/C
		float voltage = tmp * 0.00488759; //Vcc 5 / 1023 for the ADC conv.
		float tempC = (voltage - 0.5) * 100;
		return tempC;
	}
	
	float getLight(){
		uint16_t tmp = getADC();
		uint16_t tmp_new = getADC();
		//Noise filter
		tmp =  0.1 * tmp_new + 0.9 * tmp;
		//Convert to Temp/C
		float voltage = tmp * 0.00488759; //Vcc 5 / 1023 for the ADC conv.
		float tempC = (voltage - 0.5) * 100;
		return voltage;
	}

	void lightCollect(float temp){
		static uint8_t counter = 0;
		static int16_t *p;
		static int16_t series[101];
		p = series;
		p[98] = temp * 4096;
		//p[counter] = temp * 4096;

		//Prediction time, move the series, add new value to the end
		for (uint8_t x = 0; x <= 99; x++){
			series[x] = series[x+1];
		}
		if (series[0] > 5){
			series[100] = 4096;
			printf("{\"t\":%.1f,\"p\": %d\n}", temp, predictTemp(series));
		}
		
	}
	

	void tempCollect(float temp){
		static uint8_t counter = 0;
		static float *p;
		static float series[11];
		p = series;
//  p[10] = temp * 512;
		p[counter] = temp ;

if (counter++ == 9) {
			printf("1 1:%.2f 2:%.2f 3:%.2f 4:%.2f 5:%.2f 6:%.2f 7:%.2f 8:%.2f 9:%.2f 10:%.2f\n", 
			series[0], series[1], series[2], series[3], series[4],
			series[5], series[6], series[7], series[8], series[9]);
			counter = 0;
			/*
		Prediction time, move the series, add new value to the end
		for (uint8_t x = 0; x <= 9; x++){
			series[x] = series[x+1];
		}
		series[10] = 512;
		printf("{\"t\":%.1f,\"p\": %d}", temp, predictTemp(series));
		*/
		}
	}