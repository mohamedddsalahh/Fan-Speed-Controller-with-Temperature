/*
 * main.c
 *
 *  Created on: Oct 5, 2022
 *      Author: User
 */

#include"adc.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"dc_motor.h"


void main(void){
	ADC_ConfigType ADC_Configuration = {INTERNAL_VOLT, PRE_8};
	ADC_init(&ADC_Configuration);
	DCMotor_init();
	LCD_init();
	uint8 temperature;
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temp =   C");

	while(1){

		temperature = LM35_getTemperature();
		LCD_moveCursor(1, 7);
		if(temperature >= 100){
			LCD_intgerToString(temperature);
		}
		else{
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(0, 7);
		if(temperature < 30){
			LCD_displayString("OFF");
		}
		else{
			LCD_displayString("ON ");
		}
		if(temperature < 30){
			DcMotor_Rotate(STOP, 0);
		}
		else if(temperature >= 30 && temperature < 60){
			DcMotor_Rotate(CW, 25);
		}
		else if(temperature >= 60 && temperature < 90){
			DcMotor_Rotate(CW, 50);
		}
		else if(temperature >= 90 && temperature < 120){
			DcMotor_Rotate(CW, 75);
		}
		else if(temperature >= 120 && temperature <= 150){
			DcMotor_Rotate(CW, 100);
		}
	}
}
