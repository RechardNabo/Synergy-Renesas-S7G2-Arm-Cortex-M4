/* generated HAL source file - do not edit */
#include "hal_data.h"
#define RSPI_TRANSFER_SIZE_1_BYTE (0x52535049)
#define RSPI_SYNERGY_NOT_DEFINED 1
#if (RSPI_SYNERGY_NOT_DEFINED != RSPI_SYNERGY_NOT_DEFINED)
dtc_instance_ctrl_t g_spi0_transfer_tx_ctrl;
uint32_t g_spi0_tx_inter = 0;
transfer_info_t g_spi0_transfer_tx_info[2] =
{ 
#if (RSPI_TRANSFER_SIZE_1_BYTE == RSPI_SYNERGY_NOT_DEFINED)
    {
    .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, 
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_EACH, 
    .src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED, 
    .size = TRANSFER_SIZE_1_BYTE,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest = (void *) &g_spi0_tx_inter, 
    .p_src = (void const *) NULL, 
    .num_blocks = 0, 
    .length = 0,
    }, 
    {
    .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, 
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_DISABLED, 
    .src_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .size = TRANSFER_SIZE_4_BYTE,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest = (void *) NULL, 
    .p_src = (void const *) &g_spi0_tx_inter, 
    .num_blocks = 0, 
    .length = 0,
    }, 
#else
    { 
    .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
    .src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
    .size =SYNERGY_NOT_DEFINED,
    .mode = TRANSFER_MODE_NORMAL,
    .p_dest = (void *) NULL,
    .p_src = (void const *) NULL,
    .num_blocks = 0,
    .length = 0,
    },
    {
    .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, 
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_DISABLED, 
    .src_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .size = TRANSFER_SIZE_4_BYTE,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest =(void *) NULL, 
    .p_src =  (void const *) &g_spi0_tx_inter, 
    .num_blocks = 0, 
    .length = 0,
    }, 
#endif
    };
	
	const transfer_cfg_t g_spi0_transfer_tx_cfg =
{ 
	.p_info = g_spi0_transfer_tx_info, 
	.activation_source = SYNERGY_NOT_DEFINED, 
	.auto_enable = false, 
	.p_callback = NULL,
	.p_context = &g_spi0_transfer_tx, 
	.irq_ipl = SYNERGY_NOT_DEFINED
};
/* Instance structure to use this module. */
const transfer_instance_t g_spi0_transfer_tx =
{ 
	.p_ctrl = &g_spi0_transfer_tx_ctrl, 
	.p_cfg = &g_spi0_transfer_tx_cfg, 
	.p_api = &g_transfer_on_dtc 
};


dtc_instance_ctrl_t g_spi0_transfer_rx_ctrl;
uint32_t g_spi0_rx_inter = 0;
transfer_info_t g_spi0_transfer_rx_info[2] =
{ 
#if (RSPI_TRANSFER_SIZE_1_BYTE == RSPI_SYNERGY_NOT_DEFINED)
    {
    .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, 
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_EACH, 
    .src_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .size = TRANSFER_SIZE_4_BYTE,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest = (void *) &g_spi0_rx_inter, 
    .p_src = (void const *) NULL, 
    .num_blocks = 0, 
    .length = 0,
    }, 
    {
    .dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED, 
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, 
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_DISABLED, 
    .src_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .size = TRANSFER_SIZE_1_BYTE,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest = (void *) NULL, 
    .p_src = (void const *) &g_spi0_rx_inter, 
    .num_blocks = 0, 
    .length = 0,
    }, 
#else
    { 
    .dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
    .repeat_area = TRANSFER_REPEAT_AREA_DESTINATION,
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
    .src_addr_mode = TRANSFER_ADDR_MODE_FIXED,
    .size = SYNERGY_NOT_DEFINED,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest = (void *) NULL, 
    .p_src = (void const *) NULL, 
    .num_blocks = 0, 
    }, 
    {
    .dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED, 
    .repeat_area = TRANSFER_REPEAT_AREA_SOURCE, 
    .irq = TRANSFER_IRQ_END,
    .chain_mode = TRANSFER_CHAIN_MODE_DISABLED, 
    .src_addr_mode = TRANSFER_ADDR_MODE_FIXED, 
    .size = TRANSFER_SIZE_1_BYTE,
    .mode = TRANSFER_MODE_NORMAL, 
    .p_dest = (void *) NULL, 
    .p_src = (void const *) &g_spi0_rx_inter, 
    .num_blocks = 0, 
    .length = 0,
    }, 
#endif
    };
	
	const transfer_cfg_t g_spi0_transfer_rx_cfg =
{ 
	.p_info = g_spi0_transfer_rx_info, 
	.activation_source = SYNERGY_NOT_DEFINED,
	.auto_enable = false, 
	.p_callback = NULL,
	.p_context = &g_spi0_transfer_rx, 
	.irq_ipl = SYNERGY_NOT_DEFINED
};
/* Instance structure to use this module. */
const transfer_instance_t g_spi0_transfer_rx =
{ 
	.p_ctrl = &g_spi0_transfer_rx_ctrl, 
	.p_cfg = &g_spi0_transfer_rx_cfg, 
	.p_api = &g_transfer_on_dtc 
};
#endif
#undef RSPI_TRANSFER_SIZE_1_BYTE	
#undef RSPI_SYNERGY_NOT_DEFINED

