/**
 * @file   let/include/ADC.hpp
 * @author Peter Züger
 * @date   12.11.2019
 * @brief  Analog to Digital Converter abstraction
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
#ifndef LET_ADC_HPP
#define LET_ADC_HPP

#include <optional>

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace ADC{
        template<std::uint32_t A>
        class ADC{
        public:
            using value_type = std::uint16_t;

            void Enable(){set_mask(A + R::CR2, B::ADON);}
            void Disable(){clear_mask(A + R::CR2, B::ADON);}

            void EnableContinuous(){set_mask(A + R::CR2, B::CONT);}
            void DisableContinuous(){clear_mask(A + R::CR2, B::CONT);}

            void start(){
                set_mask(A + R::CR2, B::SWSTART);
            }

            bool busy(){
                return !(memory<std::uint32_t>(A + R::CSR) & B::EOC1);
            }

            value_type read(){
                while(busy());
                return memory<std::uint16_t>(A + R::DR);
            }

            std::optional<value_type> read(bool blocking){
                if(blocking){
                    return std::make_optional(read());
                }else{
                    if(!busy()){
                        return std::make_optional(read());
                    }else{
                        return std::nullopt;
                    }
                }
            }

            void set_conversions(std::uint8_t conversions){
                clear_mask(A + R::SQR1, 0xF << 20);
                set_mask(A + R::SQR1, conversions << 20);
            }

            void set_sequence(int sequence, int channel){
                std::uint32_t addr;
                /**/ if((sequence >= 1) && (sequence <= 6))  {addr = A + R::SQR3; sequence -= 1;}
                else if((sequence >= 7) && (sequence <= 12)) {addr = A + R::SQR2; sequence -= 7;}
                else if((sequence >= 13) && (sequence <= 16)){addr = A + R::SQR1; sequence -= 13;}
                else return;

                if(channel > 0xFF)return;
                clear_mask(addr, 0x1F << (5*sequence));
                set_mask(addr, channel << (5*sequence));
            }
        };
    }
}

#endif /* LET_ADC_HPP */
