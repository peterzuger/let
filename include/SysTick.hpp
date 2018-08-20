/**
 * @file   SysTick.hpp
 * @author Peter Zueger
 * @date   11.08.2018
 * @brief  SysTick timer abstraction
 */
#ifndef __SYSTICK_HPP__
#define __SYSTICK_HPP__

#include "HAL.hpp"

namespace let{
    namespace STK{

        inline void EnableSysTickCounter(){
            memory<std::uint32_t>(STK+R::CTRL) |= B::ENABLE;
        }

        inline void EnableSysTickException(){
            memory<std::uint32_t>(STK+R::CTRL) |= B::TICKINT;
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

#endif /* __SYSTICK_HPP__ */
