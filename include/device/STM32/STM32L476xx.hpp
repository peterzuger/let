/**
 * @file   device/STM32/STM32L476xx.hpp
 * @author Peter Zueger
 * @date   12.08.2018
 * @brief  STM32L476 register offsets
 */
#ifndef LET_DEVICE_STM32_STM32L476XX_HPP
#define LET_DEVICE_STM32_STM32L476XX_HPP

namespace let{
    namespace DMA{
        constexpr auto DMA1             = 0x40020000;
        constexpr auto DMA2             = 0x40020400;

        namespace R{
            constexpr auto ISR          = 0x00;   // DMA interrupt status register
            constexpr auto IFCR         = 0x04;   // DMA interrupt flag clear register
            constexpr auto CCRx         = 0x08;   // DMA channel x configuration register -->  Address offset: 0x08 + 0x14 * (x - 1), (x = 1 to 7)
            constexpr auto CNDTRx       = 0x0C;   // DMA channel x number of data to transfer register
            constexpr auto CPARx        = 0x10;   // DMA channel x peripheral address register
            constexpr auto CMARx        = 0x14;   // DMA channel x memory address register
            constexpr auto CSELR        = 0xA8;   // DMA channel selection register
        }

        namespace B{
            // ISR
            constexpr auto TEIF7        = 1 << 27;// transfer error (TE) flag for channel 7
            constexpr auto HTIF7        = 1 << 26;// half transfer (HT) flag for channel 7
            constexpr auto TCIF7        = 1 << 25;// transfer complete (TC) flag for channel 7
            constexpr auto GIF7         = 1 << 24;// global interrupt flag for channel 7
            constexpr auto TEIF6        = 1 << 23;// transfer error (TE) flag for channel 6
            constexpr auto HTIF6        = 1 << 22;// half transfer (HT) flag for channel 6
            constexpr auto TCIF6        = 1 << 21;// transfer complete (TC) flag for channel 6
            constexpr auto GIF6         = 1 << 20;// global interrupt flag for channel 6
            constexpr auto TEIF5        = 1 << 19;// transfer error (TE) flag for channel 5
            constexpr auto HTIF5        = 1 << 18;// half transfer (HT) flag for channel 5
            constexpr auto TCIF5        = 1 << 17;// transfer complete (TC) flag for channel 5
            constexpr auto GIF5         = 1 << 16;// global interrupt flag for channel 5
            constexpr auto TEIF4        = 1 << 15;// transfer error (TE) flag for channel 4
            constexpr auto HTIF4        = 1 << 14;// half transfer (HT) flag for channel 4
            constexpr auto TCIF4        = 1 << 13;// transfer complete (TC) flag for channel 4
            constexpr auto GIF4         = 1 << 12;// global interrupt flag for channel 4
            constexpr auto TEIF3        = 1 << 11;// transfer error (TE) flag for channel 3
            constexpr auto HTIF3        = 1 << 10;// half transfer (HT) flag for channel 3
            constexpr auto TCIF3        = 1 << 9; // transfer complete (TC) flag for channel 3
            constexpr auto GIF3         = 1 << 8; // global interrupt flag for channel 3
            constexpr auto TEIF2        = 1 << 7; // transfer error (TE) flag for channel 2
            constexpr auto HTIF2        = 1 << 6; // half transfer (HT) flag for channel 2
            constexpr auto TCIF2        = 1 << 5; // transfer complete (TC) flag for channel 2
            constexpr auto GIF2         = 1 << 4; // global interrupt flag for channel 2
            constexpr auto TEIF1        = 1 << 3; // transfer error (TE) flag for channel 1
            constexpr auto HTIF1        = 1 << 2; // half transfer (HT) flag for channel 1
            constexpr auto TCIF1        = 1 << 1; // transfer complete (TC) flag for channel 1
            constexpr auto GIF1         = 1 << 0; // global interrupt flag for channel 1

            // IFCR
            constexpr auto CTEIF7       = 1 << 27;// transfer error flag clear for channel 7
            constexpr auto CHTIF7       = 1 << 26;// half transfer flag clear for channel 7
            constexpr auto CTCIF7       = 1 << 25;// transfer complete flag clear for channel 7
            constexpr auto CGIIF7       = 1 << 24;// global interrupt flag clear for channel 7
            constexpr auto CTEIF6       = 1 << 23;// transfer error flag clear for channel 6
            constexpr auto CHTIF6       = 1 << 22;// half transfer flag clear for channel 6
            constexpr auto CTCIF6       = 1 << 21;// transfer complete flag clear for channel 6
            constexpr auto CGIIF6       = 1 << 20;// global interrupt flag clear for channel 6
            constexpr auto CTEIF5       = 1 << 19;// transfer error flag clear for channel 5
            constexpr auto CHTIF5       = 1 << 18;// half transfer flag clear for channel 5
            constexpr auto CTCIF5       = 1 << 17;// transfer complete flag clear for channel 5
            constexpr auto CGIIF5       = 1 << 16;// global interrupt flag clear for channel 5
            constexpr auto CTEIF4       = 1 << 15;// transfer error flag clear for channel 4
            constexpr auto CHTIF4       = 1 << 14;// half transfer flag clear for channel 4
            constexpr auto CTCIF4       = 1 << 13;// transfer complete flag clear for channel 4
            constexpr auto CGIIF4       = 1 << 12;// global interrupt flag clear for channel 4
            constexpr auto CTEIF3       = 1 << 11;// transfer error flag clear for channel 3
            constexpr auto CHTIF3       = 1 << 10;// half transfer flag clear for channel 3
            constexpr auto CTCIF3       = 1 << 9; // transfer complete flag clear for channel 3
            constexpr auto CGIIF3       = 1 << 8; // global interrupt flag clear for channel 3
            constexpr auto CTEIF2       = 1 << 7; // transfer error flag clear for channel 2
            constexpr auto CHTIF2       = 1 << 6; // half transfer flag clear for channel 2
            constexpr auto CTCIF2       = 1 << 5; // transfer complete flag clear for channel 2
            constexpr auto CGIIF2       = 1 << 4; // global interrupt flag clear for channel 2
            constexpr auto CTEIF1       = 1 << 3; // transfer error flag clear for channel 1
            constexpr auto CHTIF1       = 1 << 2; // half transfer flag clear for channel 1
            constexpr auto CTCIF1       = 1 << 1; // transfer complete flag clear for channel 1
            constexpr auto CGIIF1       = 1 << 0; // global interrupt flag clear for channel 1

