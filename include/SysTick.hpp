/**
 * @file   let/include/SysTick.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  SysTick timer abstraction
 */
#ifndef LET_SYSTICK_HPP
#define LET_SYSTICK_HPP

#include "HAL.hpp"

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
