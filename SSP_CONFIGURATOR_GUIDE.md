# SSP Configurator Guide — S7G2 Maximum Performance

> ## ⚠️ CORRECTIONS APPLIED (verified against README + Renesas SSP pack data)
>
> The original version of this guide contained several pin-mapping errors that have been corrected in `configuration.xml` and `R7FS7G27H3A01CFC.pincfg`. The corrections below supersede any conflicting statements in the rest of this document.
>
> | Item | Old (wrong) | Corrected | Reason |
> |------|-------------|-----------|--------|
> | **PMOD SPI driver** | r_sci_spi on SCI0 | **r_rspi on SPI0** (P100-P103) | SCI0 is needed for PMOD UART; P100-P103 support native SPI0 (MISO/MOSI/RSPCK/SSL0) |
> | **PMOD UART channel** | SCI3 on P408-P411 | **SCI0 group B** on P410-P413 | README §5.5 shows J16 wired to P410(RXD)/P411(TXD)/P412(DTS)/P413(CTS); P410-P413 only have SCI0 capability, not SCI3 |
> | **P408 / P409 function** | SCI3 RXD/TXD | **GPIO inputs (IRQ7 / IRQ6)** | README shows P408=IRQ7 (PMOD UART interrupt), P409=IRQ6 (PMOD SPI interrupt) — not part of UART signal path |
> | **PMOD IIC GPIO** | P202, P203, P204 | **P203, P204 only** | README §5.5 J18 table lists only P203 (GPIO1) and P204 (GPIO2); P202 is NOT part of J18 |
> | **GLCD pins** | P110, P211-P226 | **P111-P115 only** | Pack data confirms P110/P211-P226 have no GLCDC capability on this MCU package |
> | **Ethernet** | "RMII1 available" | **Only RMII0 exists** | S7G2 has one Ethernet MAC (ETHERC0); J5 must use RMII0 |
> | **Timers** | 2 (g_timer0 PWM, g_timer1 1ms) | **4 timers** | Added g_timer2 (10ms sensor poll, IRQ priority 12) and g_timer3 (100ms comms timeout, IRQ priority 12) for firmware operations |
>
> **Current module count: 21 modules, 21 stack references.**
> **Current pin count: 36 symbolic names, all 36 configured (zero missing).**

**Target device:** R7FS7G27H3A01CFC (176-pin LQFP, 4MB flash, 640KB SRAM, Arm Cortex-M4F)
**Board:** Renesas SA-BEST 2017 Target Board (Synergy S7G2)
**SSP version:** 2.7.0 (installed) — projects originally built with 2.4.0
**MCU max frequency:** 240 MHz
**Crystals:** X2 = 12 MHz (main), X1 = 32.768 kHz (sub-clock)
**Toolchain:** gcc-arm-embedded
**RTOS:** Express Logic ThreadX (included with SSP)

---

## Board Hardware — Complete Feature Inventory

### On-Board ICs

| Ref | Part | Function | SSP Driver |
|-----|------|----------|------------|
| U1 | R7FS7G27H3A01CFC | Main MCU (S7G2, 176-pin LQFP) | — |
| U2 | MAX0307-type | USB Host current-limited power switch | r_ioport (GPIO control) |
| U3 | MP5043-based | +3.3V LDO regulator | No driver — hardware only |
| U4 | — | +5V LDO regulator | No driver — hardware only |
| U6 | MPD8003-13 | +3.3VANL analog rail LDO | No driver — hardware only |
| U7 | QSPI flash footprint | Quad SPI NOR flash (not fitted by default) | r_qspi |
| U8 | R5F5192H6DFP | On-board J-Link debug probe (Renesas RX MCU) | No driver — debugger |
| U9 | MP5043-based | +3.3V_JLINK rail LDO | No driver — hardware only |

### On-Board Peripherals

| Feature | Hardware | MCU Pin(s) | SSP Driver |
|---------|----------|------------|------------|
| User LED1 (Red) | LED1 via R1 | P305 (active low) | r_ioport GPIO output |
| User LED2 (Green) | LED2 via R2 | P801 (active high) | r_ioport GPIO output |
| User LED3 (Yellow) | LED3 via R3 | P802 (active low) | r_ioport GPIO output |
| Vibration sensor | Sensolute MV5049 (SW2) via J10 | AN6 / P006 (IRQ + ADC) | r_adc + r_elc (IRQ) |
| Variable resistor (pot) | Analog potentiometer | AN0 / P000 | r_adc |
| DAC output | Analog output pin | DA0 / P014 | r_dac |
| Reset button | SW1 push button | RESET pin | No driver — hardware |
| Boot select jumper | J1 (1-2 = ROM, 2-3 = USB) | — | No driver — hardware |
| Power LED | LED4 (green) | — | No driver — hardware |
| J-Link status LED | LED2B | — | No driver — hardware |

### On-Board Connectors

| Connector | Type | Function | SSP Driver |
|-----------|------|----------|------------|
| J3 | USB Device (Full-Speed) | USB Device port | r_usb_basic (device) |
| J4 | USB Host (High-Speed) | USB Host port | r_usb_basic (host) |
| J5 | Ethernet PHY connector | RMII to external PHY | r_ether |
| J13 | PMOD SPI | SPI + 3 GPIO + IRQ | r_rspi (SPI0) |
| J15 | Graphics LCD | Direct TFT LCD drive | r_glcd + r_drw |
| J16 | PMOD UART | UART + 3 GPIO + IRQ | r_sci_uart (SCI0 group B) |
| J18 | PMOD IIC | I2C + 2 GPIO | r_iic |
| J19 | USB (J-Link debug) | SWD debug to PC | No driver — debugger |
| J34 | SWD header | External SWD debug | No driver — debugger |
| J6/J7/J8/J9/J11/J12 | Arduino Mega shield | Arduino expansion | r_ioport (various) |

### On-Board Crystals

| Ref | Frequency | Function | SSP Config |
|-----|-----------|----------|------------|
| X1 | 32.768 kHz | Sub-clock (RTC) | Sub-clock source |
| X2 | 12 MHz | Main oscillator | XTAL source for PLL |
| X3 | 12 MHz | J-Link MCU crystal | No driver — debugger |

### On-Board Power Rails

| Rail | Source | No driver needed — hardware only |
|------|--------|----------------------------------|
| +5V | From J19 USB (debug) or J3 USB (device) | |
| +3.3V | U3 (MP5043 LDO) | |
| +3.3VANL | U6 (MPD8003-13 LDO) — analog rail | |
| +3.3V_JLINK | U9 (MP5043 LDO) — debugger rail | |

---

## Clock Configuration (Clocks tab)

The board has a **12 MHz main crystal** (X2) and **32.768 kHz sub-clock** (X1).
For maximum performance, use XTAL → PLL x20 → 240 MHz ICLK.

| Setting | Value | Resulting Frequency |
|---------|-------|---------------------|
| XTAL frequency | **12 MHz** | Main crystal |
| PLL source | **XTAL** | |
| PLL multiplier | **x20.0** (option: board.clock.pll.mul.200) | 12 MHz × 20 = 240 MHz |
| PLL divider | **/1** (option: board.clock.pll.div.1) | |
| System clock source | **PLL** | |
| **ICLK** (CPU core) divider | **/1** | **240 MHz** — maximum |
| **PCLKA** divider | **/2** | 120 MHz |
| **PCLKB** divider | **/4** | 60 MHz |
| **PCLKC** divider | **/4** | 60 MHz |
| **PCLKD** divider | **/2** | 120 MHz |
| **FCLK** (flash interface) divider | **/4** | 60 MHz |
| **BCLK** divider | **/2** | 120 MHz |
| **BCLKOUT** divider | **/2** | 120 MHz (output) |
| **UCLK** (USB) divider | **/5** | 48 MHz |
| **SDCLKOUT** divider | **/1** | 120 MHz |
| HOCO (high-speed on-chip osc) | 20 MHz | Standby (not used — XTAL+PLL active) |
| LOCO (low-speed on-chip osc) | 32.768 kHz | Standby |
| MOCO (mid-speed on-chip osc) | 8 MHz | Standby |
| Sub-clock | 32.768 kHz | Active — for RTC |

