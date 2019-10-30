/**
 * @file   let/include/device/device.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  Device Family Selection
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
#ifndef LET_DEVICE_DEVICE_HPP
#define LET_DEVICE_DEVICE_HPP

#if defined(STM32L0)
# include "STM32/STM32L0.hpp" // Coretex-M0+
# include "CortexM0p.hpp"
#elif defined(STM32L1)
# include "STM32/STM32L1.hpp" // Coretex-M3
# include "CortexM3.hpp"
#elif defined(STM32L4)
# include "STM32/STM32L4.hpp" // Coretex-M4F
# include "CortexM4F.hpp"
#elif defined(STM32F0)
# include "STM32/STM32F0.hpp" // Coretex-M0
# include "CortexM0.hpp"
#elif defined(STM32F1)
# include "STM32/STM32F1.hpp" // Coretex-M3
# include "CortexM3.hpp"
#elif defined(STM32F2)
# include "STM32/STM32F2.hpp" // Coretex-M3
# include "CortexM3.hpp"
#elif defined(STM32F3)
# include "STM32/STM32F3.hpp" // Coretex-M4F
# include "CortexM4F.hpp"
#elif defined(STM32F4)
# include "STM32/STM32F4.hpp" // Coretex-M4F
# include "CortexM4F.hpp"
#elif defined(STM32F7)
# include "STM32/STM32F7.hpp" // Coretex-M7F
# include "CortexM7F.hpp"
#elif defined(STM32H7)
# include "STM32/STM32H7.hpp" // Coretex-M7F
# include "CortexM7F.hpp"
#else
# error Family not defined
#endif /* defined(STM32xx) */

#endif /* LET_DEVICE_DEVICE_HPP */
