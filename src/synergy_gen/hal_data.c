/* generated HAL source file - do not edit */
#include "hal_data.h"
can_bit_timing_cfg_t g_can0_bit_timing_cfg =
{
    .baud_rate_prescaler = 5,
    .time_segment_1 = CAN_TIME_SEGMENT1_TQ15,
    .time_segment_2 = CAN_TIME_SEGMENT2_TQ4,
    .synchronization_jump_width = CAN_SYNC_JUMP_WIDTH_TQ1,
};      

uint32_t g_can0_mailbox_mask[CAN_NO_OF_MAILBOXES_g_can0/4] =
{
0x1FFFFFFF,
#if CAN_NO_OF_MAILBOXES_g_can0 > 4
0x1FFFFFFF,
#endif
#if CAN_NO_OF_MAILBOXES_g_can0 > 8
0x1FFFFFFF,
0x1FFFFFFF,
#endif
#if CAN_NO_OF_MAILBOXES_g_can0 > 16
0x1FFFFFFF,
0x1FFFFFFF,
0x1FFFFFFF,
0x1FFFFFFF,
#endif
};

static const can_extended_cfg_t g_can0_extended_cfg =
{
   .clock_source            = CAN_CLOCK_SOURCE_CANMCLK,
   .p_mailbox_mask           = g_can0_mailbox_mask,
};

can_mailbox_t g_can0_mailbox[CAN_NO_OF_MAILBOXES_g_can0] =
{
    {
        .mailbox_id              =  0,
        .mailbox_type            =  CAN_MAILBOX_TRANSMIT,
        .frame_type              =  CAN_FRAME_TYPE_REMOTE
	},
    {
        .mailbox_id              =  1,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_REMOTE
    },
    {
        .mailbox_id              =  2,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_REMOTE,
    },
    {
        .mailbox_id              =  3,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_REMOTE
    },
#if CAN_NO_OF_MAILBOXES_g_can0 > 4
    {
        .mailbox_id              =  4,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  5,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  6,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  7,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
#endif
#if CAN_NO_OF_MAILBOXES_g_can0 > 8
    {
        .mailbox_id              =  8,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  9,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  10,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  11,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  12,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA,
    },
    {
        .mailbox_id              =  13,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  14,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  15,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
#endif  
#if CAN_NO_OF_MAILBOXES_g_can0 > 16
    {
        .mailbox_id              =  16,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    
    {
        .mailbox_id              =  17,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  18,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  19,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  20,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  21,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  22,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA,
    },
    {
        .mailbox_id              =  23,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  24,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  25,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  26,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  27,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  28,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  29,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  30,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    },
    {
        .mailbox_id              =  31,
        .mailbox_type            =  CAN_MAILBOX_RECEIVE,
        .frame_type              =  CAN_FRAME_TYPE_DATA
    }
#endif  
};

#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_can0) && !defined(SSP_SUPPRESS_ISR_CAN1)
SSP_VECTOR_DEFINE_CHAN(can_error_isr, CAN, ERROR, 1);
#endif
#endif
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_can0) && !defined(SSP_SUPPRESS_ISR_CAN1)
SSP_VECTOR_DEFINE_CHAN(can_mailbox_rx_isr, CAN, MAILBOX_RX, 1);
#endif
#endif
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_can0) && !defined(SSP_SUPPRESS_ISR_CAN1)
SSP_VECTOR_DEFINE_CHAN(can_mailbox_tx_isr, CAN, MAILBOX_TX, 1);
#endif
#endif

static can_instance_ctrl_t g_can0_ctrl;
static const can_cfg_t g_can0_cfg =
{
    .channel                = 1,
    .p_bit_timing           = &g_can0_bit_timing_cfg,
    .id_mode                = CAN_ID_MODE_STANDARD,
    .mailbox_count          = CAN_NO_OF_MAILBOXES_g_can0,
    .p_mailbox              = g_can0_mailbox,    
    .message_mode           = CAN_MESSAGE_MODE_OVERWRITE ,
    .p_callback             = user_can_callback,
    .p_extend               = &g_can0_extended_cfg,
    .p_context              = &g_can0,
    .error_ipl              = (12),
    .mailbox_tx_ipl         = (12),
    .mailbox_rx_ipl         = (12),
};
/* Instance structure to use this module. */
const can_instance_t g_can0 = 
{
    .p_ctrl        = &g_can0_ctrl,
    .p_cfg         = &g_can0_cfg,
    .p_api         = &g_can_on_can
};
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_spi_rxi_isr, SCI, RXI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_spi_txi_isr, SCI, TXI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_spi_tei_isr, SCI, TEI, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_spi0) && !defined(SSP_SUPPRESS_ISR_SCI0)
SSP_VECTOR_DEFINE_CHAN(sci_spi_eri_isr, SCI, ERI, 0);
#endif
sci_spi_instance_ctrl_t g_spi0_ctrl;

