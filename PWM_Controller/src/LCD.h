#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define D7 IOPORT_PORT_06_PIN_05
#define D6 IOPORT_PORT_06_PIN_04
#define D5 IOPORT_PORT_06_PIN_03
#define D4 IOPORT_PORT_06_PIN_02
#define EN IOPORT_PORT_06_PIN_01
#define RS IOPORT_PORT_06_PIN_00

#define OUTPUT IOPORT_DIRECTION_OUTPUT
#define INPUT IOPORT_DIRECTION_INPUT

#define MSEC BSP_DELAY_UNITS_MILLISECONDS
#define _4bit_mode 0x04
#define TIME 0X0A

void LCD_SETUP_4BIT(void);
void LCD_DATA(unsigned char data, int mode);
void LCD_INSTRUCTION_4BIT(unsigned char instruction);
void LCD_INITIALIZE_4BIT();
void LCD_DISPLAY(const char *string);
void LCD_DISPLAY_DIGIT(const float number);
void LCD_DISPLAY_NUM(float num);
void LCD_20_LINE1();
void LCD_20_LINE2();
void LCD_20_LINE3();
void LCD_20_LINE4();
void LCD_16_LINE1();
void LCD_16_LINE2();

void LCD_SETUP_4BIT(void){
    g_ioport.p_api->pinDirectionSet(D7,OUTPUT);
    g_ioport.p_api->pinDirectionSet(D6,OUTPUT);
    g_ioport.p_api->pinDirectionSet(D5,OUTPUT);
    g_ioport.p_api->pinDirectionSet(D4,OUTPUT);
    g_ioport.p_api->pinDirectionSet(EN,OUTPUT);
    g_ioport.p_api->pinDirectionSet(RS,OUTPUT);
}

void LCD_DATA(unsigned char data, int mode){
    unsigned char _data = data;
    int _4bit_[_4bit_mode];
    if(mode == 0x04){
        _data = _data>>0x04;
        for(int x =0x00; x < _4bit_mode; x++){
            _4bit_[x] = (_data & (0x01<<x))>>x;
        }
            g_ioport.p_api->pinWrite(D4,(char)_4bit_[0x00]);
            g_ioport.p_api->pinWrite(D5,(char)_4bit_[0x01]);
            g_ioport.p_api->pinWrite(D6,(char)_4bit_[0x02]);
            g_ioport.p_api->pinWrite(D7,(char)_4bit_[0x03]);

        g_ioport.p_api->pinWrite(RS,0x01);
        g_ioport.p_api->pinWrite(EN,0x01);
        R_BSP_SoftwareDelay(TIME,MSEC);
        g_ioport.p_api->pinWrite(EN,0x00);
        //=======================================
        _data = data;
        for(int x = 0x00; x< _4bit_mode; x++){
            _4bit_[x] = (_data & (0x01<<x))>>x;
        }
            g_ioport.p_api->pinWrite(D4,(char)_4bit_[0x00]);
            g_ioport.p_api->pinWrite(D5,(char)_4bit_[0x01]);
            g_ioport.p_api->pinWrite(D6,(char)_4bit_[0x02]);
            g_ioport.p_api->pinWrite(D7,(char)_4bit_[0x03]);

        g_ioport.p_api->pinWrite(RS,0x01);
        g_ioport.p_api->pinWrite(EN,0x01);
        R_BSP_SoftwareDelay(TIME,MSEC);
        g_ioport.p_api->pinWrite(EN,0x00);
        //=======================================
    }
}


void LCD_INSTRUCTION_4BIT(unsigned char instruction){
    int _4bit_[_4bit_mode];
    unsigned char data = instruction;
        data = data>>0x04;
        for(int x =0x00; x < _4bit_mode; x++){
            _4bit_[x] = (data & (0x01<<x))>>x;
        }
            g_ioport.p_api->pinWrite(D4,(char)_4bit_[0x00]);
            g_ioport.p_api->pinWrite(D5,(char)_4bit_[0x01]);
            g_ioport.p_api->pinWrite(D6,(char)_4bit_[0x02]);
            g_ioport.p_api->pinWrite(D7,(char)_4bit_[0x03]);

        g_ioport.p_api->pinWrite(RS,0x00);
        g_ioport.p_api->pinWrite(EN,0x01);
        R_BSP_SoftwareDelay(TIME,MSEC);
        g_ioport.p_api->pinWrite(EN,0x00);
        //========================================
        data = instruction;
        for(int x = 0x00; x< _4bit_mode; x++){
            _4bit_[x] = (data & (0x01<<x))>>x;
        }
            g_ioport.p_api->pinWrite(D4,(char)_4bit_[0x00]);
            g_ioport.p_api->pinWrite(D5,(char)_4bit_[0x01]);
            g_ioport.p_api->pinWrite(D6,(char)_4bit_[0x02]);
            g_ioport.p_api->pinWrite(D7,(char)_4bit_[0x03]);

        g_ioport.p_api->pinWrite(RS,0x00);
        g_ioport.p_api->pinWrite(EN,0x01);
        R_BSP_SoftwareDelay(TIME,MSEC);
        g_ioport.p_api->pinWrite(EN,0x00);
        //=======================================
}

void LCD_INITIALIZE_4BIT(){
    LCD_INSTRUCTION_4BIT(0x02);
    LCD_INSTRUCTION_4BIT(0x28);
    LCD_INSTRUCTION_4BIT(0x0c);
    LCD_INSTRUCTION_4BIT(0x06);
    LCD_INSTRUCTION_4BIT(0x01);

}


void LCD_DISPLAY(const char *string){
    int length =  (int)strlen(string);
    for(int x = 0x00 ;  x < length ; x++){
        LCD_DATA((unsigned char)string[x],_4bit_mode);
    }
}

void LCD_DISPLAY_DIGIT(const float number){
        LCD_DATA((unsigned char)number+0x30,_4bit_mode);
}

void LCD_DISPLAY_NUM(float num){
    char s[20];
    sprintf(s,"%.2f",num);
    LCD_DISPLAY(s);
}

//=======================[20x4 LCD Lines]=======================
void LCD_20_LINE1(){LCD_INSTRUCTION_4BIT(0x80);}
void LCD_20_LINE2(){LCD_INSTRUCTION_4BIT(0xC0);}
void LCD_20_LINE3(){LCD_INSTRUCTION_4BIT(0x94);}
void LCD_20_LINE4(){LCD_INSTRUCTION_4BIT(0xD4);}

//=======================[16x2 LCD Lines]=======================
void LCD_16_LINE1(){LCD_INSTRUCTION_4BIT(0x80);}
void LCD_16_LINE2(){LCD_INSTRUCTION_4BIT(0xC0);}
