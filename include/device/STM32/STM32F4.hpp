/**
 * @file   let/include/device/STM32/STM32F4.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  STM32F4 specifics
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
#ifndef LET_DEVICE_STM32_STM32F4_HPP
#define LET_DEVICE_STM32_STM32F4_HPP

#if   defined(STM32F401xC) /* STM32F401CB, STM32F401CC, STM32F401RB, STM32F401RC, STM32F401VB and STM32F401VC Devices */
# include "STM32F401xC.hpp"
#elif defined(STM32F401xE) /* STM32F401CD, STM32F401RD, STM32F401VD, STM32F401CE, STM32F401RE and STM32F401VE Devices */
# include "STM32F401xE.hpp"
#elif defined(STM32F405xx) /* STM32F405RG, STM32F405VG and STM32F405ZG Devices */
# include "STM32F405xx.hpp"
#elif defined(STM32F407xx) /* STM32F407VG, STM32F407VE, STM32F407ZG, STM32F407ZE, STM32F407IG  and STM32F407IE Devices */
# include "STM32F407xx.hpp"
#elif defined(STM32F410Tx) /* STM32F410T8 and STM32F410TB Devices */
# include "STM32F410Tx.hpp"
#elif defined(STM32F410Cx) /* STM32F410C8 and STM32F410CB Devices */
# include "STM32F410Cx.hpp"
#elif defined(STM32F410Rx) /* STM32F410R8 and STM32F410RB Devices */
# include "STM32F410Rx.hpp"
#elif defined(STM32F411xE) /* STM32F411CC, STM32F411RC, STM32F411VC, STM32F411CE, STM32F411RE and STM32F411VE Devices */
# include "STM32F411xE.hpp"
#elif defined(STM32F412Cx) /* STM32F412CEU and STM32F412CGU Devices */
# include "STM32F412Cx.hpp"
#elif defined(STM32F412Zx) /* STM32F412ZET, STM32F412ZGT, STM32F412ZEJ and STM32F412ZGJ Devices */
# include "STM32F412Zx.hpp"
#elif defined(STM32F412Vx) /* STM32F412VET, STM32F412VGT, STM32F412VEH and STM32F412VGH Devices */
# include "STM32F412Vx.hpp"
#elif defined(STM32F412Rx) /* STM32F412RET, STM32F412RGT, STM32F412REY and STM32F412RGY Devices */
# include "STM32F412Rx.hpp"
#elif defined(STM32F413xx) /* STM32F413CH, STM32F413MH, STM32F413RH, STM32F413VH, STM32F413ZH, STM32F413CG, STM32F413MG, STM32F413RG, STM32F413VG and STM32F413ZG Devices */
# include "STM32F413xx.hpp"
#elif defined(STM32F415xx) /* STM32F415RG, STM32F415VG and STM32F415ZG Devices */
# include "STM32F415xx.hpp"
#elif defined(STM32F417xx) /* STM32F417VG, STM32F417VE, STM32F417ZG, STM32F417ZE, STM32F417IG and STM32F417IE Devices */
# include "STM32F417xx.hpp"
#elif defined(STM32F423xx) /* STM32F423CH, STM32F423RH, STM32F423VH and STM32F423ZH Devices */
# include "STM32F423xx.hpp"
#elif defined(STM32F427xx) /* STM32F427VG, STM32F427VI, STM32F427ZG, STM32F427ZI, STM32F427IG and STM32F427II Devices */
# include "STM32F427xx.hpp"
#elif defined(STM32F429xx) /* STM32F429VG, STM32F429VI, STM32F429ZG, STM32F429ZI, STM32F429BG, STM32F429BI, STM32F429NG, STM32F439NI, STM32F429IG  and STM32F429II Devices */
# include "STM32F429xx.hpp"
#elif defined(STM32F437xx) /* STM32F437VG, STM32F437VI, STM32F437ZG, STM32F437ZI, STM32F437IG and STM32F437II Devices */
# include "STM32F437xx.hpp"
#elif defined(STM32F439xx) /* STM32F439VG, STM32F439VI, STM32F439ZG, STM32F439ZI, STM32F439BG, STM32F439BI, STM32F439NG, STM32F439NI, STM32F439IG and STM32F439II Devices */
# include "STM32F439xx.hpp"
#elif defined(STM32F446xx) /* STM32F446MC, STM32F446ME, STM32F446RC, STM32F446RE, STM32F446VC, STM32F446VE, STM32F446ZC, and STM32F446ZE Devices */
# include "STM32F446xx.hpp"
#elif defined(STM32F469xx) /* STM32F469AI, STM32F469II, STM32F469BI, STM32F469NI, STM32F469AG, STM32F469IG, STM32F469BG, STM32F469NG, STM32F469AE, STM32F469IE, STM32F469BE and STM32F469NE Devices */
# include "STM32F469xx.hpp"
#elif defined(STM32F479xx) /* STM32F479AI, STM32F479II, STM32F479BI, STM32F479NI, STM32F479AG, STM32F479IG, STM32F479BG and STM32F479NG Devices */
# include "STM32F479xx.hpp"
#else
# error Device not defined
#endif

#endif /* LET_DEVICE_STM32_STM32F4_HPP */
