/**
 * @file   let/include/HAL.hpp
 * @author Peter Züger
 * @date   31.07.2018
 * @brief  Hardware Abstraction Layer common
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
#ifndef LET_HAL_HPP
#define LET_HAL_HPP

#include <cstdint>
#include <cstddef>

namespace let{
    template<typename T>
    volatile T &memory(const std::size_t loc)noexcept{
        return *reinterpret_cast<T*>(loc);
    }

    constexpr auto BIT(const unsigned long i){
        return 1 << i;
    }

    template<typename T, std::size_t A>
    struct read_only{
        operator T()const volatile noexcept{
            return memory<T>(A);
        }
    };

    template<typename T, std::size_t A>
    struct write_only{
        void operator =(const std::size_t v)const volatile noexcept{
            memory<T>(A) = v;
        }
    };

    template<typename T,std::size_t A>
    struct reg:
        public read_only<T, A>,
        public write_only<T, A>{

        using read_only<T, A>::operator T;
        using write_only<T, A>::operator =;
    };

    template<typename T, std::size_t A, std::uint8_t b>
    struct bit{

        bit& operator=(bool value)volatile noexcept{
            if(value)
                reg<T, A>() |= BIT(b);
            else
                reg<T, A>() &= ~BIT(b);
            return *this;
        }

        operator bool()const volatile noexcept{
            return reg<T, A>() & BIT(b);
        }
    };
}

#endif /* LET_HAL_HPP */
