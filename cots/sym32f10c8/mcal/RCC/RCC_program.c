/*****************************************************/
/************ Author: REEM NADER SAID*****************/
/************ Date: 30 Aug 2023***********************/
/************ Version: 0.1****************************/
/************ File Name: RCC_program.h *****************/
/*****************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType Mcal_Rcc_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE
        
        /**< Enable the external clock to be the source for the system clock. */
        #if RCC_CLK_BYPASS == RCC_RC_CLK_
            SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
            CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */
        #else 
            #error "Wrong Choice !!"
        #endif /**< RCC_CLK_BYPASS */

        /**< Enable the High-Speed External clock. */
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< Wait until the High-Speed External clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

        /**< Select High-Speed External clock as the system clock source. */
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        
        /**< Enable the High-Speed Internal clock. */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the High-Speed Internal clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

        /**< Select High-Speed Internal clock as the system clock source. */
        RCC_CFGR = 0x00000000;

        Local_FunctionStatus = E_OK;

/**< Enable the PLL clock to be the source for the system clock. */
    #elif RCC_SYSCLK == RCC_PLL

        #if RCC_PLLCHOICE == RCC_HSE /***< select HSE  as PLL input clock */
          SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);

            #if RCC_PLLHSE_DIVIDOR ==RCC_NOTDIV  /**< not divide HSE before PLL entry*/
             CLR_BIT(RCC_CFGR,RCC_CFGR_ PLLXTPRE); 
            #elif RCC_PLLHSE_DIVIDOR ==RCC_DIV   /**< divide HSE before PLL entry*/
              SET_BIT(RCC_CFGR,RCC_CFGR_ PLLXTPRE);
             
        #elif RCC_PLLCHOICE == RCC_CR_HSION   /***< select HSI /2  as PLL input clock */
         CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
    #else
           #error "Wrong Choice !!"
           #endif/**<RCC_PLLHSE_DIVIDOR*/
        #endif/**< RCC_PLLCHOICE*/ 
    /**< Enable the PLL clock. */
        SET_BIT(RCC_CR, RCC_CR_PLLON);

    /**< Wait until the PLL clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_ PLLRDY));

    /**< Select PLL clock as the system clock source. */
        RCC_CFGR = 0x00000010;
        Local_FunctionStatus = E_OK;

    #endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_MultiplicationFactor(u8 *Copy_Result)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
/**<If the PLL is disabled the multiplication operation will occur*/
  if(CLR_BIT(RCC_CR, RCC_CR_PLLON)) 
  {
    /***< multiply PLL input by a factor*/   
    #if RCC_DVIDOR==RCC_PLLMUL_X2
      *Copy_Result= SET_BIT(RCC_CFGR,RCC_PLLMUL_1)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X3
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_2)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X4
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_3)
        Local_FunctionStatus = E_OK;  
    #elif RCC_DVIDOR==RCC_PLLMUL_X5
      *Copy_Result= SET_BIT(RCC_CFGR,RCC_PLLMUL_4)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X6
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_5)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X7
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_6)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X8
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_7)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X9
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_8)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X10
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_9)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X11
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_10)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X12
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_11)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X13
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_12)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X14
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_13)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X15
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_14)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL_X16
      *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_15)
        Local_FunctionStatus = E_OK;
    #elif RCC_DVIDOR==RCC_PLLMUL2_X16
    *Copy_Result=SET_BIT(RCC_CFGR,RCC_PLLMUL_16)
        Local_FunctionStatus = E_OK;
    #endif/**< RCC_DVIDOR*/

/**< The PLL output frequency must not exceed 72 MHz*/
    #if *Copy_Result <= Freq_Limit   
        /**< Enable the PLL clock. */
        SET_BIT(RCC_CR, RCC_CR_PLLON);

    /**< Wait until the PLL clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_ PLLRDY));

    /**< Select PLL clock as the system clock source. */
        RCC_CFGR = 0x00000010;
        Local_FunctionStatus = E_OK;
    #endif /**<Freq_Limit*/}
else{
 #error "YOU MUST DISABLE THE PLL CLOCK FIRST!!"
}

return Local_FunctionStatus;}