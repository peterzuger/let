/**
 * @file   device/STM32/STM32L476xx.hpp
 * @author Peter Zueger
 * @date   12.08.2018
 * @brief  STM32L476 register offsets
 */
#ifndef __STM32L476XX_HPP__
#define __STM32L476XX_HPP__

namespace let{
    namespace GPIO{
        constexpr auto GPIOA            = 0x48000000;
        constexpr auto GPIOB            = 0x48000400;
        constexpr auto GPIOC            = 0x48000800;
        constexpr auto GPIOD            = 0x48000C00;
        constexpr auto GPIOE            = 0x48001000;
        constexpr auto GPIOF            = 0x48001400;
        constexpr auto GPIOG            = 0x48001800;
        constexpr auto GPIOH            = 0x48001C00;

        namespace R{
            constexpr auto MODER        = 0x00;   // Port mode register
            constexpr auto OTYPER       = 0x04;   // Port output type register
            constexpr auto OSPEEDR      = 0x08;   // Port output speed register
            constexpr auto PUPDR        = 0x0C;   // Port pull-up/pull-down register
            constexpr auto IDR          = 0x10;   // Port input data register
            constexpr auto ODR          = 0x14;   // Port output data register
            constexpr auto BSRR         = 0x18;   // Port bit set/reset register
            constexpr auto LCKR         = 0x1C;   // Port configuration lock register
            constexpr auto AFRL         = 0x20;   // Alternate function low register
            constexpr auto AFRH         = 0x24;   // Alternate function high register
            constexpr auto BRR          = 0x28;   // Port bit reset register
            constexpr auto ASCR         = 0x2C;   // Port analog switch control register
        }

        namespace B{
            // LCKR
            constexpr auto LCKK         = 1 << 16;// Lock key
        }
    }

    namespace RCC{
        constexpr auto RCC              = 0x40021000;

        namespace R{
            constexpr auto CR           = 0x00;   //
            constexpr auto ICSCR        = 0x04;   //
            constexpr auto CFGR         = 0x08;   //
            constexpr auto PLLCFGR      = 0x0C;   //
            constexpr auto PLLSAI1CFGR  = 0x10;   //
            constexpr auto PLLSAI2CFGR  = 0x14;   //
            constexpr auto CIER         = 0x18;   //
            constexpr auto CIFR         = 0x1C;   //
            constexpr auto CICR         = 0x20;   //
            constexpr auto AHB1RSTR     = 0x28;   //
            constexpr auto AHB2RSTR     = 0x2C;   //
            constexpr auto AHB3RSTR     = 0x30;   //
            constexpr auto APB1RSTR1    = 0x38;   //
            constexpr auto APB1RSTR2    = 0x3C;   //
            constexpr auto APB2RSTR     = 0x40;   //
            constexpr auto AHB1ENR      = 0x48;   //
            constexpr auto AHB2ENR      = 0x4C;   //
            constexpr auto AHB3ENR      = 0x50;   //
            constexpr auto APB1ENR1     = 0x58;   //
            constexpr auto APB1ENR2     = 0x5C;   //
            constexpr auto APB2ENR      = 0x60;   //
            constexpr auto AHB1SMENR    = 0x68;   //
            constexpr auto AHB2SMENR    = 0x6C;   //
            constexpr auto AHB3SMENR    = 0x70;   //
            constexpr auto APB1SMENR1   = 0x78;   //
            constexpr auto APB1SMENR2   = 0x7C;   //
            constexpr auto APB2SMENR    = 0x80;   //
            constexpr auto CCIPR        = 0x88;   //
            constexpr auto BDCR         = 0x90;   //
            constexpr auto CSR          = 0x94;   //
            // constexpr auto CRRCR        = 0x98;
            // constexpr auto CCIPR2       = 0x9C;
        }

        namespace B{

        }
    }

    namespace RNG{
        constexpr auto RNG              = 0x50060800;

        namespace R{
            constexpr auto CR           = 0x00;   // Control register
            constexpr auto SR           = 0x04;   // Status register
            constexpr auto DR           = 0x08;   // Data register
        }

        namespace B{
            // CR
            constexpr auto IE           = 1 << 3; // Interrupt enable
            constexpr auto RNGEN        = 1 << 2; // True random number generator enable

