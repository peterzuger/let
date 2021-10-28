/**
 * @file   let/include/USART.hpp
 * @author Peter Züger
 * @date   14.08.201
 * @brief  Universal Synchronous/Asynchronous Receiver/Transmitter abstraction
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
#ifndef LET_USART_HPP
#define LET_USART_HPP

#include <string_view>
#include <optional>

#include "HAL.hpp"
#include "device/device.hpp"

namespace let{
    namespace USART{
        /**
         * USART Word length
         */
        enum class Wordlen{
            len7b,    /**< USART Word length 7 Bits */
            len8b,    /**< USART Word length 8 Bits */
            len9b     /**< USART Word length 9 Bits */
        };

        template<std::size_t A>
        class USART{
        public:
            using value_type = std::uint8_t;

            USART(std::size_t baudrate){
#if defined(STM32H7)
                SetBaudRate(64000000/baudrate);
#else
                SetBaudRate(16000000/baudrate);
#endif /* defined(STM32H7) */
                EnableTransmitter();
                EnableReceiver();
                Enable();
            }

            ~USART(){
                flush();
                Disable();
            }

            void Enable()volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::UE;
            }

            void Disable()volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::UE;
            }

            void EnableTransmitter()volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::TE;
            }

            void DisableTransmitter()volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::TE;
            }

            void EnableReceiver()volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::RE;
            }

            void DisableReceiver()volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::RE;
            }

            void SetWordlen(Wordlen)volatile{
                // todo
            }

            void SetPolarity()volatile{}
            void SetPhase()volatile{}

            void EnableCTS()volatile{
                memory<std::uint32_t>(A+R::CR3) &= B::CTSE;
            }
            void DisableCTS()volatile{
                memory<std::uint32_t>(A+R::CR3) &= ~B::CTSE;
            }
            void EnableRTS()volatile{
                memory<std::uint32_t>(A+R::CR3) &= B::RTSE;
            }
            void DisableRTS()volatile{
                memory<std::uint32_t>(A+R::CR3) &= ~B::RTSE;
            }

            bool busy()const volatile{
                return !(memory<std::uint32_t>(A+R::ISR) & B::TC);
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
                return memory<std::uint32_t>(A+R::ISR) & B::TXE;
            }

            void write(value_type d)const volatile{
                while(!empty());
                memory<value_type>(A+R::TDR) = d;
            }

            bool write(value_type d, bool blocking)const volatile{
                if(blocking){
                    write(d);
                    return true;
                }else{
                    if(empty()){
                        memory<value_type>(A+R::TDR) = d;
                        return true;
                    }else{
                        return false;
                    }
                }
            }

            bool any()const volatile{
                return memory<std::uint32_t>(A+R::ISR) & B::RXNE;
            }

            value_type read()const volatile{
                while(!any());
                return memory<value_type>(A+R::RDR);
            }

            std::optional<value_type> read(bool blocking)const volatile{
                if(blocking){
                    return std::make_optional(read());
                }else{
                    if(any()){
                        return std::make_optional(read());
                    }else{
                        return std::nullopt;
                    }
                }
            }

            void write(std::string_view view)const volatile{
                for(const auto i : view)
                    write(i);
            }

            void sendBreak()const volatile{
#if defined(STM32F4) && !defined(STM32F437xx)
                memory<std::uint32_t>(A+R::CR1) |= B::SBK;
#else
                memory<std::uint32_t>(A+R::RQR) |= B::SBKRQ;
#endif /* defined(STM32F4) */
            }

            void SetBaudRate(std::uint32_t baud)volatile{
                memory<std::uint32_t>(A+R::BRR) = baud;
            }

            void EnableOversampling()volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::OVER8;
            }
            void DisableOversampling()volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::OVER8;
            }
        };

        template<std::size_t A, typename T>
        USART<A>& operator<<(USART<A>& u, const T& d){
            u.write(d);
            return u;
        }
    }
}

#endif /* LET_USART_HPP */