#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SPI0)
SSP_VECTOR_DEFINE_CHAN(spi_rxi_isr, SPI, RXI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SPI0)
SSP_VECTOR_DEFINE_CHAN(spi_txi_isr, SPI, TXI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SPI0)
SSP_VECTOR_DEFINE_CHAN(spi_eri_isr, SPI, ERI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SPI0)
SSP_VECTOR_DEFINE_CHAN(spi_tei_isr, SPI, TEI, 0);
#endif
rspi_instance_ctrl_t g_spi0_ctrl;

/** RSPI extended configuration for RSPI HAL driver */
const spi_on_rspi_cfg_t g_spi0_ext_cfg =
{ .rspi_clksyn = RSPI_OPERATION_SPI,
  /* Communication mode is configured by the driver. write calls use TX_ONLY. read and writeRead use FULL_DUPLEX. */
  .rspi_comm = RSPI_COMMUNICATION_FULL_DUPLEX,
  .ssl_polarity.rspi_ssl0 = RSPI_SSLP_LOW,
  .loopback.rspi_loopback1 = RSPI_LOOPBACK1_NORMAL_DATA,
  .loopback.rspi_loopback2 = RSPI_LOOPBACK2_NORMAL_DATA,
  .mosi_idle.rspi_mosi_idle_fixed_val = RSPI_MOSI_IDLE_FIXED_VAL_LOW,
  .mosi_idle.rspi_mosi_idle_val_fixing = RSPI_MOSI_IDLE_VAL_FIXING_DISABLE,
  .parity.rspi_parity = RSPI_PARITY_STATE_DISABLE,
  .parity.rspi_parity_mode = RSPI_PARITY_MODE_EVEN,
  .ssl_select = RSPI_SSL_SELECT_SSL0,
  .ssl_level_keep = RSPI_SSL_LEVEL_KEEP_NOT,
  .clock_delay.rspi_clock_delay_count = RSPI_CLOCK_DELAY_COUNT_1,
  .clock_delay.rspi_clock_delay_state = RSPI_CLOCK_DELAY_STATE_DISABLE,
  .ssl_neg_delay.rspi_ssl_neg_delay_count = RSPI_SSL_NEGATION_DELAY_1,
  .ssl_neg_delay.rspi_ssl_neg_delay_state = RSPI_SSL_NEGATION_DELAY_DISABLE,
  .access_delay.rspi_next_access_delay_count = RSPI_NEXT_ACCESS_DELAY_COUNT_1,
  .access_delay.rspi_next_access_delay_state = RSPI_NEXT_ACCESS_DELAY_STATE_DISABLE,
  .byte_swap = RSPI_BYTE_SWAP_DISABLE, };

const spi_cfg_t g_spi0_cfg =
{ .channel = 0,
  .operating_mode = SPI_MODE_MASTER,
  .clk_phase = SPI_CLK_PHASE_EDGE_EVEN,
  .clk_polarity = SPI_CLK_POLARITY_LOW,
  .mode_fault = SPI_MODE_FAULT_ERROR_DISABLE,
  .bit_order = SPI_BIT_ORDER_MSB_FIRST,
  .bitrate = 12000000,
  .p_transfer_tx = g_spi0_P_TRANSFER_TX,
  .p_transfer_rx = g_spi0_P_TRANSFER_RX,
  .p_callback = NULL,
  .p_context = (void*) &g_spi0,
  .p_extend = (void*) &g_spi0_ext_cfg,
  .rxi_ipl = (12),
  .txi_ipl = (12),
  .eri_ipl = (12),
  .tei_ipl = (12), };
