/* HAL-only entry function */
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LCD.h"

#define TRUE 0x01
ssp_err_t status;
timer_size_t duty_cycle_percent = 0;

/******************************************************************
 * @brief  Blinky Labs application project
 *
 * Pulses an LED using the GPT output by adjusting the duty cycle.
 *
 ******************************************************************/
void hal_entry(void) {

    /* Open GPT Timer */
    status = g_timer0.p_api->open(g_timer0.p_ctrl, g_timer0.p_cfg);
    if(status != SSP_SUCCESS)
    {
        while(1);
    }

    /* Start GPT Timer */
    status = g_timer0.p_api->start(g_timer0.p_ctrl);
    if(status != SSP_SUCCESS)
    {
        while(1);
    }

    while(1)
    {
       status = g_timer0.p_api->dutyCycleSet(g_timer0.p_ctrl, duty_cycle_percent, TIMER_PWM_UNIT_PERCENT, 0);
       if(status != SSP_SUCCESS)
       {
          while(1);
       }

       R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

       if (duty_cycle_percent == 100)
       {
          duty_cycle_percent = 0;
       }
       else
       {
         duty_cycle_percent = duty_cycle_percent + 10;
       }
    }
}

