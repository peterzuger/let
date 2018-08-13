/**
 * @file   RNG.hpp
 * @author Peter Zueger
 * @date   12.08.2018
 * @brief  Random Number Generator abstraction
 */
#ifndef __RNG_HPP__
#define __RNG_HPP__

#include "HAL.hpp"

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

#endif /* __RNG_HPP__ */
