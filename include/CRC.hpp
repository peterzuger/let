/**
 * @file   let/include/CRC.hpp
 * @author Peter Züger
 * @date   27.08.2019
 * @brief  Cyclic Redundancy Check
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
#ifndef LET_CRC_HPP
#define LET_CRC_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace CRC{
        template<std::uint32_t A>
        class CRC{
        public:
            using value_type = std::uint32_t;

            CRC(){
                reset();
            }

            void reset(){
                set_mask(A + R::CR, B::RESET);
            }

            void update(value_type data){
                memory<value_type>(A+R::DR) = data;
            }

            template<typename Iterator>
            void update(Iterator first, Iterator last){
                for(; first != last; ++first){
                    update(*first);
                }
            }

            value_type result(){
                return memory<value_type>(A+R::DR);
            }

#if defined(STM32L4)
            void reverse_out(bool rev){
                if(rev)
                    set_mask(A + R::CR, REV_OUT);
                else
                    clear_mask(A + R::CR, REV_OUT);
            }

            enum class ReverseIn{
                None,
                Byte,
                HalfWord,
                Word
            };

            void reverse_in(ReverseIn rev){
                clear_mask(A + R::CR, 0b11 << 5);

                switch(rev){
                case ReverseIn::None:
                    set_mask(A + R::CR, NONE);
                    break;
                case ReverseIn::Byte:
                    set_mask(A + R::CR, BYTE);
                    break;
                case ReverseIn::HalfWord:
                    set_mask(A + R::CR, HWORD);
                    break;
                case ReverseIn::Word:
                    set_mask(A + R::CR, WORD);
                    break;
                default:
                    break;
                }
            }

            enum class Polysize{
                B32,
                B16,
                B8,
                B7
            };

            void polysize(Polysize ps){
                clear_mask(A + R::CR, 0b11 << 3);

                switch(ps){
                case Polysize::B32:
                    set_mask(A + R::CR, P32B);
                    break;
                case Polysize::B16:
                    set_mask(A + R::CR, P16B);
                    break;
                case Polysize::B8:
                    set_mask(A + R::CR, P8B);
                    break;
                case Polysize::B7:
                    set_mask(A + R::CR, P7B);
                    break;
                default:break;
                }
            }
#endif /* defined(STM32L4) */
        };
    }
}

#endif /* LET_CRC_HPP */
