/**
 * @file   let/include/FLASH.hpp
 * @author Peter Züger
 * @date   29.08.2018
 * @brief  FLASH abstraction
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
#ifndef LET_FLASH_HPP
#define LET_FLASH_HPP

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace FLASH{
#if defined(STM32F4)
        inline void EnableInstructionCache(){set_mask(FLASH + R::ACR, B::ICEN);}
        inline void DisableInstructionCache(){clear_mask(FLASH + R::ACR, B::ICEN);}

        inline void EnableDataCache(){set_mask(FLASH + R::ACR, B::DCEN);}
        inline void DisableDataCache(){clear_mask(FLASH + R::ACR, B::DCEN);}

        inline void EnablePrefetchBuffer(){set_mask(FLASH + R::ACR, B::PRFTEN);}
        inline void DisablePrefetchBuffer(){clear_mask(FLASH + R::ACR, B::PRFTEN);}
#endif /* defined(STM32F4) */


        template<std::uint32_t A>
        class Flash{
            template<typename T>
            class FlashReader{
                std::uint32_t start;

            public:
                using value_type = T;

                FlashReader(std::uint32_t _start):start{_start}{}
                FlashReader(FlashReader&& other) = default;

                FlashReader(const FlashReader& other) = delete; // non construction-copyable
                FlashReader& operator=(const FlashReader&) = delete; // non copyable

                value_type read(){
                    return memory<value_type>(start += sizeof(value_type));
                }

                value_type read(bool){
                    return read();
                }
            };


            template<typename T>
            class FlashWriter{
                std::uint32_t start;

            public:
                using value_type = T;

                FlashWriter(std::uint32_t _start):start{_start}{}
                FlashWriter(FlashWriter&& other) = default;

                FlashWriter(const FlashWriter& other) = delete; // non construction-copyable
                FlashWriter& operator=(const FlashWriter&) = delete; // non copyable

                void write(const value_type& data){
                    memory<value_type>(start += sizeof(value_type)) = data;
                }
                bool write(const value_type& data, bool){
                    write(data);
                    return true;
                }
            };

        public:
            void lock(){
                memory<std::uint32_t>(A + R::CR) |= B::LOCK;
            }

            void unlock(){
                memory<std::uint32_t>(A + R::KEYR) = B::KEY1;
                memory<std::uint32_t>(A + R::KEYR) = B::KEY2;
            }

            bool busy(){
                return memory<std::uint32_t>(A + R::SR) & B::BSY;
            }

            void start(){
                memory<std::uint32_t>(A + R::CR) |= B::STRT;
            }

            template<typename T = std::uint8_t>
            FlashReader<T> read(std::uint32_t address){
                return FlashReader<T>(address);
            }

            bool locked(){
                return memory<std::uint32_t>(A+R::CR) & B::LOCK;
            }

            void ProgrammingSize(std::size_t bits){
                memory<std::uint32_t>(A+R::CR) &= ~B::X_MASK;
                switch(bits){
                case 8:  memory<std::uint32_t>(A + R::CR) |= B::X8; break;
                case 16: memory<std::uint32_t>(A + R::CR) |= B::X16;break;
                case 32: memory<std::uint32_t>(A + R::CR) |= B::X32;break;
                case 64: memory<std::uint32_t>(A + R::CR) |= B::X64;break;
                default:break;
                }
            }

            // Must be started via start()
            // then busy wait outside of this
            void SectorErase(uint8_t sector){
                while(busy())
                    asm volatile("");
                memory<std::uint32_t>(A + R::CR) &= ~B::SNR_OFF;
                memory<std::uint32_t>(A + R::CR) |= sector << B::SNR_OFF;
                memory<std::uint32_t>(A + R::CR) |= B::SER;
            }

            void SectorErase(uint8_t sector, bool blocking){
                SectorErase(sector);
                if(blocking){
                    start();
                    while(busy())
                        asm volatile("");
                }
            }

            void MassErase(){
                memory<std::uint32_t>(A + R::CR) |= B::MER;
            }

            void EnableProgramming(){
                memory<std::uint32_t>(A + R::CR) |= B::PG;
            }

            void DisableProgramming(){
                memory<std::uint32_t>(A + R::CR) &= ~B::PG;
            }
        };
    }
}

#endif /* LET_FLASH_HPP */
