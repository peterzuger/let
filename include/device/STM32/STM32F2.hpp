/**
 * @file   let/include/device/STM32/STM32F2.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32F2 specifics
 */
#ifndef LET_DEVICE_STM32_STM32F2_HPP
#define LET_DEVICE_STM32_STM32F2_HPP

#if   defined(STM32F205xx) /* STM32F205xx Devices */
# include "STM32F205xx.hpp"
#elif defined(STM32F207xx) /* STM32F207xx Devices */
# include "STM32F207xx.hpp"
#elif defined(STM32F215xx) /* STM32F215xx Devices */
# include "STM32F215xx.hpp"
#elif defined(STM32F217xx) /* STM32F217xx Devices */
# include "STM32F217xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32F2_HPP */