            // CCRx
            constexpr auto MEM2MEM      = 1 << 14;// memory-to-memory mode
            constexpr auto MINC         = 1 << 7; // memory increment mode
            constexpr auto PINC         = 1 << 6; // peripheral increment mode
            constexpr auto CIRC         = 1 << 5; // circular mode
            constexpr auto DIR          = 1 << 4; // data transfer direction
            constexpr auto TEIE         = 1 << 3; // transfer error interrupt enable
            constexpr auto HTIE         = 1 << 2; // half transfer interrupt enable
            constexpr auto TCIE         = 1 << 1; // transfer complete interrupt enable
            constexpr auto EN           = 1 << 0; // channel enable
        }
    }

    namespace GPIO{
        constexpr auto GPIOA            = 0x48000000;
        constexpr auto GPIOB            = 0x48000400;
        constexpr auto GPIOC            = 0x48000800;
        constexpr auto GPIOD            = 0x48000C00;
        constexpr auto GPIOE            = 0x48001000;
        constexpr auto GPIOF            = 0x48001400;
        constexpr auto GPIOG            = 0x48001800;
        constexpr auto GPIOH            = 0x48001C00;

        namespace R{
            constexpr auto MODER        = 0x00;   // Port mode register
            constexpr auto OTYPER       = 0x04;   // Port output type register
            constexpr auto OSPEEDR      = 0x08;   // Port output speed register
            constexpr auto PUPDR        = 0x0C;   // Port pull-up/pull-down register
            constexpr auto IDR          = 0x10;   // Port input data register
            constexpr auto ODR          = 0x14;   // Port output data register
            constexpr auto BSRR         = 0x18;   // Port bit set/reset register
            constexpr auto LCKR         = 0x1C;   // Port configuration lock register
            constexpr auto AFRL         = 0x20;   // Alternate function low register
            constexpr auto AFRH         = 0x24;   // Alternate function high register
            constexpr auto BRR          = 0x28;   // Port bit reset register
            constexpr auto ASCR         = 0x2C;   // Port analog switch control register
        }

        namespace B{
            // MODER
            constexpr auto Input        = 0b00;   // GPIO pin input mode mask
            constexpr auto Output       = 0b01;   // GPIO pin output mode mask
            constexpr auto Analog       = 0b10;   // GPIO pin analog mode mask
            constexpr auto Alternate    = 0b11;   // GPIO pin alternate mode mask

            // OSPEEDR
            constexpr auto Slow         = 0b00;   // GPIO pin speed slow
            constexpr auto Medium       = 0b01;   // GPIO pin speed medium
            constexpr auto Fast         = 0b10;   // GPIO pin speed fast
            constexpr auto High         = 0b11;   // GPIO pin speed high

            // PUPDR
            constexpr auto NoPull       = 0b00;   // GPIO pin no pullup/down resistor
            constexpr auto Pullup       = 0b01;   // GPIO pin pullup enabled
            constexpr auto Pulldown     = 0b10;   // GPIO pin pulldown enabled

            // LCKR
            constexpr auto LCKK         = 1 << 16;// Lock key
        }
    }

    namespace RCC{
        constexpr auto RCC              = 0x40021000;

        namespace R{
            constexpr auto CR           = 0x00;   // Clock control register
            constexpr auto ICSCR        = 0x04;   // Internal clock sources calibration register
            constexpr auto CFGR         = 0x08;   // Clock configuration register
            constexpr auto PLLCFGR      = 0x0C;   // PLL configuration register
            constexpr auto PLLSAI1CFGR  = 0x10;   // PLLSAI1 configuration register
            constexpr auto PLLSAI2CFGR  = 0x14;   // PLLSAI2 configuration register
            constexpr auto CIER         = 0x18;   // Clock interrupt enable register
            constexpr auto CIFR         = 0x1C;   // Clock interrupt flag register
            constexpr auto CICR         = 0x20;   // Clock interrupt clear register
            constexpr auto AHB1RSTR     = 0x28;   // AHB1 peripheral reset register
            constexpr auto AHB2RSTR     = 0x2C;   // AHB2 peripheral reset register
            constexpr auto AHB3RSTR     = 0x30;   // AHB3 peripheral reset register
            constexpr auto APB1RSTR1    = 0x38;   // APB1 peripheral reset register 1
            constexpr auto APB1RSTR2    = 0x3C;   // APB1 peripheral reset register 2
            constexpr auto APB2RSTR     = 0x40;   // APB2 peripheral reset register
            constexpr auto AHB1ENR      = 0x48;   // AHB1 peripheral clock enable register
            constexpr auto AHB2ENR      = 0x4C;   // AHB2 peripheral clock enable register
            constexpr auto AHB3ENR      = 0x50;   // AHB3 peripheral clock enable register
            constexpr auto APB1ENR1     = 0x58;   // APB1 peripheral clock enable register 1
            constexpr auto APB1ENR2     = 0x5C;   // APB1 peripheral clock enable register 2
            constexpr auto APB2ENR      = 0x60;   // APB2 peripheral clock enable register
            constexpr auto AHB1SMENR    = 0x68;   // AHB1 peripheral clocks enable in Sleep and Stop modes register
            constexpr auto AHB2SMENR    = 0x6C;   // AHB2 peripheral clocks enable in Sleep and Stop modes register
            constexpr auto AHB3SMENR    = 0x70;   // AHB3 peripheral clocks enable in Sleep and Stop modes register
            constexpr auto APB1SMENR1   = 0x78;   // APB1 peripheral clocks enable in Sleep and Stop modes register 1
            constexpr auto APB1SMENR2   = 0x7C;   // APB1 peripheral clocks enable in Sleep and Stop modes register 2
            constexpr auto APB2SMENR    = 0x80;   // APB2 peripheral clocks enable in Sleep and Stop modes register
            constexpr auto CCIPR        = 0x88;   // Peripherals independent clock configuration register
            constexpr auto BDCR         = 0x90;   // Backup domain control register
            constexpr auto CSR          = 0x94;   // Control/status register
         // constexpr auto CRRCR        = 0x98;   // Clock recovery RC register L496/L4A6 devices only
         // constexpr auto CCIPR2       = 0x9C;   // Peripherals independent clock configuration register L496/L4A6 devices only
        }

