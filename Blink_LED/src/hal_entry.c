/* HAL-only entry function */
#include "hal_data.h"
#include <stdbool.h>
#include <stdlib.h>

void hal_entry(void)
{
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_05,IOPORT_DIRECTION_OUTPUT);
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_08_PIN_01,IOPORT_DIRECTION_OUTPUT);

   while(EXIT_FAILURE){
       g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_05,0);
       g_ioport.p_api->pinWrite(IOPORT_PORT_08_PIN_01,0);
       R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MILLISECONDS);
       g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_05,1);
       g_ioport.p_api->pinWrite(IOPORT_PORT_08_PIN_01,1);
       R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MILLISECONDS);
   }
}
