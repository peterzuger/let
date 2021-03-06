/**
 * @file   let/include/device/CortexM3.hpp
 * @author Peter Züger
 * @date   11.08.2018
 * @brief  ARM Coretex M3 device header
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
#ifndef LET_DEVICE_CORTEXM3_HPP
#define LET_DEVICE_CORTEXM3_HPP

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
            constexpr auto ACTLR        = -0xCF8; // Auxiliary control register
            constexpr auto CPUID        = 0x00;   // base register
            constexpr auto ICSR         = 0x04;   // Interrupt control and state register
            constexpr auto VTOR         = 0x08;   // Vector Table Offset Register
            constexpr auto AIRCR        = 0x0C;   // Application interrupt and reset control register
            constexpr auto SCR          = 0x10;   // System control register
            constexpr auto CCR          = 0x14;   // Configuration and control register
            constexpr auto SHPR1        = 0x18;   // System handler priority registers
            constexpr auto SHPR2        = 0x1C;   // "
            constexpr auto SHPR3        = 0x20;   // "
            constexpr auto SHCSR        = 0x24;   // System Handler control and state register
            constexpr auto CFSR         = 0x28;   // Configurable fault status register
            constexpr auto HFSR         = 0x2C;   // HardFault status register
            constexpr auto MMAR         = 0x34;   // MemoryManagement fault address register
            constexpr auto BFAR         = 0x38;   // BusFault address register
        }

        namespace B{
            // ACTLR
            constexpr auto DISMCYCINT   = 1 << 0; // Disables interrupt of multi-cycle instructions
            constexpr auto DISDEFWBUF   = 1 << 1; // Disables write buffer use during default memory map access
            constexpr auto DISFOLD      = 1 << 2; // Disables folding of IT instructions

            // ICSR
            constexpr auto RETOBASE     = 1 << 11;// Return to base level indicates if there are preempted active exceptions
            constexpr auto ISRPENDING   = 1 << 22;// Interrupt pending flag, excluding NMI and Faults.
            constexpr auto PENDSTCLR    = 1 << 25;// SysTick exception clear-pending bit (W)
            constexpr auto PENDSTSET    = 1 << 26;// SysTickexceptionset-pendingbit (R/W)
            constexpr auto PENDSVCLR    = 1 << 27;// PendSV clear-pending bit (W)
            constexpr auto PENDSVSET    = 1 << 28;// PendSV set-pending bit (W)
            constexpr auto NMIPENDSET   = 1 << 31;// NMI set-pending bit (R/W)

            // AIRCR
            constexpr auto VECTRESET    = 1 << 0; // reads as 0
            constexpr auto VECTCLRACTIVE= 1 << 1; // reads as 0
            constexpr auto SYSRESETREQ  = 1 << 2; // System reset request
            constexpr auto ENDIANES     = 1 << 15;// reads as 0 --> Little-endian
            //   31:16                            // must be 0x5FA on a write

            // SCR
            constexpr auto SLEEPONEXIT  = 1 << 1; // Disable main loop Interrupts / Exceptions only
            constexpr auto SLEEPDEEP    = 1 << 2; // Enable deep sleep
            constexpr auto SEVEONPEND   = 1 << 4; // Send Event on Pending bit

            // CCR
            constexpr auto NONBASETHRDENA= 1 << 0;// not documented
            constexpr auto USERSETMPEND = 1 << 1; // not documented
            constexpr auto UNALIGN_TRP  = 1 << 3; // Always one -> all unaligned accesses generate a HardFault
            constexpr auto DIV_0_TRP    = 1 << 4; // not documented
            constexpr auto BFHFNMIGN    = 1 << 8; // not documented
            constexpr auto STKALIGN     = 1 << 9; // Always one -> indicates 8byte stack alignment on exception entry

            // SHCSR
            constexpr auto MEMFAULTACT  = 1 << 0; // Memory management fault exception active bit, reads as 1 if exception is active
            constexpr auto BUSFAULTACT  = 1 << 1; // Bus fault exception active bit, reads as 1 if exception is active
            constexpr auto USGFAULTACT  = 1 << 3; // Usage fault exception active bit, reads as 1 if exception is active
            constexpr auto SVCALLACT    = 1 << 7; // SVC call active bit, reads as 1 if SVC call is active
            constexpr auto MONITORACT   = 1 << 8; // Debug monitor active bit, reads as 1 if exception is active
            constexpr auto PENDSVACT    = 1 << 10;// PendSV exception active bit, reads as 1 if exception is active
            constexpr auto SYSTICKACT   = 1 << 11;// SysTick exception active bit, reads as 1 if exception is active
            constexpr auto USGFAULTPENDED=1 << 12;// Usage fault exception pending bit, reads as 1 if exception is pending
            constexpr auto MEMFAULTPENDED=1 << 13;// Memory management exception pending bit, reads as 1 if exception is pending
            constexpr auto BUSFAULTPENDED=1 << 14;// Bus fault exception pending bit, reads as 1 if exception is pending
            constexpr auto SVCALLPENDED = 1 << 15;// SVC call pending bit, reads as 1 if exception is pending
            constexpr auto MEMFAULTENA  = 1 << 16;// Memory management fault enable bit, set 1 to enable
            constexpr auto BUSFAULTENA  = 1 << 17;// Bus fault enable bit, set 1 to enable
            constexpr auto USGFAULTENA  = 1 << 18;// Usage fault enable bit, set 1 to enable

            // CFSR
            constexpr auto IACCVIOL     = 1 << 0; // Instruction access violation flag
            constexpr auto DACCVIOL     = 1 << 1; // Data access violation flag
            constexpr auto MUNSTKERR    = 1 << 3; // Memory manager fault on unstacking for return from exception
            constexpr auto MSTKERR      = 1 << 4; // Memory manager fault on stacking for exception entry
            constexpr auto MMARVALID    = 1 << 7; // Memory management Fault address register valid flag
            constexpr auto IBUSERR      = 1 << 8; // Instruction bus error
            constexpr auto PRECISERR    = 1 << 9; // Precise data bus error
            constexpr auto IMPRECISERR  = 1 << 10;// Imprecise data bus error
            constexpr auto UNSTKERR     = 1 << 11;// Bus fault on unstacking for a return from exception
            constexpr auto STKERR       = 1 << 12;// Bus fault on stacking for exception entry
            constexpr auto BFARVALID    = 1 << 15;// Bus fault Address register valid flag
            constexpr auto UNDEFINSTR   = 1 << 16;// Undefined instruction usage fault
            constexpr auto INVSTATE     = 1 << 17;// Invalid state usage fault
            constexpr auto INVPC        = 1 << 18;// Invalid PC load usage fault, caused by an invalid PC load by EXC_RETURN
            constexpr auto NOCP         = 1 << 19;// No coprocessor usage fault. The processor does not support coprocessor instructions
            constexpr auto UNALIGNED    = 1 << 24;// Unaligned access usage fault
            constexpr auto DIVBYZERO    = 1 << 25;// Divide by zero usage fault

            // HFSR
            constexpr auto VECTTBL      = 1 << 1; // Vector table hard fault
            constexpr auto FORCED       = 1 << 30;// Forced hard fault
        }
    }

    namespace NVIC{
        constexpr auto NVIC             = 0xE000E100;

        namespace R{
            constexpr auto ISER         = 0x000;  // Interrupt set enable registers    - 3
            constexpr auto ICER         = 0x080;  // Interrupt clear enable registers  - 3
            constexpr auto ISPR         = 0x100;  // Interrupt set pending registers   - 3
            constexpr auto ICPR         = 0x180;  // Interrupt clear pending registers - 3
            constexpr auto IABR         = 0x200;  // Interrupt active bit registers    - 3

            constexpr auto IPR          = 0x300;  // Interrupt priority registers      - 21

            constexpr auto STIR         = 0xE00;  // Software trigger interrupt register
        }
    }

    namespace MPU{
        constexpr auto MPU              = 0xE000ED90;

        namespace R{
            constexpr auto TYPE         = 0x00;   // MPU Type register
            constexpr auto CTRL         = 0x04;   // MPU Control register
            constexpr auto RNR          = 0x08;   // MPU Region number register
            constexpr auto RBAR         = 0x0C;   // MPU Region base address register
            constexpr auto RASR         = 0x10;   // MPU Region attribute and size register
        }

        namespace B{
            // TYPE
            constexpr auto SEPARATE     = 1 << 0; // Indicates support for unified or separate instruction and data memory maps

            // CTRL
            constexpr auto ENABLE       = 1 << 0; // Enables the MPU
            constexpr auto HFNMIENA     = 1 << 1; // Enables the operation of MPU during HardFault and NMI handlers
            constexpr auto PRIVDEFENA   = 1 << 2; // Enable privileged software access to default memory map

            // RBAR
            constexpr auto VALID        = 1 << 4; // MPU region number valid bit

            // RASR
            constexpr auto ENABLE       = 1 << 0; // Region enable bit
            constexpr auto B            = 1 << 16;// Bufferable bit
            constexpr auto C            = 1 << 17;// Cacheable bit
            constexpr auto S            = 1 << 18;// Shareable bit
            constexpr auto XN           = 1 << 28;// Instruction access disable bit
        }
    }
}

#endif /* LET_DEVICE_CORTEXM3_HPP */