        namespace B{
            // CR
            constexpr auto PLLSAI2RDY   = 1 << 29;// SAI2 PLL clock ready flag
            constexpr auto PLLSAI2ON    = 1 << 28;// SAI2 PLL enable
            constexpr auto PLLSAI1RDY   = 1 << 27;// SAI1 PLL clock ready flag
            constexpr auto PLLSAI1ON    = 1 << 26;// SAI1 PLL enable
            constexpr auto PLLRDY       = 1 << 25;// Main PLL clock ready flag
            constexpr auto PLLON        = 1 << 24;// Main PLL enable
            constexpr auto CSSON        = 1 << 19;// Clock security system enable
            constexpr auto HSEBYP       = 1 << 18;// HSE crystal oscillator bypass
            constexpr auto HSERDY       = 1 << 17;// HSE clock ready flag
            constexpr auto HSEON        = 1 << 16;// HSE clock enable
            constexpr auto HSIASFS      = 1 << 11;// HSI16 automatic start from Stop
            constexpr auto HSIRDY       = 1 << 10;// HSI16 clock ready flag
            constexpr auto HSIKERON     = 1 << 9; // HSI16 always enable for peripheral kernels
            constexpr auto HSION        = 1 << 8; // HSI16 clock enable
            constexpr auto MSIRGSEL     = 1 << 3; // MSI clock range selection
            constexpr auto MSIPLLEN     = 1 << 2; // MSI clock PLL enable
            constexpr auto MSIRDY       = 1 << 1; // MSI clock ready flag
            constexpr auto MSION        = 1 << 0; // MSI clock enable

            // CFGR
            constexpr auto STOPWUCK     = 1 << 15;// Wakeup from Stop and CSS backup clock selection

            // PLLCFGR
            constexpr auto PLLREN       = 1 << 24;// Main PLL PLLCLK output enable
            constexpr auto PLLQEN       = 1 << 20;// Main PLL PLL48M1CLK output enable
            constexpr auto PLLP         = 1 << 17;// Main PLL division factor for PLLSAI3CLK (SAI1 and SAI2 clock)
            constexpr auto PLLPEN       = 1 << 16;// Main PLL PLLSAI3CLK output enable

            // PLLSAI1CFGR
            constexpr auto PLLSAI1REN   = 1 << 24;// PLLSAI1 PLLADC1CLK output enable
            constexpr auto PLLSAI1QEN   = 1 << 20;// PLLSAI1 PLL48M2CLK output enable
            constexpr auto PLLSAI1P     = 1 << 17;// PLLSAI1 division factor for PLLSAI1CLK (SAI1 or SAI2 clock)
            constexpr auto PLLSAI1PEN   = 1 << 16;// PLLSAI1 PLLSAI1CLK output enable

            // PLLSAI2CFGR
            constexpr auto PLLSAI2REN   = 1 << 24;// PLLSAI2 PLLADC2CLK output enable
         // constexpr auto PLLSAI2QEN   = 1 << 20;// RESERVED MUST BE KEPT AT RESET VALUE
            constexpr auto PLLSAI2P     = 1 << 17;// PLLSAI2 division factor for PLLSAI2CLK (SAI1 or SAI2 clock)
            constexpr auto PLLSAI2PEN   = 1 << 16;// PLLSAI2 PLLSAI2CLK output enable

            // CIER
            constexpr auto HSI48RDYIE   = 1 << 10;// HSI48 ready interrupt enable (only on STM32L496xx/4A6xx devices)
            constexpr auto LSECSSIE     = 1 << 9; // LSE clock security system interrupt enable
            constexpr auto PLLSAI2RDYIE = 1 << 7; // PLLSAI2 ready interrupt enable
            constexpr auto PLLSAI1RDYIE = 1 << 6; // PLLSAI1 ready interrupt enable
            constexpr auto PLLRDYIE     = 1 << 5; // PLL ready interrupt enable
            constexpr auto HSERDYIE     = 1 << 4; // HSE ready interrupt enable
            constexpr auto HSIRDYIE     = 1 << 3; // HSI16 ready interrupt enable
            constexpr auto MSIRDYIE     = 1 << 2; // MSI ready interrupt enable
            constexpr auto LSERDYIE     = 1 << 1; // LSE ready interrupt enable
            constexpr auto LSIRDYIE     = 1 << 0; // LSI ready interrupt enable

            // CIFR
            constexpr auto HSI48RDYF    = 1 << 10;// HSI48 ready interrupt flag (only on STM32L496xx/4A6xx devices)
            constexpr auto LSECSSF      = 1 << 9; // LSE Clock security system interrupt flag
            constexpr auto CSSF         = 1 << 8; // Clock security system interrupt flag
            constexpr auto PLLSAI2RDYF  = 1 << 7; // PLLSAI2 ready interrupt flag
            constexpr auto PLLSAI1RDYF  = 1 << 6; // PLLSAI1 ready interrupt flag
            constexpr auto PLLRDYF      = 1 << 5; // PLL ready interrupt flag
            constexpr auto HSERDYF      = 1 << 4; // HSE ready interrupt flag
            constexpr auto HSIRDYF      = 1 << 3; // HSI16 ready interrupt flag
            constexpr auto MSIRDYF      = 1 << 2; // MSI ready interrupt flag
            constexpr auto LSERDYF      = 1 << 1; // LSE ready interrupt flag
            constexpr auto LSIRDYF      = 1 << 0; // LSI ready interrupt flag

            // CICR
            constexpr auto HSI48RDYC    = 1 << 10;// HSI48 oscillator ready interrupt clear (only on STM32L496xx/4A6xx devices)
            constexpr auto LSECSSC      = 1 << 9; // LSE Clock security system interrupt clear
            constexpr auto CSSC         = 1 << 8; // Clock security system interrupt clear
            constexpr auto PLLSAI2RDYC  = 1 << 7; // PLLSAI2 ready interrupt clear
            constexpr auto PLLSAI1RDYC  = 1 << 6; // PLLSAI1 ready interrupt clear
            constexpr auto PLLRDYC      = 1 << 5; // PLL ready interrupt clear
            constexpr auto HSERDYC      = 1 << 4; // HSE ready interrupt clear
            constexpr auto HSIRDYC      = 1 << 3; // HSI16 ready interrupt clear
            constexpr auto MSIRDYC      = 1 << 2; // MSI ready interrupt clear
            constexpr auto LSERDYC      = 1 << 1; // LSE ready interrupt clear
            constexpr auto LSIRDYC      = 1 << 0; // LSI ready interrupt clear

