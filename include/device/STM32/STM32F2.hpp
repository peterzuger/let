/**
 * @file    STM32F2.hpp
 * @author  Peter Zueger
 * @date    11.08.2018
 * @brief   STM32F2 specifics
 */
#ifndef __STM32F2_HPP__
#define __STM32F2_HPP__

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

#endif /* __STM32F2_HPP__ */
