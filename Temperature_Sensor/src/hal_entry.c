/* HAL-only entry function */
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "LCD.h"
#define TRUE 0x01


void ADC(void);
void hal_entry(void){

    ADC();
    uint16_t ADC;
    float voltage = 0;
    char msg[25];
    LCD_SETUP_4BIT();
    LCD_INITIALIZE_4BIT();

    while(TRUE){
         g_adc0.p_api->scanStart(g_adc0.p_ctrl);
         g_adc0.p_api->read(g_adc0.p_ctrl,ADC_REG_CHANNEL_0 , &ADC);
         voltage = (float)ADC* (5.0/4096.0);
        sprintf((char*)msg,"Voltage: %.3f V",voltage);
        LCD_16_LINE1();
        LCD_DISPLAY("Temp Sensor ADC!");
        LCD_16_LINE2();
        LCD_DISPLAY(msg);
        R_BSP_SoftwareDelay(50,BSP_DELAY_UNITS_MILLISECONDS);

    }
}

void ADC(void){
    g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);
}


