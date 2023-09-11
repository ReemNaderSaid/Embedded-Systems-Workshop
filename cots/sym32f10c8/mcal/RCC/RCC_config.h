/*****************************************************/
/************ Author: REEM NADER SAID*****************/
/************ Date: 30 Aug 2023***********************/
/************ Version: 0.1****************************/
/************ File Name: RCC_config.h *****************/
/*****************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK            RCC_HSE


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_
                                
#endif /**< RCC_SYSCLK */

/** @} */ // end of RCC_System_Clock_Config

/***<Choose RCC_HSE or  RCC_HSI 
to be the source of the PLL*/
#define RCC_PLLCHOICE        RCC_HSE
/***<Choose  RCC_NOTDIV or  RCC_DIV
to know if the HSE of the PLL is divided by two or not*/
#define RCC_PLLHSE_DIVIDOR    RCC_NOTDIV
/***< chooose  RCC_PLLMUL_X2   : to mulitply PLL by 2  
               RCC_PLLMUL_X3   : to mulitply PLL by 3
               RCC_PLLMUL_X4   : to mulitply PLL by 4
               RCC_PLLMUL_X5   : to mulitply PLL by 5
               RCC_PLLMUL_X6   : to mulitply PLL by 6 
               RCC_PLLMUL_X7   : to mulitply PLL by 7 
               RCC_PLLMUL_X8   : to mulitply PLL by 8
               RCC_PLLMUL_X9   : to mulitply PLL by 9
               RCC_PLLMUL_X10  : to mulitply PLL by 10 
               RCC_PLLMUL_X11  : to mulitply PLL by 11 
               RCC_PLLMUL_X12  : to mulitply PLL by 12 
               RCC_PLLMUL_X13  : to mulitply PLL by 13 
               RCC_PLLMUL_X14  : to mulitply PLL by 14 
               RCC_PLLMUL_X15  : to mulitply PLL by 15 
               RCC_PLLMUL_X16  : to mulitply PLL by 16 
               RCC_PLLMUL2_X16 : to mulitply PLL by 16 */
#define RCC_DVIDOR            RCC_PLLMUL_X2       

                                
#endif /**< RCC_CONFIG_H_ */