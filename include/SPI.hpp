/**
 * @file   let/include/SPI.hpp
 * @author Peter Züger
 * @date   14.08.2018
 * @brief  Serial Peripheral Interface abstraction
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
#ifndef LET_SPI_HPP
#define LET_SPI_HPP

#include <optional>

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace SPI{
        enum class FrameFormat{
            LSB,
            MSB
        };

        template<std::uint32_t A>
        class SPI{
        public:
            using value_type = std::uint8_t;

            SPI(){
                Master();
                memory<std::uint32_t>(A+R::CR1) |= B::CPOL;
                memory<std::uint32_t>(A+R::CR1) |= B::CPHA;
                Enable();
            }

            ~SPI(){
                while(busy());
                Disable();
            }

            void Enable(){
                memory<std::uint32_t>(A+R::CR1) |= B::SPE;
            }

            void Disable(){
                memory<std::uint32_t>(A+R::CR1) &= ~B::SPE;
            }

            void Master(){
                memory<std::uint32_t>(A+R::CR1) |= B::SSM;
                memory<std::uint32_t>(A+R::CR1) |= B::SSI;
                memory<std::uint32_t>(A+R::CR1) |= B::MSTR;
            }

            void Slave(){
                memory<std::uint32_t>(A+R::CR1) &= ~B::MSTR;
            }

            void Polarity(bool pol);
            void Phase(bool pha);

            void FrameFormat(FrameFormat format){
                switch(format){
                case FrameFormat::LSB:
                    memory<std::uint32_t>(A+R::CR1) |=  B::LSBFIRST;
                    break;
                case FrameFormat::MSB:
                    memory<std::uint32_t>(A+R::CR1) &= ~B::LSBFIRST;
                    break;
                }
            }

            bool busy(){
#if defined(STM32H7)
                return !(memory<std::uint32_t>(A+R::SR) & B::TXC);
#else
                return memory<std::uint32_t>(A+R::SR) & B::BSY;
#endif
            }

            void flush()const volatile{
                while(busy());
            }

            bool flush(bool blocking)const volatile{
                if(blocking)
                    flush();
                return busy();
            }

            bool empty()const volatile{
                return memory<std::uint32_t>(A+R::SR) & B::TXE;
            }

            void write(value_type d)const volatile{
                while(!empty());
                memory<value_type>(A+R::TXR) = d;
            }

            bool write(value_type d, bool blocking)const volatile{
                if(blocking){
                    write(d);
                    return true;
                }else{
                    if(empty()){
                        memory<value_type>(A+R::TXR) = d;
                        return true;
                    }else{
                        return false;
                    }
                }
            }

            bool any()const volatile{
                return memory<std::uint32_t>(A+R::SR) & B::RXNE;
            }

            value_type read()const volatile{
                while(!any());
                return memory<value_type>(A+R::RXR);
            }

            std::optional<value_type> read(bool blocking){
                if(blocking){
                    return std::make_optional(read());
                }else{
                    if(any()){
                        return std::make_optional(memory<value_type>(A+R::RXR));
                    }else{
                        return std::nullopt;
                    }
                }
            }

            value_type transmit(value_type data){
                write(data);
                return read();
            }

            std::optional<value_type> transmit(value_type data, bool blocking){
                if(blocking){
                    return std::make_optional(transmit(data));
                }else{
                    if(write(data, false)){
                        return read(false);
                    }else{
                        return std::nullopt;
                    }
                }
            }
        };
    }
}

#endif /* LET_SPI_HPP */
