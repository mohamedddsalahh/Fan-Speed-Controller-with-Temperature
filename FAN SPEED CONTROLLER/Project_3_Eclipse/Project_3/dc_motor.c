/*
 * dc_motor.c
 *
 *  Created on: Oct 5, 2022
 *      Author: User
 */


#include"dc_motor.h"
#include"std_types.h"
#include"gpio.h"
#include"pwm.h"

void DCMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);			//IN1 Pin
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);			//IN2 Pin
	GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_LOW);			//Enable Pin
}

void DcMotor_Rotate(DCMotor_State state, uint8 speed){
	switch(state){
	case STOP:
		GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_HIGH);
		break;
	case CCW:
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_LOW);
		break;
	}
	uint16 duty = (speed*255)/100;
	PWM_TIMER0_start((uint8)duty);
}
