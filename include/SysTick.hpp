/**
 * @file   let/include/SysTick.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  SysTick timer abstraction
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
#ifndef LET_SYSTICK_HPP
#define LET_SYSTICK_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace STK{

        inline void EnableSysTickCounter(){
            memory<std::uint32_t>(STK+R::CTRL) |= B::ENABLE;
        }

        inline void DisableSysTickCounter(){
            memory<std::uint32_t>(STK+R::CTRL) &= ~B::ENABLE;
        }

        inline void EnableSysTickException(){
            memory<std::uint32_t>(STK+R::CTRL) |= B::TICKINT;
        }

        inline void DisableSysTickException(){
            memory<std::uint32_t>(STK+R::CTRL) &= ~B::TICKINT;
        }

        inline bool Countflag(){
            return memory<std::uint32_t>(STK+R::CTRL) & B::COUNTFLAG;
        }

        inline void SetSysTickLoad(std::uint32_t val){
            memory<std::uint32_t>(STK+R::LOAD) = val;
        }

        inline void ClearSysTickCurrent(){
            memory<std::uint32_t>(STK+R::VAL) = 0;
        }

        inline std::uint32_t GetSysTickCurrent(){
            return memory<std::uint32_t>(STK+R::VAL);
        }
    }
}

#endif /* LET_SYSTICK_HPP */
