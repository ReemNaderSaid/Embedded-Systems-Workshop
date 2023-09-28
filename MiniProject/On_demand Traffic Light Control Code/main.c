/****************************************************************/
/******* Author    : REEM NADER SAID            *****************/
/******* Date      : 25 Sep 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : main.c                     *****************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "C:\Users\H&M\Desktop\COTS\MCAL\SYSTICK\SYSTICK_interface.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SCB_interface.h"
#include "LED_interface.h"

volatile u32 Button_H_or_L;
int main(void)
{
	/**< Init SysCLK */
	MCAL_RCC_InitSysClock();
	/**< Enable Peripheral */
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPBEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2, RCC_APB2ENR_AFIOEN);
	
 // HAL_LED_Init(LED_PORTA,LED_PIN3);
	//HAL_LED_Init(LED_PORTA,LED_PIN4);
	//HAL_LED_Init(LED_PORTA,LED_PIN5);
	//HAL_LED_Init(LED_PORTB,LED_PIN1);
	//HAL_LED_Init(LED_PORTB,LED_PIN2);
	//HAL_LED_Init(LED_PORTB,LED_PIN3);
	
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN2, GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN3, GPIO_OUTPUT_PUSH_PULL_2MHZ);
  EXTI_Init();
	MCAL_GPIO_SetPinMode(GPIO_PORTB, GPIO_PIN0,GPIO_INPUT_PULL_DOWN_MOD);
	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0,GPIO_LOW);
	
	//void EXTI_vInit(void);
  EXTI_EnableLine(EXTI_LINE0);
	//EXTI_InitForGPIO(EXTI_LINE0,EXTI_PORTMAP_GPIOB);
	EXTI_SetTrigger(EXTI_LINE0,EXTI_RISING_EDGE);
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	MCAL_NVIC_vSetPriority(NVIC_EXTI0_IRQn,0,0);
	MCAL_AFIO_SetEXTIConfiguration(EXTI_LINE0,AFIO_PORTB);
	//MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	   __enable_irq();
	 
	 while(1)
	 {
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_HIGH);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
	    //MCAL_STK_SetDelay_ms(10000);
		  //MCAL_STK_Reset();
		 for(int b=0;b<=10000;b++);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	   // MCAL_STK_SetDelay_ms(5000);
		 // MCAL_STK_Reset();
		 for(int q=0;q<=10000;q++);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
	    //MCAL_STK_SetDelay_ms(10000);
		  //MCAL_STK_Reset();
		 for(int s=0;s<=10000;s++);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	    //MCAL_STK_SetDelay_ms(5000);
		 // MCAL_STK_Reset();
		 for(int d=0;d<=10000;d++);
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
	    MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
	 }
			
}
void EXTI0_IRQHandler(void)
{ MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN5,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN5,GPIO_HIGH);
	int i;
  for( i=0; i<=5000;i++);
	//u8 Button_H_or_L;
	MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN0,&Button_H_or_L);
	if(Button_H_or_L==GPIO_LOW)
	{
		u8 Green_Pin_Car;
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN5,&Green_Pin_Car);
		u8 Yellow_Pin_Car;
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN4,&Yellow_Pin_Car);
		if(Green_Pin_Car==GPIO_HIGH)
		{
		  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN5,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			for(i=0;i<=25;i++)
			{
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
			 MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
				for(int t=0;t<=1000;t++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
				for(int n=0;n<1000;n++);}
			
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
				for(i=0;i<=10000;i++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
				//EXTI_EXIT_IRQHandler(EXTI_LINE0);
		MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN5,GPIO_LOW);		
		MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);}
		else if (Yellow_Pin_Car==GPIO_HIGH)
		{
		   for(i=0;i<=25;i++)
			{
			 MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
			 MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
				for(int y=0;y<=1000;y++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
				for(int m=0;m<1000;m++);
			}
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN4,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
				for(i=0;i<=10000;i++);
				MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
				MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
			//	EXTI_EXIT_IRQHandler(EXTI_LINE0);
				MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN5,GPIO_LOW);	
		MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);}
		else
			//EXTI_EXIT_IRQHandler(EXTI_LINE0);
		 MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN5,GPIO_LOW);	
		MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
	}
	  else
			//EXTI_EXIT_IRQHandler(EXTI_LINE0);
		 MCAL_GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN5,GPIO_LOW);	
		MCAL_NVIC_ClearPendingIRQ(NVIC_EXTI0_IRQn);
		
}