### Clock limits on S7G2

| Clock | Max Frequency |
|-------|--------------|
| ICLK (core) | 240 MHz |
| PCLKA | 120 MHz |
| PCLKB | 60 MHz |
| PCLKC | 60 MHz |
| PCLKD | 120 MHz |
| FCLK | 60 MHz |
| BCLK | 120 MHz |
| UCLK (USB) | 48 MHz |
| ADC max freq | 60 MHz |
| SCI SPI max bitrate | 30 MHz |

---

## BSP Settings (BSP tab)

| Setting | Value | Why |
|---------|-------|-----|
| Board | **board.custom** | Custom SA-BEST 2017 board |
| CPU | **S7G2** | |
| Target name | **R7FS7G27H3A01CFC** | 176-pin LQFP, 4MB flash |
| Architecture | **cortex-m4** | Arm Cortex-M4 with FPU |
| RTOS | **Express Logic ThreadX** | ThreadX bundled with SSP |
| SSP version | **2.7.0** | Installed pack version |
| Linker script | **r7fs7g27h3a01cfc.ld** | Default for this part |
| Toolchain | **gcc-arm-embedded** | |
| VCC | **3300 mV** | 3.3V board supply |
| AVCC0 | **3300 mV** | 3.3V analog supply |
| Main stack size | **0x1000** (4 KB) | Increased from default 0x800 for USB + Ethernet + GUI |
| Heap size | **0x4000** (16 KB) | Increased from default 0x1000 for USB + networking + GUI |
| Process stack | **0** | Not used |
| Parameter checking | **Enabled** (BSP-level) | Catches config errors |
| Assert | **None** | Enable for debugging |
| Error log | **None** | Enable for debugging |
| ID mode | **Unlocked** | Development — lock for production |
| ID code | **FFFFFFFF...** | Default (all F = unlocked) |

### BSP OFS0 Register (Watchdog / IWDT)

| Setting | Value | Why |
|---------|-------|-----|
| IWDT start mode | **Disabled** | Not needed during development |
| IWDT timeout | 2048 cycles | (if enabled in production) |
| IWDT divisor | /128 | (if enabled) |
| WDT start mode | **Register start** | Software-controlled — enable in production |
| WDT timeout | 16384 cycles | (if enabled) |
| WDT divisor | /128 | (if enabled) |
| WDT stop control | Stops in debug | |

### BSP OFS1 Register (Voltage Detection)

| Setting | Value | Why |
|---------|-------|-----|
| Voltage detection 0 start | **Disabled** | Enable in production |
| Voltage detection 0 level | 2.80V | (if enabled) |
| HOCO oscillator | **Disabled** | Using XTAL + PLL instead |

### BSP MCU Limits

| Setting | Value |
|---------|-------|
| ADC max frequency | 60 MHz |
| SCI SPI max bitrate | 30 MHz |

---

## Pin Configuration (Pins tab)

### Debug Pins (always configured)

| Pin | Function | Alt Function ID | Board Use |
|-----|----------|----------------|-----------|
| P108 | DEBUG0.TMS / SWDIO | debug0.tms.p108 | J-Link SWD data |
| P109 | DEBUG0.TDO / SWO | debug0.tdo.p109 | J-Link trace output |
| P110 | DEBUG0.TDI | debug0.tdi.p110 | J-Link trace input |
| P300 | DEBUG0.TCK / SWCLK | debug0.tck.p300 | J-Link SWD clock |

### User LEDs

| Pin | Function | Drive Mode | Board Use |
|-----|----------|-----------|-----------|
| P305 | GPIO output | Output, Low (on) | LED1 (Red) — active low |
| P801 | GPIO output | Output, High (on) | LED2 (Green) — active high |
| P802 | GPIO output | Output, Low (on) | LED3 (Yellow) — active low |

### USB Host (J4)

| Pin | Function | Direction | Board Use |
|-----|----------|-----------|-----------|
| Pb00 | GPIO output | Output | USBH_VBUSEN — enable USB Host VBUS power |
| Pb01 | GPIO input | Input | USBHS_VBUS — monitor Host VBUS |
| P415 | GPIO input | Input | FAULT — over-current monitor from U2 |
| USBHS_DM | USB High-Speed D- | — | USB Host data- (fixed pin) |
| USBHS_DP | USB High-Speed D+ | — | USB Host data+ (fixed pin) |

### USB Device (J3)

| Pin | Function | Direction | Board Use |
|-----|----------|-----------|-----------|
| P407 | GPIO input | Input | USB_VBUS — monitor Device VBUS |
| USB_DM | USB Full-Speed D- | — | USB Device data- (fixed pin) |
| USB_DP | USB Full-Speed D+ | — | USB Device data+ (fixed pin) |

### Ethernet (J5)

| Pin | Function | Board Use |
|-----|----------|-----------|
| P400 | ET_RXD0 / REFCLK | RMII RX data 0 / reference clock |
| P401 | ET_RXD1 | RMII RX data 1 |
| P402 | ET_RXER | RMII RX error |
| P403 | ET_TXD0 | RMII TX data 0 |
| P404 | ET_TXD1 | RMII TX data 1 |
| P405 | ET_TXEN | RMII TX enable (also used as GPT1 GTIOCA if not using Ethernet) |
| P406 | ET_MDC | MIIM management clock |
| P407 | ET_MDIO | MIIM management data (also USB VBUS monitor if not using Ethernet) |
| P408 | ET_LINK | PHY link status |
| P409 | ET_MAGIC | PHY magic packet |
| P410 | ET_PHY_INT | PHY interrupt (also UART TX if not using Ethernet) |

Note: P405 is shared between Ethernet TXEN and GPT1 PWM output. If using Ethernet, do NOT use GPT1 GTIOCA on P405. Use a different GPT channel for PWM.

### PMOD UART (J16) — CORRECTED

**Corrected wiring (per README §5.5 + silicon pack data):**

| Pin # | Pin | Function | Board Use |
|-------|-----|----------|-----------|
| 40 | P410 | SCI0.RXD (group B) | UART RX data |
| 41 | P411 | SCI0.TXD (group B) | UART TX data |
| 39 | P412 | SCI0.SCK (group B) | UART SCK / DTS |
| 38 | P413 | SCI0.CTS (group B) | UART CTS |
| 37 | P408 | IRQ7 (GPIO input) | PMOD UART interrupt |
| 43 | P414 | GPIO | PMOD UART GPIO1 |
| 15 | P707 | GPIO | PMOD UART GPIO2 |
| 1 | P400 | GPIO | PMOD UART GPIO3 |

**Driver:** r_sci_uart on **SCI channel 0, pairing group B** (NOT SCI3 — P410-P413 only support SCI0, not SCI3).

### PMOD SPI (J13) — CORRECTED

**Corrected wiring (per README §5.5 + silicon pack data):**

| Pin # | Pin | Function | Board Use |
|-------|-----|----------|-----------|
| 129 | P103 | SPI0.SSL0 | SPI Slave Select |
| 130 | P102 | SPI0.RSPCK | SPI Clock |
| 131 | P100 | SPI0.MISO | SPI Master In / Slave Out |
| 132 | P101 | SPI0.MOSI | SPI Master Out / Slave In |
| 103 | P409 | IRQ6 (GPIO input) | PMOD SPI interrupt |
| 42 | P612 | GPIO | PMOD SPI GPIO1 |
| 104 | P613 | GPIO | PMOD SPI GPIO2 |
| 105 | P614 | GPIO | PMOD SPI GPIO3 |

**Driver:** r_rspi on **SPI channel 0** (NOT r_sci_spi — SCI0 is used by PMOD UART, so the native RSPI peripheral is used instead).

### PMOD IIC (J18)

| Pin # | Pin | Function | Board Use |
|-------|-----|----------|-----------|
| 50 | P206 | IIC1.SDA | I2C Data |
| 51 | P205 | IIC1.SCL | I2C Clock |
| 52 | P203 | GPIO | PMOD IIC GPIO1 |
| 53 | P204 | GPIO | PMOD IIC GPIO2 |

### QSPI Flash (U7 footprint)

