/**
 * @file    device/STM32/STM32H7.hpp
 * @author  Peter Zueger
 * @date    11.08.2018
 * @brief   STM32H7 specifics
 */
#ifndef LET_DEVICE_STM32_STM32H7_HPP
#define LET_DEVICE_STM32_STM32H7_HPP

#if   defined(STM32H743xx) /* STM32H743xx Devices */
# include "STM32H743xx.hpp"
#elif defined(STM32H753xx) /* STM32H753xx Devices */
# include "STM32H753xx.hpp"
#else
# else Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32H7_HPP */
