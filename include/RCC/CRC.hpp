/**
 * @file   let/include/RCC/CRC.hpp
 * @author Peter Züger
 * @date   14.08.2018
 * @brief  cyclic redundancy check clock
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
#ifndef LET_RCC_CRC_HPP
#define LET_RCC_CRC_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
        inline void EnableCRCClock(){set_mask(RCC + R::AHB1ENR, B::CRCEN);}
        inline void DisableCRCClock(){clear_mask(RCC + R::AHB1ENR, B::CRCEN);}
    }
}

#endif /* LET_RCC_CRC_HPP */