| Pin | Function | Board Use |
|-----|----------|-----------|
| P120 | QSPI.SCK | QSPI Clock |
| P121 | QSPI.IO0 | QSPI Data 0 (MOSI) |
| P122 | QSPI.IO1 | QSPI Data 1 (MISO) |
| P123 | QSPI.IO2 | QSPI Data 2 (WP) |
| P124 | QSPI.IO3 | QSPI Data 3 (HOLD) |
| P125 | QSPI.CS | QSPI Chip Select |

### Graphics LCD (J15)

| Pin | Function | Board Use |
|-----|----------|-----------|
| P110 | GLCD_DATA0 | LCD data bit 0 (shared with DEBUG TDI — use SWD not JTAG) |
| P111 | GLCD_DATA1 | LCD data bit 1 |
| P112 | GLCD_DATA2 | LCD data bit 2 |
| P113 | GLCD_DATA3 | LCD data bit 3 |
| P114 | GLCD_DATA4 | LCD data bit 4 |
| P115 | GLCD_DATA5 | LCD data bit 5 |
| P211 | GLCD_DATA6 | LCD data bit 6 |
| P212 | GLCD_DATA7 | LCD data bit 7 |
| P213 | GLCD_DATA8 | LCD data bit 8 |
| P214 | GLCD_DATA9 | LCD data bit 9 |
| P215 | GLCD_DATA10 | LCD data bit 10 |
| P216 | GLCD_DATA11 | LCD data bit 11 |
| P217 | GLCD_DATA12 | LCD data bit 12 |
| P218 | GLCD_DATA13 | LCD data bit 13 |
| P219 | GLCD_DATA14 | LCD data bit 14 |
| P220 | GLCD_DATA15 | LCD data bit 15 |
| P221 | GLCD_HSYNC | LCD horizontal sync |
| P222 | GLCD_VSYNC | LCD vertical sync |
| P223 | GLCD_DE | LCD data enable |
| P224 | GLCD_DOTCLK | LCD pixel clock |
| P226 | GLCD_TCON0 | LCD timing control 0 |

Note: P110 is shared between GLCD_DATA0 and DEBUG0.TDI. If using the LCD, use SWD (2-wire) debug mode instead of JTAG (4-wire) to free P110/P111 for the LCD.

### ADC Channels

| ADC Channel | Pin | Board Use |
|-------------|-----|-----------|
| AN0 | P000 | Variable resistor (potentiometer) |
| AN6 | P006 | Sensolute vibration sensor (via J10 jumper) |
| AN1–AN5, AN7 | P001–P005, P007 | Available on Arduino header |

### DAC Output

| DAC Channel | Pin | Board Use |
|-------------|-----|-----------|
| DA0 | P014 | DAC analog output (board feature) |

### Arduino Mega Header (J6/J7/J8/J9/J11/J12)

Exposes additional GPIO, ADC, SPI, I2C, UART pins. Pin mapping depends on which shield is used. Configure pins as needed per shield.

---

## HAL Driver Stack (Threads tab)

### Always Present (auto-added by SSP)

| Driver | Instance | Purpose | Config |
|--------|----------|---------|--------|
| r_cgc | g_cgc | Clock Generation Circuit — manages PLL, oscillators | Param checking: BSP; Main OSC: crystal; Sub-clock at reset: enabled; Low voltage mode: disabled |
| r_elc | g_elc | Event Link Controller — routes peripheral events without CPU | Checking: system |
| r_fmi | g_fmi | Factory MCU Information — part number, flash size | Param checking: BSP; Part mask: 0xFE00 |
| r_ioport | g_ioport | I/O Port — pin mux, drive strength, pull resistors | Checking: system |

### Add for Board Features

#### Timer / PWM — r_gpt

| Instance | Channel | Mode | Period | Duty | Output Pin | Board Use |
|----------|---------|------|--------|------|------------|-----------|
| g_timer0 | 0 | PWM | 10 ms | 50% | GTIOCA on P405 | PWM output (if NOT using Ethernet) |
| g_timer1 | 1 | Periodic | 1 ms | — | — | General purpose timer tick |
| g_timer2 | 2 | Periodic | 10 ms | — | — (no pin) | Sensor polling callback (IRQ priority 12) |
| g_timer3 | 3 | Periodic | 100 ms | — | — (no pin) | Communication timeout callback (IRQ priority 12) |

Config:
- Shortest PWM signal: disabled
- Auto-start: true
- GTIOCA stop level: low
- GTIOCB output: disabled
- Callback: NULL (or custom for timer events)
- IRQ IPL: (default)

Note: If using Ethernet (J5), P405 is ET_TXEN. Use GPT channel on a different pin for PWM. Available GPT output pins: P405 (GPT1), P411 (GPT4), P412 (GPT5), P413 (GPT6), P414 (GPT7), P415 (GPT8), etc.

#### ADC — r_adc

| Instance | Channel | Mode | Resolution | Pins | Board Use |
|----------|---------|------|-----------|------|-----------|
| g_adc0 | 0 | Single scan | 12-bit | AN0/P000, AN6/P006 | Potentiometer + vibration sensor |

Config:
- Mode: single scan (or continuous for streaming)
- Resolution: 12-bit
- Trigger: software (or ELC for hardware trigger)
- ADC source: PCLKB (60 MHz)
- Callback: custom (for scan complete notification)
- IRQ IPL: (default)

#### DAC — r_dac

| Instance | Channel | Pin | Board Use |
|----------|---------|-----|-----------|
| g_dac0 | 0 | DA0 / P014 | Analog output 0 |
| g_dac1 | 1 | DA1 / P015 | Analog output 1 |

Config:
- Data format: right-justified (12-bit, 0–4095)
- Output amplifier: enabled (if available)
- Auto-start: true

#### UART — r_sci_uart (PMOD UART J16)

| Instance | Channel | Baud | Data | Pins | Board Use |
|----------|---------|------|------|------|-----------|
| g_uart0 | 3 | 115200 | 8N1 | TX=P409, RX=P408, CTS=P411, SCK=P410 | PMOD UART |

Config:
- Data bits: 8
- Parity: none
- Stop bits: 1
- Flow control: hardware (CTS/RTS) or none
- Callback: custom (for TX/RX complete)
- IRQ IPL: (default)

Note: P410/P411 are shared with Ethernet ET_PHY_INT / ET_TXD. If using Ethernet, use a different SCI channel.

#### SPI — r_sci_spi (PMOD SPI J13)

| Instance | Channel | Mode | Bitrate | Pins | Board Use |
|----------|---------|------|---------|------|-----------|
| g_spi0 | 0 | Master | up to 30 MHz | MOSI=P100, MISO=P101, SCK=P102, SS=P103 | PMOD SPI |

Config:
- Mode: master
- Clock phase: data sampled on leading edge (CPHA=0)
- Clock polarity: active high (CPOL=0)
- Bit order: MSB first
- Bitrate: up to 30 MHz (PCLKA/4 = 30 MHz)
- SS: hardware or software controlled
- Callback: custom (for TX/RX complete)
- IRQ IPL: (default)

#### I2C — r_iic (PMOD IIC J18)

| Instance | Channel | Speed | Pins | Board Use |
|----------|---------|-------|------|-----------|
| g_i2c0 | 2 | 400 kHz (Fast-mode) | SCL=P205, SDA=P206 | PMOD IIC |

Config:
- Mode: master
- Clock rate: 400 kHz (Fast-mode) or 100 kHz (Standard)
- Address format: 7-bit
- Callback: custom (for TX/RX complete)
- IRQ IPL: (default)

#### USB — r_usb_basic

| Instance | Mode | Speed | Port | Board Use |
|----------|------|-------|------|-----------|
| g_usb0 | Device + Host | FS (J3) + HS (J4) | Both | USB Device + USB Host |

Config:
- USB mode: device or host (switchable at runtime)
- Device speed: Full-Speed (J3)
- Host speed: High-Speed (J4)
- VBUS control: Pb00 (Host enable), P407 (Device monitor), P415 (Host fault)
- Callback: custom (for USB events)
- IRQ IPL: (default)

USB class drivers to add on top of r_usb_basic:

| Driver | Class | Direction | Board Use |
|--------|-------|-----------|-----------|
| r_usb_pcdc | CDC (virtual serial) | Device | USB-to-UART bridge on J3 |
| r_usb_hhid | HID (keyboard/mouse) | Host | USB keyboard/mouse on J4 |
| r_usb_hmsc | Mass Storage | Host | USB flash drive on J4 |

#### Ethernet — r_ether

| Instance | Channel | Mode | Pins | Board Use |
|----------|---------|------|------|-----------|
| g_ether0 | 0 | RMII | P400–P410 | Ethernet PHY (J5) |

Config:
- PHY interface: RMII (reduced MII)
- MAC address: configurable (set in software)
- IEEE 1588 PTP: enabled (hardware timestamping)
- Promiscuous mode: disabled
- Flow control: disabled (enable if PHY supports)
- Callback: custom (for frame TX/RX)
- IRQ IPL: (default)

For TCP/IP networking, add on top of r_ether:
- **sf_el_nx** — NetX framework integration (ThreadX-compatible TCP/IP stack)
- Or use bare-metal r_ether driver with custom protocol stack

#### QSPI Flash — r_qspi

| Instance | Channel | Speed | Pins | Board Use |
|----------|---------|-------|------|-----------|
| g_qspi0 | 0 | up to 50 MHz | SCK=P120, IO0–IO3=P121–P124, CS=P125 | QSPI flash (U7 footprint) |

Config:
- Mode: Quad SPI (4 data lines)
- Clock: up to 50 MHz (BCLK/2 = 60 MHz max)
- Address size: 24-bit or 32-bit (depends on flash chip)
- Dummy cycles: per flash chip datasheet
- Auto-calibration: enabled

Note: U7 is not fitted by default. Only configure if you solder a QSPI flash IC.

#### Graphics LCD — r_glcd

| Instance | Color Depth | Resolution | Pins | Board Use |
|----------|-------------|-----------|------|-----------|
| g_lcd0 | 16-bit RGB565 | 480x272 (default) | P110–P115, P211–P226 | Graphics LCD (J15) |

Config:
- Color format: 16-bit RGB565 (or 32-bit ARGB8888 if memory allows)
- Panel timing: per LCD panel datasheet
- Hsync/Vsync polarity: active low (typical)
- Dot clock: derived from PCLKA
- Backlight: GPIO control (if wired)

Add 2D drawing engine:
- **r_drw** — 2D Drawing Engine (hardware-accelerated fills, blits, alpha blending)

Note: P110 is shared with DEBUG0.TDI. Using the LCD requires SWD (2-wire) debug mode instead of JTAG (4-wire). In the Pins tab, set debug mode to SWD to free P110/P111.

---

## Pin Conflict Matrix

Some pins serve multiple functions. Choose which feature to use:

| Pin | Function A | Function B | Resolution |
|-----|-----------|-----------|------------|
| P110 | DEBUG0.TDI (JTAG) | GLCD_DATA0 | Use SWD debug (not JTAG) to free for LCD |
| P111 | DEBUG0.TSWO (JTAG) | GLCD_DATA1 | Use SWD debug to free for LCD |
| P400 | ET_RXD0/REFCLK (Ethernet) | PMOD UART GPIO3 | Choose Ethernet OR PMOD UART GPIO3 |
| P405 | ET_TXEN (Ethernet) | GPT1.GTIOCA (PWM) | Choose Ethernet OR PWM on ch1 |
| P407 | ET_MDIO (Ethernet) | USB Device VBUS monitor | Choose Ethernet OR USB Device |
| P408 | ET_LINK (Ethernet) | IRQ7 (PMOD UART interrupt) | Choose Ethernet OR PMOD UART IRQ |
| P409 | ET_MAGIC (Ethernet) | IRQ6 (PMOD SPI interrupt) | Choose Ethernet OR PMOD SPI IRQ |
| P410 | ET_PHY_INT (Ethernet) | SCI3.SCK (PMOD UART SCK) | Choose Ethernet OR PMOD UART |
| P411 | ET_RXD1 (Ethernet) | SCI3.CTS (PMOD UART CTS) | Choose Ethernet OR PMOD UART |

### Recommended configurations:

**Config A: Ethernet + no PMOD UART**
- Use Ethernet on J5 (P400–P410)
- Use PMOD SPI on J13 (P100–P103)
- Use PMOD IIC on J18 (P205–P206)
- Use a different SCI channel for UART (not ch3)
- PWM on GPT channel not using P405

**Config B: PMOD UART + no Ethernet**
- Use PMOD UART on J16 (P408–P411)
- Use PMOD SPI on J13 (P100–P103)
- Use PMOD IIC on J18 (P205–P206)
- Ethernet J5 not usable
- PWM on GPT1 P405 is available

**Config C: Graphics LCD + SWD debug**
- Use GLCD on J15 (P110–P115, P211–P226)
- Debug via SWD only (P108 SWDIO, P300 SWCLK) — not JTAG
- Frees P109 (SWO), P110 (TDI), P111 (TDO) for other uses
- P109/P110/P111 available for LCD or other peripherals

---

## ThreadX RTOS Configuration

ThreadX is selected as the RTOS. Key settings:

| Setting | Value | Why |
|---------|-------|-----|
| RTOS | Express Logic ThreadX | Bundled with SSP |
| Timer tick source | GPT timer (g_timer1, 1ms) | ThreadX system tick |
| Preemption threshold | Enabled | ThreadX feature |
| Thread stack checking | Enabled | Catches stack overflow |

### Suggested ThreadX threads:

| Thread | Priority | Stack | Purpose |
|--------|----------|-------|---------|
| main_thread | 1 (highest) | 1 KB | System init, LED blink |
| usb_thread | 2 | 2 KB | USB host/device event handling |
| net_thread | 3 | 4 KB | Ethernet + TCP/IP stack |
| lcd_thread | 4 | 2 KB | Graphics LCD refresh |
| sensor_thread | 5 | 512 B | ADC/DAC polling |

---

## Summary — Configurator Steps

### Step 1: Clocks tab
- Set XTAL to **12 MHz**
- Set PLL to **x20 /1** = 240 MHz
- Set ICLK **/1** = 240 MHz
- Set PCLKA **/2** = 120 MHz
- Set PCLKB **/4** = 60 MHz
- Set PCLKD **/2** = 120 MHz
- Set FCLK **/4** = 60 MHz
- Set UCLK **/5** = 48 MHz

### Step 2: BSP tab
- Board: custom
- Target: R7FS7G27H3A01CFC
- RTOS: ThreadX
- Heap: 0x4000 (16 KB)
- Main stack: 0x1000 (4 KB)
- VCC/AVCC0: 3300 mV

### Step 3: Pins tab — Set Custom Names and Configure Functions

The configuration.xml already has symbolic names defined for every pin. In the e2 studio Configurator GUI, these appear in the **Pins** tab under the "Name" column for each pin.

#### 3a. Verify already-configured pins (from configuration.xml)

These pins are already configured and should show up in the Pins tab:

| Pin | Custom Name | Function | How to verify in GUI |
|-----|-------------|----------|----------------------|
| P108 | SWDIO | Debug0 SWDIO | Pins tab → Debug → SWDIO → P108 |
| P300 | SWCLK | Debug0 SWCLK | Pins tab → Debug → SWCLK → P300 |
| P305 | LED1_RED | GPIO Output Low | Pins tab → P305 → Mode: Output → Initial: Low |
| P801 | LED2_GREEN | GPIO Output High | Pins tab → P801 → Mode: Output → Initial: High |
| Pb00 | USBH_VBUSEN | GPIO Output High | Pins tab → Pb00 → Mode: Output → Initial: High |
| Pb01 | USBHS_VBUS | GPIO Input | Pins tab → Pb01 → Mode: Input |
| P415 | USBH_FAULT | GPIO Input | Pins tab → P415 → Mode: Input |
| P405 | GPT1_PWM | GPT1 GTIOCA | Pins tab → P405 → GPT1 → GTIOCA |

#### 3b. PMOD Header Pin Configuration

The three PMOD connectors on the SA-BEST 2017 board are on **separate pins** and can be used simultaneously:

| Connector | Type | Peripheral | SCI/IIC Channel | Pins |
|-----------|------|------------|-----------------|------|
| J13 | PMOD SPI | r_sci_spi | SCI ch0 | P100–P103 |
| J16 | PMOD UART | r_sci_uart | SCI ch3 | P408–P411 |
| J18 | PMOD IIC | r_iic | IIC ch1 | P205, P206 |

**IMPORTANT: PMOD UART uses SCI3 (not SCI4).** The S7G2 MCU pin mapping shows SCI3 is on P408–P411, while SCI4 is on P205/P206. The board documentation may incorrectly label the PMOD UART as SCI4 — the correct channel is **SCI3**.

**PMOD SPI (J13) — r_sci_spi on SCI channel 0:**

Already configured in configuration.xml. The r_sci_spi driver uses SCI0. In master mode: TXD=MOSI, RXD=MISO, SCK=SCK, CTS=chip select.

| Pin | Custom Name | Function | Set in GUI |
|-----|-------------|----------|------------|
| P100 | PMOD_SPI_MISO | SCI0_RXD (MISO) | Already configured — verify: Pins tab → P100 → SCI0 → RXD |
| P101 | PMOD_SPI_MOSI | SCI0_TXD (MOSI) | Already configured — verify: Pins tab → P101 → SCI0 → TXD |
| P102 | PMOD_SPI_SCK | SCI0_SCK | Already configured — verify: Pins tab → P102 → SCI0 → SCK |
| P103 | PMOD_SPI_SS | SCI0_CTS (SSL) | Already configured — verify: Pins tab → P103 → SCI0 → CTS |
| P409 | PMOD_SPI_IRQ | IRQ6 (optional) | Pins tab → P409 → IRQ mode → IRQ06 (conflicts with PMOD UART TXD) |
| P612 | PMOD_SPI_GPIO1 | GPIO Input | Pins tab → P612 → Mode: Input |
| P613 | PMOD_SPI_GPIO2 | GPIO Input | Pins tab → P613 → Mode: Input |
| P614 | PMOD_SPI_GPIO3 | GPIO Input | Pins tab → P614 → Mode: Input |

**PMOD UART (J16) — r_sci_uart on SCI channel 3:**

Already configured in configuration.xml. The r_sci_uart channel is set to **3** (not 4).

| Pin | Custom Name | Function | Set in GUI |
|-----|-------------|----------|------------|
| P408 | PMOD_UART_RXD | SCI3_RXD | Already configured — verify: Pins tab → P408 → SCI3 → RXD |
| P409 | PMOD_UART_TXD | SCI3_TXD | Already configured — verify: Pins tab → P409 → SCI3 → TXD |
| P410 | PMOD_UART_SCK | SCI3_SCK | Already configured — verify: Pins tab → P410 → SCI3 → SCK (optional, for sync mode) |
| P411 | PMOD_UART_CTS | SCI3_CTS | Already configured — verify: Pins tab → P411 → SCI3 → CTS |
| P414 | PMOD_UART_GPIO1 | GPIO Input | Pins tab → P414 → Mode: Input |
| P707 | PMOD_UART_GPIO2 | GPIO Input | Pins tab → P707 → Mode: Input |
| P400 | PMOD_UART_GPIO3 | GPIO Input | Pins tab → P400 → Mode: Input |

Note: P408/P409/P410 are shared with Ethernet RMII. If using Ethernet on J5, do not use PMOD UART simultaneously — use a different SCI channel.

**PMOD IIC (J18) — r_iic on IIC channel 1 (add after adding r_iic driver):**

Already configured in configuration.xml. The PMOD IIC connector uses **IIC1** (NOT IIC2 — IIC2 is only on P511/P512 on the Arduino header). The r_iic channel is set to **1**.

| Pin | Custom Name | Function | Set in GUI |
|-----|-------------|----------|------------|
| P205 | PMOD_IIC_SCL | IIC1_SCL | Already configured — verify: Pins tab → P205 → IIC1 → SCL |
| P206 | PMOD_IIC_SDA | IIC1_SDA | Already configured — verify: Pins tab → P206 → IIC1 → SDA |
| P204 | PMOD_IIC_GPIO1 | GPIO Input | Pins tab → P204 → Mode: Input |
| P203 | PMOD_IIC_GPIO2_CAN0_CTX | GPIO Input | Pins tab → P203 → Mode: Input (or CAN0 CTX) |

**All three PMOD connectors can be used simultaneously** since they are on separate pins:
- PMOD SPI: P100–P103 (SCI0)
- PMOD UART: P408–P411 (SCI3)
- PMOD IIC: P205–P206 (IIC1)

**CAN (external transceiver via Arduino header) — CONFIGURED:**

The S7G2 has 2 CAN channels. The SA-BEST 2017 board does not have an on-board CAN transceiver, but you can connect an external transceiver (e.g., SN65HVD230, TJA1050) via the Arduino header pins.

**Selected: CAN1 Channel B (P512=CTX, P511=CRX)** — no conflicts with any other peripheral. These pins are on the Arduino Mega header (J6–J12). The r_can driver is already configured in configuration.xml.

CAN pin options on the S7G2 (176 LQFP):

| Channel | Group | CTX Pin | CRX Pin | Conflicts | Status |
|---------|-------|---------|---------|-----------|--------|
| CAN0 | A | P203 | P202 | PMOD IIC GPIO pins | Available (alternative) |
| CAN0 | B | P401 | P402 | Ethernet RMII | Conflict with Ethernet |
| CAN1 | A | P109 | P110 | GLCD DATA0/DATA1, JTAG TDI/TDO | Conflict with GLCD |
| CAN1 | B | P512 | P511 | Arduino header (no conflicts) | **SELECTED** |

Configured CAN1 pins (already in configuration.xml):

| Pin | Custom Name | Function | Status |
|-----|-------------|----------|--------|
| P512 | ARD_CAN1_CTX_IIC2_SCL | CAN1_CTX | Configured — verify: Pins tab → P512 → CAN1 → CTX |
| P511 | ARD_CAN1_CRX_IIC2_SDA | CAN1_CRX | Configured — verify: Pins tab → P511 → CAN1 → CRX |

r_can driver settings (already in configuration.xml):

| Property | Value | Description |
|----------|-------|-------------|
| Name | g_can0 | Instance name |
| Channel | 1 | CAN1 (Channel B: P512/P511) |
| Baud Rate Prescaler | 5 | Prescaler (1-1024) |
| Time Segment 1 | 15 TQ | CAN_TIME_SEGMENT1_TQ15 |
| Time Segment 2 | 4 TQ | CAN_TIME_SEGMENT2_TQ4 |
| Sync Jump Width | 1 TQ | CAN_SYNC_JUMP_WIDTH_TQ1 |
| ID Mode | Standard | CAN_ID_MODE_STANDARD |
| Message Mode | Overwrite | CAN_MESSAGE_MODE_OVERWRITE |
| Mailbox Count | 4 | 4 mailboxes (MB0=TX, MB1-3=RX) |
| Callback | user_can_callback | User callback function |
| Error IPL | (default) | Error interrupt priority |
| RX IPL | (default) | Receive mailbox interrupt priority |
| TX IPL | (default) | Transmit mailbox interrupt priority |

**CAN bitrate calculation** (with PCLKB = 60 MHz, prescaler = 5):
- CAN clock = PCLKB / prescaler = 60 MHz / 5 = 12 MHz
- Bit time = (1 + TS1 + TS2) TQ = (1 + 15 + 4) = 20 TQ
- Bitrate = 12 MHz / 20 = **600 kbps**
- Adjust prescaler/time segments in GUI for your target bitrate (e.g., 500 kbps: prescaler=6, or TS1=12 TS2=4 → 12 MHz/20 = 600 kbps; prescaler=10, TS1=11, TS2=4 → 6MHz/16 = 375 kbps; prescaler=5, TS1=12, TS2=4 → 12MHz/17 = ~706 kbps. For 500 kbps: prescaler=6, TS1=15, TS2=4 → 10MHz/20 = 500 kbps)

**Hardware connection:**
Connect external CAN transceiver IC (e.g., SN65HVD230, TJA1050) to P512 (CTX) and P511 (CRX) on the Arduino header. The transceiver converts the MCU's TTL-level CAN signals to differential CANH/CANL bus signals.

