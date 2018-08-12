/**
 * @file   CoretexM0p.hpp
 * @author Peter Zueger
 * @date   11.08.2018
 * @brief  ARM Coretex M0+ device header
 */
#ifndef __CORETEXM0P_HPP__
#define __CORETEXM0P_HPP__

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
            constexpr auto VTOR         = 0x08;   // Vector Table Offset Register
            constexpr auto AIRCR        = 0x0C;   // Application interrupt and reset control register
            constexpr auto SCR          = 0x10;   // System control register
            constexpr auto CCR          = 0x14;   // Configuration and control register
            constexpr auto SHPR2        = 0x1C;   // System handler priority registers
            constexpr auto SHPR3        = 0x20;   // ""
        }

        namespace B{
            // ICSR
            constexpr auto RETOBASE     = 1 << 11;// Return to base level indicates if there are preempted active exceptions
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
            constexpr auto NONBASETHRDENA= 1 << 0;// not documented
            constexpr auto USERSETMPEND = 1 << 1; // not documented
            constexpr auto UNALIGN_TRP  = 1 << 3; // Always one -> all unaligned accesses generate a HardFault
            constexpr auto DIV_0_TRP    = 1 << 4; // not documented
            constexpr auto BFHFNMIGN    = 1 << 8; // not documented
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

#endif /* __CORETEXM0P_HPP__ */
