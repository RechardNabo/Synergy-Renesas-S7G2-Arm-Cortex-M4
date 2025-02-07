/* HAL-only entry function */
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LCD.h"
#include "ADC_READ.h"
#define TRUE 0x01
const int STATE= 0;

void BLINK_LED(void);
void hal_entry(void){

    float voltage = 0;
    char msg[25];
    LCD_SETUP_4BIT();
    LCD_INITIALIZE_4BIT();

    while(TRUE){

        voltage = ADC_VALUE()* (3.33/4096.0);
        sprintf((char*)msg,"Voltage: %.3f V",voltage);
        LCD_16_LINE1();
        LCD_DISPLAY("Temp Sensor ADC!");
        LCD_16_LINE2();
        LCD_DISPLAY(msg);
        R_BSP_SoftwareDelay(50,BSP_DELAY_UNITS_MILLISECONDS);
        BLINK_LED();
    }
}

void BLINK_LED(void){
    int state = STATE;
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_06_PIN_11,IOPORT_DIRECTION_OUTPUT);
    g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_11,~STATE);
    R_BSP_SoftwareDelay(100,BSP_DELAY_UNITS_MILLISECONDS);
}




