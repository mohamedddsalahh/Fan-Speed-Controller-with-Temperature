/*
 * ADC.c
 *
 *  Created on: Oct 5, 2022
 *      Author: User
 */
#include<avr/io.h>
#include"adc.h"
#include"common_macros.h"
#include"std_types.h"


void ADC_init(const ADC_ConfigType * Config_Ptr){
	uint8 pre_value, volt;
	ADMUX = 0;										//Initialize ADMUX 0000000
	volt = (Config_Ptr->ref_volt) << 6;	//Shift voltage to REFS0 and REFS1 -> bit 6 - 7
	ADMUX |= volt;
	pre_value = (Config_Ptr->prescaler);	//Get only the first 3 bits to assign them to ADCSRA

	ADCSRA = pre_value | (1<<ADEN);				//Enable ADC and assign Pre-scaler value
}

uint16 ADC_readChannel(uint8 channel_num){
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}


