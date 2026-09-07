/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_rspi.h"
#include "r_spi_api.h"
#include "r_dtc.h"
#include "r_transfer_api.h"
#include "r_sci_uart.h"
#include "r_uart_api.h"
#include "r_dac.h"
#include "r_dac_api.h"
#include "r_adc.h"
#include "r_adc_api.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#ifdef __cplusplus
extern "C" {
#endif
/** SPI config */
extern const spi_cfg_t g_spi0_cfg;
/** RSPI extended config */
extern const spi_on_rspi_cfg_t g_spi0_ext_cfg;
/** SPI on RSPI Instance. */
extern const spi_instance_t g_spi0;
/** SPI instance control */
extern rspi_instance_ctrl_t g_spi0_ctrl;
#ifndef NULL
void NULL(spi_callback_args_t *p_args);
#endif

extern const transfer_instance_t g_spi0_transfer_rx;
extern const transfer_instance_t g_spi0_transfer_tx;

#define SYNERGY_NOT_DEFINED (1)
#define RSPI_TRANSFER_SIZE_1_BYTE (0x52535049)

#if (SYNERGY_NOT_DEFINED == SYNERGY_NOT_DEFINED)
#define g_spi0_P_TRANSFER_TX (NULL)
#else
    #define g_spi0_P_TRANSFER_TX (&g_spi0_transfer_tx)
#endif
#if (SYNERGY_NOT_DEFINED == SYNERGY_NOT_DEFINED)
#define g_spi0_P_TRANSFER_RX (NULL)
#else
    #define g_spi0_P_TRANSFER_RX (&g_spi0_transfer_rx)
#endif

#undef RSPI_TRANSFER_SIZE_1_BYTE
#undef SYNERGY_NOT_DEFINED
#define g_spi0_P_EXTEND (&g_spi0_ext_cfg)
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer1;
#ifndef NULL
void NULL(transfer_callback_args_t *p_args);
#endif
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer0;
#ifndef NULL
void NULL(transfer_callback_args_t *p_args);
#endif
/** UART on SCI Instance. */
extern const uart_instance_t g_uart0;
#ifdef NULL
            #else
extern void NULL(uint32_t channel, uint32_t level);
#endif
#ifndef user_uart_callback
void user_uart_callback(uart_callback_args_t *p_args);
#endif
/** DAC on DAC Instance. */
extern const dac_instance_t g_dac1;
/** DAC on DAC Instance. */
extern const dac_instance_t g_dac0;
/** ADC on ADC Instance. */
extern const adc_instance_t g_adc1;
#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif
/** ADC on ADC Instance. */
extern const adc_instance_t g_adc0;
#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer3;
#ifndef user_timer3_comms_timeout_callback
void user_timer3_comms_timeout_callback(timer_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer2;
#ifndef user_timer2_sensor_poll_callback
void user_timer2_sensor_poll_callback(timer_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer1;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer0;
#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* HAL_DATA_H_ */