            // AHB1RSTR
            constexpr auto DMA2DRST     = 1 << 17;// DMA2D reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto TSCRST       = 1 << 16;// Touch Sensing Controller reset
            constexpr auto CRCRST       = 1 << 12;// CRC reset
            constexpr auto FLASHRST     = 1 << 8; // Flash memory interface reset
            constexpr auto DMA2RST      = 1 << 1; // DMA2 reset
            constexpr auto DMA1RST      = 1 << 0; // DMA1 reset

            // AHB2RSTR
            constexpr auto RNGRST       = 1 << 18;// Random number generator reset
            constexpr auto HASHRST      = 1 << 17;// Hash reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto AESRST       = 1 << 16;// AES hardware accelerator reset
            constexpr auto DCMIRST      = 1 << 14;// Digital Camera Interface reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto ADCRST       = 1 << 13;// ADC reset
            constexpr auto OTGFSRST     = 1 << 12;// USB OTG FS reset
            constexpr auto GPIOIRST     = 1 << 8; // IO port I reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto GPIOHRST     = 1 << 7; // IO port H reset
            constexpr auto GPIOGRST     = 1 << 6; // IO port G reset
            constexpr auto GPIOFRST     = 1 << 5; // IO port F reset
            constexpr auto GPIOERST     = 1 << 4; // IO port E reset
            constexpr auto GPIODRST     = 1 << 3; // IO port D reset
            constexpr auto GPIOCRST     = 1 << 2; // IO port C reset
            constexpr auto GPIOBRST     = 1 << 1; // IO port B reset
            constexpr auto GPIOARST     = 1 << 0; // IO port A reset

            // AHB3RSTR
            constexpr auto QSPIRST      = 1 << 8; // QUADSPI1 memory interface reset
            constexpr auto FMCRST       = 1 << 0; // Flexible memory controller reset

            // APB1RSTR1
            constexpr auto LPTIM1RST    = 1 << 31;// Low Power Timer 1 reset
            constexpr auto OPAMPRST     = 1 << 30;// OPAMP interface reset
            constexpr auto DAC1RST      = 1 << 29;// DAC1 interface reset
            constexpr auto PWRRST       = 1 << 28;// Power interface reset
            constexpr auto CAN2RST      = 1 << 26;// CAN2 reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto CAN1RST      = 1 << 25;// CAN1 reset
            constexpr auto CRSRST       = 1 << 24;// CRS reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto I2C3RST      = 1 << 23;// I2C3 reset
            constexpr auto I2C2RST      = 1 << 22;// I2C2 reset
            constexpr auto I2C1RST      = 1 << 21;// I2C1 reset
            constexpr auto UART5RST     = 1 << 20;// UART5 reset
            constexpr auto UART4RST     = 1 << 19;// UART4 reset
            constexpr auto USART3RST    = 1 << 18;// USART3 reset
            constexpr auto USART2RST    = 1 << 17;// USART2 reset
            constexpr auto SPI3RST      = 1 << 15;// SPI3 reset
            constexpr auto SPI2RST      = 1 << 14;// SPI2 reset
            constexpr auto LCDRST       = 1 << 9; // LCD interface reset
            constexpr auto TIM7RSTRST   = 1 << 5; // TIM7 timer reset
            constexpr auto TIM6RSTRST   = 1 << 4; // TIM6 timer reset
            constexpr auto TIM5RSTRST   = 1 << 3; // TIM5 timer reset
            constexpr auto TIM4RSTRST   = 1 << 2; // TIM4 timer reset
            constexpr auto TIM3RSTRST   = 1 << 1; // TIM3 timer reset
            constexpr auto TIM2RSTRST   = 1 << 0; // TIM2 timer reset

            // APB1RSTR2
            constexpr auto LPTIM2RST    = 1 << 5; // Low-power timer 2 reset
            constexpr auto SWPMI1RST    = 1 << 2; // Single wire protocol reset
            constexpr auto I2C4RST      = 1 << 1; // I2C4 reset (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto LPUART1RST   = 1 << 0; // Low-power UART 1 reset

            // APB2RSTR
            constexpr auto DFSDM1RST    = 1 << 24;// Digital filters for sigma-delta modulators (DFSDM1) reset
            constexpr auto SAI2RST      = 1 << 22;// Serial audio interface 2 (SAI2) reset
            constexpr auto SAI1RST      = 1 << 21;// Serial audio interface 1 (SAI1) reset
            constexpr auto TIM17RST     = 1 << 18;// TIM17 timer reset
            constexpr auto TIM16RST     = 1 << 17;// TIM16 timer reset
            constexpr auto TIM15RST     = 1 << 16;// TIM15 timer reset
            constexpr auto USART1RST    = 1 << 14;// USART1 reset
            constexpr auto TIM8RST      = 1 << 13;// TIM8 timer reset
            constexpr auto SPI1RST      = 1 << 12;// SPI1 reset
            constexpr auto TIM1RST      = 1 << 11;// TIM1 timer reset
            constexpr auto SDMMC1RST    = 1 << 10;// SDMMC reset
            constexpr auto SYSCFGRST    = 1 << 0; // SYSCFG + COMP + VREFBUF reset

            // AHB1ENR
            constexpr auto DMA2DEN      = 1 << 17;// DMA2D clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto TSCEN        = 1 << 16;// Touch Sensing Controller clock enable
            constexpr auto CRCEN        = 1 << 12;// CRC clock enable
            constexpr auto FLASHEN      = 1 << 8; // Flash memory interface clock enable
            constexpr auto DMA2EN       = 1 << 1; // DMA2 clock enable
            constexpr auto DMA1EN       = 1 << 0; // DMA1 clock enable

            // AHB2ENR
            constexpr auto RNGEN        = 1 << 18;// Random Number Generator clock enable
            constexpr auto HASHEN       = 1 << 17;// HASH clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto AESEN        = 1 << 16;// AES accelerator clock enable
            constexpr auto DCMIEN       = 1 << 14;// DCMI clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto ADCEN        = 1 << 13;// ADC clock enable
            constexpr auto OTGFSEN      = 1 << 12;// OTG full speed clock enable
            constexpr auto GPIOIEN      = 1 << 8; // IO port I clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto GPIOHEN      = 1 << 7; // IO port H clock enable
            constexpr auto GPIOGEN      = 1 << 6; // IO port G clock enable
            constexpr auto GPIOFEN      = 1 << 5; // IO port F clock enable
            constexpr auto GPIOEEN      = 1 << 4; // IO port E clock enable
            constexpr auto GPIODEN      = 1 << 3; // IO port D clock enable
            constexpr auto GPIOCEN      = 1 << 2; // IO port C clock enable
            constexpr auto GPIOBEN      = 1 << 1; // IO port B clock enable
            constexpr auto GPIOAEN      = 1 << 0; // IO port A clock enable

