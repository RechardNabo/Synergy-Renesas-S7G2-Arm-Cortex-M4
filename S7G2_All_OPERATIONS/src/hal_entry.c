/* HAL-only entry function */
#include <DAC_OUTPUT.h>
#include "hal_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LCD.h"
#include "ADC_READ.h"
//#include "UART.h"

#define TRUE 0x01
const int STATE= 0;
char msg_00[25];
char msg_01[25];
char msg_02[25];
char msg_03[25];
char msg_04[25];

void DAC_ADC_Function(void);
void i2c_device_scan(void);
void hal_entry(void){

    LCD_SETUP_4BIT();
    LCD_INITIALIZE_4BIT();
    while(TRUE){

        R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MICROSECONDS);
        LCD_20_LINE1();
        LCD_DISPLAY("Scanning 0 to 0x78");
        i2c_device_scan();


    }
}


void i2c_device_scan(void){
    ssp_err_t err;

    uint8_t data = 0;
    // Initialize I2C driver (replace with your actual I2C channel and configuration)
    err = g_i2c0.p_api->open(g_i2c0.p_ctrl, g_i2c0.p_cfg);
    if (SSP_SUCCESS != err)
    {
        printf("I2C initialization failed. Error code: %d\n", err);
        return;
    }
    R_BSP_SoftwareDelay(500,BSP_DELAY_UNITS_MILLISECONDS);
    // Scan I2C addresses
    for (uint16_t address = 0x00; address <= 0x78; ++address)
    {
        err = g_i2c0.p_api->slaveAddressSet(g_adc0.p_ctrl,address, I2C_ADDR_MODE_7BIT);
        if(err != SSP_SUCCESS){
            sprintf(msg_03,"Error set on slave 0x%02X",address);
            LCD_20_LINE2();
            LCD_DISPLAY(msg_03);
            //LCD_DISPLAY_DIGIT(address);
            R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
        }else{sprintf(msg_03,"Setting slave 0x%02X",address);}
        err = g_i2c0.p_api->write(g_i2c0.p_ctrl,&data,1,false);
        if(err == SSP_SUCCESS){
            sprintf(msg_04,"Device found 0x%02X", address);
            LCD_20_LINE3();
            LCD_DISPLAY(msg_04);
            R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
        }
    }
    LCD_20_LINE4();
    LCD_DISPLAY("Scan is Complete !");
    // Close I2C driver
    g_i2c0.p_api->close(g_i2c0.p_ctrl);
}

void DAC_ADC_Function(void){
    LCD_20_LINE1();
    LCD_DISPLAY("Temp Sensor ADC!");
    LCD_20_LINE2();
    sprintf((char*)msg_00,"DAC Value: %d Bits",(int)DAC_0_Output((int)ADC_VALUE()));
    LCD_DISPLAY(msg_00);
    LCD_20_LINE3();
    sprintf((char*)msg_01,"ADC Voltage: %.3fV",Voltage(ADC_VALUE()));
    LCD_DISPLAY(msg_01);
    LCD_20_LINE4();
    sprintf((char*)msg_02,"Int Temp : %.2f C",Internal_Temperature());
    LCD_DISPLAY(msg_02);
    R_BSP_SoftwareDelay(10,BSP_DELAY_UNITS_MICROSECONDS);
}
