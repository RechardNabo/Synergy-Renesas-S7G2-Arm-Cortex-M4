# RENESAS Synergy — Hardware User Manual

**SA BEST 2017 Technical Training Seminar — Time2Market**
16, 17 and 18 May 2017

Proudly presented by: CST Electronics, Electrocomp, Electrocomp Express, NuVision Electronics
*(parts of Electrocomp Holdings Group (Pty) Ltd.)*

---

## Table of Contents

| Section | Page |
|---|---|
| 1 Overview | |
| &nbsp;&nbsp;1.1 Features | 2 |
| &nbsp;&nbsp;1.2 Block Diagram | 3 |
| &nbsp;&nbsp;1.3 Hardware features | 3 |
| 2 Power Supply Requirements | |
| &nbsp;&nbsp;2.1 Power supply | 4 |
| &nbsp;&nbsp;2.2 Power-up behavior | 4 |
| 3 Board Components | |
| &nbsp;&nbsp;3.1 J-Link On-Board debugger | 5 |
| &nbsp;&nbsp;3.2 PMOD Compatible interfaces | 5 |
| &nbsp;&nbsp;3.3 USB Device port | 7 |
| &nbsp;&nbsp;3.4 USB Host port | 7 |
| &nbsp;&nbsp;3.5 User LEDs | 7 |
| &nbsp;&nbsp;3.6 Sensolute vibration sensor | 8 |
| &nbsp;&nbsp;3.7 QSPI flash | 8 |
| &nbsp;&nbsp;3.8 Arduino Shield interface | 9 |
| &nbsp;&nbsp;3.9 Graphics LCD interface | 9 |
| 4 Board Layout | 10 |
| 5 Connectivity | |
| &nbsp;&nbsp;5.1 USB Host port | 11 |
| &nbsp;&nbsp;5.2 USB Device port | 11 |
| &nbsp;&nbsp;5.3 Ethernet | 12 |
| &nbsp;&nbsp;5.5 PMOD Compatible Ports | 12 |
| &nbsp;&nbsp;5.6 Arduino Compatible Port | 13 |
| 6 SA Best 2017 Schematics | |
| &nbsp;&nbsp;6.1 MCU | 14 |
| &nbsp;&nbsp;6.1 USB | 15 |
| &nbsp;&nbsp;6.2 Connectivity | 16 |
| &nbsp;&nbsp;6.3 J-Link | 17 |
| 7 R7FS7G2 MCU — Full Specification, Board Capabilities & Applications *(added)* | — |
| 8 Implementable Features — Suggested Learning Projects *(added)* | — |

---

## 1. Overview

### 1.1 Features

*[Fig: Photo of the Renesas Target Board (SA-BEST 2017), top view — RENESAS Synergy branding]*

This is a single-board starter kit for the Renesas Synergy S7G2 microcontroller in a 176-pin LQFP package. The board provides easy-to-access interfaces to the peripherals of the S7G2 microcontroller for application development. It includes Arduino Mega style connectors, three PMOD style connectors, connector for interfacing to an Ethernet PHY IC, connector for directly driving a graphics LCD display, USB and SWD J-Link interfaces.

This is a very basic low cost board that can be used for development, prototyping or as a finished product.

### 1.2 Block Diagram

*[Fig 1: Renesas Target Board block diagram]*

The block diagram shows the **S7G2 MCU** (Renesas Synergy) at the center, with the following peripheral connections:

- **PMOD SPI** ↔ SPI
- **PMOD I²C** ↔ I²C
- **PMOD UART** ↔ UART
- **Sensolute Vibration Sensor** ↔ (interrupt/GPIO)
- **LCD Port** ↔ MCU
- **Arduino Port** ↔ MCU
- **QSPI Flash** ↔ QSPI
- **User LEDs** ↔ GPIO
- **Ethernet Port** ↔ MAC
- **JLINK** ↔ SWD ↔ USB Device
- **USB Device** ↔ USB Device
- **USB Host** ↔ USB Host

### 1.3 Hardware Features

- S7G2 microprocessor with 176 LQFP package
- 3 user LEDs
- Arduino Mega style connectors
- 1 Sensolute mechanical vibration switch connected via a jumper to a microprocessor interrupt pin
- DAC output
- Footprint to fit a QSPI memory
- SPI, IIC and SCI interface
- USB Host and Device
- Variable resistor

---

## 2. Power Supply Requirements

### 2.1 Power Supply