            // AHB3ENR
            constexpr auto QSPIEN       = 1 << 8; // Quad SPI memory interface clock enable
            constexpr auto FMCEN        = 1 << 0; // Flexible memory controller clock enable

            // APB1ENR1
            constexpr auto LPTIM1EN     = 1 << 31;// Low power timer 1 clock enable
            constexpr auto OPAMPEN      = 1 << 30;// OPAMP interface clock enable
            constexpr auto DAC1EN       = 1 << 29;// DAC1 interface clock enable
            constexpr auto PWREN        = 1 << 28;// Power interface clock enable
            constexpr auto CAN2EN       = 1 << 26;// CAN2 clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto CAN1EN       = 1 << 25;// CAN1 clock enable
            constexpr auto CRSEN        = 1 << 24;// Clock Recovery System clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto I2C3EN       = 1 << 23;// I2C3 clock enable
            constexpr auto I2C2EN       = 1 << 22;// I2C2 clock enable
            constexpr auto I2C1EN       = 1 << 21;// I2C1 clock enable
            constexpr auto UART5EN      = 1 << 20;// UART5 clock enable
            constexpr auto UART4EN      = 1 << 19;// UART4 clock enable
            constexpr auto USART3EN     = 1 << 18;// USART3 clock enable
            constexpr auto USART2EN     = 1 << 17;// USART2 clock enable
            constexpr auto SPI3EN       = 1 << 15;// SPI3 clock enable
            constexpr auto SPI2EN       = 1 << 14;// SPI2 clock enable
            constexpr auto WWDGEN       = 1 << 11;// Window watchdog clock enable
            constexpr auto RTCAPBEN     = 1 << 10;// RTC APB clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto LCDEN        = 1 << 9; // LCD clock enable
            constexpr auto TIM7EN       = 1 << 5; // TIM7 timer clock enable
            constexpr auto TIM6EN       = 1 << 4; // TIM6 timer clock enable
            constexpr auto TIM5EN       = 1 << 3; // TIM5 timer clock enable
            constexpr auto TIM4EN       = 1 << 2; // TIM4 timer clock enable
            constexpr auto TIM3EN       = 1 << 1; // TIM3 timer clock enable
            constexpr auto TIM2EN       = 1 << 0; // TIM2 timer clock enable

            // APB1ENR2
            constexpr auto LPTIM2EN     = 1 << 5; // Low power timer 2 clock enable
            constexpr auto SWPMI1EN     = 1 << 2; // Single wire protocol clock enable
            constexpr auto I2C4EN       = 1 << 1; // I2C4 clock enable (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto LPUART1EN    = 1 << 0; // Low power UART 1 clock enable

            // APB2ENR
            constexpr auto DFSDM1EN     = 1 << 24;// DFSDM1 timer clock enable
            constexpr auto SAI2EN       = 1 << 22;// SAI2 clock enable
            constexpr auto SAI1EN       = 1 << 21;// SAI1 clock enable
            constexpr auto TIM17EN      = 1 << 18;// TIM17 timer clock enable
            constexpr auto TIM16EN      = 1 << 17;// TIM16 timer clock enable
            constexpr auto TIM15EN      = 1 << 16;// TIM15 timer clock enable
            constexpr auto USART1EN     = 1 << 14;// USART1 clock enable
            constexpr auto TIM8EN       = 1 << 13;// TIM8 timer clock enable
            constexpr auto SPI1EN       = 1 << 12;// SPI1 clock enable
            constexpr auto TIM1EN       = 1 << 11;// TIM1 timer clock enable
            constexpr auto SDMMC1EN     = 1 << 10;// SDMMC clock enable
            constexpr auto FWEN         = 1 << 7; // Firewall clock enable
            constexpr auto SYSCFGEN     = 1 << 0; // SYSCFG + COMP + VREFBUF clock enable

            // AHB1SMENR
            constexpr auto DMA2DSMEN    = 1 << 17;// DMA2D clock enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto TSCSMEN      = 1 << 16;// Touch Sensing Controller clocks enable during Sleep and Stop modes
            constexpr auto CRCSMEN      = 1 << 12;// CRC clocks enable during Sleep and Stop modes
            constexpr auto SRAM1SMEN    = 1 << 9; // SRAM1 interface clocks enable during Sleep and Stop modes
            constexpr auto FLASHSMEN    = 1 << 8; // Flash memory interface clocks enable during Sleep and Stop modes
            constexpr auto DMA2SMEN     = 1 << 1; // DMA2 clocks enable during Sleep and Stop modes
            constexpr auto DMA1SMEN     = 1 << 0; // DMA1 clocks enable during Sleep and Stop modes

            // AHB2SMENR
            constexpr auto RNGSMEN      = 1 << 18;// Random Number Generator clocks enable during Sleep and Stop modes
            constexpr auto HASHSMEN     = 1 << 17;// HASH clock enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto AESSMEN      = 1 << 16;// AES accelerator clocks enable during Sleep and Stop modes
            constexpr auto DCMISMEN     = 1 << 14;// DCMI clock enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto ADCSMEN      = 1 << 13;// ADC clocks enable during Sleep and Stop modes
            constexpr auto OTGFSSMEN    = 1 << 12;// OTG full speed clocks enable during Sleep and Stop modes
            constexpr auto SRAM2SMEN    = 1 << 9; // SRAM2 interface clocks enable during Sleep and Stop modes
            constexpr auto GPIOISMEN    = 1 << 8; // IO port I clocks enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto GPIOHSMEN    = 1 << 7; // IO port H clocks enable during Sleep and Stop modes
            constexpr auto GPIOGSMEN    = 1 << 6; // IO port G clocks enable during Sleep and Stop modes
            constexpr auto GPIOFSMEN    = 1 << 5; // IO port F clocks enable during Sleep and Stop modes
            constexpr auto GPIOESMEN    = 1 << 4; // IO port E clocks enable during Sleep and Stop modes
            constexpr auto GPIODSMEN    = 1 << 3; // IO port D clocks enable during Sleep and Stop modes
            constexpr auto GPIOCSMEN    = 1 << 2; // IO port C clocks enable during Sleep and Stop modes
            constexpr auto GPIOBSMEN    = 1 << 1; // IO port B clocks enable during Sleep and Stop modes
            constexpr auto GPIOASMEN    = 1 << 0; // IO port A clocks enable during Sleep and Stop modes