            // SR
            constexpr auto SEIS         = 1 << 6; // Seed error interrupt status
            constexpr auto CEIS         = 1 << 5; // Clock error interrupt status
            constexpr auto SECS         = 1 << 2; // Seed error current status
            constexpr auto CECS         = 1 << 1; // Clock error current status
            constexpr auto DRDY         = 1 << 0; // Data ready
        }
    }

    namespace USART{
        constexpr auto USART1           = 0x40013800;
        constexpr auto USART2           = 0x40004400;
        constexpr auto USART3           = 0x40004800;

        namespace R{
            constexpr auto CR1          = 0x00;   // Control register 1
            constexpr auto CR2          = 0x04;   // Control register 2
            constexpr auto CR3          = 0x08;   // Control register 3
            constexpr auto BRR          = 0x0C;   // Baud rate register
            constexpr auto GTPR         = 0x10;   // Guard time and prescaler register
            constexpr auto RTOR         = 0x14;   // Receiver timeout register
            constexpr auto RQR          = 0x18;   // Request register
            constexpr auto ISR          = 0x1C;   // Interrupt and status register
            constexpr auto ICR          = 0x20;   // Interrupt flag clear register
            constexpr auto RDR          = 0x24;   // Receive data register
            constexpr auto TDR          = 0x28;   // Transmit data register
        }

        namespace B{
            // CR1
            constexpr auto EOBIE        = 1 << 27;// End of block interrupt enable
            constexpr auto RTOIE        = 1 << 26;// Receiver timeout interrupt enable
            constexpr auto OVER8        = 1 << 15;// Oversampling mode
            constexpr auto CMIE         = 1 << 14;// Character match interrupt enable
            constexpr auto MME          = 1 << 13;// Mute mode enable
            constexpr auto WAKE         = 1 << 11;// Receiver wakeup method
            constexpr auto PCE          = 1 << 10;// Parity control enable
            constexpr auto PS           = 1 << 9; // Parity selection
            constexpr auto PEIE         = 1 << 8; // PE interrupt enable
            constexpr auto TXEIE        = 1 << 7; // TXE interrupt enable
            constexpr auto TCIE         = 1 << 6; // Transmission complete interrupt enable
            constexpr auto RXNEIE       = 1 << 5; // RXNE interrupt enable
            constexpr auto IDLEIE       = 1 << 4; // IDLE interrupt enable
            constexpr auto TE           = 1 << 3; // Transmitter enable
            constexpr auto RE           = 1 << 2; // Receiver enable
            constexpr auto UESM         = 1 << 1; // USART enable in Stop mode
            constexpr auto UE           = 1 << 0; // USART enable

            // CR2
            constexpr auto RTOEN        = 1 << 23;// Receiver timeout enable
            constexpr auto ABREN        = 1 << 20;// Auto baud rate enable
            constexpr auto MSBFIRST     = 1 << 19;// Most significant bit first
            constexpr auto DATAINV      = 1 << 18;// Binary data inversion
            constexpr auto TXINV        = 1 << 17;// TX pin active level conversion
            constexpr auto RXINV        = 1 << 16;// RX pin active level conversion
            constexpr auto SWAP         = 1 << 15;// Swap TX/RX pins
            constexpr auto LINEN        = 1 << 14;// LIN mode enable
            constexpr auto CLKEN        = 1 << 11;// Clock enable
            constexpr auto CPOL         = 1 << 10;// Clock polarity
            constexpr auto CPHA         = 1 << 9; // Clock phase
            constexpr auto LBCL         = 1 << 8; // Last bit clock pulse
            constexpr auto LBDIE        = 1 << 6; // LIN break detection interrupt enable
            constexpr auto LBDL         = 1 << 5; // LIN break detection length
            constexpr auto ADDM7        = 1 << 4; // 7-bit Adress Detection/4-bit Adress Detection

