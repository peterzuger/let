/**
 * @file   let/include/device/STM32/STM32L0.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32L0 specifics
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
#ifndef LET_DEVICE_STM32_STM32L0_HPP
#define LET_DEVICE_STM32_STM32L0_HPP

#if   defined(STM32L011xx) /* STM32L011xx Devices */
# include "STM32L011xx.hpp"
#elif defined(STM32L021xx) /* STM32L021xx Devices */
# include "STM32L021xx.hpp"
#elif defined(STM32L031xx) /* STM32L031xx Devices */
# include "STM32L031xx.hpp"
#elif defined(STM32L041xx) /* STM32L041xx Devices */
# include "STM32L041xx.hpp"
#elif defined(STM32L051xx) /* STM32L051xx Devices */
# include "STM32L051xx.hpp"
#elif defined(STM32L052xx) /* STM32L052xx Devices */
# include "STM32L052xx.hpp"
#elif defined(STM32L053xx) /* STM32L053xx Devices */
# include "STM32L053xx.hpp"
#elif defined(STM32L061xx) /* STM32L061xx Devices */
# include "STM32L061xx.hpp"
#elif defined(STM32L062xx) /* STM32L062xx Devices */
# include "STM32L062xx.hpp"
#elif defined(STM32L063xx) /* STM32L063xx Devices */
# include "STM32L063xx.hpp"
#elif defined(STM32L071xx) /* STM32L071xx Devices */
# include "STM32L071xx.hpp"
#elif defined(STM32L072xx) /* STM32L072xx Devices */
# include "STM32L072xx.hpp"
#elif defined(STM32L073xx) /* STM32L073xx Devices */
# include "STM32L073xx.hpp"
#elif defined(STM32L081xx) /* STM32L081xx Devices */
# include "STM32L081xx.hpp"
#elif defined(STM32L082xx) /* STM32L082xx Devices */
# include "STM32L082xx.hpp"
#elif defined(STM32L083xx) /* STM32L083xx Devices */
# include "STM32L083xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32L0_HPP */
