/**
 * @file   let/include/RNG.hpp
 * @author Peter Züger
 * @date   12.08.2018
 * @brief  Random Number Generator abstraction
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
#ifndef LET_RNG_HPP
#define LET_RNG_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace RNG{

        template<std::uint32_t A>
        class RandomNumberGenerator{
        public:
            RandomNumberGenerator(){
                Enable();
            }

            bool DataReady(){
                return memory<std::uint32_t>(A+R::SR) | B::DRDY;
            }

            bool SeedError(){
                return memory<std::uint32_t>(A+R::SR) | B::SEIS;
            }

            bool ClockError(){
                return memory<std::uint32_t>(A+R::SR) | B::CEIS;
            }

            void ResetErrors(){
                memory<std::uint32_t>(A+R::SR) &= ~(B::SEIS|B::CEIS);
            }

            std::uint32_t get(){
                while(!DataReady());
                return memory<std::uint32_t>(A+R::DR);
            }

            std::uint32_t operator()(){
                return get();
            }

            void Enable(){
                memory<std::uint32_t>(A+R::CR) |= B::RNGEN;
            }
            void Disable(){
                memory<std::uint32_t>(A+R::CR) &= ~B::RNGEN;
            }
        };
    }
}

#endif /* LET_RNG_HPP */
