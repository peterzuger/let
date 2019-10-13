/**
 * @file   let/include/device/STM32/STM32F2.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32F2 specifics
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