Power is supplied to Renesas Target Board through the debug USB connector (J19). The board requires 5V applied on this interface (USB standard). Once power is supplied, the power supply indicator LED4 will light green.

### 2.2 Power-up Behaviour

*[Fig 2: CPU startup mode]*
*[Fig 3: CPU reset control]*

When power is applied to Renesas Target Board, the power-on reset (POR) monitor of the S7G2 microcontroller resets the S7G2.

The memory from which the S7G2 microcontroller starts program execution after reset depends on jumper J1. If J1 is in position 1-2 (default), the S7G2 starts execution from internal flash (ROM). If J1 is in position 2-3, the S7G2 starts execution in USB program mode, which enables you to load a program directly to the internal microcontroller flash through the USB Device interface.

The microcontroller can be forced to reset by the SW1 push button switch even while the board is powered.

---

## 3. Board Components

### 3.1 J-Link On-Board Debugger

*[Fig 4: J-Link debugger]*

Renesas Target Board features a SEGGER J-Link On-Board debugger, accessible through the J19 USB connector.

Alternatively, the onboard debugger can be bypassed by removing resistors R28, R32, R36 and R37. Once removed, SWD debugging can then be done through the J34 header.

### 3.2 PMOD Compatible Interfaces

Renesas Target Board includes three standard PMOD™ Compatible interfaces.

*[Fig 5: PMOD SPI Interface]*

PMOD_SPI, available on the J13 connector, exposes an SPI interface, three GPIO lines, and an interrupt line to the S7G2 microcontroller.

*[Fig 6: PMOD UART interface]*

PMOD_UART, available on the J16 connector, exposes a UART, three GPIO lines, and an interrupt line to the S7G2 microcontroller.

Both PMOD interfaces can output either 5V or 3.3V, depending on the position of the J14 and J17 jumpers.

*[Fig 7: PMOD IIC interface]*

PMOD_IIC, available on the J18 connector, exposes an IIC interface and two GPIO lines, to the S7G2 microcontroller.

### 3.3 USB Device Port

*[Fig 8: USB Device port]*

The Renesas Target Board is equipped with a USB Full-Speed Device port on J3. The SA_Best2017 board can be powered through this port if the J-Link is disconnected from the board.

### 3.4 USB Host Port

*[Fig 9: USB Host port]*

The Renesas Target Board is equipped with a USB High-Speed Host port on J4. This Host port can source current to devices connected to it, and over-consumption conditions on devices can be detected.

### 3.5 User LEDs

*[Fig 10: User LEDs]*

The Renesas Target Board includes three generic user LEDs connected to the microcontroller GPIO pins.

### 3.6 Sensolute Vibration Sensor

*[Fig 11: Sensolute vibration sensor]*

The Renesas Target Board includes a Sensolute vibration sensor connected via jumper J10 to the microcontroller AN6/GPIO/Interrupt pin.

### 3.7 QSPI Flash

*[Fig 12: QSPI flash – not fitted]*

Provision has been made on the Renesas Target Board for the user to fit a QSPI flash IC if so required.

### 3.8 Arduino Shield Interface

*[Fig 13: Arduino shield interface]*

The Renesas Target Board includes one Arduino Shield type interface, so that Arduino Shield boards can expand the functionality of the Renesas Target Board. The Arduino Shield interface is implemented with the J6, J7, J8, J9, J11, J12 and J15 connectors.

### 3.9 Graphics LCD Interface

*[Fig 14: Graphic LCD interface]*

Connector J15 on the Renesas Target Board can also be used as a dedicated driver for a graphics LCD display.

---

## 4. Board Layout

*[Fig 15: Renesas Target Board layout — PCB top view with silkscreen/copper overlay]*

The Renesas Target Board measures 124mm x 83mm. Figure 15 shows the location of all the relevant board components described in the prior section.

---

## 5. Connectivity

The following sections describe in detail the interfaces available on the Renesas Target Board, detailing the MCU resources utilized in each.

### 5.1 USB Host Port

The Renesas Target Board includes one USB Host port (J4). This port supplies current to devices connected to it through a current limited power switch (U4). The power output can be monitored through an S7G2 microcontroller GPIO pin and enabled through another GPIO pin.

**Table 1: USB Host port functions**

| S7G2 Pin | Function Name |
|---|---|
| USBHS_DM | USBHS_N |
| USBHS_DP | USBHS_P |
| Pb01 | USBHS_VBUS (monitor) |
| Pb00 | USBH_VBUSEN |
| P415 | FAULT (monitor) |

