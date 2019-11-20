/**
 * @file   let/include/NVIC.hpp
 * @author Peter Züger
 * @date   12.08.2018
 * @biref  Nested Vector Interrupt Controller abstraction
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
#ifndef LET_NVIC_HPP
#define LET_NVIC_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace NVIC{
        void Enable(std::uint32_t IRQn){
            memory<std::uint32_t>(NVIC+R::ISER + (IRQn >> 5)) = BIT(IRQn & 0x1F);
        }

        void EnableIRQ(){
            asm volatile ("cpsie i" : : : "memory");
        }

        void DisableIRQ(){
            asm volatile ("cpsid i" : : : "memory");
        }

        void WaitForInterrupt(){
            asm volatile ("wfi");
        }

        void WaitForEvent(){
            asm volatile ("wfe");
        }

        void SendEvent(){
            asm volatile ("sev");
        }

        void InstructionSynchronizationBarrier(){
            asm volatile ("isb 0xF":::"memory");
        }

        void DataSynchronizationBarrier(){
            asm volatile ("dsb 0xF":::"memory");
        }

        void DataMemoryBarrier(){
            asm volatile ("dmb 0xF":::"memory");
        }
    }
}

#endif /* LET_NVIC_HPP */
