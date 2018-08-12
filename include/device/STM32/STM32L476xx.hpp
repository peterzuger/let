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
}

#endif /* __STM32L476XX_HPP__ */
