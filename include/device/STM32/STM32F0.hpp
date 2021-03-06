/**
 * @file   let/include/device/STM32/STM32F0.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32F0 specifics
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
#ifndef LET_DEVICE_STM32_STM32F0_HPP
#define LET_DEVICE_STM32_STM32F0_HPP

#if   defined(STM32F030x6) /* STM32F030x4, STM32F030x6 Devices (STM32F030xx microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)              */
# include "STM32F030x6.hpp"
#elif defined(STM32F030x8) /* STM32F030x8 Devices (STM32F030xx microcontrollers where the Flash memory is 64 Kbytes)                                              */
# include "STM32F030x8.hpp"
#elif defined(STM32F031x6) /* STM32F031x4, STM32F031x6 Devices (STM32F031xx microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)              */
# include "STM32F031x6.hpp"
#elif defined(STM32F038xx) /* STM32F038xx Devices (STM32F038xx microcontrollers where the Flash memory is 32 Kbytes)                                              */
# include "STM32F038xx.hpp"
#elif defined(STM32F042x6) /* STM32F042x4, STM32F042x6 Devices (STM32F042xx microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)              */
# include "STM32F042x6.hpp"
#elif defined(STM32F048x6) /* STM32F048xx Devices (STM32F042xx microcontrollers where the Flash memory is 32 Kbytes)                                              */
# include "STM32F048x6.hpp"
#elif defined(STM32F051x8) /* STM32F051x4, STM32F051x6, STM32F051x8 Devices (STM32F051xx microcontrollers where the Flash memory ranges between 16 and 64 Kbytes) */
# include "STM32F051x8.hpp"
#elif defined(STM32F058xx) /* STM32F058xx Devices (STM32F058xx microcontrollers where the Flash memory is 64 Kbytes)                                              */
# include "STM32F058xx.hpp"
#elif defined(STM32F070x6) /* STM32F070x6 Devices (STM32F070x6 microcontrollers where the Flash memory ranges between 16 and 32 Kbytes)                           */
# include "STM32F070x6.hpp"
#elif defined(STM32F070xB) /* STM32F070xB Devices (STM32F070xB microcontrollers where the Flash memory ranges between 64 and 128 Kbytes)                          */
# include "STM32F070xB.hpp"
#elif defined(STM32F071xB) /* STM32F071x8, STM32F071xB Devices (STM32F071xx microcontrollers where the Flash memory ranges between 64 and 128 Kbytes)             */
# include "STM32F071xB.hpp"
#elif defined(STM32F072xB) /* STM32F072x8, STM32F072xB Devices (STM32F072xx microcontrollers where the Flash memory ranges between 64 and 128 Kbytes)             */
# include "STM32F072xB.hpp"
#elif defined(STM32F078xx) /* STM32F078xx Devices (STM32F078xx microcontrollers where the Flash memory is 128 Kbytes)                                             */
# include "STM32F078xx.hpp"
#elif defined(STM32F030xC) /* STM32F030xC Devices (STM32F030xC microcontrollers where the Flash memory is 256 Kbytes)                                             */
# include "STM32F030xC.hpp"
#elif defined(STM32F091xC) /* STM32F091xB, STM32F091xC Devices (STM32F091xx microcontrollers where the Flash memory ranges between 128 and 256 Kbytes)            */
# include "STM32F091xC.hpp"
#elif defined(STM32F098xx) /* STM32F098xx Devices (STM32F098xx microcontrollers where the Flash memory is 256 Kbytes)                                             */
# include "STM32F098xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32F0_HPP */