/* Instance structure to use this module. */
const spi_instance_t g_spi0 =
{ .p_ctrl = &g_spi0_ctrl, .p_cfg = &g_spi0_cfg, .p_api = &g_spi_on_rspi };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer1) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_SCI0_RXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_SCI0_RXI
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_0) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_0);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0
#endif
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_1) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_1);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1
#endif
#endif
#endif

dtc_instance_ctrl_t g_transfer1_ctrl;
transfer_info_t g_transfer1_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .repeat_area = TRANSFER_REPEAT_AREA_DESTINATION,
  .irq = TRANSFER_IRQ_END,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .size = TRANSFER_SIZE_1_BYTE,
  .mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = 0,
  .length = 0, };
const transfer_cfg_t g_transfer1_cfg =
{ .p_info = &g_transfer1_info,
  .activation_source = ELC_EVENT_SCI0_RXI,
  .auto_enable = false,
  .p_callback = NULL,
  .p_context = &g_transfer1,
  .irq_ipl = (BSP_IRQ_DISABLED) };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 =
{ .p_ctrl = &g_transfer1_ctrl, .p_cfg = &g_transfer1_cfg, .p_api = &g_transfer_on_dtc };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer0) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_SCI0_TXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_SCI0_TXI
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_0) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_0);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_0
#endif
#if defined(DTC_ACTIVATION_SRC_ELC_EVENT_ELC_SOFTWARE_EVENT_1) && !defined(DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1)
SSP_VECTOR_DEFINE(elc_software_event_isr, ELC, SOFTWARE_EVENT_1);
#define DTC_VECTOR_DEFINED_SOFTWARE_EVENT_1
#endif
#endif
#endif

dtc_instance_ctrl_t g_transfer0_ctrl;
transfer_info_t g_transfer0_info =
{ .dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .irq = TRANSFER_IRQ_END,
  .chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .size = TRANSFER_SIZE_1_BYTE,
  .mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = 0,
  .length = 0, };
const transfer_cfg_t g_transfer0_cfg =
{ .p_info = &g_transfer0_info,
  .activation_source = ELC_EVENT_SCI0_TXI,
  .auto_enable = false,
  .p_callback = NULL,
  .p_context = &g_transfer0,
  .irq_ipl = (BSP_IRQ_DISABLED) };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 =
{ .p_ctrl = &g_transfer0_ctrl, .p_cfg = &g_transfer0_cfg, .p_api = &g_transfer_on_dtc };
#if SCI_UART_CFG_RX_ENABLE
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_uart_rxi_isr, SCI, RXI, 0);
#endif
#endif
#endif
#if SCI_UART_CFG_TX_ENABLE
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_uart_txi_isr, SCI, TXI, 0);
#endif
#endif
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_uart_tei_isr, SCI, TEI, 0);
#endif
#endif
#endif
#if SCI_UART_CFG_RX_ENABLE
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_uart_eri_isr, SCI, ERI, 0);
#endif
#endif
#endif
sci_uart_instance_ctrl_t g_uart0_ctrl;

/** UART extended configuration for UARTonSCI HAL driver */
const uart_on_sci_cfg_t g_uart0_cfg_extend =
{ .clk_src = SCI_CLK_SRC_INT, .baudclk_out = false, .rx_edge_start = true, .noisecancel_en = false, .p_extpin_ctrl =
          NULL,
  .bitrate_modulation = true, .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_MAX, .baud_rate_error_x_1000 = (uint32_t) (
          2.0 * 1000),
  .uart_comm_mode = UART_MODE_RS232, .uart_rs485_mode = UART_RS485_HD, .rs485_de_pin = IOPORT_PORT_09_PIN_14, };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg =
{ .channel = 0, .baud_rate = 115200, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits =
          UART_STOP_BITS_1,
  .ctsrts_en = true, .p_callback = user_uart_callback, .p_context = &g_uart0, .p_extend = &g_uart0_cfg_extend,
#define SYNERGY_NOT_DEFINED (1)                        
#if (SYNERGY_NOT_DEFINED == g_transfer0)
                .p_transfer_tx       = NULL,
#else
  .p_transfer_tx = &g_transfer0,
#endif            
#if (SYNERGY_NOT_DEFINED == g_transfer1)
                .p_transfer_rx       = NULL,
#else
  .p_transfer_rx = &g_transfer1,
#endif   
#undef SYNERGY_NOT_DEFINED            
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (BSP_IRQ_DISABLED), };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{ .p_ctrl = &g_uart0_ctrl, .p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_sci };
dac_instance_ctrl_t g_dac1_ctrl;
const dac_extended_cfg_t g_dac1_ex_ctrl =
{ .enable_charge_pump = false, };
const dac_cfg_t g_dac1_cfg =
{ .channel = 1, .ad_da_synchronized = false, .data_format = DAC_DATA_FORMAT_FLUSH_RIGHT, .output_amplifier_enabled =
          false,
  .p_extend = &g_dac1_ex_ctrl };