### 5.2 USB Device Port

The Renesas Target Board includes one USB Device port (J3). Detection of USB connection can be done by monitoring the status of the power pin of the USB Device connector through its connection to a GPIO pin on the S7G2 microcontroller.

**Table 2: USB Device port functions**

| S7G2 Pin | Function Name |
|---|---|
| USB_DM | USBF_N |
| USB_DP | USBF_P |
| P407 | USB_VBUS (monitor) |

### 5.3 Ethernet

The Renesas Target Board includes connector J5 that can be connected to an Ethernet PHY Device.

### 5.5 PMOD Compatible Ports

The Renesas Target Board includes three PMOD Compatible ports, PMOD SPI (J13), PMOD IIC (J18) and PMOD UART (J16). Both PMOD SPI and PMOD UART can output either 3.3V or 5V while PMOD I²C only has 3.3V.

**PMOD UART (J16) — pin mapping**

| Signal | S7G2 Pin | Pin # |
|---|---|---|
| UART_CTS | P413 | 38 |
| UART_DTS | P412 | 39 |
| UART_TXD | P410 | 40 |
| UART_RXD | P411 | 41 |
| GND | — | — |
| +V | — | — |
| +V | — | — |
| GND | — | — |
| IRQ7 | P408 | 37 |
| J16_GPIO1 | P414 | 43 |
| J16_GPIO2 | P707 | 15 |
| J16_GPIO3 | P400 | 1 |

**PMOD IIC (J18) — pin mapping**

| Signal | S7G2 Pin | Pin # |
|---|---|---|
| +V | — | — |
| GND | — | — |
| J18_GPIO1 | P203 | 52 |
| J18_GPIO1 | P204 | 53 |
| I2C_SCL | P205 | 51 |
| I2C_SDA | P206 | 50 |

**PMOD SPI (J13) — pin mapping**

| Signal | S7G2 Pin | Pin # |
|---|---|---|
| SPI_SS | P103 | 129 |
| SPI_SCLK | P102 | 130 |
| SPI_MISO | P101 | 132 |
| SPI_MOSI | P100 | 131 |
| GND | — | — |
| +V | — | — |
| +V | — | — |
| GND | — | — |
| IRQ6 | P409 | 103 |
| J13_GPIO1 | P612 | 42 |
| J13_GPIO2 | P613 | 104 |
| J13_GPIO3 | P614 | 105 |

### 5.6 Arduino Compatible Port

*(Referenced on p.13 of the source document; pin-level detail not itemized beyond the Arduino connectors J6, J7, J8, J9, J11, J12 listed in the schematics below.)*

---

## 6. SA Best 2017 Schematics

### 6.1 MCU

*[Schematic: MCU sheet — file `SA_Best_2017.pdspj`, sheet 1 of 4, rev 1.0, dated 5/2/2017]*

Key elements on this sheet:
- U1 — R7FS7G2M3ADFC (S7G2 MCU, main microcontroller)
- Crystal X1 (32.768kHz) and X2 (12MHz)
- SWD header J34 (SWD I/O, SWCLK, RESET)
- Power decoupling capacitors (C1–C22, C75)
- Reset circuit: SW1 push-button, R9, C23
- Boot select jumper J1 (1-2 ROM / 2-3 USB)
- USB connector select jumper CONN-SEL3
- User LEDs LED1/LED2/LED3 (Red/Green/Yellow) with resistors R1–R3
- Full port breakout: GPIO000–GPIO077, SPI0, I2C2, SCI0, ADC (AN0–AN7), SWD/JTAG (SWDIO, SWDCLK, SWO, TDO/TDI/TMS)

### 6.1 USB

*[Schematic: USB sheet — file `SA_Best_2017.pdspj`, sheet 2 of 4, rev 1.0, dated 5/2/2017]*

Key elements on this sheet:
- USB Device connector J3 (USB_VBUS, D+, D-, GND, shield)
- USB custom connector J4 (USBH_VBUS, D+, D-, GND)
- Power switch U2 (MAX0307-type current-limited load switch) with R11/R12, C24, R13, R10, D1 (5V zener)
- LDO regulators: U4 (5V rail), U6 (MPD8003-13, +3.3VANL rail), U3 (MP5043-based PSU, +3V3 rail)
- Associated decoupling capacitors (C28–C56)
- PSU section labelled "PSU"; USB section labelled "USB"

