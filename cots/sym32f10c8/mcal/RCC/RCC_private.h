/*****************************************************/
/************ Author: REEM NADER SAID*****************/
/************ Date: 30 Aug 2023***********************/
/************ Version: 0.1****************************/
/************ File Name: RCC_private.h *****************/
/*****************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR                  (*((volatile u32 *)0x40021000))

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR                (*((volatile u32 *)0x40021004))

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR                 (*((volatile u32 *)0x40021008))

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR            (*((volatile u32 *)0x4002100C))

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR            (*((volatile u32 *)0x40021010))

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR              (*((volatile u32 *)0x40021014))

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB1ENR             (*((volatile u32 *)0x4002101C))

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB2ENR             (*((volatile u32 *)0x40021018))

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR                (*((volatile u32 *)0x40021020))

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR                 (*((volatile u32 *)0x40021024))

/** @} */ // end of RCC Control Register (CR)

/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */

#define RCC_CR_HSION        0   /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY       1   /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL       8   /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON        16  /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY       17  /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP       18  /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE       19  /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON        24  /**< Clock Security System Enable */
#define RCC_CR_PLLON        24  /**< PLL Enable */
#define RCC_CR_PLLRDY       25  /**< PLL Ready */

/** @} */ // end of RCC_CR_Bit_Definitions

#define RCC_CFGR_PLLSRC     16

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI             0   /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE             1   /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL             2   /**< Phase-Locked Loop Clock Source (PLL) */

#define RCC_NOTDIV          0
#define RCC_DIV             1

#define Freq_Limit          72000000 /**< The limit for the PLL input frequency */

/** @} */ // end of RCC_Clock_Source

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_    0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_         1   /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type

/**<user input for multiplication factor of PLL input*/
#define RCC_PLLMUL_X2       0        
#define RCC_PLLMUL_X3       1
#define RCC_PLLMUL_X4       2
#define RCC_PLLMUL_X5       3
#define RCC_PLLMUL_X6       4
#define RCC_PLLMUL_X7       5
#define RCC_PLLMUL_X8       6
#define RCC_PLLMUL_X9       7
#define RCC_PLLMUL_X10      8
#define RCC_PLLMUL_X11      9
#define RCC_PLLMUL_X12      10
#define RCC_PLLMUL_X13      11
#define RCC_PLLMUL_X14      12
#define RCC_PLLMUL_X15      13
#define RCC_PLLMUL_X16      14
#define RCC_PLLMUL2_X16     15

#define RCC_PLLMUL_1        0000        /**< PLL input clock x 2*/
#define RCC_PLLMUL_2        0001        /**< PLL input clock x 3*/
#define RCC_PLLMUL_3        0010        /**< PLL input clock x 4*/
#define RCC_PLLMUL_4        0011        /**< PLL input clock x 5*/
#define RCC_PLLMUL_5        0100        /**< PLL input clock x 6*/
#define RCC_PLLMUL_6        0101        /**< PLL input clock x 7*/
#define RCC_PLLMUL_7        0110        /**< PLL input clock x 8*/
#define RCC_PLLMUL_8        0111        /**< PLL input clock x 9*/
#define RCC_PLLMUL_9        1000        /**< PLL input clock x 10*/
#define RCC_PLLMUL_10       1001        /**< PLL input clock x 11*/
#define RCC_PLLMUL_11       1010        /**< PLL input clock x 12*/
#define RCC_PLLMUL_12       1011        /**< PLL input clock x 13*/
#define RCC_PLLMUL_13       1100        /**< PLL input clock x 14*/
#define RCC_PLLMUL_14       1101        /**< PLL input clock x 15*/
#define RCC_PLLMUL_15       1110        /**< PLL input clock x 16*/
#define RCC_PLLMUL_16       1111        /**< PLL input clock x 16*/

#endif /* RCC_PRIVATE_H_ */