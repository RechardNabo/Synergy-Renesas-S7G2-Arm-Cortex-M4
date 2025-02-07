#ifndef DAC_OUTPUT_H_
#define DAC_OUTPUT_H_
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DAC_0_Output(int ADC_RES);
int DAC_1_Output(int ADC_RES);
float DAC_Voltage(int DAC_RES);

int DAC_0_Output(int ADC_RES){
    uint16_t DAC  = (uint16_t)ADC_RES;
    g_dac0.p_api->open(g_dac0.p_ctrl,g_dac0.p_cfg);
    g_dac0.p_api->write(g_dac0.p_ctrl, DAC);
    g_dac0.p_api->start(g_dac0.p_ctrl);
    R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MICROSECONDS);
    return (DAC);
}
int DAC_1_Output(int ADC_RES){
    uint16_t DAC  = (uint16_t)ADC_RES;
    g_dac1.p_api->open(g_dac1.p_ctrl,g_dac1.p_cfg);
    g_dac1.p_api->write(g_dac1.p_ctrl, DAC);
    g_dac1.p_api->start(g_dac1.p_ctrl);
    R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MICROSECONDS);
    return (DAC);
}

float DAC_Voltage(int DAC_RES){
    float voltage= 0;
    voltage = (float) DAC_RES * (5.0f / 4096.0f);
    return (voltage);
}

#endif /* DAC_OUTPUT_H_ */