### 6.2 Connectivity

*[Schematic: Connectivity sheet — file `SA_Best_2017.pdspj`, sheet 3 of 4, rev 1.0, dated 5/2/2017]*

Sheet sections (left to right, top to bottom):
- **UART INTERFACE** — J16 (PMOD UART, Arduino-DL12), R26, C39, J17 (CONN-SEL3)
- **SPI INTERFACE** — J13 (PMOD SPI, Arduino-DL12), R25, C38, J14 (CONN-SEL3)
- **QSPI** — U7 (QSPI flash footprint), R17–R22, C36
- **IIC INTERFACE** — J18 (PMOD IIC, Arduino-DL6)
- **VIBRATION SWITCH** — SW2 (Sensolute switch, MV5049), R23, R24, C37, J10 (CONN-BL2)
- **ETHERNET** — J5 (Arduino-DL14 style connector for PHY)
- **GRAPHICS INTERFACE** — J15 (Arduino-DL38)
- **ARDUINO** — connectors J6, J7 (ARD_SDA/SDA2), J8, J9, J11, J12 (Arduino-DL8/DL14/DL16/DL18 style), including RESET line

### 6.3 J-Link

*[Schematic: J-Link sheet — file `SA_Best_2017.pdspj`, sheet 4 of 4, rev 1.0, dated 5/2/2017]*

Key elements on this sheet, labelled **"SEGGER J-LINK"**:
- U8 — R5F5192H6DFP (Renesas RX MCU used as the on-board J-Link debug probe)
- Crystal X3 (12MHz), C50/C51
- Reset/test circuit: R39, R40, R31/R32 with LED2B (J-Link status LED)
- SWD/JTAG interface to target: TDI, TDO, TMS/SWDIO, TCK/SWDCLK, SWO, RESET, TEST
- Debug header J20 (10-pin needle header)
- J19 — USB connector (shield/GND) to host PC, with associated decoupling (C40–C46) and D2 (5V/5V_USB zener/diode)
- LDO regulator U9 (MP5043-based, +3V3_JLINK rail), C53–C56
- Arduino connector J2 (Arduino-DL8) and LED4 with R41

---

## 7. R7FS7G2 MCU — Full Specification, Board Capabilities & Applications

> **Sourcing note:** This section is not part of the original SA BEST 2017 datasheet — it supplements it with manufacturer data pulled from Renesas' official S7G2 datasheet, product page, and user's manual (Renesas Synergy™ Platform, S7G2 Microcontroller Group). The schematic on p.14 of the source document silkscreens the MCU designator as **"R7FS7G2M3ADFC"**; that exact suffix doesn't match Renesas' published part-numbering scheme (no "M" appears in any position of the official code) and is most likely an artifact of the low-resolution schematic text. Given the manual explicitly states a **176-pin LQFP** package (Section 1.1, p.2), the part is almost certainly one of the two 176-pin LQFP S7G2 superset devices below — identical in every spec except flash size:
>
> | Part Number | Code Flash | Best match if... |
> |---|---|---|
> | **R7FS7G27G3A01CFC** | 3 MB | board uses the base-flash SKU |
> | **R7FS7G27H3A01CFC** | 4 MB | board uses the max-flash SKU |
>
> All specifications below apply equally to both, except where flash size is called out.

### 7.1 Part Numbering (Renesas Synergy S7G2 scheme)

```
R7FS7G2 7 H 3 A 01 C FC # AA0
        │ │ │ │ │  │ │  └─ Packing / terminal finish
        │ │ │ │ │  │ └──── Package type (FC = 176-pin LQFP)
        │ │ │ │ │  └────── Quality ID
        │ │ │ │ └───────── Product identification code (01)
        │ │ │ └─────────── Feature set (A = Superset)
        │ │ └───────────── Operating temperature (2 = -40…85°C, 3 = -40…105°C)
        │ └─────────────── Code flash size (G = 3MB, H = 4MB)
        └───────────────── Series name (7 = High-performance Synergy family)
Group name "G2" = S7G2 Group, Arm Cortex-M4, 240MHz
```

Package options across the whole S7G2 group: LFBGA224 (13×13mm, 0.8mm pitch), LFBGA176 (13×13mm, 0.8mm pitch), TFLGA145 (7×7mm, 0.5mm pitch), LQFP100 (14×14mm), LQFP144 (20×20mm), and **LQFP176 (24×24mm, 0.5mm pitch)** — the package used on this board.

