#include "hal_data.h"
#include <stdio.h>

void ADC(void);
float ADC_VALUE(void);
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
    R_BSP_SoftwareDelay(50,BSP_DELAY_UNITS_MILLISECONDS);
    return ((float)ADC);
}