Alternative: CAN0 Channel A (P203=CTX, P202=CRX) — conflicts with PMOD IIC GPIO pins only. To use this instead, change r_can channel to 0 and reconfigure pins in the Pins tab.

**USB Device (J3):**

| Pin | Custom Name | Function | Set in GUI |
|-----|-------------|----------|------------|
| P407 | USB_DEV_VBUS | GPIO Input | Pins tab → P407 → Mode: Input |

**Analog:**

| Pin | Custom Name | Set in GUI |
|-----|-------------|------------|
| P000 | ADC_AN0_POT | Pins tab → P000 → Analog → AN0 (no GPIO mode needed) |
| P006 | ADC_AN6_VIBRATION | Pins tab → P006 → Analog → AN6 (no GPIO mode needed) |
| P014 | DAC0_OUT | Pins tab → P014 → Analog → DA0 (no GPIO mode needed) |
| P015 | DAC1_OUT | Pins tab → P015 → Analog → DA1 (no GPIO mode needed) |

**QSPI Flash (U7) — NOT fitted on board, driver removed:**

The QSPI flash footprint (U7) is not populated on the SA-BEST 2017 board. The r_qspi driver was removed because the S7G2 BSP pack does not include QSPI flash chip definitions (no chip = no BSP support). Pin names P120–P125 are reserved for future use if a QSPI flash IC is soldered.

| Pin | Reserved Name | Future Use |
|-----|---------------|------------|
| P120 | QSPI_SCK | QSPI clock (if U7 populated) |
| P121 | QSPI_IO0 | QSPI data 0 (if U7 populated) |
| P122 | QSPI_IO1 | QSPI data 1 (if U7 populated) |
| P123 | QSPI_IO2 | QSPI data 2 (if U7 populated) |
| P124 | QSPI_IO3 | QSPI data 3 (if U7 populated) |
| P125 | QSPI_CS | QSPI chip select (if U7 populated) |

**Graphics LCD (J15) — for r_glcd (add after adding r_glcd driver):**

| Pin | Custom Name | Set in GUI |
|-----|-------------|------------|
| P110 | GLCD_DATA0 | Pins tab → P110 → GLCD → DATA0 |
| P111 | GLCD_DATA1 | Pins tab → P111 → GLCD → DATA1 |
| P112 | GLCD_DATA2 | Pins tab → P112 → GLCD → DATA2 |
| P113 | GLCD_DATA3 | Pins tab → P113 → GLCD → DATA3 |
| P114 | GLCD_DATA4 | Pins tab → P114 → GLCD → DATA4 |
| P115 | GLCD_DATA5 | Pins tab → P115 → GLCD → DATA5 |
| P211 | GLCD_DATA6 | Pins tab → P211 → GLCD → DATA6 |
| P212 | GLCD_DATA7 | Pins tab → P212 → GLCD → DATA7 |
| P213 | GLCD_DATA8 | Pins tab → P213 → GLCD → DATA8 |
| P214 | GLCD_DATA9 | Pins tab → P214 → GLCD → DATA9 |
| P215 | GLCD_DATA10 | Pins tab → P215 → GLCD → DATA10 |
| P216 | GLCD_DATA11 | Pins tab → P216 → GLCD → DATA11 |
| P217 | GLCD_DATA12 | Pins tab → P217 → GLCD → DATA12 |
| P218 | GLCD_DATA13 | Pins tab → P218 → GLCD → DATA13 |
| P219 | GLCD_DATA14 | Pins tab → P219 → GLCD → DATA14 |
| P220 | GLCD_DATA15 | Pins tab → P220 → GLCD → DATA15 |
| P221 | GLCD_HSYNC | Pins tab → P221 → GLCD → HSYNC |
| P222 | GLCD_VSYNC | Pins tab → P222 → GLCD → VSYNC |
| P223 | GLCD_DE | Pins tab → P223 → GLCD → DE |
| P224 | GLCD_DOTCLK | Pins tab → P224 → GLCD → DOTCLK |
| P226 | GLCD_TCON0 | Pins tab → P226 → GLCD → TCON0 |

**Ethernet (J5) — for r_ether (add after adding r_ether driver):**

| Pin | Custom Name | Set in GUI |
|-----|-------------|------------|
| P400 | ET_RXD0_REFCLK | Pins tab → P400 → ET0 → RXD0/REFCLK |
| P401 | ET_RXD1 | Pins tab → P401 → ET0 → RXD1 |
| P402 | ET_RXER | Pins tab → P402 → ET0 → RXER |
| P403 | ET_TXD0 | Pins tab → P403 → ET0 → TXD0 |
| P404 | ET_TXD1 | Pins tab → P404 → ET0 → TXD1 |
| P406 | ET_MDC | Pins tab → P406 → ET0 → MDC |
| P408 | ET_LINK | Pins tab → P408 → ET0 → LINK |

Note: P405 is already used for GPT1_PWM. If using Ethernet, change P405 from GPT1 to ET_TXEN. P408/P409/P410 are used for PMOD UART (SCI3) — if using Ethernet, do not use PMOD UART simultaneously. See Pin Conflict Matrix above.

#### 3c. How to set custom pin names in e2 studio

1. Open the **Synergy Configuration** (double-click `configuration.xml` in Project Explorer)
2. Click the **Pins** tab at the bottom
3. All pin names are already defined in configuration.xml — they should appear automatically
4. If a name is missing, select the pin → in the Properties view → set **Name** field to the custom name
5. To set a pin function: click the pin → in the dropdown select the peripheral function (e.g., SCI0, SCI3, IIC1, etc.)
6. Green checkmark = no conflict. Red X = pin conflict (two peripherals on same pin)

### Step 4: Threads tab — HAL drivers

#### Already generated from configuration.xml (11 drivers):

These 11 drivers were already generated successfully from the configuration.xml file:

| # | Driver | Instance | Status |
|---|--------|----------|--------|
| 1 | r_gpt | g_timer0 (PWM, ch0, 10ms, 50%) | Generated |
| 2 | r_gpt | g_timer1 (Periodic, ch1, 1ms) | Generated |
| 3 | r_gpt | g_timer2 (Periodic, ch2, 10ms, sensor poll) | Generated |
| 4 | r_gpt | g_timer3 (Periodic, ch3, 100ms, comms timeout) | Generated |
| 3 | r_adc | g_adc0 (12-bit, single scan, AN0+AN6) | Generated |
| 4 | r_dac | g_dac0 (ch0, 12-bit, right-justified) | Generated |
| 5 | r_dac | g_dac1 (ch1, 12-bit, right-justified) | Generated |
| 6 | r_sci_uart | g_uart0 (ch3, 115200 8N1, HW flow) | Generated |
| 7 | r_sci_spi | g_spi0 (ch0, Master, 30MHz, MSB) | Generated |
| 8 | r_dtc | g_transfer0 (UART TX DMA) | Generated |
| 9 | r_dtc | g_transfer1 (UART RX DMA) | Generated |
| 10 | r_can | g_can0 (ch1, CAN1B, 4 mailboxes, 600kbps) | Generated |
| 11 | r_qspi | g_qspi0 (ch0, QSPI flash) | **Removed** — U7 not fitted, BSP lacks QSPI chip defs |

#### Add 4 missing drivers via GUI:

These 4 drivers need to be added manually in the Threads tab because their XML property schema didn't match SSP 2.7.0 exactly.

**Driver 1: r_iic (I2C for PMOD IIC J18)**

1. Go to **Threads** tab → click **New Driver Instance**
2. Select **r_iic** (I2C)
3. Set these properties:

| Property | Value |
|----------|-------|
| Name | g_i2c0 |
| Channel | 1 |
| Rate | 400000 |
| Slave address | 0x00 |
| Address mode | 7-bit |
| Timeout mode | Short |
| Timeout SCL low | Disabled |
| Callback | user_i2c_callback |
| RXI IPL | (default) |
| TXI IPL | (default) |
| TEI IPL | (default) |
| ERI IPL | (default) |