### 7.2 Core & Architecture

| Parameter | Specification |
|---|---|
| CPU core | Arm® Cortex®-M4 with Floating Point Unit (FPU), Armv7E-M architecture, DSP instruction set |
| Max operating frequency | **240 MHz** |
| Address space | Up to 4 GB |
| On-chip debug | JTAG, SWD, ETM (Embedded Trace Macrocell), boundary scan |
| Memory protection | Arm Memory Protection Unit (MPU) |
| DMA controller | 8 channels |

### 7.3 Memory

| Parameter | Specification |
|---|---|
| Code flash | 3 MB (G-suffix) or 4 MB (H-suffix) |
| Data flash | 64 KB |
| SRAM | 640 KB |

### 7.4 Power & Environment

| Parameter | Specification |
|---|---|
| Supply voltage | 2.7 V – 3.6 V |
| Operating temperature | -40°C to +105°C (temp-code "3" variant, as fitted here) |
| Battery backup | Dedicated battery-backup domain covering RTC, sub-clock oscillator, backup memory, and automatic VCC/VBATT switchover |
| Clock sources | Main oscillator, sub-clock (32.768 kHz), on-chip high-speed/low-speed oscillators |

### 7.5 Package / Pin Count (176-pin LQFP variant fitted to this board)

| Parameter | Specification |
|---|---|
| Package | LQFP, 176 pins, 24×24×1.7 mm body, 0.5 mm pitch |
| General-purpose I/O | 126 pins |
| 12-bit ADC channels | ~21 channels |
| 12-bit DAC channels | 2 channels |
| Capacitive Touch (CTSU) electrodes | up to 12 channels |

### 7.6 Communications & Connectivity Peripherals

| Peripheral | Channels / Notes |
|---|---|
| Ethernet MAC | 1 channel, 10M/100M, with **IEEE 1588 PTP** (precision time protocol) hardware timestamping |
| USB 2.0 High-Speed | 1 host + 1 device channel |
| USB 2.0 Full-Speed | 1 host + 1 device channel |
| SCI / UART | 10 channels |
| SPI | 2 channels |
| I²C | 2–3 channels |
| CAN | 2 channels *(present on-die; not broken out to a connector on this particular board)* |
| SDHI (SD/MMC host) | 2 channels |
| Quad SPI | 1 channel (used for the on-board QSPI flash footprint) |

### 7.7 Timers & Motor/Analog Control

| Peripheral | Channels / Notes |
|---|---|
| 32-bit general timer | 12–14 channels |
| High-Resolution PWM timer | Yes — fine-grained PWM suited to power conversion / motor control |
| PWM output pins | Up to 24–28 |
| Async General-Purpose/Interval Timer | 2 channels |
| Standby-operable timer | Yes (keeps running in low-power modes) |

### 7.8 Graphics, HMI & Multimedia

| Peripheral | Notes |
|---|---|
| Graphics LCD Controller | Direct TFT LCD panel driving (used via connector J15 on this board, see §3.9) |
| 2D Drawing Engine | Hardware-accelerated fills, blits, and alpha blending, offloading the CPU for GUI rendering |
| Image Codec | JPEG hardware codec |
| Capacitive Touch Sensing Unit (CTSU) | On-die touch-sense front end (not populated on this board, but pin-available) |

### 7.9 Security & Safety

| Feature | Notes |
|---|---|
| Unique ID | Factory-programmed per-device identifier |
| True Random Number Generator (TRNG) | Hardware entropy source |
| Symmetric crypto | AES-128/192/256, 3DES, ARC4 |
| Asymmetric crypto | ECC, RSA, DSA |
| Hashing | SHA-1, SHA-224, SHA-256, GHASH |
| Functional safety | Safety-oriented features supported (per Renesas safety documentation) |

### 7.10 What This MCU Enables on the SA-BEST 2017 Board

Mapping the S7G2's on-die capabilities to what's actually wired up on this specific board (Sections 1–6 above):