            // AHB3SMENR
            constexpr auto QSPISMEN     = 1 << 8; // Quad SPI memory interface clocks enable during Sleep and Stop modes
            constexpr auto FMCSMEN      = 1 << 0; // Flexible memory controller clocks enable during Sleep and Stop modes

            // APB1SMENR1
            constexpr auto LPTIM1SMEN   = 1 << 31;// Low power timer 1 clocks enable during Sleep and Stop modes
            constexpr auto OPAMPSMEN    = 1 << 30;// OPAMP interface clocks enable during Sleep and Stop modes
            constexpr auto DAC1SMEN     = 1 << 29;// DAC1 interface clocks enable during Sleep and Stop modes
            constexpr auto PWRSMEN      = 1 << 28;// Power interface clocks enable during Sleep and Stop modes
            constexpr auto CAN2SMEN     = 1 << 26;// CAN2 clocks enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto CAN1SMEN     = 1 << 25;// CAN1 clocks enable during Sleep and Stop modes
            constexpr auto CRSSMEN      = 1 << 24;// CRS clock enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto I2C3SMEN     = 1 << 23;// I2C3 clocks enable during Sleep and Stop modes
            constexpr auto I2C2SMEN     = 1 << 22;// I2C2 clocks enable during Sleep and Stop modes
            constexpr auto I2C1SMEN     = 1 << 21;// I2C1 clocks enable during Sleep and Stop modes
            constexpr auto UART5SMEN    = 1 << 20;// UART5 clocks enable during Sleep and Stop modes
            constexpr auto UART4SMEN    = 1 << 19;// UART4 clocks enable during Sleep and Stop modes
            constexpr auto USART3SMEN   = 1 << 18;// USART3 clocks enable during Sleep and Stop modes
            constexpr auto USART2SMEN   = 1 << 17;// USART2 clocks enable during Sleep and Stop modes
            constexpr auto SPI3SMEN     = 1 << 15;// SPI3 clocks enable during Sleep and Stop modes
            constexpr auto SPI2SMEN     = 1 << 14;// SPI2 clocks enable during Sleep and Stop modes
            constexpr auto WWDGSMEN     = 1 << 11;// Window watchdog clocks enable during Sleep and Stop modes
            constexpr auto RTCAPBSMEN   = 1 << 10;// RTC APB clock enable during Sleep and Stop modes
            constexpr auto LCDSMEN      = 1 << 9; // LCD clocks enable during Sleep and Stop modes
            constexpr auto TIM7SMEN     = 1 << 5; // TIM7 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM6SMEN     = 1 << 4; // TIM6 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM5SMEN     = 1 << 3; // TIM5 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM4SMEN     = 1 << 2; // TIM4 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM3SMEN     = 1 << 1; // TIM3 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM2SMEN     = 1 << 0; // TIM2 timer clocks enable during Sleep and Stop modes

            // APB1SMENR2
            constexpr auto LPTIM2SMEN   = 1 << 5; // Low power timer 2 clocks enable during Sleep and Stop modes
            constexpr auto SWPMI1SMEN   = 1 << 2; // Single wire protocol clocks enable during Sleep and Stop modes
            constexpr auto I2C4SMEN     = 1 << 1; // I2C4 clocks enable during Sleep and Stop modes (This bit is reserved for STM32L475xx/476xx/486xx devices)
            constexpr auto LPUART1SMEN  = 1 << 0; // Low power UART 1 clocks enable during Sleep and Stop modes

            // APB2SMENR
            constexpr auto DFSDSMEN     = 1 << 24;// DFSDM1 timer clocks enable during Sleep and Stop modes
            constexpr auto SAI2SMEN     = 1 << 22;// SAI2 clocks enable during Sleep and Stop modes
            constexpr auto SAI1SMEN     = 1 << 21;// SAI1 clocks enable during Sleep and Stop modes
            constexpr auto TIM17SMEN    = 1 << 18;// TIM17 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM16SMEN    = 1 << 17;// TIM16 timer clocks enable during Sleep and Stop modes
            constexpr auto TIM15SMEN    = 1 << 16;// TIM15 timer clocks enable during Sleep and Stop modes
            constexpr auto USART1SMEN   = 1 << 14;// USART1clocks enable during Sleep and Stop modes
            constexpr auto TIM8SMEN     = 1 << 13;// TIM8 timer clocks enable during Sleep and Stop modes
            constexpr auto SPI1SMEN     = 1 << 12;// SPI1 clocks enable during Sleep and Stop modes
            constexpr auto TIM1SMEN     = 1 << 11;// TIM1 timer clocks enable during Sleep and Stop modes
            constexpr auto SDMMC1SMEN   = 1 << 10;// SDMMC clocks enable during Sleep and Stop modes
            constexpr auto SYSCFGSMEN   = 1 << 0; // SYSCFG + COMP + VREFBUF clocks enable during Sleep and Stop modes

            // CCIPR
            constexpr auto DFSDM1SEL    = 1 << 31;// DFSDM1 clock source selection
            constexpr auto SWPM1SEL     = 1 << 30;// SWPMI1 clock source selection

            // BDCR
            constexpr auto LSCOSEL      = 1 << 25;// Low speed clock output selection
            constexpr auto LSCOEN       = 1 << 24;// Low speed clock output enable
            constexpr auto BDRST        = 1 << 16;// Backup domain software reset
            constexpr auto RTCEN        = 1 << 15;// RTC clock enable
            constexpr auto LSECSSD      = 1 << 6; // CSS on LSE failure Detection
            constexpr auto LSECSSON     = 1 << 5; // CSS on LSE enable
            constexpr auto LSEBYP       = 1 << 2; // LSE oscillator bypass
            constexpr auto LSERDY       = 1 << 1; // LSE oscillator ready
            constexpr auto LSEON        = 1 << 0; // LSE oscillator enable

            // CSR
            constexpr auto LPWRRSTF     = 1 << 31;// Low-power reset flag
            constexpr auto WWDGRSTF     = 1 << 30;// Window watchdog reset flag
            constexpr auto IWWGRSTF     = 1 << 29;// Independent window watchdog reset flag
            constexpr auto SFTRSTF      = 1 << 28;// Software reset flag
            constexpr auto BORRSTF      = 1 << 27;// BOR flag
            constexpr auto PINRSTF      = 1 << 26;// Pin reset flag
            constexpr auto OBLRSTF      = 1 << 25;// Option byte loader reset flag
            constexpr auto FWRSTF       = 1 << 24;// Firewall reset flag
            constexpr auto RMVF         = 1 << 23;// Remove reset flag
            constexpr auto LSIRDY       = 1 << 1; // LSI oscillator ready
            constexpr auto LSION        = 1 << 0; // LSI oscillator enable

