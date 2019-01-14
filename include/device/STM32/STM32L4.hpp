/**
 * @file    device/STM32/STM32L4.hpp
 * @author  Peter Zueger
 * @date    11.08.2018
 * @brief   STM32L4 specifics
 */
#ifndef LET_DEVICE_STM32_STM32L4_HPP
#define LET_DEVICE_STM32_STM32L4_HPP

#if   defined(STM32L431xx) /* STM32L431xx Devices */
# include "STM32L431xx.hpp"
#elif defined(STM32L432xx) /* STM32L432xx Devices */
# include "STM32L432xx.hpp"
#elif defined(STM32L433xx) /* STM32L433xx Devices */
# include "STM32L433xx.hpp"
#elif defined(STM32L442xx) /* STM32L442xx Devices */
# include "STM32L442xx.hpp"
#elif defined(STM32L443xx) /* STM32L443xx Devices */
# include "STM32L443xx.hpp"
#elif defined(STM32L451xx) /* STM32L451xx Devices */
# include "STM32L451xx.hpp"
#elif defined(STM32L452xx) /* STM32L452xx Devices */
# include "STM32L452xx.hpp"
#elif defined(STM32L462xx) /* STM32L462xx Devices */
# include "STM32L462xx.hpp"
#elif defined(STM32L471xx) /* STM32L471xx Devices */
# include "STM32L471xx.hpp"
#elif defined(STM32L475xx) /* STM32L475xx Devices */
# include "STM32L475xx.hpp"
#elif defined(STM32L476xx) /* STM32L476xx Devices */
# include "STM32L476xx.hpp"
#elif defined(STM32L485xx) /* STM32L485xx Devices */
# include "STM32L485xx.hpp"
#elif defined(STM32L486xx) /* STM32L486xx Devices */
# include "STM32L486xx.hpp"
#elif defined(STM32L496xx) /* STM32L496xx Devices */
# include "STM32L496xx.hpp"
#elif defined(STM32L4A6xx) /* STM32L4A6xx Devices */
# include "STM32L4A6xx.hpp"
#elif defined(STM32L4R5xx) /* STM32L4R5xx Devices */
# include "STM32L4R5xx.hpp"
#elif defined(STM32L4R7xx) /* STM32L4R7xx Devices */
# include "STM32L4R7xx.hpp"
#elif defined(STM32L4R9xx) /* STM32L4R9xx Devices */
# include "STM32L4R9xx.hpp"
#elif defined(STM32L4S5xx) /* STM32L4S5xx Devices */
# include "STM32L4S5xx.hpp"
#elif defined(STM32L4S7xx) /* STM32L4S7xx Devices */
# include "STM32L4S7xx.hpp"
#elif defined(STM32L4S9xx) /* STM32L4S9xx Devices */
# include "STM32L4S9xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32L4_HPP */
