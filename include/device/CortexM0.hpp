/**
 * @file   let/include/device/CortexM0.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  ARM Coretex M0 device header
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
#ifndef LET_DEVICE_CORTEXM0_HPP
#define LET_DEVICE_CORTEXM0_HPP

namespace let{
    namespace STK{
        constexpr auto STK              = 0xE000E010;

        namespace R{
            constexpr auto CTRL         = 0x00;   // SysTick control and status register
            constexpr auto LOAD         = 0x04;   // SysTick reload value register
            constexpr auto VAL          = 0x08;   // SysTick current value register
            constexpr auto CALIB        = 0x0C;   // SysTick calibration value register
        }

        namespace B{
            // CTRL
            constexpr auto ENABLE       = 1 << 0; // Counter enable
            constexpr auto TICKINT      = 1 << 1; // SysTick exception request enable
            constexpr auto CLKSOURCE    = 1 << 2; // Clock source selection
            constexpr auto COUNTFLAG    = 1 << 16;// Counted to 0 ?

            // CALIB
            constexpr auto SKEW         = 1 << 30;// Reads as one
            constexpr auto NOREF        = 1 << 31;// Reads as one
        }
    }

    namespace SCB{
        constexpr auto SCB              = 0xE000ED00;

        namespace R{
            constexpr auto CPUID        = 0x00;   // base register
            constexpr auto ICSR         = 0x04;   // Interrupt control and state register
            constexpr auto AIRCR        = 0x0C;   // Application interrupt and reset control register
            constexpr auto SCR          = 0x10;   // System control register
            constexpr auto CCR          = 0x14;   // Configuration and control register
            constexpr auto SHPR2        = 0x1C;   // System handler priority registers
            constexpr auto SHPR3        = 0x20;   // ""
        }

        namespace B{
            // ICSR
            constexpr auto ISRPENDING   = 1 << 22;// Interrupt pending flag, excluding NMI and Faults.
            constexpr auto PENDSTCLR    = 1 << 25;// SysTick exception clear-pending bit (W)
            constexpr auto PENDSTSET    = 1 << 26;// SysTickexceptionset-pendingbit (R/W)
            constexpr auto PENDSVCLR    = 1 << 27;// PendSV clear-pending bit (W)
            constexpr auto PENDSVSET    = 1 << 28;// PendSV set-pending bit (W)
            constexpr auto NMIPENDSET   = 1 << 31;// NMI set-pending bit (R/W)

            // AIRCR
            constexpr auto VECTCLRACTIVE= 1 << 1; // reads as 0
            constexpr auto SYSRESETREQ  = 1 << 2; // System reset request
            constexpr auto ENDIANES     = 1 << 15;// reads as 0 --> Little-endian
            //   31:16                            // must be 0x5FA on a write

            // SCR
            constexpr auto SLEEPONEXIT  = 1 << 1; // Disable main loop Interrupts / Exceptions only
            constexpr auto SLEEPDEEP    = 1 << 2; // Enable deep sleep
            constexpr auto SEVEONPEND   = 1 << 4; // Send Event on Pending bit

            // CCR
            constexpr auto UNALIGN_TRP  = 1 << 3; // Always one -> all unaligned accesses generate a HardFault
            constexpr auto STKALIGN     = 1 << 9; // Always one -> indicates 8byte stack alignment on exception entry
        }
    }

    namespace NVIC{
        constexpr auto NVIC             = 0xE000E100;

        namespace R{
            constexpr auto ISER         = 0x000;  // Interrupt set enable register
            constexpr auto ICER         = 0x080;  // Interrupt clear enable register
            constexpr auto ISPR         = 0x100;  // Interrupt set pending register
            constexpr auto ICPR         = 0x180;  // Interrupt clear pending register

            constexpr auto IPR          = 0x300;  // Interrupt priority register
        }
    }
}

#endif /* LET_DEVICE_CORTEXM0_HPP */
