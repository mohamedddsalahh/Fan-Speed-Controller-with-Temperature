/*
 * ADC.h
 *
 *  Created on: Oct 5, 2022
 *      Author: User
 */

#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5
#define ADC_INTERNAL_VOLT_VALUE   2.56

typedef enum {
	AREF, AVCC, RESERVED, INTERNAL_VOLT
}ADC_ReferenceVoltage;

typedef enum {
	PRE_2, PRE2_2, PRE_4, PRE_8, PRE_16, PRE_32, PRE_64, PRE_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
