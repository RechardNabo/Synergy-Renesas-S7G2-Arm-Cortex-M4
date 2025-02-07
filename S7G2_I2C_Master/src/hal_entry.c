/* HAL-only entry function */
#include  <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hal_data.h"
#include "LCD.h"

#define TRUE            0x01
#define FALSE           0x00

void I2C_Scanner(void);
void I2C_Scanner_00(void);
void hal_entry(void){

   // ssp_err_t Error_2 = SSP_SUCCESS;
   // bool device = false;
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_05,IOPORT_DIRECTION_OUTPUT); //RED
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_06,IOPORT_DIRECTION_OUTPUT); //Green
    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_03_PIN_07,IOPORT_DIRECTION_OUTPUT); //Yellow

    LCD_SETUP_4BIT();
    LCD_INITIALIZE_4BIT();

    g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_05,IOPORT_LEVEL_HIGH);
    g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_06,IOPORT_LEVEL_HIGH);
    g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_07,IOPORT_LEVEL_HIGH);

    while(TRUE){
        I2C_Scanner_00();
    }
}



void I2C_Scanner_00(void){
    LCD_20_LINE1();
    LCD_DISPLAY("I2C Master Scanner");
    for(uint16_t addresses = 1 ; addresses <=128 ; addresses++){
        g_i2c1.p_api->slaveAddressSet(g_i2c1.p_ctrl,addresses,I2C_ADDR_MODE_7BIT);
        g_i2c1.p_api->open(g_i2c1.p_ctrl,g_i2c1.p_cfg);

    }
}






















void I2C_Scanner(void){
    char MSG [50];
    uint8_t  Device = 0 ;
    LCD_20_LINE1();
    LCD_DISPLAY("I2C Master Scanner");

    ssp_err_t Error_1;

    for(uint8_t  Addresses = 1 ; Addresses <= 128; Addresses++){
        Error_1 = g_i2c0.p_api->open(g_i2c0.p_ctrl,g_i2c0.p_cfg);
        g_i2c0.p_api->reset(g_i2c0.p_ctrl);
        if(SSP_SUCCESS == Error_1){                                                     //check coms are open
            g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_07,IOPORT_LEVEL_LOW);
            LCD_20_LINE2();
            LCD_DISPLAY("I2C Open Success");
            sprintf(MSG,"Scanning: 0x%x = %d",Addresses,Addresses);
            LCD_20_LINE3();
            LCD_DISPLAY(MSG);
            Error_1 = g_i2c0.p_api->slaveAddressSet(g_i2c0.p_ctrl,Addresses,I2C_ADDR_MODE_7BIT);
            if(Error_1 == SSP_SUCCESS){
                /*LCD_20_LINE4();
                LCD_DISPLAY("Slave Set Success");*/
                for(uint8_t register_address = 0 ; register_address <= 128; register_address++){
                    g_i2c0.p_api->write(g_i2c0.p_ctrl,&register_address,1,false);
                    Error_1 = g_i2c0.p_api->read(g_i2c0.p_ctrl,&register_address,1,false);
                    if(Error_1 == SSP_SUCCESS){
                       g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_06,IOPORT_LEVEL_LOW);
                       Device  =  Addresses;
                       break;
                    }
                }
            }else{
                LCD_20_LINE4();
                LCD_DISPLAY("Slave Set Error");
            }
        }else{
            LCD_20_LINE2();
            LCD_DISPLAY("I2C Open Error !");
        }
        if(Device != 0){
            sprintf(MSG,"Device Found : 0x%x ",Addresses);
            g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_06,IOPORT_LEVEL_LOW);
            LCD_20_LINE4();
            LCD_DISPLAY(MSG);
            R_BSP_SoftwareDelay(5,BSP_DELAY_UNITS_SECONDS);
        }

        g_i2c0.p_api->close(g_i2c0.p_ctrl);
        g_i2c0.p_api->reset(g_i2c0.p_ctrl);
    }
    LCD_INITIALIZE_4BIT();
    g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_06,IOPORT_LEVEL_HIGH);
    g_ioport.p_api->pinWrite(IOPORT_PORT_03_PIN_07,IOPORT_LEVEL_LOW);
}

