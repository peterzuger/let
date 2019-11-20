/**
 * @file   let/include/FPU.hpp
 * @author Peter Züger
 * @date   20.08.2018
 * @brief  Floating Point Unit abstraction
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
#ifndef LET_FPU_HPP
#define LET_FPU_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace FPU{
        inline void EnableFPU(){
            memory<std::uint32_t>(FPU+R::CPACR) |= (0xf << 20);
        }
    }
}

#endif /* LET_FPU_HPP */
