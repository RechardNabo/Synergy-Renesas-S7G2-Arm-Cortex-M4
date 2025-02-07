/* HAL-only entry function */
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "LCD.h"
#define TRUE 0x01

void hal_entry(void){

    float counter = 0.681;
    LCD_SETUP_4BIT();
    LCD_INITIALIZE_4BIT();
    while(TRUE){
        LCD_16_LINE1();
        LCD_DISPLAY("Hello Rechard!");
        LCD_16_LINE2();
        LCD_DISPLAY("Number : ");
        LCD_DISPLAY_NUM(counter);
        counter = counter + 0.168;
        R_BSP_SoftwareDelay(100,BSP_DELAY_UNITS_MILLISECONDS);
    }
}
