/**
 * @file   let/include/RCC/DMA.hpp
 * @author Peter Züger
 * @date   14.08.2018
 * @brief  Reset and Clock Control for DMA
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
#ifndef LET_RCC_DMA_HPP
#define LET_RCC_DMA_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
        inline void EnableDMA1Clock(){set_mask(RCC + R::AHB1ENR, B::DMA1EN);}
        inline void DisableDMA1Clock(){clear_mask(RCC + R::AHB1ENR, B::DMA1EN);}

        inline void EnableDMA2Clock(){set_mask(RCC + R::AHB1ENR, B::DMA2EN);}
        inline void DisableDMA2Clock(){clear_mask(RCC + R::AHB1ENR, B::DMA2EN);}
    }
}

#endif /* LET_RCC_DMA_HPP */
