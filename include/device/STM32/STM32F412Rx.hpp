/**
 * @file   let/include/device/STM32/STM32F412Rx.hpp
 * @author Peter Züger
 * @date   18.12.2018
 * @brief  STM32F412Rx register offsets
 *
 * This file is part of let (https://gitlab.com/peterzuger/let).
 * Copyright (c) 2019 Peter Züger.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LET_DEVICE_STM32_STM32F412RX_HPP
#define LET_DEVICE_STM32_STM32F412RX_HPP

namespace let{
    namespace ADC{
        constexpr auto ADC1                       = 0x40012000;

        namespace R{
            constexpr auto SR                     = 0x00;         // status register
            constexpr auto CR1                    = 0x04;         // control register 1
            constexpr auto CR2                    = 0x08;         // control register 2
            constexpr auto SMPR1                  = 0x0C;         // sample time register 1
            constexpr auto SMPR2                  = 0x10;         // sample time register 2
            constexpr auto JOFR1                  = 0x14;         // injected channel data offset register 1
            constexpr auto JOFR2                  = 0x18;         // injected channel data offset register 2
            constexpr auto JOFR3                  = 0x1C;         // injected channel data offset register 3
            constexpr auto JOFR4                  = 0x20;         // injected channel data offset register 4
            constexpr auto HTR                    = 0x24;         // watchdog higher threshold register
            constexpr auto LTR                    = 0x28;         // watchdog lower threshhold register
            constexpr auto SQR1                   = 0x2C;         // sequence register 1
            constexpr auto SQR2                   = 0x30;         // sequence register 2
            constexpr auto SQR3                   = 0x34;         // sequence register 3
            constexpr auto JSQR                   = 0x38;         // injected sequence register
            constexpr auto JDR1                   = 0x3C;         // injected data register 1
            constexpr auto JDR2                   = 0x40;         // injected data register 2
            constexpr auto JDR3                   = 0x44;         // injected data register 3
            constexpr auto JDR4                   = 0x48;         // injected data register 4
            constexpr auto DR                     = 0x4C;         // data register

            constexpr auto COMMON                 = 0x300;        // ADC common register offset

            constexpr auto CSR                    = 0x00;         // common status register
            constexpr auto CCR                    = 0x04;         // common control register
        }

        namespace B{
            // SR
            constexpr auto OVR                    = 1 << 5;       // Overrun
            constexpr auto STRT                   = 1 << 4;       // Start Flag
            constexpr auto JSTRT                  = 1 << 3;       // Injected Channel Start Flag
            constexpr auto JEOC                   = 1 << 2;       // Injected Channel End of Conversion
            constexpr auto EOC                    = 1 << 1;       // End of conversion
            constexpr auto AWD                    = 1 << 0;       // Analog Watchdog

            // CR1
            constexpr auto OVRIE                  = 1 << 26;      // Overrun Interrupt Enable
            constexpr auto RES_12bit              = 0b00 << 24;   // Resolution: 12-bit (minimum 15 ADCCLK cycles)
            constexpr auto RES_10bit              = 0b01 << 24;   // Resolution: 10-bit (minimum 13 ADCCLK cycles)
            constexpr auto RES_8bit               = 0b10 << 24;   // Resolution: 8-bit (minimum 11 ADCCLK cycles)
            constexpr auto RES_6bit               = 0b11 << 24;   // Resolution: 6-bit (minimum 9 ADCCLK cycles)
            constexpr auto AWDEN                  = 1 << 23;      // Analog Watchdog Enable
            constexpr auto JAWDEN                 = 1 << 22;      // Analog Watchdog Enable on Injected Channels
            constexpr auto JDISCEN                = 1 << 12;      // Discontinuous mode on injected channels
            constexpr auto DISCEN                 = 1 << 11;      // Discontinuous mode
            constexpr auto JAUTO                  = 1 << 10;      // Automatic injected group conversion
            constexpr auto AWDSGL                 = 1 << 9;       // Enable Watchdog on a single channel in scan mode
            constexpr auto SCAN                   = 1 << 8;       // Scan mode
            constexpr auto JEOCIE                 = 1 << 7;       // Interrupt enable for Injected Channels
            constexpr auto AWDIE                  = 1 << 6;       // Analog Watchdog Interrupt Enable
            constexpr auto EOCIE                  = 1 << 5;       // Interrupt Enable for EOC
                                                                  // 18 Analog Watchdog Channels

            // CR2
            constexpr auto SWSTART                = 1 << 30;      // Start conversion
            constexpr auto EXTEN_DISABLE          = 0b00 << 28;   // Trigger detection disabled
            constexpr auto EXTEN_RISING           = 0b00 << 28;   // Trigger detection on the rising edge
            constexpr auto EXTEN_FALLING          = 0b00 << 28;   // Trigger detection on the falling edge
            constexpr auto EXTEN_BOTH             = 0b00 << 28;   // Trigger detection on both the rising and falling edges
            constexpr auto EXTSEL_T1CC1           = 0b0000 << 24; // Timer 1 CC1 event
            constexpr auto EXTSEL_T1CC2           = 0b0001 << 24; // Timer 1 CC2 event
            constexpr auto EXTSEL_T1CC3           = 0b0010 << 24; // Timer 1 CC3 event
            constexpr auto EXTSEL_T2CC2           = 0b0011 << 24; // Timer 2 CC2 event
            constexpr auto EXTSEL_T2CC3           = 0b0100 << 24; // Timer 2 CC3 event
            constexpr auto EXTSEL_T2CC4           = 0b0101 << 24; // Timer 2 CC4 event
            constexpr auto EXTSEL_T2TRGO          = 0b0110 << 24; // Timer 2 TRGO event
            constexpr auto EXTSEL_T3CC1           = 0b0111 << 24; // Timer 3 CC1 event
            constexpr auto EXTSEL_T3TRGO          = 0b1000 << 24; // Timer 3 TRGO event
            constexpr auto EXTSEL_T4CC4           = 0b1001 << 24; // Timer 4 CC4 event
            constexpr auto EXTSEL_T5CC1           = 0b1010 << 24; // Timer 5 CC1 event
            constexpr auto EXTSEL_T5CC2           = 0b1011 << 24; // Timer 5 CC2 event
            constexpr auto EXTSEL_T5CC3           = 0b1100 << 24; // Timer 5 CC3 event
            constexpr auto EXTSEL_T8CC1           = 0b1101 << 24; // Timer 8 CC1 event
            constexpr auto EXTSEL_T8TRGO          = 0b1110 << 24; // Timer 8 TRGO event
            constexpr auto EXTSEL_EXTI            = 0b1111 << 24; // EXTI line 11
            constexpr auto JSWSTART               = 1 << 22;      // Start conversion of Injected Channels
            constexpr auto JEXTEN_DISABLE         = 0b00 << 20;   // Trigger detection disabled for Injected Channels
            constexpr auto JEXTEN_RISING          = 0b00 << 20;   // Trigger detection on the rising edge for Injected Channels
            constexpr auto JEXTEN_FALLING         = 0b00 << 20;   // Trigger detection on the falling edge for Injected Channels
            constexpr auto JEXTEN_BOTH            = 0b00 << 20;   // Trigger detection on both the rising and falling edges for Injected Channels
            constexpr auto JEXTSEL_T1CC4          = 0b0000 << 16; // Timer 1 CC4 event
            constexpr auto JEXTSEL_T1TRGO         = 0b0001 << 16; // Timer 1 TRGO event
            constexpr auto JEXTSEL_T2CC1          = 0b0010 << 16; // Timer 2 CC1 event
            constexpr auto JEXTSEL_T2TRGO         = 0b0011 << 16; // Timer 2 TRGO event
            constexpr auto JEXTSEL_T3CC2          = 0b0100 << 16; // Timer 3 CC2 event
            constexpr auto JEXTSEL_T3CC4          = 0b0101 << 16; // Timer 3 CC4 event
            constexpr auto JEXTSEL_T4CC1          = 0b0110 << 16; // Timer 4 CC1 event
            constexpr auto JEXTSEL_T4CC2          = 0b0111 << 16; // Timer 4 CC2 event
            constexpr auto JEXTSEL_T4CC3          = 0b1000 << 16; // Timer 4 CC3 event
            constexpr auto JEXTSEL_T4TRGO         = 0b1001 << 16; // Timer 4 TRGO event
            constexpr auto JEXTSEL_T5CC4          = 0b1010 << 16; // Timer 5 CC4 event
            constexpr auto JEXTSEL_T5TRGO         = 0b1011 << 16; // Timer 5 TRGO event
            constexpr auto JEXTSEL_T8CC2          = 0b1100 << 16; // Timer 8 CC2 event
            constexpr auto JEXTSEL_T8CC3          = 0b1101 << 16; // Timer 8 CC3 event
            constexpr auto JEXTSEL_T8CC4          = 0b1110 << 16; // Timer 8 CC4 event
            constexpr auto JEXTSEL_EXTI           = 0b1111 << 16; // EXTI line15
            constexpr auto ALIGN                  = 1 << 11;      // Data Alignment
            constexpr auto EOCS                   = 1 << 10;      // End of Conversion Selection
            constexpr auto DDS                    = 1 << 9;       // DMA disable selection
            constexpr auto DMA                    = 1 << 8;       // DMA mode
            constexpr auto CONT                   = 1 << 1;       // Continuous mode
            constexpr auto ADON                   = 1 << 0;       // AD converter ON/OFF

            // SMPR1 (CH 10-18)
            // SMPR2 (CH 0-9)
            constexpr auto SMPx_CHS               = 3;
            constexpr auto SMPx3                  = 0b000;        // Channel x sample time selection
            constexpr auto SMPx15                 = 0b001;        // Channel x sample time selection
            constexpr auto SMPx28                 = 0b010;        // Channel x sample time selection
            constexpr auto SMPx56                 = 0b011;        // Channel x sample time selection
            constexpr auto SMPx84                 = 0b100;        // Channel x sample time selection
            constexpr auto SMPx112                = 0b101;        // Channel x sample time selection
            constexpr auto SMPx144                = 0b110;        // Channel x sample time selection
            constexpr auto SMPx480                = 0b111;        // Channel x sample time selection

            // JOFR1

            // JOFR2

            // JOFR3

            // JOFR4

            // HTR

            // LTR

            // SQR1

            // SQR2

            // SQR3

            // JSQR

            // JDR1

            // JDR2

            // JDR3

            // JDR4

            // DR

            // CSR
            constexpr auto OVR1                   = 1 << 5;       // Overrun Flag of ADC1
            constexpr auto STRT1                  = 1 << 4;       // Start flag of ADC1
            constexpr auto JSTRT1                 = 1 << 3;       // Injected Channel Start Flag of ADC1
            constexpr auto JEOC1                  = 1 << 2;       // Injected Channel End of conversion of ADC1
            constexpr auto EOC1                   = 1 << 1;       // End of conversion of ADC1
            constexpr auto AWD1                   = 1 << 0;       // Analog Watchdog flag of ADC1

            // CCR
            constexpr auto TSVREFE                = 1 << 23;      // Temperature sensor and VREFINT enable
            constexpr auto VBATE                  = 1 << 22;      // VBAT enable
            constexpr auto ADCPRE2                = 0b00 << 16;   // ADC Prescaler PCLK2 / 2
            constexpr auto ADCPRE4                = 0b01 << 16;   // ADC Prescaler PCLK2 / 4
            constexpr auto ADCPRE6                = 0b10 << 16;   // ADC Prescaler PCLK2 / 6
            constexpr auto ADCPRE8                = 0b11 << 16;   // ADC Prescaler PCLK2 / 8
        }
    }

    namespace CRC{
        constexpr auto CRC1                       = 0x40023000;

        namespace R{
            constexpr auto DR                     = 0x00;         // Data register
            constexpr auto IDR                    = 0x04;         // Independent data register
            constexpr auto CR                     = 0x08;         // Control register
        }

        namespace B{
            // CR
            constexpr auto RESET                  = 1 << 0;       // RESET CRC value
        }
    }

    namespace DMA{
        constexpr auto DMA1                       = 0x40026000;
        constexpr auto DMA2                       = 0x40026400;

        namespace R{
            constexpr auto LISR                   = 0x00;         // DMA interrupt status register
            constexpr auto HISR                   = 0x00;         // DMA interrupt status register
            constexpr auto LIFCR                  = 0x04;         // DMA interrupt flag clear register
            constexpr auto HIFCR                  = 0x04;         // DMA interrupt flag clear register
            constexpr auto CCRx                   = 0x08;         // DMA channel x configuration register -->  Address offset: 0x08 + 0x14 * (x - 1), (x = 1 to 7)
            constexpr auto CNDTRx                 = 0x0C;         // DMA channel x number of data to transfer register
            constexpr auto CPARx                  = 0x10;         // DMA channel x peripheral address register
            constexpr auto CMARx                  = 0x14;         // DMA channel x memory address register
            constexpr auto CSELR                  = 0xA8;         // DMA channel selection register
        }

        namespace B{
            // ISR
            constexpr auto TEIF7                  = 1 << 27;      // transfer error (TE) flag for channel 7
            constexpr auto HTIF7                  = 1 << 26;      // half transfer (HT) flag for channel 7
            constexpr auto TCIF7                  = 1 << 25;      // transfer complete (TC) flag for channel 7
            constexpr auto GIF7                   = 1 << 24;      // global interrupt flag for channel 7
            constexpr auto TEIF6                  = 1 << 23;      // transfer error (TE) flag for channel 6
            constexpr auto HTIF6                  = 1 << 22;      // half transfer (HT) flag for channel 6
            constexpr auto TCIF6                  = 1 << 21;      // transfer complete (TC) flag for channel 6
            constexpr auto GIF6                   = 1 << 20;      // global interrupt flag for channel 6
            constexpr auto TEIF5                  = 1 << 19;      // transfer error (TE) flag for channel 5
            constexpr auto HTIF5                  = 1 << 18;      // half transfer (HT) flag for channel 5
            constexpr auto TCIF5                  = 1 << 17;      // transfer complete (TC) flag for channel 5
            constexpr auto GIF5                   = 1 << 16;      // global interrupt flag for channel 5
            constexpr auto TEIF4                  = 1 << 15;      // transfer error (TE) flag for channel 4
            constexpr auto HTIF4                  = 1 << 14;      // half transfer (HT) flag for channel 4
            constexpr auto TCIF4                  = 1 << 13;      // transfer complete (TC) flag for channel 4
            constexpr auto GIF4                   = 1 << 12;      // global interrupt flag for channel 4
            constexpr auto TEIF3                  = 1 << 11;      // transfer error (TE) flag for channel 3
            constexpr auto HTIF3                  = 1 << 10;      // half transfer (HT) flag for channel 3
            constexpr auto TCIF3                  = 1 << 9;       // transfer complete (TC) flag for channel 3
            constexpr auto GIF3                   = 1 << 8;       // global interrupt flag for channel 3
            constexpr auto TEIF2                  = 1 << 7;       // transfer error (TE) flag for channel 2
            constexpr auto HTIF2                  = 1 << 6;       // half transfer (HT) flag for channel 2
            constexpr auto TCIF2                  = 1 << 5;       // transfer complete (TC) flag for channel 2
            constexpr auto GIF2                   = 1 << 4;       // global interrupt flag for channel 2
            constexpr auto TEIF1                  = 1 << 3;       // transfer error (TE) flag for channel 1
            constexpr auto HTIF1                  = 1 << 2;       // half transfer (HT) flag for channel 1
            constexpr auto TCIF1                  = 1 << 1;       // transfer complete (TC) flag for channel 1
            constexpr auto GIF1                   = 1 << 0;       // global interrupt flag for channel 1

            // IFCR
            constexpr auto CTEIF7                 = 1 << 27;      // transfer error flag clear for channel 7
            constexpr auto CHTIF7                 = 1 << 26;      // half transfer flag clear for channel 7
            constexpr auto CTCIF7                 = 1 << 25;      // transfer complete flag clear for channel 7
            constexpr auto CGIIF7                 = 1 << 24;      // global interrupt flag clear for channel 7
            constexpr auto CTEIF6                 = 1 << 23;      // transfer error flag clear for channel 6
            constexpr auto CHTIF6                 = 1 << 22;      // half transfer flag clear for channel 6
            constexpr auto CTCIF6                 = 1 << 21;      // transfer complete flag clear for channel 6
            constexpr auto CGIIF6                 = 1 << 20;      // global interrupt flag clear for channel 6
            constexpr auto CTEIF5                 = 1 << 19;      // transfer error flag clear for channel 5
            constexpr auto CHTIF5                 = 1 << 18;      // half transfer flag clear for channel 5
            constexpr auto CTCIF5                 = 1 << 17;      // transfer complete flag clear for channel 5
            constexpr auto CGIIF5                 = 1 << 16;      // global interrupt flag clear for channel 5
            constexpr auto CTEIF4                 = 1 << 15;      // transfer error flag clear for channel 4
            constexpr auto CHTIF4                 = 1 << 14;      // half transfer flag clear for channel 4
            constexpr auto CTCIF4                 = 1 << 13;      // transfer complete flag clear for channel 4
            constexpr auto CGIIF4                 = 1 << 12;      // global interrupt flag clear for channel 4
            constexpr auto CTEIF3                 = 1 << 11;      // transfer error flag clear for channel 3
            constexpr auto CHTIF3                 = 1 << 10;      // half transfer flag clear for channel 3
            constexpr auto CTCIF3                 = 1 << 9;       // transfer complete flag clear for channel 3
            constexpr auto CGIIF3                 = 1 << 8;       // global interrupt flag clear for channel 3
            constexpr auto CTEIF2                 = 1 << 7;       // transfer error flag clear for channel 2
            constexpr auto CHTIF2                 = 1 << 6;       // half transfer flag clear for channel 2
            constexpr auto CTCIF2                 = 1 << 5;       // transfer complete flag clear for channel 2
            constexpr auto CGIIF2                 = 1 << 4;       // global interrupt flag clear for channel 2
            constexpr auto CTEIF1                 = 1 << 3;       // transfer error flag clear for channel 1
            constexpr auto CHTIF1                 = 1 << 2;       // half transfer flag clear for channel 1
            constexpr auto CTCIF1                 = 1 << 1;       // transfer complete flag clear for channel 1
            constexpr auto CGIIF1                 = 1 << 0;       // global interrupt flag clear for channel 1

            // CCRx
            constexpr auto MEM2MEM                = 1 << 14;      // memory-to-memory mode
            constexpr auto MINC                   = 1 << 7;       // memory increment mode
            constexpr auto PINC                   = 1 << 6;       // peripheral increment mode
            constexpr auto CIRC                   = 1 << 5;       // circular mode
            constexpr auto DIR                    = 1 << 4;       // data transfer direction
            constexpr auto TEIE                   = 1 << 3;       // transfer error interrupt enable
            constexpr auto HTIE                   = 1 << 2;       // half transfer interrupt enable
            constexpr auto TCIE                   = 1 << 1;       // transfer complete interrupt enable
            constexpr auto EN                     = 1 << 0;       // channel enable
        }
    }

    namespace FLASH{
        constexpr auto FLASH                      = 0x40023C00;

        namespace R{
            constexpr auto ACR                    = 0x00;         // access control register
            constexpr auto KEYR                   = 0x04;         // key register
            constexpr auto OPTKEYR                = 0x08;         // option key register
            constexpr auto SR                     = 0x0C;         // status register
            constexpr auto CR                     = 0x10;         // control register
            constexpr auto OPTCR                  = 0x14;         // option control register
        }

        namespace B{
            // ACR
            constexpr auto DCRST                  = 1 << 12;      // Data cache reset
            constexpr auto ICRST                  = 1 << 11;      // Instruction cache reset
            constexpr auto DCEN                   = 1 << 10;      // Data cache enable
            constexpr auto ICEN                   = 1 << 9;       // Instruction cache enable
            constexpr auto PRFTEN                 = 1 << 8;       // Prefetch enable

            // KEYR
            constexpr auto KEY1                   = 0x45670123;
            constexpr auto KEY2                   = 0xCDEF89AB;

            // OPTKEYR
            constexpr auto OPTKEY1                = 0x08192A3B;
            constexpr auto OPTKEY2                = 0x4C5D6E7F;

            // SR
            constexpr auto BSY                    = 1 << 16;      // Busy
            constexpr auto RDERR                  = 1 << 8;       // Read Protection Error (PCROP)
            constexpr auto PGSERR                 = 1 << 7;       // Programming sequence error
            constexpr auto PGPERR                 = 1 << 6;       // Programming parallelism error
            constexpr auto PGAERR                 = 1 << 5;       // Programming alignment error
            constexpr auto WRPERR                 = 1 << 4;       // Write protection error
            constexpr auto OPERR                  = 1 << 1;       // Operation error
            constexpr auto EOP                    = 1 << 0;       // End of operation

            // CR
            constexpr auto LOCK                   = 1 << 31;      // Lock
            constexpr auto ERRIE                  = 1 << 25;      // Error interrupt enable
            constexpr auto EOPIE                  = 1 << 24;      // End of operation interrupt enable
            constexpr auto STRT                   = 1 << 16;      // Start
            constexpr auto X8                     = 0b00 << 8;    //
            constexpr auto X16                    = 0b01 << 8;    //
            constexpr auto X32                    = 0b10 << 8;    //
            constexpr auto X64                    = 0b11 << 8;    //
            constexpr auto X_MASK                 = 0b11 << 8;    // programming parallelism mask
            constexpr auto SNR_OFF                = 3;            // sector erase selection number
            constexpr auto SNR_MASK               = 0xF << 3;     // sector erase selection number
            constexpr auto MER                    = 1 << 2;       // Mass Erase
            constexpr auto SER                    = 1 << 1;       // Sector Erase
            constexpr auto PG                     = 1 << 0;       // Programming

            // OPTCR
            constexpr auto SPRMOD                 = 1 << 31;      // Selection of Protection Mode of nWPRi bits
            constexpr auto NSRT_STDBY             = 1 << 7;       // nRST_STDBY
            constexpr auto NRST_STOP              = 1 << 6;       // nRST_STOP
            constexpr auto WDG_SW                 = 1 << 5;       // WDG_SW
            constexpr auto OPTSTRT                = 1 << 1;       // Option start
            constexpr auto OPTLOCK                = 1 << 0;       // Option lock
        }
    }

    namespace GPIO{
        constexpr auto GPIOA                      = 0x40020000;
        constexpr auto GPIOB                      = 0x40020400;
        constexpr auto GPIOC                      = 0x40020800;
        constexpr auto GPIOD                      = 0x40020C00;
        constexpr auto GPIOE                      = 0x40021000;
        constexpr auto GPIOF                      = 0x40021400;
        constexpr auto GPIOG                      = 0x40021800;
        constexpr auto GPIOH                      = 0x40021C00;

        namespace R{
            constexpr auto MODER                  = 0x00;         // Port mode register
            constexpr auto OTYPER                 = 0x04;         // Port output type register
            constexpr auto OSPEEDR                = 0x08;         // Port output speed register
            constexpr auto PUPDR                  = 0x0C;         // Port pull-up/pull-down register
            constexpr auto IDR                    = 0x10;         // Port input data register
            constexpr auto ODR                    = 0x14;         // Port output data register
            constexpr auto BSRR                   = 0x18;         // Port bit set/reset register
            constexpr auto LCKR                   = 0x1C;         // Port configuration lock register
            constexpr auto AFRL                   = 0x20;         // Alternate function low register
            constexpr auto AFRH                   = 0x24;         // Alternate function high register
        }

        namespace B{
            // MODER
            constexpr auto Input                  = 0b00;         // GPIO pin input mode mask
            constexpr auto Output                 = 0b01;         // GPIO pin output mode mask
            constexpr auto Alternate              = 0b10;         // GPIO pin alternate mode mask
            constexpr auto Analog                 = 0b11;         // GPIO pin analog mode mask

            // OTYPER
            constexpr auto PushPull               = 0b0;          // GPIO pin push pull mode
            constexpr auto OpenDrain              = 0b1;          // GPIO pin open drain mode

            // OSPEEDR
            constexpr auto Slow                   = 0b00;         // GPIO pin speed slow
            constexpr auto Medium                 = 0b01;         // GPIO pin speed medium
            constexpr auto Fast                   = 0b10;         // GPIO pin speed fast
            constexpr auto High                   = 0b11;         // GPIO pin speed high

            // PUPDR
            constexpr auto NoPull                 = 0b00;         // GPIO pin no pullup/down resistor
            constexpr auto Pullup                 = 0b01;         // GPIO pin pullup enabled
            constexpr auto Pulldown               = 0b10;         // GPIO pin pulldown enabled

            // LCKR
            constexpr auto LCKK                   = 1 << 16;      // Lock key
        }
    }

    namespace RCC{
        constexpr auto RCC                        = 0x40023800;

        namespace R{
            constexpr auto CR                     = 0x00;         // Clock control register
            constexpr auto PLLCFGR                = 0x04;         // PLL configuration register
            constexpr auto CFGR                   = 0x08;         // Clock configuration register
            constexpr auto CIR                    = 0x0C;         // Clock interrupt register
            constexpr auto AHB1RSTR               = 0x10;         // AHB1 peripheral reset register
            constexpr auto AHB2RSTR               = 0x14;         // AHB2 peripheral reset register
            constexpr auto AHB3RSTR               = 0x18;         // AHB3 peripheral reset register
            constexpr auto APB1RSTR               = 0x20;         // APB1 peripheral reset register
            constexpr auto APB2RSTR               = 0x24;         // APB2 peripheral reset register
            constexpr auto AHB1ENR                = 0x30;         // AHB1 peripheral clock enable register
            constexpr auto AHB2ENR                = 0x34;         // AHB2 peripheral clock enable register
            constexpr auto AHB3ENR                = 0x38;         // AHB3 peripheral clock enable register
            constexpr auto APB1ENR                = 0x40;         // APB1 peripheral clock enable register
            constexpr auto APB2ENR                = 0x44;         // APB2 peripheral clock enable register
            constexpr auto AHB1LPENR              = 0x50;         // AHB1 peripheral clock enable in low power mode register
            constexpr auto AHB2LPENR              = 0x54;         // AHB2 peripheral clock enable in low power mode register
            constexpr auto AHB3LPENR              = 0x58;         // AHB3 peripheral clock enable in low power mode register
            constexpr auto APB1LPENR              = 0x60;         // APB1 peripheral clock enable in low power mode register
            constexpr auto APB2LPENR              = 0x64;         // APB peripheral clock enable in low power mode register
            constexpr auto BDCR                   = 0x70;         // Backup domain control register
            constexpr auto CSR                    = 0x74;         // Clock control & status register
            constexpr auto SSCGR                  = 0x80;         // Spread spectrum clock generation register
            constexpr auto PLLI2SCFGR             = 0x84;         // PLLI2S configuration register
            constexpr auto DCKCF                  = 0x8C;         // Dedicated Clocks Configuration Register
            constexpr auto CKGATENR               = 0x90;         // Clocks gated enable register
            constexpr auto DCKCFGR2               = 0x94;         // Dedicated Clocks Configuration Register
        }

        namespace B{
            // CR
            constexpr auto PLLI2SRDY              = 1 << 27;      // PLLI2S clock ready flag
            constexpr auto PLLI2SON               = 1 << 26;      // PLLI2S enable
            constexpr auto PLLRDY                 = 1 << 25;      // Main PLL (PLL) clock ready flag
            constexpr auto PLLON                  = 1 << 24;      // Main PLL (PLL) enable
            constexpr auto CSSON                  = 1 << 19;      // Clock security system enable
            constexpr auto HSEBYP                 = 1 << 18;      // HSE clock bypass
            constexpr auto HSERDY                 = 1 << 17;      // HSE clock ready flag
            constexpr auto HSEON                  = 1 << 16;      // HSE clock enable
            constexpr auto HSIRDY                 = 1 << 1;       // Internal high-speed clock ready flag
            constexpr auto HSION                  = 1 << 0;       // Internal high-speed clock enable

            // PLLCFGR
            constexpr auto PLLSRC                 = 1 << 22;      // Main PLL(PLL) and audio PLL (PLLI2S) entry clock source

            // CIR
            constexpr auto CSSC                   = 1 << 23;      // Clock security system interrupt clear
            constexpr auto PLLI2SRDYC             = 1 << 21;      // PLLI2S ready interrupt clear
            constexpr auto PLLRDYC                = 1 << 20;      // Main PLL(PLL) ready interrupt clear
            constexpr auto HSERDYC                = 1 << 19;      // HSE ready interrupt clear
            constexpr auto HSIRDYC                = 1 << 18;      // HSI ready interrupt clear
            constexpr auto LSERDYC                = 1 << 17;      // LSE ready interrupt clear
            constexpr auto LSIRDYC                = 1 << 16;      // LSI ready interrupt clear
            constexpr auto PLLI2SRDYIE            = 1 << 13;      // PLLI2S ready interrupt enable
            constexpr auto PLLRDYIE               = 1 << 12;      // Main PLL (PLL) ready interrupt enable
            constexpr auto HSERDYIE               = 1 << 11;      // HSE ready interrupt enable
            constexpr auto HSIRDYIE               = 1 << 10;      // HSI ready interrupt enable
            constexpr auto LSERDYIE               = 1 << 9;       // LSE ready interrupt enable
            constexpr auto LSIRDYIE               = 1 << 8;       // LSI ready interrupt enable
            constexpr auto CSSF                   = 1 << 7;       // Clock security system interrupt flag
            constexpr auto PLLI2SRDYF             = 1 << 5;       // PLLI2S ready interrupt flag
            constexpr auto PLLRDYF                = 1 << 4;       // Main PLL (PLL) ready interrupt flag
            constexpr auto HSERDYF                = 1 << 3;       // HSE ready interrupt flag
            constexpr auto HSIRDYF                = 1 << 2;       // HSI ready interrupt flag
            constexpr auto LSERDYF                = 1 << 1;       // LSE ready interrupt flag
            constexpr auto LSIRDYF                = 1 << 0;       // LSI ready interrupt flag

            // AHB1RSTR
            constexpr auto DMA2RST                = 1 << 22;      // DMA2 reset
            constexpr auto DMA1RST                = 1 << 21;      // DMA1 reset
            constexpr auto CRCRST                 = 1 << 12;      // CRC reset
            constexpr auto GPIOHRST               = 1 << 7;       // IO port H reset
            constexpr auto GPIOGRST               = 1 << 6;       // IO port G reset
            constexpr auto GPIOFRST               = 1 << 5;       // IO port F reset
            constexpr auto GPIOERST               = 1 << 4;       // IO port E reset
            constexpr auto GPIODRST               = 1 << 3;       // IO port D reset
            constexpr auto GPIOCRST               = 1 << 2;       // IO port C reset
            constexpr auto GPIOBRST               = 1 << 1;       // IO port B reset
            constexpr auto GPIOARST               = 1 << 0;       // IO port A reset

            // AHB2RSTR
            constexpr auto OTGFSRST               = 1 << 6;       // USB OTG FS module reset
            constexpr auto RNGRST                 = 1 << 7;       // RNG module reset

            // AHB3RSTR
            constexpr auto QSPIRST                = 1 << 1;       // QUADSPI module reset
            constexpr auto FSMCRST                = 1 << 0;       // Flexible memory controller module reset

            // APB1RSTR
            constexpr auto PWRRST                 = 1 << 28;      // Power interface reset
            constexpr auto CAN2RST                = 1 << 26;      // CAN2 reset
            constexpr auto CAN1RST                = 1 << 25;      // CAN1 reset
            constexpr auto I2CFMP1RST             = 1 << 24;      // I2CFMP1 reset
            constexpr auto I2C3RST                = 1 << 23;      // I2C3 reset
            constexpr auto I2C2RST                = 1 << 22;      // I2C2 reset
            constexpr auto I2C1RST                = 1 << 21;      // I2C1 reset
            constexpr auto USART3RST              = 1 << 18;      // USART3 reset
            constexpr auto USART2RST              = 1 << 17;      // USART2 reset
            constexpr auto SPI3RST                = 1 << 15;      // SPI3 reset
            constexpr auto SPI2RST                = 1 << 14;      // SPI2 reset
            constexpr auto WWDGRST                = 1 << 11;      // Window watchdog reset
            constexpr auto TIM14RST               = 1 << 8;       // TIM14 reset
            constexpr auto TIM13RST               = 1 << 7;       // TIM13 reset
            constexpr auto TIM12RST               = 1 << 6;       // TIM12 reset
            constexpr auto TIM7RST                = 1 << 5;       // TIM7 reset
            constexpr auto TIM6RST                = 1 << 4;       // TIM6 reset
            constexpr auto TIM5RST                = 1 << 3;       // TIM5 reset
            constexpr auto TIM4RST                = 1 << 2;       // TIM4 reset
            constexpr auto TIM3RST                = 1 << 1;       // TIM3 reset
            constexpr auto TIM2RST                = 1 << 0;       // TIM2 reset

            // APB2RSTR
            constexpr auto DFSDM1RST              = 1 << 24;      // DFSDM1 reset
            constexpr auto SPI5RST                = 1 << 20;      // SPI5RST
            constexpr auto TIM11RST               = 1 << 18;      // TIM11 reset
            constexpr auto TIM10RST               = 1 << 17;      // TIM10 reset
            constexpr auto TIM9RST                = 1 << 16;      // TIM9 reset
            constexpr auto SYSCFGRST              = 1 << 14;      // System configuration controller reset
            constexpr auto SP45RST                = 1 << 13;      // SPI4 reset
            constexpr auto SPI1RST                = 1 << 12;      // SPI1 reset
            constexpr auto SDIORST                = 1 << 11;      // SDIO reset
            constexpr auto ADC1RST                = 1 << 8;       // ADC interface reset
            constexpr auto USART6RST              = 1 << 5;       // USART6 reset
            constexpr auto USART1RST              = 1 << 4;       // USART1 reset
            constexpr auto TIM8RST                = 1 << 1;       // TIM8 reset
            constexpr auto TIM1RST                = 1 << 0;       // TIM1 reset

            // AHB1ENR
            constexpr auto DMA2EN                 = 1 << 22;      // DMA2 clock enable
            constexpr auto DMA1EN                 = 1 << 21;      // DMA1 clock enable
            constexpr auto CRCEN                  = 1 << 12;      // CRC clock enable
            constexpr auto GPIOHEN                = 1 << 7;       // IO port H clock enable
            constexpr auto GPIOGEN                = 1 << 6;       // IO port G clock enable
            constexpr auto GPIOFEN                = 1 << 5;       // IO port F clock enable
            constexpr auto GPIOEEN                = 1 << 4;       // IO port E clock enable
            constexpr auto GPIODEN                = 1 << 3;       // IO port D clock enable
            constexpr auto GPIOCEN                = 1 << 2;       // IO port C clock enable
            constexpr auto GPIOBEN                = 1 << 1;       // IO port B clock enable
            constexpr auto GPIOAEN                = 1 << 0;       // IO port A clock enable

            // AHB2ENR
            constexpr auto OTGFSEN                = 1 << 7;       // USB OTG FS clock enable
            constexpr auto RNGEN                  = 1 << 6;       // RNG clock enable

            // AHB3ENR
            constexpr auto QSPIEN                 = 1 << 1;       // QUADSPI memory controller module clock enable
            constexpr auto FSMCEN                 = 1 << 0;       // Flexible memory controller module clock enable

            // APB1ENR
            constexpr auto PWREN                  = 1 << 28;      // Power interface clock enable
            constexpr auto CAN2EN                 = 1 << 26;      // CAN 2 clock enable
            constexpr auto CAN1EN                 = 1 << 25;      // CAN 1 clock enable
            constexpr auto I2CFMP1EN              = 1 << 24;      // I2CFMP1 clock enable
            constexpr auto I2C3EN                 = 1 << 23;      // I2C3 clock enable
            constexpr auto I2C2EN                 = 1 << 22;      // I2C2 clock enable
            constexpr auto I2C1EN                 = 1 << 21;      // I2C1 clock enable
            constexpr auto USART3EN               = 1 << 18;      // USART3 clock enable
            constexpr auto USART2EN               = 1 << 17;      // USART2 clock enable
            constexpr auto SPI3EN                 = 1 << 15;      // SPI3 clock enable
            constexpr auto SPI2EN                 = 1 << 14;      // SPI2 clock enable
            constexpr auto WWDGEN                 = 1 << 11;      // Window watchdog clock enable
            constexpr auto RTCAPBEN               = 1 << 10;      // RTC clock enable
            constexpr auto TIM14EN                = 1 << 8;       // TIM14 clock enable
            constexpr auto TIM13EN                = 1 << 7;       // TIM13 clock enable
            constexpr auto TIM12EN                = 1 << 6;       // TIM12 clock enable
            constexpr auto TIM7EN                 = 1 << 5;       // TIM7 clock enable
            constexpr auto TIM6EN                 = 1 << 4;       // TIM6 clock enable
            constexpr auto TIM5EN                 = 1 << 3;       // TIM5 clock enable
            constexpr auto TIM4EN                 = 1 << 2;       // TIM4 clock enable
            constexpr auto TIM3EN                 = 1 << 1;       // TIM3 clock enable
            constexpr auto TIM2EN                 = 1 << 0;       // TIM2 clock enable

            // APB2ENR
            constexpr auto DFSDM1EN               = 1 << 24;      // DFSDM1 clock enable
            constexpr auto SPI5EN                 = 1 << 20;      // SPI5 clock enable
            constexpr auto TIM11EN                = 1 << 18;      // TIM11 clock enable
            constexpr auto TIM10EN                = 1 << 17;      // TIM10 clock enable
            constexpr auto TIM9EN                 = 1 << 16;      // TIM9 clock enable
            constexpr auto SYSCFGEN               = 1 << 14;      // System configuration controller clock enable
            constexpr auto SPI4EN                 = 1 << 13;      // SPI4 clock enable
            constexpr auto SPI1EN                 = 1 << 12;      // SPI1 clock enable
            constexpr auto SDIOEN                 = 1 << 11;      // SDIO clock enable
            constexpr auto ADC1EN                 = 1 << 8;       // ADC1 clock enable
            constexpr auto USART6EN               = 1 << 5;       // USART6 clock enable
            constexpr auto USART1EN               = 1 << 4;       // USART1 clock enable
            constexpr auto TIM8EN                 = 1 << 1;       // TIM8 clock enable
            constexpr auto TIM1EN                 = 1 << 0;       // TIM1 clock enable

            // AHB1LPENR
            constexpr auto DMA2LPEN               = 1 << 22;      // DMA2 clock enable during Sleep mode
            constexpr auto DMA1LPEN               = 1 << 21;      // DMA1 clock enable during Sleep mode
            constexpr auto SRAM1LPEN              = 1 << 16;      // SRAM1interface clock enable during Sleep mode
            constexpr auto FLITFLPEN              = 1 << 15;      // Flash interface clock enable during Sleep mode
            constexpr auto CRCLPEN                = 1 << 12;      // CRC clock enable during Sleep mode
            constexpr auto GPIOHLPEN              = 1 << 7;       // IO port H clock enable during sleep mode
            constexpr auto GPIOGLPEN              = 1 << 6;       // IO port G clock enable during Sleep mode
            constexpr auto GPIOFLPEN              = 1 << 5;       // IO port F clock enable during Sleep mode
            constexpr auto GPIOELPEN              = 1 << 4;       // IO port E clock enable during Sleep mode
            constexpr auto GPIODLPEN              = 1 << 3;       // IO port D clock enable during Sleep mode
            constexpr auto GPIOCLPEN              = 1 << 2;       // IO port C clock enable during Sleep mode
            constexpr auto GPIOBLPEN              = 1 << 1;       // IO port B clock enable during Sleep mode
            constexpr auto GPIOALPEN              = 1 << 0;       // IO port A clock enable during sleep mode

            // AHB2LPENR
            constexpr auto OTGFSLPEN              = 1 << 7;       // USB OTG FS clock enable during Sleep mode
            constexpr auto RNGLPEN                = 1 << 6;       // RNG clock enable during Sleep mode

            // AHB3LPENR
            constexpr auto QSPILPEN               = 1 << 1;       // QUADSPI memory controller module clock enable during Sleep mode
            constexpr auto FSMCLPEN               = 1 << 0;       // Flexible memory controller module clock enable during Sleep mode

            // APB1LPENR
            constexpr auto PWRLPEN                = 1 << 28;      // Power interface clock enable during Sleep mode
            constexpr auto CAN2LPEN               = 1 << 26;      // CAN2 clock enable during Sleep mode
            constexpr auto CAN1LPEN               = 1 << 25;      // CAN1 clock enable during Sleep mode
            constexpr auto I2CFMP1LPEN            = 1 << 24;      // I2CFMP1 clock enable during Sleep mode
            constexpr auto I2C3LPEN               = 1 << 23;      // I2C3 clock enable during Sleep mode
            constexpr auto I2C2LPEN               = 1 << 22;      // I2C2 clock enable during Sleep mode
            constexpr auto I2C1LPEN               = 1 << 21;      // I2C1 clock enable during Sleep mode
            constexpr auto USART3LPEN             = 1 << 18;      // USART3 clock enable during Sleep mode
            constexpr auto USART2LPEN             = 1 << 17;      // USART2 clock enable during Sleep mode
            constexpr auto SPI3LPEN               = 1 << 15;      // SPI3 clock enable during Sleep mode
            constexpr auto SPI2LPEN               = 1 << 14;      // SPI2 clock enable during Sleep mode
            constexpr auto WWDGLPEN               = 1 << 11;      // Window watchdog clock enable during Sleep mode
            constexpr auto RTCAPBLPEN             = 1 << 10;      // RTC APB clock enable during Sleep mode
            constexpr auto TIM14LPEN              = 1 << 8;       // TIM14 clock enable during Sleep mode
            constexpr auto TIM13LPEN              = 1 << 7;       // TIM13 clock enable during Sleep mode
            constexpr auto TIM12LPEN              = 1 << 6;       // TIM12 clock enable during Sleep mode
            constexpr auto TIM7LPEN               = 1 << 5;       // TIM7 clock enable during Sleep mode
            constexpr auto TIM6LPEN               = 1 << 4;       // TIM6 clock enable during Sleep mode
            constexpr auto TIM5LPEN               = 1 << 3;       // TIM5 clock enable during Sleep mode
            constexpr auto TIM4LPEN               = 1 << 2;       // TIM4 clock enable during Sleep mode
            constexpr auto TIM3LPEN               = 1 << 1;       // TIM3 clock enable during Sleep mode
            constexpr auto TIM2LPEN               = 1 << 0;       // TIM2 clock enable during Sleep mode

            // APB2LPENR
            constexpr auto DFSDM1LPEN             = 1 << 24;      // DFSDM1 clock enable during Sleep mode
            constexpr auto SPI5LPEN               = 1 << 20;      // SPI5 clock enable during Sleep mode
            constexpr auto TIM11LPEN              = 1 << 18;      // TIM11 clock enable during Sleep mode
            constexpr auto TIM10LPEN              = 1 << 17;      // TIM10 clock enable during Sleep mode
            constexpr auto TIM9LPEN               = 1 << 16;      // TIM9 clock enable during sleep mode
            constexpr auto EXTITEN                = 1 << 15;      // EXTIT APB and SYSCTRL PFREE clock enable during Sleep mode
            constexpr auto SYSCFGLPEN             = 1 << 14;      // System configuration controller clock enable during Sleep mode
            constexpr auto SPI4LPEN               = 1 << 13;      // SPI4 clock enable during sleep mode
            constexpr auto SPI1LPEN               = 1 << 12;      // SPI1 clock enable during Sleep mode
            constexpr auto SDIOLPEN               = 1 << 11;      // SDIO clock enable during Sleep mode
            constexpr auto ADC1LPEN               = 1 << 8;       // ADC1 clock enable during Sleep mode
            constexpr auto USART6LPEN             = 1 << 5;       // USART6 clock enable during Sleep mode
            constexpr auto USART1LPEN             = 1 << 4;       // USART1 clock enable during Sleep mode
            constexpr auto TIM8LPEN               = 1 << 1;       // TIM8 clock enable during Sleep mode
            constexpr auto TIM1LPEN               = 1 << 0;       // TIM1 clock enable during Sleep mode

            // BDCR
            constexpr auto BDRST                  = 1 << 16;      // Backup domain software reset
            constexpr auto RTCEN                  = 1 << 15;      // RTC clock enable
            constexpr auto LSEMOD                 = 1 << 3;       // External low-speed oscillator bypass
            constexpr auto LSEBYP                 = 1 << 2;       // External low-speed oscillator bypass
            constexpr auto LSERDY                 = 1 << 1;       // External low-speed oscillator ready
            constexpr auto LSEON                  = 1 << 0;       // External low-speed oscillator enable

            // CSR
            constexpr auto LPWRRSTF               = 1 << 31;      // Low-power reset flag
            constexpr auto WWDGRSTF               = 1 << 30;      // Window watchdog reset flag
            constexpr auto WDGRSTF                = 1 << 29;      // Independent watchdog reset flag
            constexpr auto SFTRSTF                = 1 << 28;      // Software reset flag
            constexpr auto PORRSTF                = 1 << 27;      // POR/PDR reset flag
            constexpr auto PADRSTF                = 1 << 26;      // PIN reset flag
            constexpr auto BORRSTF                = 1 << 25;      // BOR reset flag
            constexpr auto RMVF                   = 1 << 24;      // Remove reset flag
            constexpr auto LSIRDY                 = 1 << 1;       // Internal low-speed oscillator ready
            constexpr auto LSION                  = 1 << 0;       // Internal low-speed oscillator enable

            // SSCGR
            constexpr auto SSCGEN                 = 1 << 31;      // Spread spectrum modulation enable
            constexpr auto SPAREADSEL             = 1 << 30;      // Spread Select

            // PLLI2SCFGR
            constexpr auto PLLI2SSRC              = 1 << 22;      // PLLI2S entry clock source

            // DCKCF
            constexpr auto CKDFSDM1SEL            = 1 << 31;      // DFSDM1 kernel clock selection
            constexpr auto TIMPRE                 = 1 << 24;      // Timers clocks prescalers selection
            constexpr auto CKDFSDM1ASEL           = 1 << 15;      // DFSDM1 audio clock selection

            // CKGATEENR
            constexpr auto EVTCL_CKEN             = 1 << 7;       // clock gating enable
            constexpr auto RCC_CKEN               = 1 << 6;       // RCC clock enable
            constexpr auto FLITF_CKEN             = 1 << 5;       // Flash Interface clock enable
            constexpr auto SRAM_CKEN              = 1 << 4;       // SRQAM controller clock enable
            constexpr auto SPARE_CKEN             = 1 << 3;       // Spare clock enable
            constexpr auto CM4DBG_CKEN            = 1 << 2;       // Cortex M4 ETM clock enable
            constexpr auto AHB2APB2_CKEN          = 1 << 1;       // AHB to APB2 Bridge clock enable
            constexpr auto AHB1APB1_CKEN          = 1 << 0;       // AHB to APB1 Bridge clock enable

            // DCKCFGR2
            constexpr auto SDIOSEL                = 1 << 28;      // SDIO clock selection
            constexpr auto CK48MSEL               = 1 << 27;      // SDIO/USBFS clock selection
        }
    }

    namespace RNG{
        constexpr auto RNG                        = 0x50060800;

        namespace R{
            constexpr auto CR                     = 0x00;         // control register
            constexpr auto SR                     = 0x04;         // status register
            constexpr auto DR                     = 0x08;         // data register
        }

        namespace B{
            // CR
            constexpr auto IE                     = 1 << 3;       // Interrupt Enable
            constexpr auto RNGEN                  = 1 << 2;       // Random number generator enable

            // SR
            constexpr auto SEIS                   = 1 << 6;       // Seed error interrupt status
            constexpr auto CEIS                   = 1 << 5;       // Clock error interrupt status
            constexpr auto SECS                   = 1 << 2;       // Seed error current status
            constexpr auto CECS                   = 1 << 1;       // Clock error current status
            constexpr auto DRDY                   = 1 << 0;       // Data ready
        }
    }

    namespace SPI{
        constexpr auto SPI1                       = 0x40013000;
        constexpr auto SPI2                       = 0x40003800;
        constexpr auto SPI3                       = 0x40003C00;
        constexpr auto SPI4                       = 0x40013400;
        constexpr auto SPI5                       = 0x40015000;

        namespace R{
            constexpr auto CR1                    = 0x00;         // control register 1
            constexpr auto CR2                    = 0x04;         // control register 2
            constexpr auto SR                     = 0x08;         // status register
            constexpr auto DR                     = 0x0C;         // data register
            constexpr auto CRCPR                  = 0x10;         // CRC polynomial register
            constexpr auto RXCRCR                 = 0x14;         // RX CRC register
            constexpr auto TXCRCR                 = 0x18;         // TX CRC register
            constexpr auto I2SCFGR                = 0x1C;         // I2S configuration register
            constexpr auto I2SPR                  = 0x20;         // I2S prescaler register

            constexpr auto TXR                    = DR;
            constexpr auto RXR                    = DR;
        }

        namespace B{
            // CR1
            constexpr auto BIDIMODE               = 1 << 15;      // Bidirectional data mode enable
            constexpr auto BIDIOE                 = 1 << 14;      // Output enable in bidirectional mode
            constexpr auto CRCEN                  = 1 << 13;      // Hardware CRC calculation enable
            constexpr auto CRCNEXT                = 1 << 12;      // CRC transfer next
            constexpr auto DFF                    = 1 << 11;      // Data frame format
            constexpr auto RXONLY                 = 1 << 10;      // Receive only mode enable
            constexpr auto SSM                    = 1 << 9;       // Software slave management
            constexpr auto SSI                    = 1 << 8;       // Internal slave select
            constexpr auto LSBFIRST               = 1 << 7;       // Frame format
            constexpr auto SPE                    = 1 << 6;       // SPI enable
            constexpr auto MSTR                   = 1 << 2;       // Master selection
            constexpr auto CPOL                   = 1 << 1;       // Clock polarity
            constexpr auto CPHA                   = 1 << 0;       // Clock phase

            // CR2
            constexpr auto TXEIE                  = 1 << 7;       // Tx buffer empty interrupt enable
            constexpr auto RXNEIE                 = 1 << 6;       // RX buffer not empty interrupt enable
            constexpr auto ERRIE                  = 1 << 5;       // Error interrupt enable
            constexpr auto FRF                    = 1 << 4;       // Frame format
            constexpr auto SSOE                   = 1 << 2;       // SS output enable
            constexpr auto TXDMAEN                = 1 << 1;       // Tx buffer DMA enable
            constexpr auto RXDMAEN                = 1 << 0;       // Rx buffer DMA enable

            // SR
            constexpr auto FRE                    = 1 << 8;       // Frame Error
            constexpr auto BSY                    = 1 << 7;       // Busy flag
            constexpr auto OVR                    = 1 << 6;       // Overrun flag
            constexpr auto MODF                   = 1 << 5;       // Mode fault
            constexpr auto CRCERR                 = 1 << 4;       // CRC error flag
            constexpr auto UDR                    = 1 << 3;       // Underrun flag
            constexpr auto CHSIDE                 = 1 << 2;       // Channel side
            constexpr auto TXE                    = 1 << 1;       // Transmit buffer empty
            constexpr auto RXNE                   = 1 << 0;       // Receive buffer not empty

            // I2SCRGR
            constexpr auto ASTREN                 = 1 << 12;      // Asynchronous start enable
            constexpr auto I2SMOD                 = 1 << 11;      // I2S mode selection
            constexpr auto I2SE                   = 1 << 10;      // I2S Enable
            constexpr auto PCMSYNC                = 1 << 7;       // PCM frame synchronization
            constexpr auto CKPOL                  = 1 << 3;       // Steady state clock polarity
            constexpr auto CHLEN                  = 1 << 0;       // Channel length (number of bits per audio channel)

            // I2SPR
            constexpr auto MCKOE                  = 1 << 9;       // Master clock output enable
            constexpr auto ODD                    = 1 << 8;       // Odd factor for the prescaler
        }
    }

    namespace TIM{
        constexpr auto TIM1                       = 0x40010000;
        constexpr auto TIM2                       = 0x40000000;
        constexpr auto TIM3                       = 0x40000400;
        constexpr auto TIM4                       = 0x40000800;
        constexpr auto TIM5                       = 0x40000C00;
        constexpr auto TIM6                       = 0x40001000;
        constexpr auto TIM7                       = 0x40001400;
        constexpr auto TIM8                       = 0x40010400;
        constexpr auto TIM9                       = 0x40014000;
        constexpr auto TIM10                      = 0x40014400;
        constexpr auto TIM11                      = 0x40014800;
        constexpr auto TIM12                      = 0x40001800;
        constexpr auto TIM13                      = 0x40001C00;
        constexpr auto TIM14                      = 0x40002000;
    }

    namespace USART{
        constexpr auto USART1                     = 0x40011000;
        constexpr auto USART2                     = 0x40004400;
        constexpr auto USART3                     = 0x40004800;
        constexpr auto USART6                     = 0x40011400;

        namespace R{
            constexpr auto SR                     = 0x00;         // Status register
            constexpr auto DR                     = 0x04;         // Data register
            constexpr auto BRR                    = 0x08;         // Baud rate register
            constexpr auto CR1                    = 0x0C;         // Control register 1
            constexpr auto CR2                    = 0x10;         // Control register 2
            constexpr auto CR3                    = 0x14;         // Control register 3
            constexpr auto GTPR                   = 0x18;         // Guard time and prescaler register

            // aliases for compatibility
            constexpr auto TDR                    = DR;           // Transmitt data register
            constexpr auto RDR                    = DR;           // Receive data register
            constexpr auto ISR                    = SR;           // Status register
        }

        namespace B{
            // SR
            constexpr auto CTS                    = 1 << 9;       // CTS flag
            constexpr auto LBD                    = 1 << 8;       // LIN break detection flag
            constexpr auto TXE                    = 1 << 7;       // Transmit data register empty
            constexpr auto TC                     = 1 << 6;       // Transmission complete
            constexpr auto RXNE                   = 1 << 5;       // Read data register not empty
            constexpr auto IDLE                   = 1 << 4;       // IDLE line detected
            constexpr auto ORE                    = 1 << 3;       // Overrun error
            constexpr auto NF                     = 1 << 2;       // Noise detected flag
            constexpr auto FE                     = 1 << 1;       // Framing error
            constexpr auto PE                     = 1 << 0;       // Parity error

            // CR1
            constexpr auto OVER8                  = 1 << 15;      // Oversampling mode
            constexpr auto UE                     = 1 << 13;      // USART enable
            constexpr auto M                      = 1 << 12;      // Word length
            constexpr auto WAKE                   = 1 << 11;      // Wakeup method
            constexpr auto PCE                    = 1 << 10;      // Parity control enable
            constexpr auto PS                     = 1 << 9;       // Parity selection
            constexpr auto PEIE                   = 1 << 8;       // PE interrupt enable
            constexpr auto TXEIE                  = 1 << 7;       // TXE interrupt enable
            constexpr auto TCIE                   = 1 << 6;       // Transmission complete interrupt enable
            constexpr auto RXNEIE                 = 1 << 5;       // RXNE interrupt enable
            constexpr auto IDLEIE                 = 1 << 4;       // IDLE interrupt enable
            constexpr auto TE                     = 1 << 3;       // Transmitter enable
            constexpr auto RE                     = 1 << 2;       // Receiver enable
            constexpr auto RWU                    = 1 << 1;       // Receiver wakeup
            constexpr auto SBK                    = 1 << 0;       // Send break

            // CR2
            constexpr auto LINEN                  = 1 << 14;      // LIN mode enable
            constexpr auto CLKEN                  = 1 << 11;      // Clock enable
            constexpr auto CPOL                   = 1 << 10;      // Clock polarity
            constexpr auto CPHA                   = 1 << 9;       // Clock phase
            constexpr auto LBCL                   = 1 << 8;       // Last bit clock pulse
            constexpr auto LBDIE                  = 1 << 6;       // LIN break detection interrupt enable
            constexpr auto LBDL                   = 1 << 5;       // lin break detection length

            // CR3
            constexpr auto ONEBIT                 = 1 << 11;      // One sample bit method enable
            constexpr auto CTSIE                  = 1 << 10;      // CTS interrupt enable
            constexpr auto CTSE                   = 1 << 9;       // CTS enable
            constexpr auto RTSE                   = 1 << 8;       // RTS enable
            constexpr auto DMAT                   = 1 << 7;       // DMA enable transmitter
            constexpr auto DMAR                   = 1 << 6;       // DMA enable receiver
            constexpr auto SCEN                   = 1 << 5;       // Smartcard mode enable
            constexpr auto NACK                   = 1 << 4;       // Smartcard NACK enable
            constexpr auto HDSEL                  = 1 << 3;       // Half-duplex selection
            constexpr auto IRLP                   = 1 << 2;       // IrDA low-power
            constexpr auto IREN                   = 1 << 1;       // IrDA mode enable
            constexpr auto EIE                    = 1 << 0;       // Error interrupt enable
        }
    }

    namespace IWDG{
        constexpr auto IWDG                       = 0x40003000;
        constexpr auto WWDG                       = 0x40002C00;

        namespace R{
            constexpr auto KR                     = 0x00;         // Status register
            constexpr auto PR                     = 0x04;         // Prescaler register
            constexpr auto RLR                    = 0x08;         // Reload register
            constexpr auto SR                     = 0x0C;         // Status register
        }

        namespace B{
            // KR
            constexpr auto FEED_KEY               = 0xAAAA;       // Key to Feed the dog
            constexpr auto START_KEY              = 0xCCCC;       // Watchdog Start Key
            constexpr auto UNLOCK_KEY             = 0x5555;       // Watchdog register Unlock key

            // SR
            constexpr auto RVU                    = 1 << 1;       // Watchdog counter reload value update
            constexpr auto PVU                    = 1 << 0;       // Watchdog prescaler value update
        }
    }

    namespace WWDG{
        constexpr auto WWDG                       = 0x40002C00;

        namespace R{
            constexpr auto CR                     = 0x00;         // Control Register
            constexpr auto CFR                    = 0x04;         // Configuration Register
            constexpr auto SR                     = 0x08;         // Status Register
        }

        namespace B{
            // CR
            constexpr auto WDGA                   = 1 << 7;       // Activation bit

            // CFR
            constexpr auto EWI                    = 1 << 9;       // Early wakeup interrupt

            // SR
            constexpr auto EWIF                   = 1 << 0;       // Early wakeup interrupt flag
        }
    }
}

#endif /* LET_DEVICE_STM32_STM32F412RX_HPP */
