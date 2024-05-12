/*
 * pwm.c
 *
 *  Created on: Oct 5, 2022
 *      Author: User
 */

#include"pwm.h"
#include<avr/io.h>
#include"std_types.h"
#include"gpio.h"


void PWM_TIMER0_start(uint8 duty_cycle){

	TCNT0 = 0;													//Initialize Timer0 Counter = 0
	OCR0 = duty_cycle;
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);		//Set OC0 Output
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01)| (1<<CS01);	//Fast PWM Mode, Non-Inverting, Pre-scaler = 8
}