4. After adding, go to **Pins** tab and verify (already configured in configuration.xml):
   - P205 → IIC1 → SCL (name: PMOD_IIC_SCL)
   - P206 → IIC1 → SDA (name: PMOD_IIC_SDA)
   - Note: r_iic channel must be set to 1 (not 2) — IIC2 is only on P511/P512 (Arduino header).

**Driver 2: r_usb_basic (USB Host + Device)**

1. Go to **Threads** tab → click **New Driver Instance**
2. Select **r_usb_basic** (USB Basic)
3. Set these properties:

| Property | Value |
|----------|-------|
| Name | g_usb0 |
| Type | Full-Speed |
| Speed | Full-Speed |
| Module number | 0 |
| Callback | user_usb_callback |
| IPL | (default) |
| IPL USBI0 | (default) |
| IPL USBI1 | (default) |
| IPL USBR | (default) |

4. After adding, go to **Pins** tab and verify:
   - Pb00 → USBH_VBUSEN (already configured as GPIO output high)
   - Pb01 → USBHS_VBUS (already configured as GPIO input)
   - P415 → USBH_FAULT (already configured as GPIO input)
   - P407 → USB_DEV_VBUS (already configured as GPIO input)

**Driver 3: r_ether (Ethernet for J5)**

1. Go to **Threads** tab → click **New Driver Instance**
2. Select **r_ether** (Ethernet)
3. Set these properties:

| Property | Value |
|----------|-------|
| Name | g_ether0 |
| Channel | 0 |
| Callback | user_ether_callback |
| IRQ IPL | (default) |

4. After adding, go to **Pins** tab and configure:
   - P400 → ET0 → RMII_RXD0/REFCLK
   - P401 → ET0 → RMII_RXD1
   - P402 → ET0 → RMII_RXER
   - P403 → ET0 → RMII_TXD0
   - P404 → ET0 → RMII_TXD1
   - P405 → ET0 → RMII_TXEN (conflicts with GPT1_PWM — change P405 from GPT to ET)
   - P406 → ET0 → RMII_MDC
   - P407 → ET0 → RMII_MDIO (conflicts with USB_DEV_VBUS — change P407 from GPIO to ET)
   - P408 → ET0 → LINK (conflicts with PMOD_UART_IRQ — change P408 from IRQ to ET)

   **Important:** Adding Ethernet will conflict with GPT1 PWM (P405) and PMOD UART (P408/P409/P410/P411, SCI3). If you need both Ethernet AND PMOD UART, use a different SCI channel for UART (not ch3). If you need both Ethernet AND PWM, use a different GPT channel (not ch1 on P405).

**Driver 4: r_glcd (Graphics LCD for J15)**

1. Go to **Threads** tab → click **New Driver Instance**
2. Select **r_glcd** (Graphics LCD)
3. Set these properties:

| Property | Value |
|----------|-------|
| Name | g_lcd0 |
| Input | Layer 1 |
| Output | Little endian |
| Color depth | 16bpp RGB565 |
| Callback | NULL |
| IRQ IPL | (default) |
| Vsync IPL | (default) |
| Line0 IPL | (default) |
| Line1 IPL | (default) |
| Line2 IPL | (default) |
| Underflow IPL | (default) |

4. After adding, go to **Pins** tab and configure all GLCD pins:
   - P110 → GLCD → DATA0 (name: GLCD_DATA0)
   - P111 → GLCD → DATA1 (name: GLCD_DATA1)
   - P112 → GLCD → DATA2 (name: GLCD_DATA2)
   - P113 → GLCD → DATA3 (name: GLCD_DATA3)
   - P114 → GLCD → DATA4 (name: GLCD_DATA4)
   - P115 → GLCD → DATA5 (name: GLCD_DATA5)
   - P211 → GLCD → DATA6 (name: GLCD_DATA6)
   - P212 → GLCD → DATA7 (name: GLCD_DATA7)
   - P213 → GLCD → DATA8 (name: GLCD_DATA8)
   - P214 → GLCD → DATA9 (name: GLCD_DATA9)
   - P215 → GLCD → DATA10 (name: GLCD_DATA10)
   - P216 → GLCD → DATA11 (name: GLCD_DATA11)
   - P217 → GLCD → DATA12 (name: GLCD_DATA12)
   - P218 → GLCD → DATA13 (name: GLCD_DATA13)
   - P219 → GLCD → DATA14 (name: GLCD_DATA14)
   - P220 → GLCD → DATA15 (name: GLCD_DATA15)
   - P221 → GLCD → HSYNC (name: GLCD_HSYNC)
   - P222 → GLCD → VSYNC (name: GLCD_VSYNC)
   - P223 → GLCD → DE (name: GLCD_DE)
   - P224 → GLCD → DOTCLK (name: GLCD_DOTCLK)
   - P226 → GLCD → TCON0 (name: GLCD_TCON0)

   **Important:** P110/P111 are shared with JTAG debug (TDI/TDO). Debug mode is already set to SWD (2-wire), which frees P110/P111 for GLCD. Verify debug mode is SWD in the Pins tab → Debug → Mode → SWD.

### Step 5: Generate project
- Click **Generate Project Content** button (green icon in toolbar)
- SSP generates all driver source files, configuration headers, and pin setup
- The 4 new drivers (r_iic, r_usb_basic, r_ether, r_glcd) will be added to `hal_data.c`
- Build the project — all driver .c files should now compile

### Step 6: Build and verify
- Build the project (Project → Build Project)
- Verify 0 errors
- The `bsp_irq.c` array-bounds warning is a known GCC issue — safe to ignore

---

## Complete Pin Name Reference

All custom pin names defined in configuration.xml:

| Pin | Custom Name | Function | Board Feature |
|-----|-------------|----------|---------------|
| P108 | SWDIO | Debug0 SWDIO | J-Link SWD data |
| P300 | SWCLK | Debug0 SWCLK | J-Link SWD clock |
| P305 | LED1_RED | GPIO Output Low | User LED1 (Red) — active low |
| P801 | LED2_GREEN | GPIO Output High | User LED2 (Green) — active high |
| Pb00 | USBH_VBUSEN | GPIO Output High | USB Host VBUS power enable |
| Pb01 | USBHS_VBUS | GPIO Input | USB Host VBUS monitor |
| P415 | USBH_FAULT | GPIO Input | USB Host over-current fault |
| P405 | GPT1_PWM | GPT1 GTIOCA | PWM output (or ET_TXEN if using Ethernet) |
| P100 | PMOD_SPI_MOSI | SPI0 MOSI | PMOD SPI J13 pin 131 |
| P101 | PMOD_SPI_MISO | SPI0 MISO | PMOD SPI J13 pin 132 |
| P102 | PMOD_SPI_SCK | SPI0 SCK | PMOD SPI J13 pin 130 |
| P103 | PMOD_SPI_SS | SPI0 SSL0 | PMOD SPI J13 pin 129 |
| P409 | PMOD_SPI_IRQ | IRQ6 | PMOD SPI J13 pin 103 |
| P612 | PMOD_SPI_GPIO1 | GPIO Input | PMOD SPI J13 pin 42 |
| P613 | PMOD_SPI_GPIO2 | GPIO Input | PMOD SPI J13 pin 104 |
| P614 | PMOD_SPI_GPIO3 | GPIO Input | PMOD SPI J13 pin 105 |
| P408 | PMOD_UART_RXD | SCI3 RXD | PMOD UART J16 pin 37 |
| P409 | PMOD_UART_TXD | SCI3 TXD | PMOD UART J16 pin 36 |
| P410 | PMOD_UART_SCK | SCI3 SCK | PMOD UART J16 pin 40 |
| P411 | PMOD_UART_CTS | SCI3 CTS | PMOD UART J16 pin 38 |
| P414 | PMOD_UART_GPIO1 | GPIO Input | PMOD UART J16 pin 43 |
| P707 | PMOD_UART_GPIO2 | GPIO Input | PMOD UART J16 pin 15 |
| P400 | PMOD_UART_GPIO3 | GPIO Input | PMOD UART J16 pin 1 |
| P205 | PMOD_IIC_SCL | IIC1 SCL | PMOD IIC J18 pin 51 |
| P206 | PMOD_IIC_SDA | IIC1 SDA | PMOD IIC J18 pin 50 |
| P204 | PMOD_IIC_GPIO1 | GPIO Input | PMOD IIC J18 pin 53 |
| P203 | PMOD_IIC_GPIO2_CAN0_CTX | GPIO / CAN0 CTX | PMOD IIC J18 pin 52 |
| P202 | PMOD_IIC_GPIO3_CAN0_CRX | GPIO / CAN0 CRX | (Arduino header) |
| P408 | PMOD_UART_RXD | SCI3 RXD | PMOD UART J16 pin 37 |
| P409 | PMOD_UART_TXD | SCI3 TXD | PMOD UART J16 pin 36 |
| P410 | PMOD_UART_SCK | SCI3 SCK | PMOD UART J16 pin 40 |
| P411 | PMOD_UART_CTS | SCI3 CTS | PMOD UART J16 pin 38 |
| P407 | USB_DEV_VBUS | GPIO Input | USB Device J3 VBUS monitor |
| P511 | ARD_CAN1_CRX_IIC2_SDA | CAN1 CRX / IIC2 SDA | Arduino header |
| P512 | ARD_CAN1_CTX_IIC2_SCL | CAN1 CTX / IIC2 SCL | Arduino header |
| P014 | DAC0_OUT | DAC0 | DAC analog output 0 |
| P015 | DAC1_OUT | DAC1 | DAC analog output 1 |
| P000 | ADC_AN0_POT | ADC AN0 | Variable resistor (potentiometer) |
| P006 | ADC_AN6_VIBRATION | ADC AN6 | Sensolute vibration sensor |
| P120 | QSPI_SCK | QSPI SCK | QSPI flash U7 clock (U7 not fitted) |
| P121 | QSPI_IO0 | QSPI IO0 | QSPI flash U7 data 0 (U7 not fitted) |
| P122 | QSPI_IO1 | QSPI IO1 | QSPI flash U7 data 1 (U7 not fitted) |
| P123 | QSPI_IO2 | QSPI IO2 | QSPI flash U7 data 2 (U7 not fitted) |
| P124 | QSPI_IO3 | QSPI IO3 | QSPI flash U7 data 3 (U7 not fitted) |
| P125 | QSPI_CS | QSPI CS | QSPI flash U7 chip select (U7 not fitted) |
| P110 | GLCD_DATA0 | GLCD DATA0 | Graphics LCD J15 data bit 0 |
| P111 | GLCD_DATA1 | GLCD DATA1 | Graphics LCD J15 data bit 1 |
| P112 | GLCD_DATA2 | GLCD DATA2 | Graphics LCD J15 data bit 2 |
| P113 | GLCD_DATA3 | GLCD DATA3 | Graphics LCD J15 data bit 3 |
| P114 | GLCD_DATA4 | GLCD DATA4 | Graphics LCD J15 data bit 4 |
| P115 | GLCD_DATA5 | GLCD DATA5 | Graphics LCD J15 data bit 5 |
| P211 | GLCD_DATA6 | GLCD DATA6 | Graphics LCD J15 data bit 6 |
| P212 | GLCD_DATA7 | GLCD DATA7 | Graphics LCD J15 data bit 7 |
| P213 | GLCD_DATA8 | GLCD DATA8 | Graphics LCD J15 data bit 8 |
| P214 | GLCD_DATA9 | GLCD DATA9 | Graphics LCD J15 data bit 9 |
| P215 | GLCD_DATA10 | GLCD DATA10 | Graphics LCD J15 data bit 10 |
| P216 | GLCD_DATA11 | GLCD DATA11 | Graphics LCD J15 data bit 11 |
| P217 | GLCD_DATA12 | GLCD DATA12 | Graphics LCD J15 data bit 12 |
| P218 | GLCD_DATA13 | GLCD DATA13 | Graphics LCD J15 data bit 13 |
| P219 | GLCD_DATA14 | GLCD DATA14 | Graphics LCD J15 data bit 14 |
| P220 | GLCD_DATA15 | GLCD DATA15 | Graphics LCD J15 data bit 15 |
| P221 | GLCD_HSYNC | GLCD HSYNC | Graphics LCD J15 horizontal sync |
| P222 | GLCD_VSYNC | GLCD VSYNC | Graphics LCD J15 vertical sync |
| P223 | GLCD_DE | GLCD DE | Graphics LCD J15 data enable |
| P224 | GLCD_DOTCLK | GLCD DOTCLK | Graphics LCD J15 pixel clock |
| P226 | GLCD_TCON0 | GLCD TCON0 | Graphics LCD J15 timing control 0 |

---

## Verification Checklist

- [ ] XTAL set to 12 MHz (not 8 or 24 MHz)
- [ ] PLL x20 /1 = 240 MHz ICLK
- [ ] PCLKA = 120 MHz, PCLKB = 60 MHz, PCLKD = 120 MHz
- [ ] FCLK = 60 MHz, UCLK = 48 MHz
- [ ] Heap increased to 0x4000 for USB + Ethernet + GUI
- [ ] Main stack increased to 0x1000
- [ ] Debug mode: SWD (frees P110/P111 for GLCD)
- [ ] Pin names set for all pins (see Complete Pin Name Reference)
- [ ] LED1_RED: P305 GPIO output low
- [ ] LED2_GREEN: P801 GPIO output high
- [ ] USBH_VBUSEN: Pb00 GPIO output high
- [ ] USBHS_VBUS: Pb01 GPIO input
- [ ] USBH_FAULT: P415 GPIO input
- [ ] USB_DEV_VBUS: P407 GPIO input
- [ ] GPT1_PWM: P405 GPT1 GTIOCA (or ET_TXEN if using Ethernet)
- [ ] PMOD_SPI_MISO: P100 SCI0 RXD (MISO)
- [ ] PMOD_SPI_MOSI: P101 SCI0 TXD (MOSI)
- [ ] PMOD_SPI_SCK: P102 SCI0 SCK
- [ ] PMOD_SPI_SS: P103 SCI0 CTS (SSL)
- [ ] PMOD_IIC_SCL: P205 IIC1 SCL
- [ ] PMOD_IIC_SDA: P206 IIC1 SDA
- [ ] PMOD_IIC_GPIO1: P204 GPIO Input
- [ ] PMOD_IIC_GPIO2_CAN0_CTX: P203 GPIO or CAN0 CTX
- [ ] PMOD_IIC_GPIO3_CAN0_CRX: P202 GPIO or CAN0 CRX
- [ ] PMOD_UART_RXD: P408 SCI3 RXD
- [ ] PMOD_UART_TXD: P409 SCI3 TXD
- [ ] PMOD_UART_SCK: P410 SCI3 SCK (optional)
- [ ] PMOD_UART_CTS: P411 SCI3 CTS
- [ ] ARD_CAN1_CRX_IIC2_SDA: P511 CAN1 CRX (configured in XML)
- [ ] ARD_CAN1_CTX_IIC2_SCL: P512 CAN1 CTX (configured in XML)
- [ ] r_can: g_can0 ch1, 4 mailboxes, 600kbps, callback=user_can_callback (configured in XML)
- [ ] ADC_AN0_POT: P000 AN0
- [ ] ADC_AN6_VIBRATION: P006 AN6
- [ ] DAC0_OUT: P014 DA0
- [ ] DAC1_OUT: P015 DA1
- [ ] QSPI: Removed (U7 not fitted on board — add later if flash IC soldered)
- [ ] GLCD_DATA0–15: P110–P115, P211–P220
- [ ] GLCD_HSYNC: P221, GLCD_VSYNC: P222, GLCD_DE: P223, GLCD_DOTCLK: P224
- [ ] r_iic driver added (g_i2c0, ch1, 400kHz)
- [ ] r_usb_basic driver added (g_usb0, Full-Speed)
- [ ] r_ether driver added (g_ether0, ch0)
- [ ] r_glcd driver added (g_lcd0, 16bpp RGB565)
- [ ] Pin conflicts resolved (see Pin Conflict Matrix)
- [ ] ThreadX tick timer configured (g_timer1, 1 ms periodic)
- [ ] Project generates without errors
- [ ] Project builds without errors (bsp_irq.c warning is safe to ignore)