/* Instance structure to use this module. */
const dac_instance_t g_dac1 =
{ .p_ctrl = &g_dac1_ctrl, .p_cfg = &g_dac1_cfg, .p_api = &g_dac_on_dac };
dac_instance_ctrl_t g_dac0_ctrl;
const dac_extended_cfg_t g_dac0_ex_ctrl =
{ .enable_charge_pump = false, };
const dac_cfg_t g_dac0_cfg =
{ .channel = 0, .ad_da_synchronized = false, .data_format = DAC_DATA_FORMAT_FLUSH_RIGHT, .output_amplifier_enabled =
          false,
  .p_extend = &g_dac0_ex_ctrl };
/* Instance structure to use this module. */
const dac_instance_t g_dac0 =
{ .p_ctrl = &g_dac0_ctrl, .p_cfg = &g_dac0_cfg, .p_api = &g_dac_on_dac };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc1) && !defined(SSP_SUPPRESS_ISR_ADC1)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_isr, ADC, SCAN_END, 1);
#endif
#endif
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc1) && !defined(SSP_SUPPRESS_ISR_ADC1)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_b_isr, ADC, SCAN_END_B, 1);
#endif
#endif
adc_instance_ctrl_t g_adc1_ctrl;
const adc_cfg_t g_adc1_cfg =
{ .unit = 1,
  .mode = ADC_MODE_SINGLE_SCAN,
  .resolution = ADC_RESOLUTION_12_BIT,
  .alignment = ADC_ALIGNMENT_RIGHT,
  .add_average_count = ADC_ADD_OFF,
  .clearing = ADC_CLEAR_AFTER_READ_ON,
  .trigger = ADC_TRIGGER_SOFTWARE,
  .trigger_group_b = ADC_TRIGGER_SYNC_ELC,
  .p_callback = NULL,
  .p_context = &g_adc1,
  .scan_end_ipl = (BSP_IRQ_DISABLED),
  .scan_end_b_ipl = (BSP_IRQ_DISABLED),
  .calib_adc_skip = false,
  .voltage_ref = ADC_EXTERNAL_VOLTAGE,
  .over_current = OVER_CURRENT_DETECTION_ENABLE,
  .pga0 = PGA_DISABLE,
  .pga1 = PGA_DISABLE,
  .pga2 = PGA_DISABLE, };
const adc_channel_cfg_t g_adc1_channel_cfg =
{ .scan_mask = (uint32_t) (
        ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) ADC_MASK_CHANNEL_2) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | (0)),
  /** Group B channel mask is right shifted by 32 at the end to form the proper mask */
  .scan_mask_group_b = (uint32_t) (
          (((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) ADC_MASK_CHANNEL_2) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | (0)) >> 32),
  .priority_group_a = ADC_GROUP_A_PRIORITY_OFF, .add_mask = (uint32_t) (
          (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)
                  | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)),
  .sample_hold_mask = (uint32_t) ((0) | (0) | (0)), .sample_hold_states = 24, };
/* Instance structure to use this module. */
const adc_instance_t g_adc1 =
{ .p_ctrl = &g_adc1_ctrl, .p_cfg = &g_adc1_cfg, .p_channel_cfg = &g_adc1_channel_cfg, .p_api = &g_adc_on_adc };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc0) && !defined(SSP_SUPPRESS_ISR_ADC0)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_isr, ADC, SCAN_END, 0);
#endif
#endif
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_adc0) && !defined(SSP_SUPPRESS_ISR_ADC0)
SSP_VECTOR_DEFINE_CHAN(adc_scan_end_b_isr, ADC, SCAN_END_B, 0);
#endif
#endif
adc_instance_ctrl_t g_adc0_ctrl;
const adc_cfg_t g_adc0_cfg =
{ .unit = 0,
  .mode = ADC_MODE_SINGLE_SCAN,
  .resolution = ADC_RESOLUTION_12_BIT,
  .alignment = ADC_ALIGNMENT_RIGHT,
  .add_average_count = ADC_ADD_OFF,
  .clearing = ADC_CLEAR_AFTER_READ_ON,
  .trigger = ADC_TRIGGER_SOFTWARE,
  .trigger_group_b = ADC_TRIGGER_SYNC_ELC,
  .p_callback = NULL,
  .p_context = &g_adc0,
  .scan_end_ipl = (BSP_IRQ_DISABLED),
  .scan_end_b_ipl = (BSP_IRQ_DISABLED),
  .calib_adc_skip = false,
  .voltage_ref = ADC_EXTERNAL_VOLTAGE,
  .over_current = OVER_CURRENT_DETECTION_ENABLE,
  .pga0 = PGA_DISABLE,
  .pga1 = PGA_DISABLE,
  .pga2 = PGA_DISABLE, };
