/**
 * @file   device/Family.hpp
 * @author Peter Zueger
 * @date   11.08.2018
 * @brief  Device Family Selection
 */
#ifndef LET_DEVICE_FAMILY_HPP
#define LET_DEVICE_FAMILY_HPP

#if defined(STM32L0)
# include "STM32/STM32L0.hpp" // Coretex-M0+
# include "CoretexM0p.hpp"
#elif defined(STM32L1)
# include "STM32/STM32L1.hpp" // Coretex-M3
# include "CoretexM3.hpp"
#elif defined(STM32L4)
# include "STM32/STM32L4.hpp" // Coretex-M4F
# include "CoretexM4F.hpp"
#elif defined(STM32F0)
# include "STM32/STM32F0.hpp" // Coretex-M0
# include "CoretexM0.hpp"
#elif defined(STM32F1)
# include "STM32/STM32F1.hpp" // Coretex-M3
# include "CoretexM3.hpp"
#elif defined(STM32F2)
# include "STM32/STM32F2.hpp" // Coretex-M3
# include "CoretexM3.hpp"
#elif defined(STM32F3)
# include "STM32/STM32F3.hpp" // Coretex-M4F
# include "CoretexM4F.hpp"
#elif defined(STM32F4)
# include "STM32/STM32F4.hpp" // Coretex-M4F
# include "CoretexM4F.hpp"
#elif defined(STM32F7)
# include "STM32/STM32F7.hpp" // Coretex-M7F
# include "CoretexM7F.hpp"
#elif defined(STM32H7)
# include "STM32/STM32H7.hpp" // Coretex-M7F
# include "CoretexM7F.hpp"
#else
# error Family not defined
#endif /* defined(STM32xx) */

#endif /* LET_DEVICE_FAMILY_HPP */
