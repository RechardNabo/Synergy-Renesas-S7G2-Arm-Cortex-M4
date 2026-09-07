# S7G2 Dev Board — Implementable Feature Names

Concise reference of the 10 suggested learning features for the Renesas SA-BEST 2017 S7G2 Target Board. Full details (hardware resources, SSP drivers, APIs, difficulty) are in `README.md` Section 8.

| # | Feature Name | Category |
|---|--------------|----------|
| 1 | LED Blinker | GPIO Output |
| 2 | USB Device CDC Console | USB |
| 3 | Switch Input + Debounce | GPIO Input / IRQ |
| 4 | ADC Sampling | Analog Input |
| 5 | DAC Waveform Generation | Analog Output |
| 6 | PWM Controller | Timer / PWM |
| 7 | PMOD UART Console | Serial Communication |
| 8 | PMOD SPI Master | Serial Communication |
| 9 | PMOD I2C Master | Serial Communication |
| 10 | Graphics LCD Display | Display / GUI |

## Status

| # | Feature Name | SSP Driver Ready | Status |
|---|--------------|------------------|--------|
| 1 | LED Blinker | Yes (`g_ioport`) | Implemented |
| 2 | USB Device CDC Console | No — add `r_usb_basic` via SSP GUI | Not started |
| 3 | Switch Input + Debounce | Yes (`g_ioport`, `g_elc`) | Not started |
| 4 | ADC Sampling | Yes (`g_adc0`) | Not started |
| 5 | DAC Waveform Generation | Yes (`g_dac0`, `g_dac1`) | Not started |
| 6 | PWM Controller | Yes (`g_timer0`) | Not started |
| 7 | PMOD UART Console | Yes (`g_uart0`, `g_transfer0/1`) | Not started |
| 8 | PMOD SPI Master | Yes (`g_spi0`) | Not started |
| 9 | PMOD I2C Master | No — add `r_iic` via SSP GUI | Not started |
| 10 | Graphics LCD Display | No — add `r_glcd` + `r_drw` via SSP GUI | Not started |

## Additional Features (Beyond Top 10)

| Feature Name | Hardware | SSP Driver | Notes |
|--------------|----------|------------|-------|
| CAN Communication | P511 (CRX), P512 (CTX) | r_can (`g_can0`) | 2 CAN channels on-die; ch1 broken out |
| Ethernet TCP/IP | J5 (RMII0) | r_ether *(add via SSP GUI)* | Single MAC (ETHERC0), IEEE 1588 PTP |
| QSPI Flash | U7 footprint (not fitted) | r_qspi | Hardware not populated by default |
| Temperature Sensor | Via ADC (external sensor) | r_adc | Requires external sensor on Arduino/PMOD |
| Relay Controller | Via GPIO on Arduino header | r_ioport | Requires external relay module |
| ThreadX RTOS Demo | On-chip | ThreadX (bundled) | Multi-threaded demo of above features |
