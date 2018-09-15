/**
 * @file   GPIO.hpp
 * @author Peter Zueger
 * @date   12.08.2017
 * @brief  General Purpose Input / Output abstraction
 */
#ifndef __GPIO_HPP__
#define __GPIO_HPP__

#include "HAL.hpp"

namespace let{
    namespace GPIO{

        /**
         * GPIO pin modes
         */
        enum class Mode{
            Input,     /**< Configure as input pin          */
            Output,    /**< Configure as output pin         */
            Alternate, /**< Use pin for alternate functions */
            Analog     /**< Use pin as analog input         */
        };

        /**
         * GPIO pin output modes
         */
        enum class OType{
            PushPull,  /**< Configure output pin as Push Pull  */
            OpenDrain  /**< Configure output Pin as Open Drain */
        };

        /**
         * GPIO speed's a.e. slew rate control
         */
        enum class OSpeed{
            Slow,     /**< ~2MHz   */
            Medium,   /**< ~25MHz  */
            Fast,     /**< ~50MHz  */
            High      /**< ~100MHz */
        };

        /**
         * internal resistor states
         */
        enum class Pull{
            NoPull,   /**< no internal pullup or pulldown resistors */
            Pullup,   /**< enable the internal pullup resistor      */
            Pulldown  /**< enable the internal pulldown resistor    */
        };

        /**
         * @brief capture a GPIO pin in an object
         * A object of this class does not use any storage and all methods
         * can be inlined.
         *
         * @note always prefer to call .set()/.clear() instead of .write()
         * @tparam P GPIO Port e.g. let::GPIO::GPIOA
         * @tparam p GPIO pin  e.g. 3
         */
        template<std::uint32_t P,std::uint8_t p>
        class Pin{
            static_assert(p <= 15, "GPIO Pin pin out of range [0 ... 15]");

        public:
            Pin() = default;

            Pin(Mode m){
                mode(m);
            }

            Pin(Mode m,OType o){
                mode(m);
                OutputType(o);
            }

            operator bool(){
                return read();
            }

            Pin& operator=(bool val){
                write(val);
                return *this;
            }

            void write(bool val){
                if(val)
                    set();
                else
                    clear();
            }

            bool read(){
                return memory<std::uint32_t>(P+R::IDR) & BIT(p);
            }

            void set(){
                memory<std::uint32_t>(P+R::BSRR) = BIT(p);
            }

            void clear(){
                memory<std::uint16_t>(P+R::BSRR+2) = BIT(p);
            }

            void toggle(){
                memory<std::uint32_t>(P+R::ODR) ^= BIT(p);
            }

            void mode(Mode m){
                memory<std::uint32_t>(P+R::MODER) &= ~(0b11 << (p*2));

                switch(m){
                case Mode::Input:
                    memory<std::uint32_t>(P+R::MODER) |= (B::Input << (p*2));
                    break;

                case Mode::Output:
                    memory<std::uint32_t>(P+R::MODER) |= (B::Output << (p*2));
                    break;

                case Mode::Alternate:
                    memory<std::uint32_t>(P+R::MODER) |= (B::Analog << (p*2));
                    break;

                case Mode::Analog:
                    memory<std::uint32_t>(P+R::MODER) |= (B::Alternate << (p*2));
                    break;
                }
            }

            void OutputType(OType o){
                if(o == OType::OpenDrain)
                    memory<std::uint32_t>(P+R::OTYPER) |= BIT(p);
                else
                    memory<std::uint32_t>(P+R::OTYPER) &= ~BIT(p);
            }

            void OutputSpeed(OSpeed o){
                memory<std::uint32_t>(P+R::OSPEEDR) &= ~(0b11 << (p*2));

                switch(o){
                case OSpeed::Slow:
                    memory<std::uint32_t>(P+R::OSPEEDR) |= (B::Slow << (p*2));
                    break;

                case OSpeed::Medium:
                    memory<std::uint32_t>(P+R::OSPEEDR) |= (B::Medium << (p*2));
                    break;

                case OSpeed::Fast:
                    memory<std::uint32_t>(P+R::OSPEEDR) |= (B::Fast << (p*2));
                    break;

                case OSpeed::High:
                    memory<std::uint32_t>(P+R::OSPEEDR) |= (B::High << (p*2));
                    break;
                }
            }

            void PullUpDown(Pull m){
                memory<std::uint32_t>(P+R::PUPDR) &= ~(0b11 << (p*2));

                switch(m){
                case Pull::NoPull:
                    memory<std::uint32_t>(P+R::PUPDR) |= (B::NoPull << (p*2));
                    break;

                case Pull::Pullup:
                    memory<std::uint32_t>(P+R::PUPDR) |= (B::Pullup << (p*2));
                    break;

                case Pull::Pulldown:
                    memory<std::uint32_t>(P+R::PUPDR) |= (B::Pulldown << (p*2));
                    break;
                }
            }

            void AlternateFunction(const std::uint8_t f){
                if(p < 8){
                    memory<std::uint32_t>(P+R::AFRL) &= ~(0xF << (p*4));
                    memory<std::uint32_t>(P+R::AFRL) |= (f << (p*4));
                }else{
                    memory<std::uint32_t>(P+R::AFRH) &= ~(0xF << ((p-8)*4));
                    memory<std::uint32_t>(P+R::AFRH) |= (f << ((p-8)*4));
                }
            }
        };

        /**
         * @brief configure a pin for alternate use
         * This function can be used to configure a GPIO pin
         * for use with an alternate Peripheral e.g. USART
         *
         * @tparam P GPIO Port to use
         * @tparam p GPIO Pin to use
         * @param  f alternate function to be configured
         * @return true on success
         */
        template<std::uint32_t P,std::uint8_t p>
        void AlternateFunction(const std::uint8_t f){
            Pin<P,p>(Mode::Alternate).AlternateFunction(f);
        }

        /**
         * @brief Lock pins in Port
         * This function will lock all configuration registers
         * for the pins in Port
         *
         * @note Can only be called once per port
         * @tparam P wich port to lock
         * @tparam pins wich pins in Port to lock
         * @return true on success
         */
        template<std::uint32_t P,std::uint16_t p>
        bool LockPort(){
            std::uint32_t& m = memory<std::uint32_t>(P+R::LCKR);
            std::uint32_t tmp = p | B::LCKK;

            m = tmp;
            m = p;
            m = tmp;
            tmp = m;
            return m & B::LCKK;
        }
    }
}

#endif /* __GPIO_HPP__ */
