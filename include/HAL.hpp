/**
 * @file   HAL.hpp
 * @author Peter Zueger
 * @date   31.07.2018
 * @brief  Hardware Abstraction Layer common
 */
#ifndef __HAL_HPP__
#define __HAL_HPP__

#include <cstdint>

#include "device/Family.hpp"

namespace let{

    template<typename T>
    volatile T &memory(const std::uint32_t loc){
        return *reinterpret_cast<T*>(loc);
    }

    constexpr auto BIT(const unsigned long i){
        return 1 << i;
    }

    template<typename T,std::uint32_t A>
    struct read_only{
        operator T()const volatile{return memory<T>(A);}
    };

    template<typename T,std::uint32_t A>
    struct write_only{
        void operator =(const std::uint32_t v)const volatile{memory<T>(A) = v;}
    };

    template<typename T,std::uint32_t A>
    struct reg:
        public read_only<T, A>,
        public write_only<T, A>{

        using read_only<T, A>::operator T;
        using write_only<T, A>::operator =;
    };
}

#endif /* __HAL_HPP__ */