/** SPI extended configuration */
const sci_spi_extended_cfg g_spi0_cfg_extend =
{
    .bitrate_modulation  = true
};

const spi_cfg_t g_spi0_cfg =
{
    .channel             = 0,
    .operating_mode      = SPI_MODE_MASTER,
    .clk_phase           = SPI_CLK_PHASE_EDGE_EVEN,
    .clk_polarity        = SPI_CLK_POLARITY_LOW,
    .mode_fault          = SPI_MODE_FAULT_ERROR_DISABLE,
    .bit_order           = SPI_BIT_ORDER_MSB_FIRST,
    .bitrate             = 30000000,
#define SYNERGY_NOT_DEFINED (1)             
#if (SYNERGY_NOT_DEFINED == SYNERGY_NOT_DEFINED)
                .p_transfer_tx       = NULL,
#else
                .p_transfer_tx       = &SYNERGY_NOT_DEFINED,
#endif
#if (SYNERGY_NOT_DEFINED == SYNERGY_NOT_DEFINED)
                .p_transfer_rx       = NULL,
#else
                .p_transfer_rx       = &SYNERGY_NOT_DEFINED,
#endif
#undef SYNERGY_NOT_DEFINED	
	.p_callback          = NULL,
	.p_context           = (void *)&g_spi0,
    .rxi_ipl             = (12),
    .txi_ipl             = (12),
    .tei_ipl             = (12),
    .eri_ipl             = (12),
	.p_extend            = &g_spi0_cfg_extend,	
};
/* Instance structure to use this module. */
const spi_instance_t g_spi0 = 
{
    .p_ctrl        = &g_spi0_ctrl,
    .p_cfg         = &g_spi0_cfg,
    .p_api         = &g_spi_on_sci
};
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer1) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_SCI3_RXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_SCI3_RXI
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
{
    .dest_addr_mode      = TRANSFER_ADDR_MODE_INCREMENTED,
    .repeat_area         = TRANSFER_REPEAT_AREA_DESTINATION,
    .irq                 = TRANSFER_IRQ_END,
    .chain_mode          = TRANSFER_CHAIN_MODE_DISABLED,
    .src_addr_mode       = TRANSFER_ADDR_MODE_FIXED,
    .size                = TRANSFER_SIZE_1_BYTE,
    .mode                = TRANSFER_MODE_NORMAL,
    .p_dest              = (void *) NULL,
    .p_src               = (void const *) NULL,
    .num_blocks          = 0,
    .length              = 0,
};
const transfer_cfg_t g_transfer1_cfg =
{
    .p_info              = &g_transfer1_info,
    .activation_source   = ELC_EVENT_SCI3_RXI,
    .auto_enable         = false,
    .p_callback          = NULL,
    .p_context           = &g_transfer1,
    .irq_ipl             = (BSP_IRQ_DISABLED)
};
/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 = 
{
    .p_ctrl        = &g_transfer1_ctrl,
    .p_cfg         = &g_transfer1_cfg,
    .p_api         = &g_transfer_on_dtc
};
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_transfer0) && !defined(SSP_SUPPRESS_ISR_DTCELC_EVENT_SCI3_TXI)
#define DTC_ACTIVATION_SRC_ELC_EVENT_SCI3_TXI
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
{
    .dest_addr_mode      = TRANSFER_ADDR_MODE_FIXED,
    .repeat_area         = TRANSFER_REPEAT_AREA_SOURCE,
    .irq                 = TRANSFER_IRQ_END,
    .chain_mode          = TRANSFER_CHAIN_MODE_DISABLED,
    .src_addr_mode       = TRANSFER_ADDR_MODE_INCREMENTED,
    .size                = TRANSFER_SIZE_1_BYTE,
    .mode                = TRANSFER_MODE_NORMAL,
    .p_dest              = (void *) NULL,
    .p_src               = (void const *) NULL,
    .num_blocks          = 0,
    .length              = 0,
};
const transfer_cfg_t g_transfer0_cfg =
{
    .p_info              = &g_transfer0_info,
    .activation_source   = ELC_EVENT_SCI3_TXI,
    .auto_enable         = false,
    .p_callback          = NULL,
    .p_context           = &g_transfer0,
    .irq_ipl             = (BSP_IRQ_DISABLED)
};
/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 = 
{
    .p_ctrl        = &g_transfer0_ctrl,
    .p_cfg         = &g_transfer0_cfg,
    .p_api         = &g_transfer_on_dtc
};
#if SCI_UART_CFG_RX_ENABLE
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_rxi_isr, SCI, RXI, 3);
#endif
#endif
#endif
#if SCI_UART_CFG_TX_ENABLE
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_txi_isr, SCI, TXI, 3);
#endif
#endif
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_tei_isr, SCI, TEI, 3);
#endif
#endif
#endif
#if SCI_UART_CFG_RX_ENABLE
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_uart0) && !defined(SSP_SUPPRESS_ISR_SCI3)
SSP_VECTOR_DEFINE_CHAN(sci_uart_eri_isr, SCI, ERI, 3);
#endif
#endif
#endif
            sci_uart_instance_ctrl_t     g_uart0_ctrl;

            /** UART extended configuration for UARTonSCI HAL driver */
            const uart_on_sci_cfg_t g_uart0_cfg_extend =
            {
                .clk_src                 = SCI_CLK_SRC_INT,
                .baudclk_out             = false,
                .rx_edge_start           = true,
                .noisecancel_en          = false,
                .p_extpin_ctrl           = NULL,
                .bitrate_modulation      = true,
                .rx_fifo_trigger         = SCI_UART_RX_FIFO_TRIGGER_MAX,
                .baud_rate_error_x_1000  = (uint32_t)(2.0*1000),
		 .uart_comm_mode          = UART_MODE_RS232,		 
		 .uart_rs485_mode         = UART_RS485_HD,
		 .rs485_de_pin            = IOPORT_PORT_09_PIN_14,
            };

            /** UART interface configuration */
            const uart_cfg_t g_uart0_cfg =
            {
                .channel             = 3,
                .baud_rate           = 115200,
                .data_bits           = UART_DATA_BITS_8,
                .parity              = UART_PARITY_OFF,
                .stop_bits           = UART_STOP_BITS_1,
                .ctsrts_en           = true,
                .p_callback          = user_uart_callback,
                .p_context           = &g_uart0,
                .p_extend            = &g_uart0_cfg_extend,
#define SYNERGY_NOT_DEFINED (1)                        
#if (SYNERGY_NOT_DEFINED == g_transfer0)
                .p_transfer_tx       = NULL,
#else
                .p_transfer_tx       = &g_transfer0,
#endif            
#if (SYNERGY_NOT_DEFINED == g_transfer1)
                .p_transfer_rx       = NULL,
#else
                .p_transfer_rx       = &g_transfer1,
#endif   
#undef SYNERGY_NOT_DEFINED            
                .rxi_ipl             = (12),
                .txi_ipl             = (12),
                .tei_ipl             = (12),
                .eri_ipl             = (BSP_IRQ_DISABLED),
            };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 = 
{
    .p_ctrl        = &g_uart0_ctrl,
    .p_cfg         = &g_uart0_cfg,
    .p_api         = &g_uart_on_sci
};
dac_instance_ctrl_t g_dac1_ctrl;
const dac_extended_cfg_t g_dac1_ex_ctrl = 
{
    .enable_charge_pump   = false,
};
const dac_cfg_t g_dac1_cfg =
{
    .channel             = 0,
    .ad_da_synchronized  = false,
    .data_format         = DAC_DATA_FORMAT_FLUSH_RIGHT,
    .output_amplifier_enabled = false,
    .p_extend            = &g_dac1_ex_ctrl
};
/* Instance structure to use this module. */
const dac_instance_t g_dac1 = 
{
    .p_ctrl        = &g_dac1_ctrl,
    .p_cfg         = &g_dac1_cfg,
    .p_api         = &g_dac_on_dac
};
dac_instance_ctrl_t g_dac0_ctrl;
const dac_extended_cfg_t g_dac0_ex_ctrl = 
{
    .enable_charge_pump   = false,
};
const dac_cfg_t g_dac0_cfg =
{
    .channel             = 0,
    .ad_da_synchronized  = false,
    .data_format         = DAC_DATA_FORMAT_FLUSH_RIGHT,
    .output_amplifier_enabled = false,
    .p_extend            = &g_dac0_ex_ctrl
};
/* Instance structure to use this module. */
const dac_instance_t g_dac0 = 
{
    .p_ctrl        = &g_dac0_ctrl,
    .p_cfg         = &g_dac0_cfg,
    .p_api         = &g_dac_on_dac
};
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
{
    .unit                = 0,
    .mode                = ADC_MODE_SINGLE_SCAN,
    .resolution          = ADC_RESOLUTION_12_BIT,
    .alignment           = ADC_ALIGNMENT_RIGHT,
    .add_average_count   = ADC_ADD_OFF,
    .clearing            = ADC_CLEAR_AFTER_READ_ON,
    .trigger             = ADC_TRIGGER_SOFTWARE,
    .trigger_group_b     = ADC_TRIGGER_SYNC_ELC,
    .p_callback          = NULL,
    .p_context           = &g_adc0,
    .scan_end_ipl        = (BSP_IRQ_DISABLED),
    .scan_end_b_ipl      = (BSP_IRQ_DISABLED),
    .calib_adc_skip      = false,
    .voltage_ref         = ADC_EXTERNAL_VOLTAGE, 
    .over_current        = OVER_CURRENT_DETECTION_ENABLE,   
    .pga0                = PGA_DISABLE,
    .pga1                = PGA_DISABLE,
    .pga2                = PGA_DISABLE,
};
const adc_channel_cfg_t g_adc0_channel_cfg =
{
    .scan_mask           = (uint32_t)(((uint64_t)ADC_MASK_CHANNEL_0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)ADC_MASK_CHANNEL_6) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | (0)),
	/** Group B channel mask is right shifted by 32 at the end to form the proper mask */
	.scan_mask_group_b   = (uint32_t)((((uint64_t)ADC_MASK_CHANNEL_0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)ADC_MASK_CHANNEL_6) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | ((uint64_t)0) | (0)) >> 32),
	.priority_group_a    = ADC_GROUP_A_PRIORITY_OFF,
	.add_mask            = (uint32_t)((0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)| (0) | (0)| (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0) | (0)),
	.sample_hold_mask    = (uint32_t)((0) | (0) | (0)),
	.sample_hold_states  = 24,
};
/* Instance structure to use this module. */
const adc_instance_t g_adc0 = 
{
	.p_ctrl 	   = &g_adc0_ctrl,
	.p_cfg  	   = &g_adc0_cfg,
	.p_channel_cfg = &g_adc0_channel_cfg,
	.p_api  	   = &g_adc_on_adc
};
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer1) && !defined(SSP_SUPPRESS_ISR_GPT1)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 1);
#endif
#endif
static gpt_instance_ctrl_t g_timer1_ctrl;
static const timer_on_gpt_cfg_t g_timer1_extend =
{
    .gtioca = { .output_enabled = false,
                .stop_level     = GPT_PIN_LEVEL_LOW
              },
    .gtiocb = { .output_enabled = false,
                .stop_level     = GPT_PIN_LEVEL_RETAINED
              },
    .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF,
};
static const timer_cfg_t g_timer1_cfg =
{
    .mode                = TIMER_MODE_PERIODIC,
    .period              = 1,
    .unit                = TIMER_UNIT_PERIOD_MSEC,
    .duty_cycle          = 50,
    .duty_cycle_unit     = TIMER_PWM_UNIT_RAW_COUNTS,
    .channel             = 1,
    .autostart           = true,
    .p_callback          = NULL,
    .p_context           = &g_timer1,
    .p_extend            = &g_timer1_extend,
    .irq_ipl             = (BSP_IRQ_DISABLED),
};
/* Instance structure to use this module. */
const timer_instance_t g_timer1 = 
{
    .p_ctrl        = &g_timer1_ctrl,
    .p_cfg         = &g_timer1_cfg,
    .p_api         = &g_timer_on_gpt
};
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer0) && !defined(SSP_SUPPRESS_ISR_GPT0)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 0);
#endif
#endif
static gpt_instance_ctrl_t g_timer0_ctrl;
static const timer_on_gpt_cfg_t g_timer0_extend =
{
    .gtioca = { .output_enabled = true,
                .stop_level     = GPT_PIN_LEVEL_LOW
              },
    .gtiocb = { .output_enabled = false,
                .stop_level     = GPT_PIN_LEVEL_RETAINED
              },
    .shortest_pwm_signal = GPT_SHORTEST_LEVEL_OFF,
};
static const timer_cfg_t g_timer0_cfg =
{
    .mode                = TIMER_MODE_PWM,
    .period              = 10,
    .unit                = TIMER_UNIT_PERIOD_MSEC,
    .duty_cycle          = 50,
    .duty_cycle_unit     = TIMER_PWM_UNIT_RAW_COUNTS,
    .channel             = 0,
    .autostart           = true,
    .p_callback          = NULL,
    .p_context           = &g_timer0,
    .p_extend            = &g_timer0_extend,
    .irq_ipl             = (BSP_IRQ_DISABLED),
};
/* Instance structure to use this module. */
const timer_instance_t g_timer0 = 
{
    .p_ctrl        = &g_timer0_ctrl,
    .p_cfg         = &g_timer0_cfg,
    .p_api         = &g_timer_on_gpt
};
void g_hal_init(void) {
g_common_init();
}
