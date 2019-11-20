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
                SetBaudRate(16000000/baudrate);
                EnableTransmitter();
                EnableReceiver();
                Enable();
            }

            ~USART(){
                while(!(memory<std::uint32_t>(A+R::ISR) & B::TC));
                Disable();
            }

            void Enable()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::UE;
            }

            void Disable()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::UE;
            }

            void EnableTransmitter()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::TE;
            }

            void DisableTransmitter()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::TE;
            }

            void EnableReceiver()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::RE;
            }

            void DisableReceiver()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) &= ~B::RE;
            }

            void SetWordlen(Wordlen)noexcept volatile{
                // todo
            }

            void SetPolarity()noexcept volatile{}
            void SetPhase()noexcept volatile{}

            void EnableCTS()noexcept volatile{
                memory<std::uint32_t>(A+R::CR3) &= B::CTSE;
            }
            void DisableCTS()noexcept volatile{
                memory<std::uint32_t>(A+R::CR3) &= ~B::CTSE;
            }
            void EnableRTS()noexcept volatile{
                memory<std::uint32_t>(A+R::CR3) &= B::RTSE;
            }
            void DisableRTS()noexcept volatile{
                memory<std::uint32_t>(A+R::CR3) &= ~B::RTSE;
            }

            void flush()const noexcept volatile{
                while(!(memory<std::uint32_t>(A+R::ISR) & B::TC));
            }

            bool flush(bool blocking)const noexcept volatile{
                if(blocking)
                    flush();
                return memory<std::uint32_t>(A+R::ISR) & B::TC;
            }

            bool empty()const noexcept volatile{
                return memory<std::uint32_t>(A+R::ISR) & B::TXE;
            }

            void write(value_type d)const noexcept volatile{
                while(!empty());
                memory<std::uint32_t>(A+R::TDR) = d;
            }

            bool write(value_type d, bool blocking)const noexcept volatile{
                if(blocking){
                    write(d);
                    return true;
                }else{
                    if(empty()){
                        memory<std::uint32_t>(A+R::TDR) = d;
                        return true;
                    }else{
                        return false;
                    }
                }
            }

            bool any()const noexcept volatile{
                return memory<std::uint32_t>(A+R::ISR) & B::RXNE;
            }

            value_type read()const noexcept volatile{
                while(!any());
                return static_cast<std::uint8_t>(memory<std::uint32_t>(A+R::RDR));
            }

            std::optional<value_type> read(bool blocking)const noexcept volatile{
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

            void write(std::string_view view)const noexcept volatile{
                for(const auto i : view)
                    write(i);
            }

            void sendBreak()const noexcept volatile{
#if defined(STM32F4) && !defined(STM32F437xx)
                memory<std::uint32_t>(A+R::CR1) |= B::SBK;
#else
                memory<std::uint32_t>(A+R::RQR) |= B::SBKRQ;
#endif /* defined(STM32F4) */
            }

            void SetBaudRate(std::uint32_t baud)noexcept volatile{
                memory<std::uint32_t>(A+R::BRR) = baud;
            }

            void EnableOversampling()noexcept volatile{
                memory<std::uint32_t>(A+R::CR1) |= B::OVER8;
            }
            void DisableOversampling()noexcept volatile{
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
