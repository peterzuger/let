/**
 * @file   let/include/SCB.hpp
 * @author Peter Züger
 * @date   22.01.2019
 * @brief  System Control Block
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
#ifndef LET_SCB_HPP
#define LET_SCB_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace SCB{
        void VectorTableOffset(std::size_t addr, bool SRAM){
            std::uint32_t tmp = addr & 0x1FFFFE00;
            if(SRAM)
                tmp |= BIT(29);
            memory<std::uint32_t>(SCB+R::VTOR) = tmp;
        }

        [[noreturn]] void SystemReset(){
            asm volatile ("dsb 0xF":::"memory");
            memory<std::uint32_t>(SCB+R::AIRCR) |= B::SYSRESETREQ | B::VECTKEY;
            asm volatile ("dsb 0xF":::"memory");
            while(1);
        }

        inline void setMSP(std::uint32_t addr){
            asm volatile ("MSR msp, %0" : : "r" (addr) : );
        }
    }
}

#endif /* LET_SCB_HPP */