            // CRRCR
            constexpr auto HSI48RDY     = 1 << 1; // HSI48 clock ready flag
            constexpr auto HSI48ON      = 1 << 0; // HSI48 clock enable
        }
    }

    namespace RNG{
        constexpr auto RNG              = 0x50060800;

        namespace R{
            constexpr auto CR           = 0x00;   // Control register
            constexpr auto SR           = 0x04;   // Status register
            constexpr auto DR           = 0x08;   // Data register
        }

        namespace B{
            // CR
            constexpr auto IE           = 1 << 3; // Interrupt enable
            constexpr auto RNGEN        = 1 << 2; // True random number generator enable

            // SR
            constexpr auto SEIS         = 1 << 6; // Seed error interrupt status
            constexpr auto CEIS         = 1 << 5; // Clock error interrupt status
            constexpr auto SECS         = 1 << 2; // Seed error current status
            constexpr auto CECS         = 1 << 1; // Clock error current status
            constexpr auto DRDY         = 1 << 0; // Data ready
        }
    }

    namespace SPI{
        constexpr auto SPI1             = 0x40013000;
        constexpr auto SPI2             = 0x40003800;
        constexpr auto SPI3             = 0x40003C00;

        namespace R{
            constexpr auto CR1          = 0x00;   // control register 1
            constexpr auto CR2          = 0x04;   // control register 2
            constexpr auto SR           = 0x08;   // status register
            constexpr auto DR           = 0x0C;   // data register
            constexpr auto CRCPR        = 0x10;   // CRC polynomial register
            constexpr auto RXCRCR       = 0x14;   // RX CRC register
            constexpr auto TXCRCR       = 0x18;   // TX CRC register
        }

        namespace B{
            // CR1
            constexpr auto BIDIMODE     = 1 << 15;// Bidirectional data mode enable.
            constexpr auto BIDIOE       = 1 << 14;// Output enable in bidirectional mode
            constexpr auto CRCEN        = 1 << 13;// Hardware CRC calculation enable
            constexpr auto CRCNEXT      = 1 << 12;// Transmit CRC next
            constexpr auto CRCL         = 1 << 11;// CRC length
            constexpr auto RXONLY       = 1 << 10;// Receive only mode enabled
            constexpr auto SSM          = 1 << 9; // Software slave management
            constexpr auto SSI          = 1 << 8; // Internal slave select
            constexpr auto LSBFIRST     = 1 << 7; // Least signifigant bit first
            constexpr auto SPE          = 1 << 6; // SPI enable
            constexpr auto MSTR         = 1 << 2; // Master selection
            constexpr auto CPOL         = 1 << 1; // Clock polarity
            constexpr auto CPHA         = 1 << 0; // Clock phase

            // CR2
            constexpr auto LDMA_TX      = 1 << 14;// Last DMA transfer for transmission
            constexpr auto LDMA_RX      = 1 << 13;// Last DMA transfer for reception
            constexpr auto FRXTH        = 1 << 12;// FIFO reception threshold
            constexpr auto TXEIE        = 1 << 7; // Tx buffer empty interrupt enable
            constexpr auto RXNEIE       = 1 << 6; // RX buffer not empty interrupt enable
            constexpr auto ERRIE        = 1 << 5; // Error interrupt enable
            constexpr auto FRF          = 1 << 4; // Frame format
            constexpr auto NSSP         = 1 << 3; // NSS pulse management
            constexpr auto SSOE         = 1 << 2; // SS output enable
            constexpr auto TXDMAEN      = 1 << 1; // Tx buffer DMA enable
            constexpr auto RXDMAEN      = 1 << 0; // Rx buffer DMA enable

            // SR
            constexpr auto FRE          = 1 << 8; // Frame format error
            constexpr auto BSY          = 1 << 7; // Busy flag
            constexpr auto OVR          = 1 << 6; // Overrun flag
            constexpr auto MODF         = 1 << 5; // Mode fault
            constexpr auto CRCERR       = 1 << 4; // CRC error flag
            constexpr auto TXE          = 1 << 1; // Transmit buffer empty
            constexpr auto RXNE         = 1 << 0; // Receive buffer not empty
        }
    }

    namespace I2C{
        constexpr auto I2C1             = 0x40005400;
        constexpr auto I2C2             = 0x40005800;
        constexpr auto I2C3             = 0x40005C00;

    }

    namespace USART{
        constexpr auto USART1           = 0x40013800;
        constexpr auto USART2           = 0x40004400;
        constexpr auto USART3           = 0x40004800;

        namespace R{
            constexpr auto CR1          = 0x00;   // Control register 1
            constexpr auto CR2          = 0x04;   // Control register 2
            constexpr auto CR3          = 0x08;   // Control register 3
            constexpr auto BRR          = 0x0C;   // Baud rate register
            constexpr auto GTPR         = 0x10;   // Guard time and prescaler register
            constexpr auto RTOR         = 0x14;   // Receiver timeout register
            constexpr auto RQR          = 0x18;   // Request register
            constexpr auto ISR          = 0x1C;   // Interrupt and status register
            constexpr auto ICR          = 0x20;   // Interrupt flag clear register
            constexpr auto RDR          = 0x24;   // Receive data register
            constexpr auto TDR          = 0x28;   // Transmit data register
        }

        namespace B{
            // CR1
            constexpr auto EOBIE        = 1 << 27;// End of block interrupt enable
            constexpr auto RTOIE        = 1 << 26;// Receiver timeout interrupt enable
            constexpr auto OVER8        = 1 << 15;// Oversampling mode
            constexpr auto CMIE         = 1 << 14;// Character match interrupt enable
            constexpr auto MME          = 1 << 13;// Mute mode enable
            constexpr auto WAKE         = 1 << 11;// Receiver wakeup method
            constexpr auto PCE          = 1 << 10;// Parity control enable
            constexpr auto PS           = 1 << 9; // Parity selection
            constexpr auto PEIE         = 1 << 8; // PE interrupt enable
            constexpr auto TXEIE        = 1 << 7; // TXE interrupt enable
            constexpr auto TCIE         = 1 << 6; // Transmission complete interrupt enable
            constexpr auto RXNEIE       = 1 << 5; // RXNE interrupt enable
            constexpr auto IDLEIE       = 1 << 4; // IDLE interrupt enable
            constexpr auto TE           = 1 << 3; // Transmitter enable
            constexpr auto RE           = 1 << 2; // Receiver enable
            constexpr auto UESM         = 1 << 1; // USART enable in Stop mode
            constexpr auto UE           = 1 << 0; // USART enable

