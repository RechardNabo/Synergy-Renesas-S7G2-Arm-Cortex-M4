#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ADC(void);
float ADC_VALUE(void);
float Voltage(float ADC_RES);
float Internal_Temperature(void);
void ADC(void){
    g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);
}

float ADC_VALUE(void){
    uint16_t ADC = 0;
    g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);
    g_adc0.p_api->read(g_adc0.p_ctrl,ADC_REG_CHANNEL_0 , &ADC);
    R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MICROSECONDS);
    return ((float)ADC);
}

float Voltage(float ADC_RES){
    float voltage = 0;
    voltage = ADC_RES * (float)(5.0/4096.0);
    return (voltage);
}

float Internal_Temperature(void){
    uint16_t temperature_adc = 0;
    float temp_voltage,temperatureDegreesC,average  = 0;
    g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart(g_adc0.p_ctrl);
    for(int x  = 0 ; x <=1000 ; x-=-1){
        g_adc0.p_api->read(g_adc0.p_ctrl,ADC_REG_TEMPERATURE ,&temperature_adc);
        average = average + temperature_adc;
        R_BSP_SoftwareDelay(5,BSP_DELAY_UNITS_MICROSECONDS);
    }
    average = average /1000;
    temp_voltage = (float)(average * 3.3f)/(4096.0f);
    temperatureDegreesC  = ((temp_voltage - 1.24f)/0.0051f)+25.0f;
    return (temperatureDegreesC);
}
