/**
 * @file hal_entry.c
 * @brief LED Blinker - blinks all 3 user LEDs (P305, P306, P307) together
 *
 * Hardware: SA-BEST 2017 Target Board, S7G2 MCU
 *   LED1 (Red)    - P305
 *   LED2 (Green)  - P306
 *   LED3 (Yellow) - P307
 */
#include "hal_data.h"
#include <stdbool.h>
#include <stdlib.h>

void hal_entry(void)
{
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_05, IOPORT_DIRECTION_OUTPUT);
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_06, IOPORT_DIRECTION_OUTPUT);
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_07, IOPORT_DIRECTION_OUTPUT);

    while (EXIT_FAILURE)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_05, 0);
        g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_06, 0);
        g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_07, 0);
        R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MILLISECONDS);
        g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_05, 1);
        g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_06, 1);
        g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_07, 1);
        R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MILLISECONDS);
    }
}