            // CR2
            constexpr auto RTOEN        = 1 << 23;// Receiver timeout enable
            constexpr auto ABREN        = 1 << 20;// Auto baud rate enable
            constexpr auto MSBFIRST     = 1 << 19;// Most significant bit first
            constexpr auto DATAINV      = 1 << 18;// Binary data inversion
            constexpr auto TXINV        = 1 << 17;// TX pin active level conversion
            constexpr auto RXINV        = 1 << 16;// RX pin active level conversion
            constexpr auto SWAP         = 1 << 15;// Swap TX/RX pins
            constexpr auto LINEN        = 1 << 14;// LIN mode enable
            constexpr auto CLKEN        = 1 << 11;// Clock enable
            constexpr auto CPOL         = 1 << 10;// Clock polarity
            constexpr auto CPHA         = 1 << 9; // Clock phase
            constexpr auto LBCL         = 1 << 8; // Last bit clock pulse
            constexpr auto LBDIE        = 1 << 6; // LIN break detection interrupt enable
            constexpr auto LBDL         = 1 << 5; // LIN break detection length
            constexpr auto ADDM7        = 1 << 4; // 7-bit Adress Detection/4-bit Adress Detection

            // CR3
            constexpr auto TCBGTIE      = 1 << 24;// Transmission complete before guard time interrupt enable
            constexpr auto UCESM        = 1 << 23;// USART Clock Enable in Stop mode
            constexpr auto WUFIE        = 1 << 22;// Wakeup from Stop mode interrupt enable
            constexpr auto DEP          = 1 << 15;// Driver enable polartity selection
            constexpr auto DEM          = 1 << 14;// Driver enable mode
            constexpr auto DDRE         = 1 << 13;// DMA Disable on Reception Error
            constexpr auto OVRDIS       = 1 << 12;// Overrun Disable
            constexpr auto ONEBIT       = 1 << 11;// One sample bit method enable
            constexpr auto CTSIE        = 1 << 10;// CTS interrupt enable
            constexpr auto CTSE         = 1 << 9; // CTS enable
            constexpr auto RTSE         = 1 << 8; // RTS enable
            constexpr auto DMAT         = 1 << 7; // DMA enable transmitter
            constexpr auto DMAR         = 1 << 6; // DMA enable receiver
            constexpr auto SCEN         = 1 << 5; // Smartcard mode enable
            constexpr auto NACK         = 1 << 4; // Smartcard NACK enable
            constexpr auto HDSEL        = 1 << 3; // Half-duplex selection
            constexpr auto IRLP         = 1 << 2; // IrDA low power
            constexpr auto IREN         = 1 << 1; // IrDA mode enable
            constexpr auto EIE          = 1 << 0; // Error interrupt enable

            // RQR
            constexpr auto TXFRQ        = 1 << 4; // Transmit data flush request
            constexpr auto RXFRQ        = 1 << 3; // Receive data flush request
            constexpr auto MMRQ         = 1 << 2; // Mute mode request
            constexpr auto SBKRQ        = 1 << 1; // Send break request
            constexpr auto ABRRQ        = 1 << 0; // Auto baud rate request

            // ISR
            constexpr auto TCBGT        = 1 << 25;// Transmission complete before guard time completion
            constexpr auto REACK        = 1 << 22;// Receive enable acknowledge flag
            constexpr auto TEACK        = 1 << 21;// Transmit enable acknowledge flag
            constexpr auto WUF          = 1 << 20;// Wakeup from Stop mode flag
            constexpr auto RWU          = 1 << 19;// Receiver wakeup from mute mode
            constexpr auto SBKF         = 1 << 18;// Send break flag
            constexpr auto CMF          = 1 << 17;// Character match flag
            constexpr auto BUSY         = 1 << 16;// Busy flag
            constexpr auto ABRF         = 1 << 15;// Auto baud rate flag
            constexpr auto ABRE         = 1 << 14;// Auto baud rate error
            constexpr auto EOBF         = 1 << 12;// End of block flag
            constexpr auto RTOF         = 1 << 11;// Receiver timeout
            constexpr auto CTS          = 1 << 10;// CTS flag
            constexpr auto CTSIF        = 1 << 9; // CTS interrupt flag
            constexpr auto LBDF         = 1 << 8; // LIN break detection flag
            constexpr auto TXE          = 1 << 7; // Transmit data register empty
            constexpr auto TC           = 1 << 6; // Transmission complete
            constexpr auto RXNE         = 1 << 5; // Read data register not empty
            constexpr auto IDLE         = 1 << 4; // Idle line detected
            constexpr auto ORE          = 1 << 3; // Overrun error
            constexpr auto NF           = 1 << 2; // START bit Noise detection flag
            constexpr auto FE           = 1 << 1; // Framing error
            constexpr auto PE           = 1 << 0; // Parity error

            // ICR
            constexpr auto WUCF         = 1 << 20;// Wakeup from Stop mode clear flag
            constexpr auto CMCF         = 1 << 17;// Character match clear flag
            constexpr auto EOBCF        = 1 << 12;// End of block clear flag
            constexpr auto RTOCF        = 1 << 11;// Receiver timeout clear flag
            constexpr auto CTSCF        = 1 << 9; // CTS clear flag
            constexpr auto LBDCF        = 1 << 8; // LIN break detection clear flag
            constexpr auto TCBGTCF      = 1 << 7; // Transmission complete before guard time clear flag
            constexpr auto TCCF         = 1 << 6; // Transmission complete clear flag
            constexpr auto IDLECF       = 1 << 4; // Idle line detected clear flag
            constexpr auto ORECF        = 1 << 3; // Overrun error clear flag
            constexpr auto NCF          = 1 << 2; // Noise detected flag
            constexpr auto FECF         = 1 << 1; // Framing error clear flag
            constexpr auto PECF         = 1 << 0; // Parity error clear flag
        }
    }
}

#endif /* LET_DEVICE_STM32_STM32L476XX_HPP */
