/**
 * @file   let/include/RCC/SPI.hpp
 * @author Peter Züger
 * @date   14.08.2018
 * @brief  Reset and Clock Control for SPI
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
#ifndef LET_RCC_SPI_HPP
#define LET_RCC_SPI_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
#if defined(STM32F4) && !defined(STM32F437xx)
        inline constexpr auto SPICLK = R::APB1ENR;
#elif defined(STM32H7)
        inline constexpr auto SPICLK = R::APB1LENR;
#else
        inline constexpr auto SPICLK = R::APB1ENR1;
#endif /* defined(STM32F4) */

        inline void EnableSPI1Clock(){set_mask(RCC + R::APB2ENR, B::SPI1EN);}
        inline void DisableSPI1Clock(){clear_mask(RCC + R::APB2ENR, B::SPI1EN);}

        inline void EnableSPI2Clock(){set_mask(RCC + SPICLK, B::SPI2EN);}
        inline void DisableSPI2Clock(){clear_mask(RCC + SPICLK, B::SPI2EN);}

        inline void EnableSPI3Clock(){set_mask(RCC + SPICLK, B::SPI3EN);}
        inline void DisableSPI3Clock(){clear_mask(RCC + SPICLK, B::SPI3EN);}

        #if defined(STM32F4)

        #elif defined(STM32L4)

        #else
        inline void EnableSPI4Clock(){set_mask(RCC + R::APB2ENR, B::SPI4EN);}
        inline void DisableSPI4Clock(){clear_mask(RCC + R::APB2ENR, B::SPI4EN);}

        inline void EnableSPI5Clock(){set_mask(RCC + R::APB2ENR, B::SPI5EN);}
        inline void DisableSPI5Clock(){clear_mask(RCC + R::APB2ENR, B::SPI5EN);}
        #endif /* defined(STM32F4) */
    }
}

#endif /* LET_RCC_SPI_HPP */
