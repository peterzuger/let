/**
 * @file   let/include/device/STM32/STM32H7.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32H7 specifics
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
#ifndef LET_DEVICE_STM32_STM32H7_HPP
#define LET_DEVICE_STM32_STM32H7_HPP

#if   defined(STM32H743xx) /* STM32H743xx Devices */
# include "STM32H743xx.hpp"
#elif defined(STM32H753xx) /* STM32H753xx Devices */
# include "STM32H753xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32H7_HPP */
