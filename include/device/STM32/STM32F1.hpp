/**
 * @file   let/include/device/STM32/STM32F1.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32F1 specifics
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
#ifndef LET_DEVICE_STM32_STM32F1_HPP
#define LET_DEVICE_STM32_STM32F1_HPP

#if   defined(STM32F100xB) /* STM32F100C4, STM32F100R4, STM32F100C6, STM32F100R6, STM32F100C8, STM32F100R8, STM32F100V8, STM32F100CB, STM32F100RB and STM32F100VB */
# include "STM32F100xB.hpp"
#elif defined(STM32F100xE) /* STM32F100RC, STM32F100VC, STM32F100ZC, STM32F100RD, STM32F100VD, STM32F100ZD, STM32F100RE, STM32F100VE and STM32F100ZE */
# include "STM32F100xE.hpp"
#elif defined(STM32F101x6) /* STM32F101C4, STM32F101R4, STM32F101T4, STM32F101C6, STM32F101R6 and STM32F101T6 Devices */
# include "STM32F101x6.hpp"
#elif defined(STM32F101xB) /* STM32F101C8, STM32F101R8, STM32F101T8, STM32F101V8, STM32F101CB, STM32F101RB, STM32F101TB and STM32F101VB */
# include "STM32F101xB.hpp"
#elif defined(STM32F101xE) /* STM32F101RC, STM32F101VC, STM32F101ZC, STM32F101RD, STM32F101VD, STM32F101ZD, STM32F101RE, STM32F101VE and STM32F101ZE */
# include "STM32F101xE.hpp"
#elif defined(STM32F101xG) /* STM32F101RF, STM32F101VF, STM32F101ZF, STM32F101RG, STM32F101VG and STM32F101ZG */
# include "STM32F101xG.hpp"
#elif defined(STM32F102x6) /* STM32F102C4, STM32F102R4, STM32F102C6 and STM32F102R6 */
# include "STM32F102x6.hpp"
#elif defined(STM32F102xB) /* STM32F102C8, STM32F102R8, STM32F102CB and STM32F102RB */
# include "STM32F102xB.hpp"
#elif defined(STM32F103x6) /* STM32F103C4, STM32F103R4, STM32F103T4, STM32F103C6, STM32F103R6 and STM32F103T6 */
# include "STM32F103x6.hpp"
#elif defined(STM32F103xB) /* STM32F103C8, STM32F103R8, STM32F103T8, STM32F103V8, STM32F103CB, STM32F103RB, STM32F103TB and STM32F103VB */
# include "STM32F103xB.hpp"
#elif defined(STM32F103xE) /* STM32F103RC, STM32F103VC, STM32F103ZC, STM32F103RD, STM32F103VD, STM32F103ZD, STM32F103RE, STM32F103VE and STM32F103ZE */
# include "STM32F103xE.hpp"
#elif defined(STM32F103xG) /* STM32F103RF, STM32F103VF, STM32F103ZF, STM32F103RG, STM32F103VG and STM32F103ZG */
# include "STM32F103xG.hpp"
#elif defined(STM32F105xC) /* STM32F105R8, STM32F105V8, STM32F105RB, STM32F105VB, STM32F105RC and STM32F105VC */
# include "STM32F105xC.hpp"
#elif defined(STM32F107xC) /* STM32F107RB, STM32F107VB, STM32F107RC and STM32F107VC */
# include "STM32F107xC.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32F1_HPP */
