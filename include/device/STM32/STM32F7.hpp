/**
 * @file    device/STM32/STM32F7.hpp
 * @author  Peter Zueger
 * @date    11.08.2018
 * @brief   STM32F7 specifics
 */
#ifndef __STM32F7_HPP__
#define __STM32F7_HPP__

#if   defined(STM32F722xx) /* STM32F722xx Devices */
# include "STM32F722xx.hpp"
#elif defined(STM32F723xx) /* STM32F723xx Devices */
# include "STM32F723xx.hpp"
#elif defined(STM32F732xx) /* STM32F732xx Devices */
# include "STM32F732xx.hpp"
#elif defined(STM32F733xx) /* STM32F733xx Devices */
# include "STM32F733xx.hpp"
#elif defined(STM32F745xx) /* STM32F745xx Devices */
# include "STM32F745xx.hpp"
#elif defined(STM32F746xx) /* STM32F746xx Devices */
# include "STM32F746xx.hpp"
#elif defined(STM32F756xx) /* STM32F756xx Devices */
# include "STM32F756xx.hpp"
#elif defined(STM32F765xx) /* STM32F765xx Devices */
# include "STM32F765xx.hpp"
#elif defined(STM32F767xx) /* STM32F767xx Devices */
# include "STM32F767xx.hpp"
#elif defined(STM32F769xx) /* STM32F769xx Devices */
# include "STM32F769xx.hpp"
#elif defined(STM32F777xx) /* STM32F777xx Devices */
# include "STM32F777xx.hpp"
#elif defined(STM32F779xx) /* STM32F779xx Devices */
# include "STM32F779xx.hpp"
#else
# error Device not defined
#endif

#endif /* __STM32F7_HPP__ */
