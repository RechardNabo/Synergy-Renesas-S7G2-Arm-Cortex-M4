/**
 * @file led.c
 * @brief LED driver implementation for the S7G2 SA-BEST 2017 Target Board
 *
 * Abstracts the active-low / active-high polarity of the three user LEDs
 * so the caller always uses IOPORT_LEVEL_HIGH to mean "ON".
 */
#include "led.h"

/* ------------------------------------------------------------------ */
/* Private data                                                       */
/* ------------------------------------------------------------------ */

/** Physical pin for each logical LED (indexed by led_id_t) */
static const ioport_port_pin_t led_pin[LED_COUNT] =
{
    [LED_RED]    = IOPORT_PORT_03_PIN_05,   /* P305 */
    [LED_GREEN]  = IOPORT_PORT_08_PIN_01,   /* P801 */
    [LED_YELLOW] = IOPORT_PORT_08_PIN_02,   /* P802 */
};

/**
 * Active level that turns each LED ON.
 *   Active-low  LEDs light when the pin is LOW  (0)
 *   Active-high LEDs light when the pin is HIGH (1)
 */
static const ioport_level_t led_on_level[LED_COUNT] =
{
    [LED_RED]    = IOPORT_LEVEL_LOW,    /* LED1 active low  */
    [LED_GREEN]  = IOPORT_LEVEL_HIGH,  /* LED2 active high */
    [LED_YELLOW] = IOPORT_LEVEL_LOW,   /* LED3 active low  */
};

/* ------------------------------------------------------------------ */
/* Public functions                                                   */
/* ------------------------------------------------------------------ */

void LED_Init(void)
{
    for (uint32_t i = 0U; i < LED_COUNT; i++)
    {
        g_ioport.p_api->pinDirectionSet(led_pin[i], IOPORT_DIRECTION_OUTPUT);
        /* Start with all LEDs off */
        LED_Off((led_id_t)i);
    }
}

void LED_On(led_id_t led)
{
    if (led < LED_COUNT)
    {
        g_ioport.p_api->pinWrite(led_pin[led], led_on_level[led]);
    }
}

void LED_Off(led_id_t led)
{
    if (led < LED_COUNT)
    {
        /* Write the opposite of the ON level */
        ioport_level_t off_level =
            (led_on_level[led] == IOPORT_LEVEL_HIGH) ? IOPORT_LEVEL_LOW : IOPORT_LEVEL_HIGH;
        g_ioport.p_api->pinWrite(led_pin[led], off_level);
    }
}

void LED_Toggle(led_id_t led)
{
    if (led < LED_COUNT)
    {
        ioport_level_t current_level;
        g_ioport.p_api->pinRead(led_pin[led], &current_level);
        /* Write the opposite of whatever we just read */
        ioport_level_t new_level =
            (current_level == IOPORT_LEVEL_HIGH) ? IOPORT_LEVEL_LOW : IOPORT_LEVEL_HIGH;
        g_ioport.p_api->pinWrite(led_pin[led], new_level);
    }
}

void LED_AllOff(void)
{
    for (uint32_t i = 0U; i < LED_COUNT; i++)
    {
        LED_Off((led_id_t)i);
    }
}

void LED_AllOn(void)
{
    for (uint32_t i = 0U; i < LED_COUNT; i++)
    {
        LED_On((led_id_t)i);
    }
}