const adc_channel_cfg_t g_adc0_channel_cfg =
{ .scan_mask = (uint32_t) (
        ((uint64_t) ADC_MASK_CHANNEL_0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                | (0)),
  /** Group B channel mask is right shifted by 32 at the end to form the proper mask */
  .scan_mask_group_b = (uint32_t) (
          (((uint64_t) ADC_MASK_CHANNEL_0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0) | ((uint64_t) 0)
                  | (0)) >> 32),
  .priority_group_a = ADC_GROUP_A_PRIORITY_OFF, .add_mask = (uint32_t) (
          (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)
                  | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)),
  .sample_hold_mask = (uint32_t) ((0) | (0) | (0)), .sample_hold_states = 24, };
/* Instance structure to use this module. */
const adc_instance_t g_adc0 =
{ .p_ctrl = &g_adc0_ctrl, .p_cfg = &g_adc0_cfg, .p_channel_cfg = &g_adc0_channel_cfg, .p_api = &g_adc_on_adc };
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer3) && !defined(SSP_SUPPRESS_ISR_GPT3)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 3);
#endif
#endif
static gpt_instance_ctrl_t g_timer3_ctrl;
static const timer_on_gpt_cfg_t g_timer3_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_RETAINED },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer3_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 100, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 3, .autostart = true, .p_callback = user_timer3_comms_timeout_callback, .p_context = &g_timer3, .p_extend =
          &g_timer3_extend,
  .irq_ipl = (12), };
/* Instance structure to use this module. */
const timer_instance_t g_timer3 =
{ .p_ctrl = &g_timer3_ctrl, .p_cfg = &g_timer3_cfg, .p_api = &g_timer_on_gpt };
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer2) && !defined(SSP_SUPPRESS_ISR_GPT2)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 2);
#endif
#endif
static gpt_instance_ctrl_t g_timer2_ctrl;
static const timer_on_gpt_cfg_t g_timer2_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_RETAINED },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer2_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 10, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 2, .autostart = true, .p_callback = user_timer2_sensor_poll_callback, .p_context = &g_timer2, .p_extend =
          &g_timer2_extend,
  .irq_ipl = (12), };
/* Instance structure to use this module. */
const timer_instance_t g_timer2 =
{ .p_ctrl = &g_timer2_ctrl, .p_cfg = &g_timer2_cfg, .p_api = &g_timer_on_gpt };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer1) && !defined(SSP_SUPPRESS_ISR_GPT1)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 1);
#endif
#endif
static gpt_instance_ctrl_t g_timer1_ctrl;
static const timer_on_gpt_cfg_t g_timer1_extend =
{ .gtioca =
{ .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_RETAINED },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer1_cfg =
{ .mode = TIMER_MODE_PERIODIC, .period = 1, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 1, .autostart = true, .p_callback = NULL, .p_context = &g_timer1, .p_extend = &g_timer1_extend, .irq_ipl =
          (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_timer1 =
{ .p_ctrl = &g_timer1_ctrl, .p_cfg = &g_timer1_cfg, .p_api = &g_timer_on_gpt };
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer0) && !defined(SSP_SUPPRESS_ISR_GPT0)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 0);
#endif
#endif
static gpt_instance_ctrl_t g_timer0_ctrl;
static const timer_on_gpt_cfg_t g_timer0_extend =
{ .gtioca =
{ .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
  .gtiocb =
  { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_RETAINED },
  .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF, };
static const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PWM, .period = 10, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50, .duty_cycle_unit =
          TIMER_PWM_UNIT_RAW_COUNTS,
  .channel = 0, .autostart = true, .p_callback = NULL, .p_context = &g_timer0, .p_extend = &g_timer0_extend, .irq_ipl =
          (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_gpt };
void g_hal_init(void)
{
    g_common_init ();
}
