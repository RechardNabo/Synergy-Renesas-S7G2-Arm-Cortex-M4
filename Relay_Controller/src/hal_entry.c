/* HAL-only entry function */
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "LCD.h"

#define TRUE 0x01
#define RELAY IOPORT_PORT_08_PIN_00

void hal_entry(void){
    g_ioport.p_api->pinDirectionSet(RELAY,OUTPUT);
    LCD_SETUP_4BIT();
    LCD_INITIALIZE_4BIT();
    int state = 0;
    while(TRUE){

        LCD_16_LINE1();
        LCD_DISPLAY("Relay Controller");
        if(state == 0x00){
            g_ioport.p_api->pinWrite(RELAY,1);
            LCD_16_LINE2();
            LCD_DISPLAY("Relay ON ");
            state = 0x01;
            R_BSP_SoftwareDelay(1000,BSP_DELAY_UNITS_MILLISECONDS);
        }
        if(state == 0x01){
            g_ioport.p_api->pinWrite(RELAY,0);
            LCD_16_LINE2();
            LCD_DISPLAY("Relay OFF");
            state = 0x00;
            R_BSP_SoftwareDelay(1000,BSP_DELAY_UNITS_MILLISECONDS);
        }

    }
}
