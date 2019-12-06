/**
 * @file   let/include/RCC/RNG.hpp
 * @author Peter Züger
 * @date   15.01.2019
 * @brief  Reset and Clock Control for the RNG
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
#ifndef LET_RCC_RNG_HPP
#define LET_RCC_RNG_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
        inline void EnableRNGClock(){set_mask(RCC + R::AHB2ENR, B::RNGEN);}
        inline void DisableRNGClock(){clear_mask(RCC + R::AHB2ENR, B::RNGEN);}
    }
}

#endif /* LET_RCC_RNG_HPP */
