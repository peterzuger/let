/**
 * @file   let/include/device/STM32/STM32H753xx.hpp
 * @author Peter Züger
 * @date   30.09.2021
 * @brief  STM32H753xx register offsets
 *
 * This file is part of let (https://gitlab.com/peterzuger/let).
 * Copyright (c) 2021 Peter Züger.
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
#ifndef LET_DEVICE_STM32_STM32H753XX_HPP
#define LET_DEVICE_STM32_STM32H753XX_HPP

namespace let{
    namespace FLASH{
        constexpr auto FLASH                      = 0x52002000;

        namespace R{
            constexpr auto BANK1                  = 0x000;        //
            constexpr auto BANK2                  = 0x100;        //

            constexpr auto ACR                    = 0x00;         // access control register
            constexpr auto KEYR                   = 0x04;         // key register
            constexpr auto OPTKEYR                = 0x08;         // option key register
            constexpr auto CR                     = 0x0C;         // control register
            constexpr auto SR                     = 0x10;         // status register
            constexpr auto CCR                    = 0x14;         // clear control register

            constexpr auto OPTCR                  = 0x18;         // option control register
            constexpr auto OPTSR_CUR              = 0x1C;         // option status register (current value)
            constexpr auto OPTSR_PRG              = 0x20;         // option status register (value to program)
            constexpr auto OPTCCR                 = 0x24;         // option clear control register (FLASH_OPTCCR)
            constexpr auto PRAR_CUR               = 0x28;         // protection address (current value)
            constexpr auto PRAR_PRG               = 0x2C;         // protection address
            constexpr auto SCAR_CUR               = 0x30;         // secure address (current value)
            constexpr auto SCAR_PRG               = 0x34;         // secure address
            constexpr auto WPSN_CURR              = 0x38;         // sector protection (current value)
            constexpr auto WPSN_PRGR              = 0x3C;         // write sector protection

            constexpr auto CRCCR                  = 0x50;         // CRC control register
            constexpr auto CRCSADDR               = 0x54;         // CRC start address register
            constexpr auto CRCEADDR               = 0x58;         // CRC end address register
            constexpr auto CRCDATAR               = 0x5C;         // CRC data register
            constexpr auto ECC_FAR                = 0x60;         // ECC fail address

            constexpr auto BOOT_CURR              = 0x40;         // register with boot address (current value)
            constexpr auto BOOT_PRGR              = 0x44;         // register with boot address (value to program)
        }

        namespace B{
            // KEYR
            constexpr auto KEY1                   = 0x45670123;
            constexpr auto KEY2                   = 0xCDEF89AB;

            // OPTKEYR
            constexpr auto OPTKEY1                = 0x08192A3B;
            constexpr auto OPTKEY2                = 0x4C5D6E7F;

            // CR
            constexpr auto CRCENDIE1              = 1 << 27;      // end of CRC calculation interrupt enable bit
            constexpr auto DBECCERRIE             = 1 << 26;      // ECC double detection error interrupt enable bit
            constexpr auto SNECCERRIE             = 1 << 25;      // ECC single correction error interrupt enable bit
            constexpr auto RDSERRIE               = 1 << 24;      // secure error interrupt enable bit
            constexpr auto RDPERRIE               = 1 << 23;      // read protection error interrupt enable bit
            constexpr auto OPERRIE                = 1 << 22;      // write/erase error interrupt enable bit
            constexpr auto INCERRIE               = 1 << 21;      // inconsistency error interrupt enable bit
            constexpr auto STRBERRIE              = 1 << 19;      // strobe error interrupt enable bit
            constexpr auto PGSERRIE               = 1 << 18;      // programming sequence error interrupt enable bit
            constexpr auto WRPERRIE               = 1 << 17;      // write protection error interrupt enable bit
            constexpr auto EOPIE                  = 1 << 16;      // end-of-program interrupt control bit
            constexpr auto CRC_EN                 = 1 << 15;      // CRC control bit
            constexpr auto START                  = 1 << 7;       // bank or sector erase start control bit
            constexpr auto FW                     = 1 << 6;       // write forcing control bit
            constexpr auto X8                     = 0b00 << 4;    // programming executed with byte parallelism
            constexpr auto X16                    = 0b01 << 4;    // programming executed with half-word parallelism
            constexpr auto X32                    = 0b10 << 4;    // programming executed with word parallelism
            constexpr auto X64                    = 0b11 << 4;    // programming executed with double word parallelism
            constexpr auto X_MASK                 = 0b11 << 4;    // programming parallelism mask
            constexpr auto SNR_OFF                = 8;            // sector erase selection number
            constexpr auto SNR_MASK               = 0x7 << 8;     // sector erase selection number
            constexpr auto BER                    = 1 << 3;       // bank erase request
            constexpr auto SER                    = 1 << 2;       // sector erase request
            constexpr auto PG                     = 1 << 1;       // program enable bit
            constexpr auto LOCK                   = 1 << 0;       // configuration lock bit

            constexpr auto STRT                   = START;        // bank or sector erase start control bit

            // SR
            constexpr auto CRCEND                 = 1 << 27;      // CRC-complete flag
            constexpr auto DBECCERR               = 1 << 26;      // ECC double detection error flag
            constexpr auto SNECCERR1              = 1 << 25;      // single correction error flag
            constexpr auto RDSERR                 = 1 << 24;      // secure error flag
            constexpr auto RDPERR                 = 1 << 23;      // read protection error flag
            constexpr auto OPERR                  = 1 << 22;      // write/erase error flag
            constexpr auto INCERR                 = 1 << 21;      // inconsistency error flag
            constexpr auto STRBERR                = 1 << 19;      // strobe error flag
            constexpr auto PGSERR                 = 1 << 18;      // programming sequence error flag
            constexpr auto WRPERR                 = 1 << 17;      // write protection error flag
            constexpr auto EOP                    = 1 << 16;      // end-of-program flag
            constexpr auto CRC_BUSY               = 1 << 3;       // CRC busy flag
            constexpr auto QW                     = 1 << 2;       // wait queue flag
            constexpr auto WBNE                   = 1 << 1;       // write buffer not empty flag
            constexpr auto BSY                    = 1 << 0;       // ongoing program flag

            // CCR
            constexpr auto CRCENDC                = 1 << 27;      // CRCEND flag clear bit
            constexpr auto DBECCERRC              = 1 << 26;      // DBECCERR flag clear bit
            constexpr auto SNECCERR1C             = 1 << 25;      // SNECCERR1 flag clear bit
            constexpr auto RDSERRC                = 1 << 24;      // RDSERR flag clear bit
            constexpr auto RDPERRC                = 1 << 23;      // RDPERR flag clear bit
            constexpr auto OPERRC                 = 1 << 22;      // OPERR flag clear bit
            constexpr auto INCERRC                = 1 << 21;      // INCERR flag clear bit
            constexpr auto STRBERRC               = 1 << 19;      // STRBERR flag clear bit
            constexpr auto PGSERRC                = 1 << 18;      // PGSERR flag clear bit
            constexpr auto WRPERRC                = 1 << 17;      // WRPERR flag clear bit
            constexpr auto EOPC                   = 1 << 16;      // EOP flag clear bit

            // OPTCR
            constexpr auto SWAP_BANK              = 1 << 31;      // Bank swapping configuration bit
            constexpr auto OPTCHANGEERRIE         = 1 << 30;      // Option byte change error interrupt enable bit
            constexpr auto MER                    = 1 << 3;       // Flash mass erase enable bit
            constexpr auto OPTSTART               = 1 << 1;       // Option byte start change option configuration bit
            constexpr auto OPTLOCK                = 1 << 0;       // FLASH_OPTCR lock option configuration bit

            // OPTSR_CUR
            constexpr auto SWAP_BANK_OPT          = 1 << 31;      // Bank swapping option status bit
            constexpr auto OPTCHANGEERR           = 1 << 30;      // Option byte change error flag
            constexpr auto IO_HSLV                = 1 << 29;      // I/O high-speed at low-voltage status bit (PRODUCT_BELOW_27V)
            constexpr auto PERSO_OK               = 1 << 28;      // Device personalization status bit
            constexpr auto RSS2                   = 1 << 27;      // User option status bit 2
            constexpr auto RSS1                   = 1 << 26;      // User option status bit 1
            constexpr auto SECURITY               = 1 << 21;      // Security enable option status bit
            constexpr auto FZ_IWDG_SDBY           = 1 << 18;      // IWDG Standby mode freeze option status bit
            constexpr auto FZ_IWDG_STOP           = 1 << 17;      // IWDG Stop mode freeze option status bit
            constexpr auto nRST_STBY_D1           = 1 << 7;       // D1 DStandby entry reset option status bit
            constexpr auto nRST_STOP_D1           = 1 << 6;       // D1 DStop entry reset option status bit
            constexpr auto IWDG1_HW               = 1 << 4;       // IWDG1 control option status bit
            constexpr auto OPT_BUSY               = 1 << 0;       // Option byte change ongoing flag

            // OPTCCR
            constexpr auto OPTCHANGEERRC          = 1 << 30;      // OPTCHANGEERR reset bit
        }
    }

    namespace GPIO{
        constexpr auto GPIOA                      = 0x58020000;
        constexpr auto GPIOB                      = 0x58020400;
        constexpr auto GPIOC                      = 0x58020800;
        constexpr auto GPIOD                      = 0x58020C00;
        constexpr auto GPIOE                      = 0x58021000;
        constexpr auto GPIOF                      = 0x58021400;
        constexpr auto GPIOG                      = 0x58021800;
        constexpr auto GPIOH                      = 0x58021C00;
        constexpr auto GPIOI                      = 0x58022000;
        constexpr auto GPIOJ                      = 0x58022400;
        constexpr auto GPIOK                      = 0x58022800;

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
        constexpr auto RCC                        = 0x58024400;

        namespace R{
            constexpr auto CR                     = 0x00;         // Source Control Register
            constexpr auto ICSCR                  = 0x04;         // Internal Clock Source Calibration Register
            constexpr auto CRRCR                  = 0x08;         // Clock Recovery RC Register
            constexpr auto CFGR                   = 0x10;         // Clock Configuration Register
            constexpr auto D1CFGR                 = 0x18;         // Domain 1 Clock Configuration Register
            constexpr auto D2CFGR                 = 0x1C;         // Domain 2 Clock Configuration Register
            constexpr auto D3CFGR                 = 0x20;         // Domain 3 Clock Configuration Register
            constexpr auto PLLCKSELR              = 0x28;         // PLLs Clock Source Selection Register
            constexpr auto PLLCFGR                = 0x2C;         // PLLs Configuration Register
            constexpr auto PLL1DIVR               = 0x30;         // PLL1 Dividers Configuration Register
            constexpr auto PLL1FRACR              = 0x34;         // PLL1 Fractional Divider Register
            constexpr auto PLL2DIVR               = 0x38;         // PLL2 Dividers Configuration Register
            constexpr auto PLL2FRACR              = 0x3C;         // PLL2 Fractional Divider Register
            constexpr auto PLL3DIVR               = 0x40;         // PLL3 Dividers Configuration Register
            constexpr auto PLL3FRACR              = 0x44;         // PLL3 Fractional Divider Register
            constexpr auto D1CCIPR                = 0x4C;         // Domain 1 Kernel Clock Configuration Register
            constexpr auto D2CCIP1R               = 0x50;         // Domain 2 Kernel Clock Configuration Register
            constexpr auto D2CCIP2R               = 0x54;         // Domain 2 Kernel Clock Configuration Register
            constexpr auto D3CCIPR                = 0x58;         // Domain 3 Kernel Clock Configuration Register
            constexpr auto CIER                   = 0x60;         // Clock Source Interrupt Enable Register
            constexpr auto CIFR                   = 0x64;         // Clock Source Interrupt Flag Register
            constexpr auto CICR                   = 0x68;         // Clock Source Interrupt Clear Register
            constexpr auto BDCR                   = 0x70;         // Backup Domain Control Register
            constexpr auto CSR                    = 0x74;         // Clock Control and Status Register

            constexpr auto AHB3RSTR               = 0x7C;         // AHB3 Reset Register
            constexpr auto AHB1RSTR               = 0x80;         // AHB1 Peripheral Reset Register
            constexpr auto AHB2RSTR               = 0x84;         // AHB2 Peripheral Reset Register
            constexpr auto AHB4RSTR               = 0x88;         // AHB4 Peripheral Reset Register
            constexpr auto APB3RSTR               = 0x8C;         // APB3 Peripheral Reset Register
            constexpr auto APB1LRSTR              = 0x90;         // APB1 Peripheral Reset Register
            constexpr auto APB1HRSTR              = 0x94;         // APB1 Peripheral Reset Register
            constexpr auto APB2RSTR               = 0x98;         // APB2 Peripheral Reset Register
            constexpr auto APB4RSTR               = 0x9C;         // APB4 Peripheral Reset Register
            constexpr auto GCR                    = 0xA0;         // Global Control Register
            constexpr auto D3AMR                  = 0xA8;         // D3 Autonomous mode Register
            constexpr auto RSR                    = 0xD0;         // Reset Status Register

            constexpr auto AHB3ENR                = 0xD4;         // AHB3 Clock Register
            constexpr auto AHB1ENR                = 0xD8;         // AHB1 Clock Register
            constexpr auto AHB2ENR                = 0xDC;         // AHB2 Clock Register
            constexpr auto AHB4ENR                = 0xE0;         // AHB4 Clock Register
            constexpr auto APB3ENR                = 0xE4;         // APB3 Clock Register
            constexpr auto APB1LENR               = 0xE8;         // APB1 Clock Register
            constexpr auto APB1HENR               = 0xEC;         // APB1 Clock Register
            constexpr auto APB2ENR                = 0xF0;         // APB2 Clock Register
            constexpr auto APB4ENR                = 0xF4;         // APB4 Clock Register
            constexpr auto AHB3LPENR              = 0xFC;         // AHB3 Sleep Clock Register
            constexpr auto AHB1LPENR              = 0x100;        // AHB1 Sleep Clock Register
            constexpr auto AHB2LPENR              = 0x104;        // AHB2 Sleep Clock Register
            constexpr auto AHB4LPENR              = 0x108;        // AHB4 Sleep Clock Register
            constexpr auto APB3LPENR              = 0x10C;        // APB3 Sleep Clock Register
            constexpr auto APB1LLPENR             = 0x110;        // APB1 Low Sleep Clock Register
            constexpr auto APB1HLPENR             = 0x114;        // APB1 High Sleep Clock Register
            constexpr auto APB2LPENR              = 0x118;        // APB2 Sleep Clock Register
            constexpr auto APB4LPENR              = 0x11C;        // APB4 Sleep Clock Register

            constexpr auto C1_AHB3ENR             = 0x134;        // AHB3 Clock Register
            constexpr auto C1_AHB1ENR             = 0x138;        // AHB1 Clock Register
            constexpr auto C1_AHB2ENR             = 0x13C;        // AHB2 Clock Register
            constexpr auto C1_AHB4ENR             = 0x140;        // AHB4 Clock Register
            constexpr auto C1_APB3ENR             = 0x144;        // APB3 Clock Register
            constexpr auto C1_APB1LENR            = 0x148;        // APB1 Clock Register
            constexpr auto C1_APB1HENR            = 0x14C;        // APB1 Clock Register
            constexpr auto C1_APB2ENR             = 0x150;        // APB2 Clock Register
            constexpr auto C1_APB4ENR             = 0x154;        // APB4 Clock Register
            constexpr auto C1_AHB3LPENR           = 0x15C;        // AHB3 Sleep Clock Register
            constexpr auto C1_AHB1LPENR           = 0x160;        // AHB1 Sleep Clock Register
            constexpr auto C1_AHB2LPENR           = 0x164;        // AHB2 Sleep Clock Register
            constexpr auto C1_AHB4LPENR           = 0x168;        // AHB4 Sleep Clock Register
            constexpr auto C1_APB3LPENR           = 0x16C;        // APB3 Sleep Clock Register
            constexpr auto C1_APB1LLPENR          = 0x170;        // APB1 Low Sleep Clock Register
            constexpr auto C1_APB1HLPENR          = 0x174;        // APB1 High Sleep Clock Register
            constexpr auto C1_APB2LPENR           = 0x178;        // APB2 Sleep Clock Register
            constexpr auto C1_APB4LPENR           = 0x17C;        // APB4 Sleep Clock Register
        }

        namespace B{
            // CR
            constexpr auto PLL3RDY                = 1 << 29;      // PLL3 clock ready flag
            constexpr auto PLL3ON                 = 1 << 28;      // PLL3 enable
            constexpr auto PLL2RDY                = 1 << 27;      // PLL2 clock ready flag
            constexpr auto PLL2ON                 = 1 << 26;      // PLL2 enable
            constexpr auto PLL1RDY                = 1 << 25;      // PLL1 clock ready flag
            constexpr auto PLL1ON                 = 1 << 24;      // PLL1 enable
            constexpr auto HSECSSON               = 1 << 19;      // HSE Clock Security System enable
            constexpr auto HSEBYP                 = 1 << 18;      // HSE clock bypass
            constexpr auto HSERDY                 = 1 << 17;      // HSE clock ready flag
            constexpr auto HSEON                  = 1 << 16;      // HSE clock enable
            constexpr auto D2CKRDY                = 1 << 15;      // D2 domain clocks ready flag
            constexpr auto D1CKRDY                = 1 << 14;      // D1 domain clocks ready flag
            constexpr auto HSI48RDY               = 1 << 13;      // HSI48 clock ready flag
            constexpr auto HSI48ON                = 1 << 12;      // HSI48 clock enable
            constexpr auto CSIKERON               = 1 << 9;       // CSI clock enable in Stop mode
            constexpr auto CSIRDY                 = 1 << 8;       // CSI clock ready flag
            constexpr auto CSION                  = 1 << 7;       // CSI clock enable
            constexpr auto HSIDIVF                = 1 << 5;       // HSI divider flag
            constexpr auto HSIRDY                 = 1 << 2;       // HSI clock ready flag
            constexpr auto HSIKERON               = 1 << 1;       // High Speed Internal clock enable in Stop mode
            constexpr auto HSION                  = 1 << 0;       // High Speed Internal clock enable

            // CFGR
            constexpr auto TMPRE                  = 1 << 15;      // Timers clocks prescaler selection
            constexpr auto HRTIMSEL               = 1 << 14;      // High Resolution Timer clock prescaler selection
            constexpr auto STOPKERWUCK            = 1 << 7;       // Kernel clock selection after a wake up from system Stop
            constexpr auto STOPWUCK               = 1 << 8;       // System clock selection after a wake up from system Stop

            // PLLCFGR
            constexpr auto DIVR3EN                = 1 << 24;      // PLL3 DIVR divider output enable
            constexpr auto DIVQ3EN                = 1 << 23;      // PLL3 DIVQ divider output enable
            constexpr auto DIVP3EN                = 1 << 22;      // PLL3 DIVP divider output enable
            constexpr auto DIVR2EN                = 1 << 21;      // PLL2 DIVR divider output enable
            constexpr auto DIVQ2EN                = 1 << 20;      // PLL2 DIVQ divider output enable
            constexpr auto DIVP2EN                = 1 << 19;      // PLL2 DIVP divider output enable
            constexpr auto DIVR1EN                = 1 << 18;      // PLL1 DIVR divider output enable
            constexpr auto DIVQ1EN                = 1 << 17;      // PLL1 DIVQ divider output enable
            constexpr auto DIVP1EN                = 1 << 16;      // PLL1 DIVP divider output enable
            constexpr auto PLL3VCOSEL             = 1 << 9;       // PLL3 VCO selection
            constexpr auto PLL3FRACEN             = 1 << 8;       // PLL3 fractional latch enable
            constexpr auto PLL2VCOSEL             = 1 << 5;       // PLL2 VCO selection
            constexpr auto PLL2FRACEN             = 1 << 4;       // PLL2 fractional latch enable
            constexpr auto PLL1VCOSEL             = 1 << 1;       // PLL1 VCO selection
            constexpr auto PLL1FRACEN             = 1 << 0;       // PLL1 fractional latch enable

            // CIER
            constexpr auto LSECSSIE               = 1 << 9;       // LSE clock security system Interrupt Enable
            constexpr auto PLL3RDYIE              = 1 << 8;       // PLL3 ready Interrupt Enable
            constexpr auto PLL2RDYIE              = 1 << 7;       // PLL2 ready Interrupt Enable
            constexpr auto PLL1RDYIE              = 1 << 6;       // PLL1 ready Interrupt Enable
            constexpr auto HSI48RDYIE             = 1 << 5;       // HSI48 ready Interrupt Enable
            constexpr auto CSIRDYIE               = 1 << 4;       // CSI ready Interrupt Enable
            constexpr auto HSERDYIE               = 1 << 3;       // HSE ready Interrupt Enable
            constexpr auto HSIRDYIE               = 1 << 2;       // HSI ready Interrupt Enable
            constexpr auto LSERDYIE               = 1 << 1;       // LSE ready Interrupt Enable
            constexpr auto LSIRDYIE               = 1 << 0;       // LSI ready Interrupt Enable

            // CIFR
            constexpr auto HSECSSF                = 1 << 10;      // HSE clock security system Interrupt Flag
            constexpr auto LSECSSF                = 1 << 9;       // LSE clock security system Interrupt Flag
            constexpr auto PLL3RDYF               = 1 << 8;       // PLL3 ready Interrupt Flag
            constexpr auto PLL2RDYF               = 1 << 7;       // PLL2 ready Interrupt Flag
            constexpr auto PLL1RDYF               = 1 << 6;       // PLL1 ready Interrupt Flag
            constexpr auto HSI48RDYF              = 1 << 5;       // HSI48 ready Interrupt Flag
            constexpr auto CSIRDYF                = 1 << 4;       // CSI ready Interrupt Flag
            constexpr auto HSERDYF                = 1 << 3;       // HSE ready Interrupt Flag
            constexpr auto HSIRDYF                = 1 << 2;       // HSI ready Interrupt Flag
            constexpr auto LSERDYF                = 1 << 1;       // LSE ready Interrupt Flag
            constexpr auto LSIRDYF                = 1 << 0;       // LSI ready Interrupt Flag

            // CICR
            constexpr auto HSECSSC                = 1 << 10;      // HSE clock security system Interrupt Clear
            constexpr auto LSECSSC                = 1 << 9;       // LSE clock security system Interrupt Clear
            constexpr auto PLL3RDYC               = 1 << 8;       // PLL3 ready Interrupt Clear
            constexpr auto PLL2RDYC               = 1 << 7;       // PLL2 ready Interrupt Clear
            constexpr auto PLL1RDYC               = 1 << 6;       // PLL1 ready Interrupt Clear
            constexpr auto HSI48RDYC              = 1 << 5;       // HSI48 ready Interrupt Clear
            constexpr auto CSIRDYC                = 1 << 4;       // CSI ready Interrupt Clear
            constexpr auto HSERDYC                = 1 << 3;       // HSE ready Interrupt Clear
            constexpr auto HSIRDYC                = 1 << 2;       // HSI ready Interrupt Clear
            constexpr auto LSERDYC                = 1 << 1;       // LSE ready Interrupt Clear
            constexpr auto LSIRDYC                = 1 << 0;       // LSI ready Interrupt Clear

            // BDCR
            constexpr auto BDRST                  = 1 << 16;      // Backup domain software reset
            constexpr auto RTCEN                  = 1 << 15;      // RTC clock enable
            constexpr auto LSECSSD                = 1 << 6;       // LSE clock security system failure detection
            constexpr auto LSECSSON               = 1 << 5;       // LSE clock security system enable
            constexpr auto LSEBYP                 = 1 << 2;       // LSE oscillator bypass
            constexpr auto LSERDY                 = 1 << 1;       // LSE oscillator ready
            constexpr auto LSEON                  = 1 << 0;       // LSE oscillator enabled

            // CSR
            constexpr auto LSIRDY                 = 1 << 1;       // LSI oscillator ready
            constexpr auto LSION                  = 1 << 0;       // LSI oscillator enabled

            // AHB3RSTR
            constexpr auto CPURST                 = 1 << 31;      // CPU reset
            constexpr auto SDMMC1RST              = 1 << 16;      // SDMMC1 and SDMMC1 delay block reset
            constexpr auto QSPIRST                = 1 << 14;      // QUADSPI and QUADSPI delay block reset
            constexpr auto FMCRST                 = 1 << 12;      // FMC block reset
            constexpr auto JPGDECRST              = 1 << 5;       // JPGDEC block reset
            constexpr auto DMA2DRST               = 1 << 4;       // DMA2D block reset
            constexpr auto MDMARST                = 1 << 0;       // MDMA block reset

            // AHB1RSTR
            constexpr auto USB2OTGRST             = 1 << 27;      // USB2OTG block reset
            constexpr auto USB1OTGRST             = 1 << 25;      // USB1OTG block reset
            constexpr auto ETH1MACRST             = 1 << 15;      // ETH1MAC block reset
            constexpr auto ADC12RST               = 1 << 5;       // ADC1 and 2 block reset
            constexpr auto DMA2RST                = 1 << 1;       // DMA2 block reset
            constexpr auto DMA1RST                = 1 << 0;       // DMA1 block reset

            // AHB2RSTR
            constexpr auto SDMMC2RST              = 1 << 9;       // SDMMC2 and SDMMC2 Delay block reset
            constexpr auto RNGRST                 = 1 << 6;       // Random Number Generator block reset
            constexpr auto HASHRST                = 1 << 5;       // Hash block reset
            constexpr auto CRYPTRST               = 1 << 4;       // Cryptography block reset
            constexpr auto CAMITFRST              = 1 << 0;       // CAMITF block reset

            // AHB4RSTR
            constexpr auto HSEMRST                = 1 << 25;      // HSEM block reset
            constexpr auto ADC3RST                = 1 << 24;      // ADC3 block reset
            constexpr auto BDMARST                = 1 << 21;      // BDMA block reset
            constexpr auto CRCRST                 = 1 << 19;      // CRC block reset
            constexpr auto GPIOKRST               = 1 << 10;      // GPIOK block reset
            constexpr auto GPIOJRST               = 1 << 9;       // GPIOJ block reset
            constexpr auto GPIOIRST               = 1 << 8;       // GPIOI block reset
            constexpr auto GPIOHRST               = 1 << 7;       // GPIOH block reset
            constexpr auto GPIOGRST               = 1 << 6;       // GPIOG block reset
            constexpr auto GPIOFRST               = 1 << 5;       // GPIOF block reset
            constexpr auto GPIOERST               = 1 << 4;       // GPIOE block reset
            constexpr auto GPIODRST               = 1 << 3;       // GPIOD block reset
            constexpr auto GPIOCRST               = 1 << 2;       // GPIOC block reset
            constexpr auto GPIOBRST               = 1 << 1;       // GPIOB block reset
            constexpr auto GPIOARST               = 1 << 0;       // GPIOA block reset

            // APB3RSTR
            constexpr auto LTDCRST                = 1 << 3;       // LTDC block reset

            // APB1LRSTR
            constexpr auto UART8RST               = 1 << 31;      // UART8 block reset
            constexpr auto UART7RST               = 1 << 30;      // UART7 block reset
            constexpr auto DAC12RST               = 1 << 29;      // DAC1 and 2 Blocks Reset
            constexpr auto HDMICECRST             = 1 << 27;      // HDMI-CEC block reset
            constexpr auto I2C3RST                = 1 << 23;      // I2C3 block reset
            constexpr auto I2C2RST                = 1 << 22;      // I2C2 block reset
            constexpr auto I2C1RST                = 1 << 21;      // I2C1 block reset
            constexpr auto UART5RST               = 1 << 20;      // UART5 block reset
            constexpr auto UART4RST               = 1 << 19;      // UART4 block reset
            constexpr auto USART3RST              = 1 << 18;      // USART3 block reset
            constexpr auto USART2RST              = 1 << 17;      // USART2 block reset
            constexpr auto SPDIFRXRST             = 1 << 16;      // SPDIFRX block reset
            constexpr auto SPI3RST                = 1 << 15;      // SPI3 block reset
            constexpr auto SPI2RST                = 1 << 14;      // SPI2 block reset
            constexpr auto LPTIM1RST              = 1 << 9;       // LPTIM1 block reset
            constexpr auto TIM14RST               = 1 << 8;       // TIM14 block reset
            constexpr auto TIM13RST               = 1 << 7;       // TIM13 block reset
            constexpr auto TIM12RST               = 1 << 6;       // TIM12 block reset
            constexpr auto TIM7RST                = 1 << 5;       // TIM7 block reset
            constexpr auto TIM6RST                = 1 << 4;       // TIM6 block reset
            constexpr auto TIM5RST                = 1 << 3;       // TIM5 block reset
            constexpr auto TIM4RST                = 1 << 2;       // TIM4 block reset
            constexpr auto TIM3RST                = 1 << 1;       // TIM3 block reset
            constexpr auto TIM2RST                = 1 << 0;       // TIM2 block reset

            // APB1HRSTR
            constexpr auto FDCANRST               = 1 << 8;       // FDCAN block reset
            constexpr auto MDIOSRST               = 1 << 5;       // MDIOS block reset
            constexpr auto OPAMPRST               = 1 << 4;       // OPAMP block reset
            constexpr auto SWPRST                 = 1 << 2;       // SWPMI block reset
            constexpr auto CRSRST                 = 1 << 1;       // Clock Recovery System reset

            // APB2RSTR
            constexpr auto HRTIMRST               = 1 << 29;      // HRTIM block reset
            constexpr auto DFSDM1RST              = 1 << 28;      // DFSDM1 block reset
            constexpr auto SAI3RST                = 1 << 24;      // SAI3 block reset
            constexpr auto SAI2RST                = 1 << 23;      // SAI2 block reset
            constexpr auto SAI1RST                = 1 << 22;      // SAI1 block reset
            constexpr auto SPI5RST                = 1 << 20;      // SPI5 block reset
            constexpr auto TIM17RST               = 1 << 18;      // TIM17 block reset
            constexpr auto TIM16RST               = 1 << 17;      // TIM16 block reset
            constexpr auto TIM15RST               = 1 << 16;      // TIM15 block reset
            constexpr auto SPI4RST                = 1 << 13;      // SPI4 block reset
            constexpr auto SPI1RST                = 1 << 12;      // SPI1 block reset
            constexpr auto USART6RST              = 1 << 5;       // USART6 block reset
            constexpr auto USART1RST              = 1 << 4;       // USART1 block reset
            constexpr auto TIM8RST                = 1 << 1;       // TIM8 block reset
            constexpr auto TIM1RST                = 1 << 0;       // TIM1 block reset

            // APB4RSTR
            constexpr auto SAI4RST                = 1 << 21;      // SAI4 block reset
            constexpr auto VREFRST                = 1 << 15;      // VREF block reset
            constexpr auto COMP12RST              = 1 << 14;      // COMP12 Blocks Reset
            constexpr auto LPTIM5RST              = 1 << 12;      // LPTIM5 block reset
            constexpr auto LPTIM4RST              = 1 << 11;      // LPTIM4 block reset
            constexpr auto LPTIM3RST              = 1 << 10;      // LPTIM3 block reset
            constexpr auto LPTIM2RST              = 1 << 9;       // LPTIM2 block reset
            constexpr auto I2C4RST                = 1 << 7;       // I2C4 block reset
            constexpr auto SPI6RST                = 1 << 5;       // SPI6 block reset
            constexpr auto LPUART1RST             = 1 << 3;       // LPUART1 block reset
            constexpr auto SYSCFGRST              = 1 << 1;       // SYSCFG block reset

            // GCR
            constexpr auto WW1RSC                 = 1 << 0;       // WWDG1 reset scope control

            // D3AMR
            constexpr auto SRAM4AMEN              = 1 << 29;      // SRAM4 Autonomous mode enable
            constexpr auto BKPSRAMAMEN            = 1 << 28;      // Backup RAM Autonomous mode enable
            constexpr auto ADC3AMEN               = 1 << 24;      // ADC3 Autonomous mode enable
            constexpr auto SAI4AMEN               = 1 << 21;      // SAI4 Autonomous mode enable
            constexpr auto CRCAMEN                = 1 << 19;      // CRC Autonomous mode enable
            constexpr auto RTCAMEN                = 1 << 16;      // RTC Autonomous mode enable
            constexpr auto VREFAMEN               = 1 << 15;      // VREF Autonomous mode enable
            constexpr auto COMP12AMEN             = 1 << 14;      // COMP12 Autonomous mode enable
            constexpr auto LPTIM5AMEN             = 1 << 12;      // LPTIM5 Autonomous mode enable
            constexpr auto LPTIM4AMEN             = 1 << 11;      // LPTIM4 Autonomous mode enable
            constexpr auto LPTIM3AMEN             = 1 << 10;      // LPTIM3 Autonomous mode enable
            constexpr auto LPTIM2AMEN             = 1 << 9;       // LPTIM2 Autonomous mode enable
            constexpr auto I2C4AMEN               = 1 << 7;       // I2C4 Autonomous mode enable
            constexpr auto SPI6AMEN               = 1 << 5;       // SPI6 Autonomous mode enable
            constexpr auto LPUART1AMEN            = 1 << 3;       // LPUART1 Autonomous mode enable
            constexpr auto BDMAAMEN               = 1 << 0;       // BDMA and DMAMUX Autonomous mode enable

            // RSR
            constexpr auto LPWRRSTF               = 1 << 30;      // Reset due to illegal D1 DStandby or CPU CStop flag
            constexpr auto WWDG1RSTF              = 1 << 28;      // Window Watchdog reset flag
            constexpr auto IWDG1RSTF              = 1 << 26;      // Independent Watchdog reset flag
            constexpr auto SFTRSTF                = 1 << 24;      // System reset from CPU reset flag
            constexpr auto PORRSTF                = 1 << 23;      // POR/PDR reset flag
            constexpr auto PINRSTF                = 1 << 22;      // Pin reset flag (NRST)
            constexpr auto BORRSTF                = 1 << 21;      // BOR reset flag
            constexpr auto D2RSTF                 = 1 << 20;      // D2 domain power switch reset flag
            constexpr auto D1RSTF                 = 1 << 19;      // D1 domain power switch reset flag
            constexpr auto CPURSTF                = 1 << 17;      // CPU reset flag
            constexpr auto RMVF                   = 1 << 16;      // Remove reset flag

            // AHB3ENR
            constexpr auto SDMMC1EN               = 1 << 16;      // SDMMC1 and SDMMC1 delay block enable
            constexpr auto QSPIEN                 = 1 << 14;      // QUADSPI and QUADSPI delay block enable
            constexpr auto FMCEN                  = 1 << 12;      // FMC block enable
            constexpr auto JPGDECEN               = 1 << 5;       // JPGDEC block enable
            constexpr auto DMA2DEN                = 1 << 4;       // DMA2D block enable
            constexpr auto MDMAEN                 = 1 << 0;       // MDMA block enable

            // AHB1ENR
            constexpr auto USB2ULPIEN             = 1 << 28;      // USB_PHY2 Clocks Enable
            constexpr auto USB2OTGEN              = 1 << 27;      // USB2OTG Peripheral Clocks Enable
            constexpr auto USB1ULPIEN             = 1 << 26;      // USB_PHY1 Clocks Enable
            constexpr auto USB1OTGEN              = 1 << 25;      // USB1OTG Peripheral Clocks Enable
            constexpr auto ETH1RXEN               = 1 << 17;      // Ethernet Reception Clock Enable
            constexpr auto ETH1TXEN               = 1 << 16;      // Ethernet Transmission Clock Enable
            constexpr auto ETH1MACEN              = 1 << 15;      // Ethernet MAC bus interface Clock Enable
            constexpr auto ADC12EN                = 1 << 5;       // ADC1/2 Peripheral Clocks Enable
            constexpr auto DMA2EN                 = 1 << 1;       // DMA2 Clock Enable
            constexpr auto DMA1EN                 = 1 << 0;       // DMA1 Clock Enable

            constexpr auto ADC1EN                 = ADC12EN;      // ADC1/2 Peripheral Clocks Enable
            constexpr auto ADC2EN                 = ADC12EN;      // ADC1/2 Peripheral Clocks Enable

            // AHB2ENR
            constexpr auto SRAM3EN                = 1 << 31;      // SRAM3 block enable
            constexpr auto SRAM2EN                = 1 << 30;      // SRAM2 block enable
            constexpr auto SRAM1EN                = 1 << 29;      // SRAM1 block enable
            constexpr auto SDMMC2EN               = 1 << 9;       // SDMMC2 and SDMMC2 Delay block enable
            constexpr auto RNGEN                  = 1 << 6;       // Random Number Generator block enable
            constexpr auto HASHEN                 = 1 << 5;       // Hash block enable
            constexpr auto CRYPTEN                = 1 << 4;       // Cryptography block enable
            constexpr auto DCMIEN                 = 1 << 0;       // DCMI block enable

            // AHB4ENR
            constexpr auto BKPRAMEN               = 1 << 27;      // Backup RAM block enable
            constexpr auto HSEMEN                 = 1 << 25;      // HSEM block enable
            constexpr auto ADC3EN                 = 1 << 24;      // ADC3 block enable
            constexpr auto BDMAEN                 = 1 << 21;      // BDMA block enable
            constexpr auto CRCEN                  = 1 << 19;      // CRC block enable
            constexpr auto GPIOKEN                = 1 << 10;      // GPIOK block enable
            constexpr auto GPIOJEN                = 1 << 9;       // GPIOJ block enable
            constexpr auto GPIOIEN                = 1 << 8;       // GPIOI block enable
            constexpr auto GPIOHEN                = 1 << 7;       // GPIOH block enable
            constexpr auto GPIOGEN                = 1 << 6;       // GPIOG block enable
            constexpr auto GPIOFEN                = 1 << 5;       // GPIOF block enable
            constexpr auto GPIOEEN                = 1 << 4;       // GPIOE block enable
            constexpr auto GPIODEN                = 1 << 3;       // GPIOD block enable
            constexpr auto GPIOCEN                = 1 << 2;       // GPIOC block enable
            constexpr auto GPIOBEN                = 1 << 1;       // GPIOB block enable
            constexpr auto GPIOAEN                = 1 << 0;       // GPIOA block enable

            // APB3ENR
            constexpr auto WWDG1EN                = 1 << 6;       // WWDG1 block enable
            constexpr auto LTDCEN                 = 1 << 3;       // LTDC block enable

            // APB1LENR
            constexpr auto UART8EN                = 1 << 31;      // UART8 block enable
            constexpr auto UART7EN                = 1 << 30;      // UART7 block enable
            constexpr auto DAC12EN                = 1 << 29;      // DAC1 and 2 Blocks Enable
            constexpr auto HDMICECEN              = 1 << 27;      // HDMI-CEC block enable
            constexpr auto I2C3EN                 = 1 << 23;      // I2C3 block enable
            constexpr auto I2C2EN                 = 1 << 22;      // I2C2 block enable
            constexpr auto I2C1EN                 = 1 << 21;      // I2C1 block enable
            constexpr auto UART5EN                = 1 << 20;      // UART5 block enable
            constexpr auto UART4EN                = 1 << 19;      // UART4 block enable
            constexpr auto USART3EN               = 1 << 18;      // USART3 block enable
            constexpr auto USART2EN               = 1 << 17;      // USART2 block enable
            constexpr auto SPDIFRXEN              = 1 << 16;      // SPDIFRX block enable
            constexpr auto SPI3EN                 = 1 << 15;      // SPI3 block enable
            constexpr auto SPI2EN                 = 1 << 14;      // SPI2 block enable
            constexpr auto LPTIM1EN               = 1 << 9;       // LPTIM1 block enable
            constexpr auto TIM14EN                = 1 << 8;       // TIM14 block enable
            constexpr auto TIM13EN                = 1 << 7;       // TIM13 block enable
            constexpr auto TIM12EN                = 1 << 6;       // TIM12 block enable
            constexpr auto TIM7EN                 = 1 << 5;       // TIM7 block enable
            constexpr auto TIM6EN                 = 1 << 4;       // TIM6 block enable
            constexpr auto TIM5EN                 = 1 << 3;       // TIM5 block enable
            constexpr auto TIM4EN                 = 1 << 2;       // TIM4 block enable
            constexpr auto TIM3EN                 = 1 << 1;       // TIM3 block enable
            constexpr auto TIM2EN                 = 1 << 0;       // TIM2 block enable

            // APB1HENR
            constexpr auto FDCANEN                = 1 << 8;       // FDCAN block enable
            constexpr auto MDIOSEN                = 1 << 5;       // MDIOS block enable
            constexpr auto OPAMPEN                = 1 << 4;       // OPAMP block enable
            constexpr auto SWPEN                  = 1 << 2;       // SWPMI block enable
            constexpr auto CRSEN                  = 1 << 1;       // Clock Recovery System enable

            // APB2ENR
            constexpr auto HRTIMEN                = 1 << 29;      // HRTIM block enable
            constexpr auto DFSDM1EN               = 1 << 28;      // DFSDM1 block enable
            constexpr auto SAI3EN                 = 1 << 24;      // SAI3 block enable
            constexpr auto SAI2EN                 = 1 << 23;      // SAI2 block enable
            constexpr auto SAI1EN                 = 1 << 22;      // SAI1 block enable
            constexpr auto SPI5EN                 = 1 << 20;      // SPI5 block enable
            constexpr auto TIM17EN                = 1 << 18;      // TIM17 block enable
            constexpr auto TIM16EN                = 1 << 17;      // TIM16 block enable
            constexpr auto TIM15EN                = 1 << 16;      // TIM15 block enable
            constexpr auto SPI4EN                 = 1 << 13;      // SPI4 block enable
            constexpr auto SPI1EN                 = 1 << 12;      // SPI1 block enable
            constexpr auto USART6EN               = 1 << 5;       // USART6 block enable
            constexpr auto USART1EN               = 1 << 4;       // USART1 block enable
            constexpr auto TIM8EN                 = 1 << 1;       // TIM8 block enable
            constexpr auto TIM1EN                 = 1 << 0;       // TIM1 block enable

            // APB4ENR
            constexpr auto SAI4EN                 = 1 << 21;      // SAI4 block enable
            constexpr auto RTCAPBEN               = 1 << 16;      // RTC APB block enable
            constexpr auto VREFEN                 = 1 << 15;      // VREF block enable
            constexpr auto COMP12EN               = 1 << 14;      // COMP12 Blocks Enable
            constexpr auto LPTIM5EN               = 1 << 12;      // LPTIM5 block enable
            constexpr auto LPTIM4EN               = 1 << 11;      // LPTIM4 block enable
            constexpr auto LPTIM3EN               = 1 << 10;      // LPTIM3 block enable
            constexpr auto LPTIM2EN               = 1 << 9;       // LPTIM2 block enable
            constexpr auto I2C4EN                 = 1 << 7;       // I2C4 block enable
            constexpr auto SPI6EN                 = 1 << 5;       // SPI6 block enable
            constexpr auto LPUART1EN              = 1 << 3;       // LPUART1 block enable
            constexpr auto SYSCFGEN               = 1 << 1;       // SYSCFG block enable

            // AHB3LPENR
            constexpr auto AXISRAMLPEN            = 1 << 31;      // AXISRAM Block Clock Enable During CSleep mode
            constexpr auto ITCMLPEN               = 1 << 30;      // D1ITCM Block Clock Enable During CSleep mode
            constexpr auto DTCM2LPEN              = 1 << 29;      // D1 DTCM2 Block Clock Enable During CSleep mode
            constexpr auto D1DTCM1LPEN            = 1 << 28;      // D1DTCM1 Block Clock Enable During CSleep mode
            constexpr auto SDMMC1LPEN             = 1 << 16;      // SDMMC1 and SDMMC1 Delay Clock Enable During CSleep Mode
            constexpr auto QSPILPEN               = 1 << 14;      // QUADSPI and QUADSPI Delay Clock Enable During CSleep Mode
            constexpr auto FMCLPEN                = 1 << 12;      // FMC Peripheral Clocks Enable During CSleep Mode
            constexpr auto FLASHLPEN              = 1 << 8;       // Flash interface Clock Enable During CSleep Mode
            constexpr auto JPGDECLPEN             = 1 << 5;       // JPGDEC Clock Enable During CSleep Mode
            constexpr auto DMA2DLPEN              = 1 << 4;       // DMA2D Clock Enable During CSleep Mode
            constexpr auto MDMALPEN               = 1 << 0;       // MDMA Clock Enable During CSleep Mode

            // AHB1LPENR
            constexpr auto USB2ULPILPEN           = 1 << 28;      // USB_PHY2 clocks enable during CSleep mode
            constexpr auto USB2OTGLPEN            = 1 << 27;      // USB2OTG peripheral clock enable during CSleep mode
            constexpr auto USB1ULPILPEN           = 1 << 26;      // USB_PHY1 clock enable during CSleep mode
            constexpr auto USB1OTGLPEN            = 1 << 25;      // USB1OTG peripheral clock enable during CSleep mode
            constexpr auto ETH1RXLPEN             = 1 << 17;      // Ethernet Reception Clock Enable During CSleep Mode
            constexpr auto ETH1TXLPEN             = 1 << 16;      // Ethernet Transmission Clock Enable During CSleep Mode
            constexpr auto ETH1MACLPEN            = 1 << 15;      // Ethernet MAC bus interface Clock Enable During CSleep Mode
            constexpr auto ADC12LPEN              = 1 << 5;       // ADC1/2 Peripheral Clocks Enable During CSleep Mode
            constexpr auto DMA2LPEN               = 1 << 1;       // DMA2 Clock Enable During CSleep Mode
            constexpr auto DMA1LPEN               = 1 << 0;       // DMA1 Clock Enable During CSleep Mode

            // AHB2LPENR
            constexpr auto SRAM3LPEN              = 1 << 31;      // SRAM3 Clock Enable During CSleep Mode
            constexpr auto SRAM2LPEN              = 1 << 30;      // SRAM2 Clock Enable During CSleep Mode
            constexpr auto SRAM1LPEN              = 1 << 29;      // SRAM1 Clock Enable During CSleep Mode
            constexpr auto SDMMC2LPEN             = 1 << 9;       // SDMMC2 and SDMMC2 Delay Clock Enable During CSleep Mode
            constexpr auto RNGLPEN                = 1 << 6;       // RNG peripheral clock enable during CSleep mode
            constexpr auto HASHLPEN               = 1 << 5;       // HASH peripheral clock enable during CSleep mode
            constexpr auto CRYPTLPEN              = 1 << 4;       // CRYPT peripheral clock enable during CSleep mode
            constexpr auto DCMILPEN               = 1 << 0;       // DCMI peripheral clock enable during CSleep mode

            // AHB4LPENR
            constexpr auto SRAM4LPEN              = 1 << 29;      // SRAM4 Clock Enable During CSleep Mode
            constexpr auto BKPRAMLPEN             = 1 << 28;      // Backup RAM Clock Enable During CSleep Mode
            constexpr auto ADC3LPEN               = 1 << 24;      // ADC3 Peripheral Clocks Enable During CSleep Mode
            constexpr auto BDMALPEN               = 1 << 21;      // BDMA Clock Enable During CSleep Mode
            constexpr auto CRCLPEN                = 1 << 19;      // CRC peripheral clock enable during CSleep mode
            constexpr auto GPIOKLPEN              = 1 << 10;      // GPIOK peripheral clock enable during CSleep mode
            constexpr auto GPIOJLPEN              = 1 << 9;       // GPIOJ peripheral clock enable during CSleep mode
            constexpr auto GPIOILPEN              = 1 << 8;       // GPIOI peripheral clock enable during CSleep mode
            constexpr auto GPIOHLPEN              = 1 << 7;       // GPIOH peripheral clock enable during CSleep mode
            constexpr auto GPIOGLPEN              = 1 << 6;       // GPIOG peripheral clock enable during CSleep mode
            constexpr auto GPIOFLPEN              = 1 << 5;       // GPIOF peripheral clock enable during CSleep mode
            constexpr auto GPIOELPEN              = 1 << 4;       // GPIOE peripheral clock enable during CSleep mode
            constexpr auto GPIODLPEN              = 1 << 3;       // GPIOD peripheral clock enable during CSleep mode
            constexpr auto GPIOCLPEN              = 1 << 2;       // GPIOC peripheral clock enable during CSleep mode
            constexpr auto GPIOBLPEN              = 1 << 1;       // GPIOB peripheral clock enable during CSleep mode
            constexpr auto GPIOALPEN              = 1 << 0;       // GPIOA peripheral clock enable during CSleep mode

            // APB3LPENR
            constexpr auto WWDG1LPEN              = 1 << 6;       // WWDG1 Clock Enable During CSleep Mode
            constexpr auto LTDCLPEN               = 1 << 3;       // LTDC peripheral clock enable during CSleep mode

            // APB1LLPENR
            constexpr auto UART8LPEN              = 1 << 31;      // UART8 Peripheral Clocks Enable During CSleep Mode
            constexpr auto UART7LPEN              = 1 << 30;      // UART7 Peripheral Clocks Enable During CSleep Mode
            constexpr auto DAC12LPEN              = 1 << 29;      // DAC1/2 peripheral clock enable during CSleep mode
            constexpr auto HDMICECLPEN            = 1 << 27;      // HDMI-CEC Peripheral Clocks Enable During CSleep Mode
            constexpr auto I2C3LPEN               = 1 << 23;      // I2C3 Peripheral Clocks Enable During CSleep Mode
            constexpr auto I2C2LPEN               = 1 << 22;      // I2C2 Peripheral Clocks Enable During CSleep Mode
            constexpr auto I2C1LPEN               = 1 << 21;      // I2C1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto UART5LPEN              = 1 << 20;      // UART5 Peripheral Clocks Enable During CSleep Mode
            constexpr auto UART4LPEN              = 1 << 19;      // UART4 Peripheral Clocks Enable During CSleep Mode
            constexpr auto USART3LPEN             = 1 << 18;      // USART3 Peripheral Clocks Enable During CSleep Mode
            constexpr auto USART2LPEN             = 1 << 17;      // USART2 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SPDIFRXLPEN            = 1 << 16;      // SPDIFRX Peripheral Clocks Enable During CSleep Mode
            constexpr auto SPI3LPEN               = 1 << 15;      // SPI3 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SPI2LPEN               = 1 << 14;      // SPI2 Peripheral Clocks Enable During CSleep Mode
            constexpr auto LPTIM1LPEN             = 1 << 9;       // LPTIM1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto TIM14LPEN              = 1 << 8;       // TIM14 peripheral clock enable during CSleep mode
            constexpr auto TIM13LPEN              = 1 << 7;       // TIM13 peripheral clock enable during CSleep mode
            constexpr auto TIM12LPEN              = 1 << 6;       // TIM12 peripheral clock enable during CSleep mode
            constexpr auto TIM7LPEN               = 1 << 5;       // TIM7 peripheral clock enable during CSleep mode
            constexpr auto TIM6LPEN               = 1 << 4;       // TIM6 peripheral clock enable during CSleep mode
            constexpr auto TIM5LPEN               = 1 << 3;       // TIM5 peripheral clock enable during CSleep mode
            constexpr auto TIM4LPEN               = 1 << 2;       // TIM4 peripheral clock enable during CSleep mode
            constexpr auto TIM3LPEN               = 1 << 1;       // TIM3 peripheral clock enable during CSleep mode
            constexpr auto TIM2LPEN               = 1 << 0;       // TIM2 peripheral clock enable during CSleep mode

            // APB1HLPENR
            constexpr auto FDCANLPEN              = 1 << 8;       // FDCAN Peripheral Clocks Enable During CSleep Mode
            constexpr auto MDIOSLPEN              = 1 << 5;       // MDIOS peripheral clock enable during CSleep mode
            constexpr auto OPAMPLPEN              = 1 << 4;       // OPAMP peripheral clock enable during CSleep mode
            constexpr auto SWPLPEN                = 1 << 2;       // SWPMI Peripheral Clocks Enable During CSleep Mode
            constexpr auto CRSLPEN                = 1 << 1;       // Clock Recovery System peripheral clock enable during CSleep mode

            // APB2LPENR
            constexpr auto HRTIMLPEN              = 1 << 29;      // HRTIM peripheral clock enable during CSleep mode
            constexpr auto DFSDM1LPEN             = 1 << 28;      // DFSDM1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SAI3LPEN               = 1 << 24;      // SAI3 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SAI2LPEN               = 1 << 23;      // SAI2 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SAI1LPEN               = 1 << 22;      // SAI1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SPI5LPEN               = 1 << 20;      // SPI5 Peripheral Clocks Enable During CSleep Mode
            constexpr auto TIM17LPEN              = 1 << 18;      // TIM17 peripheral clock enable during CSleep mode
            constexpr auto TIM16LPEN              = 1 << 17;      // TIM16 peripheral clock enable during CSleep mode
            constexpr auto TIM15LPEN              = 1 << 16;      // TIM15 peripheral clock enable during CSleep mode
            constexpr auto SPI4LPEN               = 1 << 13;      // SPI4 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SPI1LPEN               = 1 << 12;      // SPI1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto USART6LPEN             = 1 << 5;       // USART6 Peripheral Clocks Enable During CSleep Mode
            constexpr auto USART1LPEN             = 1 << 4;       // USART1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto TIM8LPEN               = 1 << 1;       // TIM8 peripheral clock enable during CSleep mode
            constexpr auto TIM1LPEN               = 1 << 0;       // TIM1 peripheral clock enable during CSleep mode

            // APB4LPENR
            constexpr auto SAI4LPEN               = 1 << 21;      // SAI4 Peripheral Clocks Enable During CSleep Mode
            constexpr auto RTCAPBLPEN             = 1 << 16;      // RTC APB Clock Enable During CSleep Mode
            constexpr auto VREFLPEN               = 1 << 15;      // VREF peripheral clock enable during CSleep mode
            constexpr auto COMP12LPEN             = 1 << 14;      // COMP1/2 peripheral clock enable during CSleep mode
            constexpr auto LPTIM5LPEN             = 1 << 12;      // LPTIM5 Peripheral Clocks Enable During CSleep Mode
            constexpr auto LPTIM4LPEN             = 1 << 11;      // LPTIM4 Peripheral Clocks Enable During CSleep Mode
            constexpr auto LPTIM3LPEN             = 1 << 10;      // LPTIM3 Peripheral Clocks Enable During CSleep Mode
            constexpr auto LPTIM2LPEN             = 1 << 9;       // LPTIM2 Peripheral Clocks Enable During CSleep Mode
            constexpr auto I2C4LPEN               = 1 << 7;       // I2C4 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SPI6LPEN               = 1 << 5;       // SPI6 Peripheral Clocks Enable During CSleep Mode
            constexpr auto LPUART1LPEN            = 1 << 3;       // LPUART1 Peripheral Clocks Enable During CSleep Mode
            constexpr auto SYSCFGLPEN             = 1 << 1;       // SYSCFG peripheral clock enable during CSleep mode
        }
    }

    namespace SPI{
        constexpr auto SPI1                       = 0x40013000;
        constexpr auto SPI2                       = 0x40003800;
        constexpr auto SPI3                       = 0x40003C00;
        constexpr auto SPI4                       = 0x40013400;
        constexpr auto SPI5                       = 0x40015000;
        constexpr auto SPI6                       = 0x58001400;

        namespace R{
            constexpr auto CR1                    = 0x00;         // control register 1
            constexpr auto CR2                    = 0x04;         // control register 2
            constexpr auto CFG1                   = 0x08;         // configuration register 1
            constexpr auto CFG2                   = 0x0C;         // configuration register 2
            constexpr auto IER                    = 0x10;         // Interrupt Enable Register
            constexpr auto SR                     = 0x14;         // Status Register
            constexpr auto IFCR                   = 0x18;         // Interrupt/Status Flags Clear Register
            constexpr auto TXDR                   = 0x20;         // Transmit Data Register
            constexpr auto RXDR                   = 0x30;         // Receive Data Register
            constexpr auto CRCPOLY                = 0x40;         // Polynomial Register
            constexpr auto TXCRC                  = 0x44;         // Transmitter CRC Register
            constexpr auto RXCRC                  = 0x48;         // Receiver CRC Register
            constexpr auto UDRDR                  = 0x4C;         // Underrun Data Register
            constexpr auto I2SCFGR                = 0x4C;         // SPI/I2S configuration register

            constexpr auto TXR                    = TXDR;
            constexpr auto RXR                    = RXDR;
        }

        namespace B{
            // CR1
            constexpr auto IOLOCK                 = 1 << 16;      // Locking the AF configuration of associated IOs
            constexpr auto TCRCI                  = 1 << 15;      // CRC calculation initialization pattern control for transmitter
            constexpr auto RCRCI                  = 1 << 14;      // CRC calculation initialization pattern control for receiver
            constexpr auto CRC33_17               = 1 << 13;      // 32-bit CRC polynomial configuration
            constexpr auto SSI                    = 1 << 12;      // Internal SS signal input level
            constexpr auto HDDIR                  = 1 << 11;      // Rx/Tx direction at Half-duplex mode
            constexpr auto CSUSP                  = 1 << 10;      // Master SUSPend request
            constexpr auto CSTART                 = 1 << 9;       // Master transfer start
            constexpr auto MASRX                  = 1 << 8;       // Master automatic SUSP in Receive mode
            constexpr auto SPE                    = 1 << 0;       // Serial Peripheral Enable

            // CFG1
            constexpr auto CRCEN                  = 1 << 22;      // Hardware CRC computation enable
            constexpr auto TXDMAEN                = 1 << 15;      // Tx DMA stream enable
            constexpr auto RXDMAEN                = 1 << 14;      // Rx DMA stream enable

            // CFG2
            constexpr auto AFCNTR                 = 1 << 31;      // Alternate function GPIOs control
            constexpr auto SSOM                   = 1 << 30;      // SS output management in master mode
            constexpr auto SSOE                   = 1 << 29;      // SS output enable
            constexpr auto SSIOP                  = 1 << 28;      // SS input/output polarity
            constexpr auto SSM                    = 1 << 26;      // Software management of SS signal input
            constexpr auto CPOL                   = 1 << 25;      // Clock polarity
            constexpr auto CPHA                   = 1 << 24;      // Clock phase
            constexpr auto LSBFRST                = 1 << 23;      // Data frame format
            constexpr auto MASTER                 = 1 << 22;      // SPI Master
            constexpr auto IOSWP                  = 1 << 15;      // Swap functionality of MISO and MOSI pins

            constexpr auto MSTR                   = MASTER;       // SPI Master
            constexpr auto LSBFIRST               = LSBFRST;      // Data frame format

            // IER
            constexpr auto TSERFIE                = 1 << 10;      // Additional number of transactions reload interrupt enable
            constexpr auto MODFIE                 = 1 << 9;       // Mode Fault interrupt enable
            constexpr auto TIFREIE                = 1 << 8;       // TIFRE interrupt enable
            constexpr auto CRCIE                  = 1 << 7;       // CRC Interrupt enable
            constexpr auto OVRIE                  = 1 << 6;       // OVR interrupt enable
            constexpr auto UDRIE                  = 1 << 5;       // UDR interrupt enable
            constexpr auto TXTFIE                 = 1 << 4;       // TXTFIE interrupt enable
            constexpr auto EOTIE                  = 1 << 3;       // EOT, SUSP and TXC interrupt enable
            constexpr auto DPXPIE                 = 1 << 2;       // DXP interrupt enabled
            constexpr auto TXPIE                  = 1 << 1;       // TXP interrupt enable
            constexpr auto RXPIE                  = 1 << 0;       // RXP Interrupt Enable

            // SR
            constexpr auto RXWNE                  = 1 << 15;      // RxFIFO Word Not Empty
            constexpr auto TXC                    = 1 << 12;      // TxFIFO transmission complete
            constexpr auto SUSP                   = 1 << 11;      // SUSPend
            constexpr auto TSERF                  = 1 << 10;      // Additional number of SPI data to be transacted was reload
            constexpr auto MODF                   = 1 << 9;       // Mode Fault
            constexpr auto TIFRE                  = 1 << 8;       // TI frame format error
            constexpr auto CRCE                   = 1 << 7;       // CRC Error
            constexpr auto OVR                    = 1 << 6;       // Overrun
            constexpr auto UDR                    = 1 << 5;       // Underrun at slave transmission mode
            constexpr auto TXTF                   = 1 << 4;       // Transmission Transfer Filled
            constexpr auto EOT                    = 1 << 3;       // End Of Transfer
            constexpr auto DPXP                   = 1 << 2;       // Duplex Packet
            constexpr auto TXP                    = 1 << 1;       // Tx-Packet space available
            constexpr auto RXP                    = 1 << 0;       // Rx-Packet available

            constexpr auto RXNE                   = RXWNE;        // RxFIFO Word Not Empty
            constexpr auto TXE                    = TXP;          // Tx-Packet space available
            constexpr auto RXE                    = RXP;          // Rx-Packet available

            // IFCR
            constexpr auto SUSPC                  = 1 << 11;      // SUSPend flag clear
            constexpr auto TSERFC                 = 1 << 10;      // TSERFC flag clear
            constexpr auto MODFC                  = 1 << 9;       // Mode Fault flag clear
            constexpr auto TIFRC                  = 1 << 8;       // TI frame format error flag clear
            constexpr auto CRCEC                  = 1 << 7;       // CRC Error flag clear
            constexpr auto OVRC                   = 1 << 6;       // Overrun flag clear
            constexpr auto UDRC                   = 1 << 5;       // Underrun flag clear
            constexpr auto TXTFC                  = 1 << 4;       // Transmission Transfer Filled flag clear
            constexpr auto EOTC                   = 1 << 3;       // End Of Transfer flag clear

            // I2SCFGR
            constexpr auto MCKOE                  = 1 << 25;      // Master clock output enable
            constexpr auto ODD                    = 1 << 24;      // Odd factor for the prescaler
            constexpr auto DATFMT                 = 1 << 14;      // Data format
            constexpr auto WSINV                  = 1 << 13;      // Word select inversion
            constexpr auto FIXCH                  = 1 << 12;      // Fixed channel length in slave
            constexpr auto CKPOL                  = 1 << 11;      // Serial audio clock polarity
            constexpr auto CHLEN                  = 1 << 10;      // Channel length (number of bits per audio channel)
            constexpr auto PCMSYNC                = 1 << 7;       // PCM frame synchronization
            constexpr auto I2SMOD                 = 1 << 0;       // I2S mode selection
        }
    }

    namespace USART{
        constexpr auto USART1                     = 0x40011000;
        constexpr auto USART2                     = 0x40004400;
        constexpr auto USART3                     = 0x40004800;
        constexpr auto UART4                      = 0x40004C00;
        constexpr auto UART5                      = 0x40005000;
        constexpr auto USART6                     = 0x40011400;
        constexpr auto UART7                      = 0x40007800;
        constexpr auto UART8                      = 0x40007C00;

        namespace R{
            constexpr auto CR1                    = 0x00;         // Control register 1
            constexpr auto CR2                    = 0x04;         // Control register 2
            constexpr auto CR3                    = 0x08;         // Control register 3
            constexpr auto BRR                    = 0x0C;         // Baud rate register
            constexpr auto GTPR                   = 0x10;         // Guard time and prescaler register
            constexpr auto RTOR                   = 0x14;         // receiver timeout register
            constexpr auto RQR                    = 0x18;         // request register
            constexpr auto ISR                    = 0x1C;         // interrupt and status register
            constexpr auto ICR                    = 0x20;         // interrupt flag clear register
            constexpr auto RDR                    = 0x24;         // receive data register
            constexpr auto TDR                    = 0x28;         // transmit data register
            constexpr auto PRESC                  = 0x2C;         // prescaler register
        }

        namespace B{
            // CR1
            constexpr auto EOBIE                  = 1 << 27;      // End of block interrupt enable
            constexpr auto RTOIE                  = 1 << 26;      // Receiver timeout interrupt enable
            constexpr auto OVER8                  = 1 << 15;      // Oversampling mode
            constexpr auto CMIE                   = 1 << 14;      // Character match interrupt enable
            constexpr auto MME                    = 1 << 13;      // Mute mode enable
            constexpr auto WAKE                   = 1 << 11;      // Receiver wakeup method
            constexpr auto PCE                    = 1 << 10;      // Parity control enable
            constexpr auto PS                     = 1 << 9;       // Parity selection
            constexpr auto PEIE                   = 1 << 8;       // PE interrupt enable
            constexpr auto TXEIE                  = 1 << 7;       // TXE interrupt enable
            constexpr auto TCIE                   = 1 << 6;       // Transmission complete interrupt enable
            constexpr auto RXNEIE                 = 1 << 5;       // RXNE interrupt enable
            constexpr auto IDLEIE                 = 1 << 4;       // IDLE interrupt enable
            constexpr auto TE                     = 1 << 3;       // Transmitter enable
            constexpr auto RE                     = 1 << 2;       // Receiver enable
            constexpr auto UESM                   = 1 << 1;       // USART enable in Stop mode
            constexpr auto UE                     = 1 << 0;       // USART enable

            // CR2
            constexpr auto RTOEN                  = 1 << 23;      // Receiver timeout enable
            constexpr auto ABREN                  = 1 << 20;      // Auto baud rate enable
            constexpr auto MSBFIRST               = 1 << 19;      // Most significant bit first
            constexpr auto DATAINV                = 1 << 18;      // Binary data inversion
            constexpr auto TXINV                  = 1 << 17;      // TX pin active level conversion
            constexpr auto RXINV                  = 1 << 16;      // RX pin active level conversion
            constexpr auto SWAP                   = 1 << 15;      // Swap TX/RX pins
            constexpr auto LINEN                  = 1 << 14;      // LIN mode enable
            constexpr auto CLKEN                  = 1 << 11;      // Clock enable
            constexpr auto CPOL                   = 1 << 10;      // Clock polarity
            constexpr auto CPHA                   = 1 << 9;       // Clock phase
            constexpr auto LBCL                   = 1 << 8;       // Last bit clock pulse
            constexpr auto LBDIE                  = 1 << 6;       // LIN break detection interrupt enable
            constexpr auto LBDL                   = 1 << 5;       // LIN break detection length
            constexpr auto ADDM7                  = 1 << 4;       // 7-bit Adress Detection/4-bit Adress Detection

            // CR3
            constexpr auto TCBGTIE                = 1 << 24;      // Transmission complete before guard time interrupt enable
            constexpr auto WUFIE                  = 1 << 22;      // Wakeup from Stop mode interrupt enable
            constexpr auto DEP                    = 1 << 15;      // Driver enable polartity selection
            constexpr auto DEM                    = 1 << 14;      // Driver enable mode
            constexpr auto DDRE                   = 1 << 13;      // DMA Disable on Reception Error
            constexpr auto OVRDIS                 = 1 << 12;      // Overrun Disable
            constexpr auto ONEBIT                 = 1 << 11;      // One sample bit method enable
            constexpr auto CTSIE                  = 1 << 10;      // CTS interrupt enable
            constexpr auto CTSE                   = 1 << 9;       // CTS enable
            constexpr auto RTSE                   = 1 << 8;       // RTS enable
            constexpr auto DMAT                   = 1 << 7;       // DMA enable transmitter
            constexpr auto DMAR                   = 1 << 6;       // DMA enable receiver
            constexpr auto SCEN                   = 1 << 5;       // Smartcard mode enable
            constexpr auto NACK                   = 1 << 4;       // Smartcard NACK enable
            constexpr auto HDSEL                  = 1 << 3;       // Half-duplex selection
            constexpr auto IRLP                   = 1 << 2;       // IrDA low power
            constexpr auto IREN                   = 1 << 1;       // IrDA mode enable
            constexpr auto EIE                    = 1 << 0;       // Error interrupt enable

            // RQR
            constexpr auto TXFRQ                  = 1 << 4;       // Transmit data flush request
            constexpr auto RXFRQ                  = 1 << 3;       // Receive data flush request
            constexpr auto MMRQ                   = 1 << 2;       // Mute mode request
            constexpr auto SBKRQ                  = 1 << 1;       // Send break request
            constexpr auto ABRRQ                  = 1 << 0;       // Auto baud rate request

            // ISR
            constexpr auto TCBGT                  = 1 << 25;      // Transmission complete before guard time completion
            constexpr auto REACK                  = 1 << 22;      // Receive enable acknowledge flag
            constexpr auto TEACK                  = 1 << 21;      // Transmit enable acknowledge flag
            constexpr auto WUF                    = 1 << 20;      // Wakeup from Stop mode flag
            constexpr auto RWU                    = 1 << 19;      // Receiver wakeup from mute mode
            constexpr auto SBKF                   = 1 << 18;      // Send break flag
            constexpr auto CMF                    = 1 << 17;      // Character match flag
            constexpr auto BUSY                   = 1 << 16;      // Busy flag
            constexpr auto ABRF                   = 1 << 15;      // Auto baud rate flag
            constexpr auto ABRE                   = 1 << 14;      // Auto baud rate error
            constexpr auto EOBF                   = 1 << 12;      // End of block flag
            constexpr auto RTOF                   = 1 << 11;      // Receiver timeout
            constexpr auto CTS                    = 1 << 10;      // CTS flag
            constexpr auto CTSIF                  = 1 << 9;       // CTS interrupt flag
            constexpr auto LBDF                   = 1 << 8;       // LIN break detection flag
            constexpr auto TXE                    = 1 << 7;       // Transmit data register empty
            constexpr auto TC                     = 1 << 6;       // Transmission complete
            constexpr auto RXNE                   = 1 << 5;       // Read data register not empty
            constexpr auto IDLE                   = 1 << 4;       // Idle line detected
            constexpr auto ORE                    = 1 << 3;       // Overrun error
            constexpr auto NF                     = 1 << 2;       // START bit Noise detection flag
            constexpr auto FE                     = 1 << 1;       // Framing error
            constexpr auto PE                     = 1 << 0;       // Parity error

            // ICR
            constexpr auto WUCF                   = 1 << 20;      // Wakeup from Stop mode clear flag
            constexpr auto CMCF                   = 1 << 17;      // Character match clear flag
            constexpr auto EOBCF                  = 1 << 12;      // End of block clear flag
            constexpr auto RTOCF                  = 1 << 11;      // Receiver timeout clear flag
            constexpr auto CTSCF                  = 1 << 9;       // CTS clear flag
            constexpr auto LBDCF                  = 1 << 8;       // LIN break detection clear flag
            constexpr auto TCBGTCF                = 1 << 7;       // Transmission complete before guard time clear flag
            constexpr auto TCCF                   = 1 << 6;       // Transmission complete clear flag
            constexpr auto IDLECF                 = 1 << 4;       // Idle line detected clear flag
            constexpr auto ORECF                  = 1 << 3;       // Overrun error clear flag
            constexpr auto NCF                    = 1 << 2;       // Noise detected flag
            constexpr auto FECF                   = 1 << 1;       // Framing error clear flag
            constexpr auto PECF                   = 1 << 0;       // Parity error clear flag
        }
    }
}

#endif /* LET_DEVICE_STM32_STM32H753XX_HPP */
