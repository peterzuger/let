/**
 * @file   let/include/RCC/GPIO.hpp
 * @author Peter Züger
 * @date   14.08.2018
 * @brief  Reset and Clock Control for GPIO
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
#ifndef LET_RCC_GPIO_HPP
#define LET_RCC_GPIO_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
#if defined(STM32F4)
        inline constexpr auto GPIOCLK = R::AHB1ENR;
#else
        inline constexpr auto GPIOCLK = R::AHB2ENR;
#endif /* defined(STM32F4) */

        inline void EnableGPIOAClock(){set_mask(RCC + GPIOCLK, B::GPIOAEN);}
        inline void DisableGPIOAClock(){clear_mask(RCC + GPIOCLK, B::GPIOAEN);}

        inline void EnableGPIOBClock(){set_mask(RCC + GPIOCLK, B::GPIOBEN);}
        inline void DisableGPIOBClock(){clear_mask(RCC + GPIOCLK, B::GPIOBEN);}

        inline void EnableGPIOCClock(){set_mask(RCC + GPIOCLK, B::GPIOCEN);}
        inline void DisableGPIOCClock(){clear_mask(RCC + GPIOCLK, B::GPIOCEN);}

        inline void EnableGPIODClock(){set_mask(RCC + GPIOCLK, B::GPIODEN);}
        inline void DisableGPIODClock(){clear_mask(RCC + GPIOCLK, B::GPIODEN);}

        inline void EnableGPIOEClock(){set_mask(RCC + GPIOCLK, B::GPIOEEN);}
        inline void DisableGPIOEClock(){clear_mask(RCC + GPIOCLK, B::GPIOEEN);}

        inline void EnableGPIOFClock(){set_mask(RCC + GPIOCLK, B::GPIOFEN);}
        inline void DisableGPIOFClock(){clear_mask(RCC + GPIOCLK, B::GPIOFEN);}

        inline void EnableGPIOGClock(){set_mask(RCC + GPIOCLK, B::GPIOGEN);}
        inline void DisableGPIOGClock(){clear_mask(RCC + GPIOCLK, B::GPIOGEN);}

        inline void EnableGPIOHClock(){set_mask(RCC + GPIOCLK, B::GPIOHEN);}
        inline void DisableGPIOHClock(){clear_mask(RCC + GPIOCLK, B::GPIOHEN);}
    }
}

#endif /* LET_RCC_GPIO_HPP */
