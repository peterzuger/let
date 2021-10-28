/**
 * @file   let/include/SoftSPI.hpp
 * @author Peter Züger
 * @date   25.12.2018
 * @brief  Software SPI peripheral
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
#ifndef LET_SOFTSPI_HPP
#define LET_SOFTSPI_HPP

#include <tuple>

#include "HAL.hpp"
#include "GPIO.hpp"

namespace let{
    namespace SoftSPI{
        enum class FrameFormat{
            LSB,
            MSB
        };

        /**
         * A fixed soft SPI implementation
         * This uses MSB First
         * CPOL = 0
         * CPHA = 0
         */
        template<typename CLK, typename MOSI, typename MISO>
        class SoftSPI{
            CLK clk;
            MOSI mosi;
            MISO miso;

        public:
            SoftSPI(const CLK& _clk, const MOSI& _mosi, const MISO& _miso):
                clk{_clk}, mosi{_mosi}, miso{_miso}{}

            void Enable(){}
            void Disable(){}
            void Master(){}
            void Slave(){}
            void Polarity(bool){}
            void Phase(bool){}
            void FrameFormat(FrameFormat){}

            void write(std::uint8_t data){
                for(std::uint8_t i = 0; i < 8; i++){
                    clk.clear();
                    mosi = (data << i) & 0x80;
                    clk.set();
                }
            }

            bool write(std::uint8_t d, bool){
                write(d);
                return true;
            }

            std::uint8_t read(){
                std::uint8_t data;
                for(std::uint8_t i = 0; i < 8; i++){
                    clk.clear();
                    data |= miso << i;
                    clk.set();
                }
                return data;
            }

            std::tuple<bool, std::uint8_t> read(bool){
                return std::make_tuple(true, read());
            }

            std::uint8_t transmit(std::uint8_t data){
                std::uint8_t rdata = 0;
                for(std::uint8_t i = 0; i < 8; i++){
                    clk.clear();
                    rdata |= static_cast<std::uint8_t>(miso << (7-i));
                    mosi = (data << i) & 0x80;
                    clk.set();
                }
                return rdata;
            }

            std::tuple<bool, std::uint8_t> transmit(std::uint8_t data, bool){
                return std::make_tuple(true, transmit(data));
            }

            bool busy(){
                return false;
            }
        };
    }
}

#endif /* LET_SOFTSPI_HPP */
