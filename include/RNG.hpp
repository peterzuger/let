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
        class RandomDevice{
        public:
            RandomDevice()noexcept{
                Enable();
            }

            RandomDevice(const RandomDevice&) = delete;
            RandomDevice(RandomDevice&&) = delete;

            RandomDevice& operator=(RandomDevice other)noexcept = delete;
            RandomDevice& operator=(RandomDevice&& other)noexcept = delete;

            bool DataReady()noexcept{
                return memory<std::uint32_t>(RNG+R::SR) | B::DRDY;
            }

            bool SeedError()noexcept{
                return memory<std::uint32_t>(RNG+R::SR) | B::SEIS;
            }

            bool ClockError()noexcept{
                return memory<std::uint32_t>(RNG+R::SR) | B::CEIS;
            }

            void ResetErrors()noexcept{
                memory<std::uint32_t>(RNG+R::SR) &= ~(B::SEIS|B::CEIS);
            }

            std::uint32_t get()noexcept{
                while(!DataReady());
                return memory<std::uint32_t>(RNG+R::DR);
            }

            std::uint32_t operator()()noexcept{
                return get();
            }

            static std::uint32_t min()noexcept{
                return 0;
            }

            static std::uint32_t max()noexcept{
                return 0xFFFFFFFF;
            }

            double entropy()const noexcept{
                return 0.0;
            }

            void Enable()noexcept{
                memory<std::uint32_t>(RNG+R::CR) |= B::RNGEN;
            }

            void Disable()noexcept{
                memory<std::uint32_t>(RNG+R::CR) &= ~B::RNGEN;
            }
        };
    }
}

#endif /* LET_RNG_HPP */