- **USB Host + USB Device, simultaneously** — the S7G2's dual USB Full-/High-Speed controllers are why the board can act as a USB host (J4, powering peripherals) *and* a USB device (J3, for flashing/enumerating to a PC) at the same time, without external USB bridge silicon.
- **Direct graphics LCD driving** — the on-chip Graphics LCD Controller + 2D drawing engine is what lets connector J15 drive a display directly from the MCU, with no external LCD controller IC needed.
- **Ethernet-ready with almost no extra silicon** — the MCU's onboard MAC (with IEEE 1588 PTP) means connector J5 only needs to break out to an external PHY; all MAC-layer and precision-timing logic is already on-die.
- **QSPI expansion** — the MCU's native Quad-SPI controller is what the U7 footprint (Section 3.7 / 6.2) is provisioned for, letting the board add external serial NOR flash for larger data logging or OTA firmware images without touching the internal 3–4 MB code flash.
- **Analog front end already on-chip** — the DAC output called out in Section 1.3, and the AN6 vibration-sensor input (Section 3.6), both use the MCU's built-in 12-bit DAC/ADC blocks rather than external converters.
- **PMOD flexibility from shared peripheral blocks** — the same SPI/I²C/SCI hardware blocks that back the PMOD SPI (J13), PMOD IIC (J18) and PMOD UART (J16) connectors are general-purpose peripherals shared with the Arduino header, which is why jumpers (J14/J17) are needed to arbitrate 3.3V vs 5V signalling rather than needing separate silicon per interface.
- **Native JTAG/SWD + ETM** — this is what the onboard SEGGER J-Link debugger (Section 3.1 / 6.3) talks to; ETM trace support also means, with the right J-Link variant, instruction trace/profiling is possible beyond basic breakpoint debugging.
- **Headroom that isn't used on this board** — CAN (2 channels) and the Capacitive Touch Sensing Unit are present on the silicon but not broken out on the SA-BEST 2017 board, meaning derivative board designs could add a CAN transceiver or touch buttons/sliders without changing MCU.

### 7.11 Possible Applications

Given the combination of a 240 MHz Cortex-M4, hardware graphics acceleration, Ethernet with PTP, dual USB, and generous flash/RAM, Renesas positions the S7G2 group — and by extension this board — for:

- **Industrial process control & automation** — Renesas' own stated primary application for the S7G2 group; the CAN/Ethernet/PTP combination suits distributed control and time-synchronised industrial networks.
- **Human-Machine Interfaces (HMI)** — the graphics LCD controller + 2D drawing engine + capacitive touch front end are purpose-built for embedded touchscreen panels (e.g. equipment control panels, appliance displays).
- **IoT gateways / connected devices** — Ethernet MAC, dual USB, QSPI expansion, and a security block (AES/RSA/SHA/TRNG) cover the connectivity and secure-boot/secure-communication needs of an IoT edge node.
- **Metering & data acquisition** — the ADC/DAC front end, SDHI (SD card logging), and QSPI flash expansion suit power/utility metering or sensor data-logging applications — relevant given the ADE9000-based metering firmware work already tracked in your notes.
- **Motor control / power conversion** — the High-Resolution PWM timer and rich 32-bit timer set are aimed at motor-drive and power-electronics control loops.
- **Time-synchronised networked control** — IEEE 1588 PTP hardware timestamping on the Ethernet MAC targets applications needing sub-microsecond clock sync across a network (e.g. synchronised measurement/control nodes).
- **General-purpose rapid prototyping** — as the manual itself states (Section 1.1), the low-cost, breakout-everything design of this specific board makes it equally suited to quick evaluation, teaching/training use (its original SA-BEST 2017 seminar purpose), or as the core of a finished low-volume product.

### 7.12 Key Feature Summary

- 240 MHz Arm Cortex-M4 + FPU, DSP instructions, 8-channel DMA
- 3–4 MB code flash, 64 KB data flash, 640 KB SRAM
- 126 GPIO, ~21-channel 12-bit ADC, 2-channel 12-bit DAC
- Ethernet MAC with IEEE 1588 PTP
- USB 2.0 Full-Speed **and** High-Speed, each with Host + Device
- Graphics LCD controller with 2D drawing engine and JPEG codec
- Capacitive Touch Sensing Unit (up to 12 electrodes)
- 2× CAN, 10× SCI/UART, 2× SPI, 2–3× I²C, 2× SDHI, Quad-SPI
- High-resolution PWM + 12–14 channel 32-bit timers
- Hardware security: TRNG, AES/3DES/ARC4, ECC/RSA/DSA, SHA-1/224/256, GHASH, unique ID
- 2.7–3.6 V supply, -40°C to +105°C operation, battery-backed RTC domain

