/**
 * @file   device/STM32/STM32L476xx.hpp
 * @author Peter Zueger
 * @date   12.08.2018
 * @brief  STM32L476 register offsets
 */
#ifndef __STM32L476XX_HPP__
#define __STM32L476XX_HPP__

namespace let{
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
            // LCKR
            constexpr auto LCKK         = 1 << 16;// Lock key
        }
    }

    namespace RCC{
        constexpr auto RCC              = 0x40021000;

        namespace R{
            constexpr auto CR           = 0x00;   //
            constexpr auto ICSCR        = 0x04;   //
            constexpr auto CFGR         = 0x08;   //
            constexpr auto PLLCFGR      = 0x0C;   //
            constexpr auto PLLSAI1CFGR  = 0x10;   //
            constexpr auto PLLSAI2CFGR  = 0x14;   //
            constexpr auto CIER         = 0x18;   //
            constexpr auto CIFR         = 0x1C;   //
            constexpr auto CICR         = 0x20;   //
            constexpr auto AHB1RSTR     = 0x28;   //
            constexpr auto AHB2RSTR     = 0x2C;   //
            constexpr auto AHB3RSTR     = 0x30;   //
            constexpr auto APB1RSTR1    = 0x38;   //
            constexpr auto APB1RSTR2    = 0x3C;   //
            constexpr auto APB2RSTR     = 0x40;   //
            constexpr auto AHB1ENR      = 0x48;   //
            constexpr auto AHB2ENR      = 0x4C;   //
            constexpr auto AHB3ENR      = 0x50;   //
            constexpr auto APB1ENR1     = 0x58;   //
            constexpr auto APB1ENR2     = 0x5C;   //
            constexpr auto APB2ENR      = 0x60;   //
            constexpr auto AHB1SMENR    = 0x68;   //
            constexpr auto AHB2SMENR    = 0x6C;   //
            constexpr auto AHB3SMENR    = 0x70;   //
            constexpr auto APB1SMENR1   = 0x78;   //
            constexpr auto APB1SMENR2   = 0x7C;   //
            constexpr auto APB2SMENR    = 0x80;   //
            constexpr auto CCIPR        = 0x88;   //
            constexpr auto BDCR         = 0x90;   //
            constexpr auto CSR          = 0x94;   //
            // constexpr auto CRRCR        = 0x98;
            // constexpr auto CCIPR2       = 0x9C;
        }

        namespace B{

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
}

#endif /* __STM32L476XX_HPP__ */
