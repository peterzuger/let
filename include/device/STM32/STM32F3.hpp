/**
 * @file   let/include/device/STM32/STM32F3.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32F3 specifics
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
#ifndef LET_DEVICE_STM32_STM32F3_HPP
#define LET_DEVICE_STM32_STM32F3_HPP

#if   defined(STM32F301x8) /* STM32F301K6, STM32F301K8, STM32F301C6, STM32F301C8, STM32F301R6 and STM32F301R8 Devices */
# include "STM32F301x8.hpp"
#elif defined(STM32F302x8) /* STM32F302K6, STM32F302K8, STM32F302C6, STM32F302C8, STM32F302R6 and STM32F302R8 Devices */
# include "STM32F302x8.hpp"
#elif defined(STM32F302xC) /* STM32F302CB, STM32F302CC, STM32F302RB, STM32F302RC, STM32F302VB and STM32F302VC Devices */
# include "STM32F302xC.hpp"
#elif defined(STM32F302xE) /* STM32F302RE, STM32F302VE, STM32F302ZE, STM32F302RD, STM32F302VD and STM32F302ZD Devices */
# include "STM32F302xE.hpp"
#elif defined(STM32F303x8) /* STM32F303K6, STM32F303K8, STM32F303C6, STM32F303C8, STM32F303R6 and STM32F303R8 Devices */
# include "STM32F303x8.hpp"
#elif defined(STM32F303xC) /* STM32F303CB, STM32F303CC, STM32F303RB, STM32F303RC, STM32F303VB and STM32F303VC Devices */
# include "STM32F303xC.hpp"
#elif defined(STM32F303xE) /* STM32F303RE, STM32F303VE, STM32F303ZE, STM32F303RD, STM32F303VD and STM32F303ZD Devices */
# include "STM32F303xE.hpp"
#elif defined(STM32F318xx) /* STM32F318K8, STM32F318C8: STM32F301x8 with regulator off: STM32F318xx Devices */
# include "STM32F318xx.hpp"
#elif defined(STM32F328xx) /* STM32F328C8, STM32F328R8: STM32F334x8 with regulator off: STM32F328xx Devices */
# include "STM32F328xx.hpp"
#elif defined(STM32F334x8) /* STM32F334K4, STM32F334K6, STM32F334K8, STM32F334C4, STM32F334C6, STM32F334C8, STM32F334R4, STM32F334R6 and STM32F334R8 Devices */
# include "STM32F334x8.hpp"
#elif defined(STM32F358xx) /* STM32F358CC, STM32F358RC, STM32F358VC: STM32F303xC with regulator off: STM32F358xx Devices */
# include "STM32F358xx.hpp"
#elif defined(STM32F373xC) /* STM32F373C8, STM32F373CB, STM32F373CC, STM32F373R8, STM32F373RB, STM32F373RC, STM32F373V8, STM32F373VB and STM32F373VC Devices */
# include "STM32F373xC.hpp"
#elif defined(STM32F378xx) /* STM32F378CC, STM32F378RC, STM32F378VC: STM32F373xC with regulator off: STM32F378xx Devices */
# include "STM32F378xx.hpp"
#elif defined(STM32F398xx) /* STM32F398VE: STM32F303xE with regulator off: STM32F398xx Devices */
# include "STM32F398xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32F3_HPP */