*Sources: Renesas S7G2 Microcontroller Group Datasheet (R01DS0262EU0150, Rev.1.50, Sep 2025) and the Renesas S7G2 product page (renesas.com/en/products/s7g2), current as of August 2026.*

---

## 8. Implementable Features — Suggested Learning Projects

The following 10 features map directly to on-board hardware and the SSP HAL drivers already configured in `configuration.xml`. They are ordered from simplest (GPIO only) to most advanced (networking + GUI). Each feature lists the hardware resource, the SSP driver instance, and the key API entry points.

| # | Feature | Hardware Resource | SSP Driver (Instance) | Key APIs | Difficulty |
|---|---------|-------------------|----------------------|----------|------------|
| 1 | **LED Blinker** | LED1 (P305, active low), LED2 (P801, active high) | r_ioport (`g_ioport`) | `pinDirectionSet`, `pinWrite`, `R_BSP_SoftwareDelay` | Beginner |
| 2 | **USB Device CDC Console** | USB Device J3 (USB_DM/DP, P407 VBUS monitor) | r_usb_basic *(add via SSP GUI)* | `usbOpen`, CDC read/write callbacks | Advanced |
| 3 | **Switch Input + Debounce** | SW1 reset, vibration sensor SW2 (P006/IRQ7) | r_ioport + r_elc (`g_elc`) | `pinRead`, IRQ callback, software debounce | Beginner |
| 4 | **ADC Sampling** | Potentiometer (AN0/P000), vibration sensor (AN6/P006) | r_adc (`g_adc0`) | `adcOpen`, `adcScanStart`, `adcRead`, `adcClose` | Beginner |
| 5 | **DAC Waveform Generation** | DAC0 output (DA0/P014), DAC1 output | r_dac (`g_dac0`, `g_dac1`) | `dacOpen`, `dacWrite`, `dacClose` | Intermediate |
| 6 | **PWM Controller** | GPT1 PWM output (P405/GTIOCA) | r_gpt (`g_timer0`) | `timerOpen`, `timerDutyCycleSet`, `timerStart`, `timerStop` | Intermediate |
| 7 | **PMOD UART Console** | PMOD UART J16 (P410 RXD, P411 TXD, P412 DTS, P413 CTS) | r_sci_uart (`g_uart0`) + r_dtc (`g_transfer0/1`) | `uartOpen`, `uartWrite`, `uartRead`, callback | Intermediate |
| 8 | **PMOD SPI Master** | PMOD SPI J13 (P100 MOSI, P101 MISO, P102 SCK, P103 SSL) | r_sci_spi (`g_spi0`) | `spiOpen`, `spiWrite`, `spiRead`, `spiClose` | Intermediate |
| 9 | **PMOD I2C Master** | PMOD IIC J18 (P205 SCL, P206 SDA, P203/P204 GPIO) | r_iic *(add via SSP GUI)* | `iicOpen`, `iicMasterWrite`, `iicMasterRead` | Intermediate |
| 10 | **Graphics LCD Display** | Graphics LCD J15 (P111-P115, GLCDC) | r_glcd + r_drw *(add via SSP GUI)* | `glcdOpen`, `glcdStart`, `gx_canvas` drawing APIs | Advanced |

### Implementation Notes

- **Features 1, 3-8** are ready to implement immediately — their SSP driver instances are already generated in `src/synergy_gen/hal_data.c`.
- **Features 2, 9, 10** require adding `r_usb_basic`, `r_iic`, and `r_glcd`/`r_drw` drivers respectively via the SSP Configurator GUI (see `SSP_CONFIGURATOR_GUIDE.md` Step 4).
- **ThreadX RTOS** is bundled with SSP and can be used to run multiple features concurrently as separate threads.
- **CAN** (2 channels on P511/P512) and **Ethernet** (RMII0 on J5) are additional advanced features not in the top-10 list but are documented in `SSP_CONFIGURATOR_GUIDE.md`.
- See **`FEATURES.md`** for a concise feature-name reference.

---

*End of mirrored content — SABest-2017-RSP-datasheet.pdf (17 pages, Renesas Synergy S7G2 "SA-BEST 2017" Target Board Hardware User Manual), extended with Section 7 (MCU full specification, board capabilities, and applications) from Renesas' published S7G2 documentation, and Section 8 (implementable features).*
*Note: Figures/photos and full schematic drawings are visual/graphical elements in the source PDF and are referenced here by their captions rather than reproduced as images.*
