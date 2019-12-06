/**
 * @file   let/include/RCC/USART.hpp
 * @author Peter Züger
 * @date   14.08.2018
 * @brief  Reset and Clock Control for USART
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
#ifndef LET_RCC_USART_HPP
#define LET_RCC_USART_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
#if defined(STM32F4) && !defined(STM32F437xx)
        inline constexpr auto USARTCLK = R::APB1ENR;
#else
        inline constexpr auto USARTCLK = R::APB1ENR1;
#endif /* defined(STM32F4) */

        inline void EnableUSART1Clock(){set_mask(RCC + R::APB2ENR, B::USART1EN);}
        inline void DisableUSART1Clock(){clear_mask(RCC + R::APB2ENR, B::USART1EN);}

        inline void EnableUSART2Clock(){set_mask(RCC + USARTCLK, B::USART2EN);}
        inline void DisableUSART2Clock(){clear_mask(RCC + USARTCLK, B::USART2EN);}

        inline void EnableUSART3Clock(){set_mask(RCC + USARTCLK, B::USART3EN);}
        inline void DisableUSART3Clock(){clear_mask(RCC + USARTCLK, B::USART3EN);}

        #if defined(STM32F4) && !defined(STM32F437xx)
        inline void EnableUSART6Clock(){set_mask(RCC + R::APB2ENR, B::USART6EN);}
        inline void DisableUSART6Clock(){clear_mask(RCC + R::APB2ENR, B::USART6EN);}
        #else

        #endif /* defined(STM32F4) */
    }
}

#endif /* LET_RCC_USART_HPP */
