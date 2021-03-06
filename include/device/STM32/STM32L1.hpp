/**
 * @file   let/include/device/STM32/STM32L1.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32L1 specifics
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
#ifndef LET_DEVICE_STM32_STM32L1_HPP
#define LET_DEVICE_STM32_STM32L1_HPP

#if   defined(STM32L100xB) /* STM32L100C6, STM32L100R and STM32L100RB Devices */
# include "STM32L100xB.hpp"
#elif defined(STM32L100xBA)/* STM32L100C6-A, STM32L100R8-A and STM32L100RB-A Devices */
# include "STM32L100xBA.hpp"
#elif defined(STM32L100xC) /* STM32L100RC Devices */
# include "STM32L100xC.hpp"
#elif defined(STM32L151xB) /* STM32L151C6, STM32L151R6, STM32L151C8, STM32L151R8, STM32L151V8, STM32L151CB, STM32L151RB and STM32L151VB */
# include "STM32L151xB.hpp"
#elif defined(STM32L151xBA)/* STM32L151C6-A, STM32L151R6-A, STM32L151C8-A, STM32L151R8-A, STM32L151V8-A, STM32L151CB-A, STM32L151RB-A and STM32L151VB-A */
# include "STM32L151xBA.hpp"
#elif defined(STM32L151xC) /* STM32L151CC, STM32L151UC, STM32L151RC and STM32L151VC */
# include "STM32L151xC.hpp"
#elif defined(STM32L151xCA)/* STM32L151RC-A, STM32L151VC-A, STM32L151QC and STM32L151ZC */
# include "STM32L151xCA.hpp"
#elif defined(STM32L151xD) /* STM32L151QD, STM32L151RD, STM32L151VD & STM32L151ZD */
# include "STM32L151xD.hpp"
#elif defined(STM32L151xDX)/* STM32L151VD-X Devices */
# include "STM32L151xDX.hpp"
#elif defined(STM32L151xE) /* STM32L151QE, STM32L151RE, STM32L151VE and STM32L151ZE */
# include "STM32L151xE.hpp"
#elif defined(STM32L152xB) /* STM32L152C6, STM32L152R6, STM32L152C8, STM32L152R8, STM32L152V8, STM32L152CB, STM32L152RB and STM32L152VB */
# include "STM32L152xB.hpp"
#elif defined(STM32L152xBA)/* STM32L152C6-A, STM32L152R6-A, STM32L152C8-A, STM32L152R8-A, STM32L152V8-A, STM32L152CB-A, STM32L152RB-A and STM32L152VB-A */
# include "STM32L152xBA.hpp"
#elif defined(STM32L152xC) /* STM32L152CC, STM32L152UC, STM32L152RC and STM32L152VC */
# include "STM32L152xC.hpp"
#elif defined(STM32L152xCA)/* STM32L152RC-A, STM32L152VC-A, STM32L152QC and STM32L152ZC */
# include "STM32L152xCA.hpp"
#elif defined(STM32L152xD) /* STM32L152QD, STM32L152RD, STM32L152VD and STM32L152ZD */
# include "STM32L152xD.hpp"
#elif defined(STM32L152xDX)/* STM32L152VD-X Devices */
# include "STM32L152xDX.hpp"
#elif defined(STM32L152xE) /* STM32L152QE, STM32L152RE, STM32L152VE and STM32L152ZE */
# include "STM32L152xE.hpp"
#elif defined(STM32L162xC) /* STM32L162RC and STM32L162VC */
# include "STM32L162xC.hpp"
#elif defined(STM32L162xCA)/* STM32L162RC-A, STM32L162VC-A, STM32L162QC and STM32L162ZC */
# include "STM32L162xCA.hpp"
#elif defined(STM32L162xD) /* STM32L162QD, STM32L162RD, STM32L162VD and STM32L162ZD */
# include "STM32L162xD.hpp"
#elif defined(STM32L162xDX)/* STM32L162VD-X Devices */
# include "STM32L162xDX.hpp"
#elif defined(STM32L162xE) /* STM32L162RE, STM32L162VE and STM32L162ZE */
# include "STM32L162xe.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32L1_HPP */
