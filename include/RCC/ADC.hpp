/**
 * @file   let/include/RCC/ADC.hpp
 * @author Peter Züger
 * @date   12.11.2019
 * @brief  Analog to Digital Converter clock
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
#ifndef LET_RCC_ADC_HPP
#define LET_RCC_ADC_HPP

#include "../HAL.hpp"
#include "../device/device.hpp"

namespace let{
    namespace RCC{
        inline void EnableADC1Clock(){set_mask(RCC + R::APB2ENR, B::ADC1EN);}
        inline void DisableADC1Clock(){clear_mask(RCC + R::APB2ENR, B::ADC1EN);}
    }
}

#endif /* LET_RCC_ADC_HPP */
