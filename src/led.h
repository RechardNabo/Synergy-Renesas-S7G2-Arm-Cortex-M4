/**
 * @file led.h
 * @brief LED driver for the S7G2 SA-BEST 2017 Target Board
 *
 * Three user LEDs are available on the board:
 *   LED1 (Red)    - P305, active low
 *   LED2 (Green)  - P801, active high
 *   LED3 (Yellow) - P802, active low
 *
 * The active-low/active-high polarity is abstracted so callers
 * always use IOPORT_LEVEL_HIGH to turn an LED ON.
 */
#ifndef LED_H_
#define LED_H_

#include <stdint.h>
#include "hal_data.h"

/* ------------------------------------------------------------------ */
/* Constants                                                          */
/* ------------------------------------------------------------------ */

/** Number of user LEDs on the board */
#define LED_COUNT (3U)

/** Delay (ms) between LED state changes in the blinker pattern */
#define LED_BLINK_DELAY_MS (200U)

/* ------------------------------------------------------------------ */
/* Types                                                              */
/* ------------------------------------------------------------------ */

/** Logical LED identifiers (board silkscreen order) */
typedef enum e_led_id
{
    LED_RED    = 0U,   ///< LED1 on P305 (active low)
    LED_GREEN  = 1U,   ///< LED2 on P801 (active high)
    LED_YELLOW = 2U,   ///< LED3 on P802 (active low)
} led_id_t;

/* ------------------------------------------------------------------ */
/* Public API                                                         */
/* ------------------------------------------------------------------ */

/**
 * @brief Configure all LED GPIO pins as outputs.
 *        Call once before using any other LED function.
 */
void LED_Init(void);

/**
 * @brief Turn a specific LED on.
 * @param led  Which LED to control (LED_RED, LED_GREEN, LED_YELLOW)
 */
void LED_On(led_id_t led);

/**
 * @brief Turn a specific LED off.
 * @param led  Which LED to control (LED_RED, LED_GREEN, LED_YELLOW)
 */
void LED_Off(led_id_t led);

/**
 * @brief Toggle a specific LED.
 *        Reads the current physical level and writes the opposite.
 * @param led  Which LED to toggle
 */
void LED_Toggle(led_id_t led);

/**
 * @brief Turn all LEDs off.
 */
void LED_AllOff(void);

/**
 * @brief Turn all LEDs on.
 */
void LED_AllOn(void);

#endif /* LED_H_ */