            // CR3
            constexpr auto TCBGTIE      = 1 << 24;// Transmission complete before guard time interrupt enable
            constexpr auto UCESM        = 1 << 23;// USART Clock Enable in Stop mode
            constexpr auto WUFIE        = 1 << 22;// Wakeup from Stop mode interrupt enable
            constexpr auto DEP          = 1 << 15;// Driver enable polartity selection
            constexpr auto DEM          = 1 << 14;// Driver enable mode
            constexpr auto DDRE         = 1 << 13;// DMA Disable on Reception Error
            constexpr auto OVRDIS       = 1 << 12;// Overrun Disable
            constexpr auto ONEBIT       = 1 << 11;// One sample bit method enable
            constexpr auto CTSIE        = 1 << 10;// CTS interrupt enable
            constexpr auto CTSE         = 1 << 9; // CTS enable
            constexpr auto RTSE         = 1 << 8; // RTS enable
            constexpr auto DMAT         = 1 << 7; // DMA enable transmitter
            constexpr auto DMAR         = 1 << 6; // DMA enable receiver
            constexpr auto SCEN         = 1 << 5; // Smartcard mode enable
            constexpr auto NACK         = 1 << 4; // Smartcard NACK enable
            constexpr auto HDSEL        = 1 << 3; // Half-duplex selection
            constexpr auto IRLP         = 1 << 2; // IrDA low power
            constexpr auto IREN         = 1 << 1; // IrDA mode enable
            constexpr auto EIE          = 1 << 0; // Error interrupt enable

            // RQR
            constexpr auto TXFRQ        = 1 << 4; // Transmit data flush request
            constexpr auto RXFRQ        = 1 << 3; // Receive data flush request
            constexpr auto MMRQ         = 1 << 2; // Mute mode request
            constexpr auto SBKRQ        = 1 << 1; // Send break request
            constexpr auto ABRRQ        = 1 << 0; // Auto baud rate request

            // ISR
            constexpr auto TCBGT        = 1 << 25;// Transmission complete before guard time completion
            constexpr auto REACK        = 1 << 22;// Receive enable acknowledge flag
            constexpr auto TEACK        = 1 << 21;// Transmit enable acknowledge flag
            constexpr auto WUF          = 1 << 20;// Wakeup from Stop mode flag
            constexpr auto RWU          = 1 << 19;// Receiver wakeup from mute mode
            constexpr auto SBKF         = 1 << 18;// Send break flag
            constexpr auto CMF          = 1 << 17;// Character match flag
            constexpr auto BUSY         = 1 << 16;// Busy flag
            constexpr auto ABRF         = 1 << 15;// Auto baud rate flag
            constexpr auto ABRE         = 1 << 14;// Auto baud rate error
            constexpr auto EOBF         = 1 << 12;// End of block flag
            constexpr auto RTOF         = 1 << 11;// Receiver timeout
            constexpr auto CTS          = 1 << 10;// CTS flag
            constexpr auto CTSIF        = 1 << 9; // CTS interrupt flag
            constexpr auto LBDF         = 1 << 8; // LIN break detection flag
            constexpr auto TXE          = 1 << 7; // Transmit data register empty
            constexpr auto TC           = 1 << 6; // Transmission complete
            constexpr auto RXNE         = 1 << 5; // Read data register not empty
            constexpr auto IDLE         = 1 << 4; // Idle line detected
            constexpr auto ORE          = 1 << 3; // Overrun error
            constexpr auto NF           = 1 << 2; // START bit Noise detection flag
            constexpr auto FE           = 1 << 1; // Framing error
            constexpr auto PE           = 1 << 0; // Parity error

            // ICR
            constexpr auto WUCF         = 1 << 20;// Wakeup from Stop mode clear flag
            constexpr auto CMCF         = 1 << 17;// Character match clear flag
            constexpr auto EOBCF        = 1 << 12;// End of block clear flag
            constexpr auto RTOCF        = 1 << 11;// Receiver timeout clear flag
            constexpr auto CTSCF        = 1 << 9; // CTS clear flag
            constexpr auto LBDCF        = 1 << 8; // LIN break detection clear flag
            constexpr auto TCBGTCF      = 1 << 7; // Transmission complete before guard time clear flag
            constexpr auto TCCF         = 1 << 6; // Transmission complete clear flag
            constexpr auto IDLECF       = 1 << 4; // Idle line detected clear flag
            constexpr auto ORECF        = 1 << 3; // Overrun error clear flag
            constexpr auto NCF          = 1 << 2; // Noise detected flag
            constexpr auto FECF         = 1 << 1; // Framing error clear flag
            constexpr auto PECF         = 1 << 0; // Parity error clear flag
        }
    }
}

#endif /* __STM32L476XX_HPP__ */
