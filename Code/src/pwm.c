/**
 * PWM Setting:
 *
 * Default:
 *  - Prescaler value PMW is 72-1
 *  - Value to autoreload 1000
 *  - fill factor 300
 *
 *  USE PA1 for PWM input.
 *
 *  If you want to change freq PWM you should to use SettingPWM function,
 *  where is you should set an argument how you need.
 *
 * */
/*********************************Includes*********************************/

#include "pwm.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/*********************************Variables********************************/



/*******************************END Variables******************************/
/*========================================================================*/
/********************************Functions*********************************/

void InitPWM(void)
{

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN								// Port A clock enable
				 |  RCC_APB2ENR_AFIOEN;								// AF is enable
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;								// TIM2 click is enable

	//RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;								// APB1 prescaler is 2. 72MHz/2 = 36 MHz (is max clock for APB1)

	GPIOA->CRL &= ~GPIO_CRL_CNF1;									// Clear reg
	GPIOA->CRL &= ~GPIO_CRL_MODE1;

	GPIOA->CRL |= GPIO_CRL_CNF1_1									// PA1 AF mode
			   |  GPIO_CRL_MODE1;

	TIM2->PSC = 7200-1;												// Prescaler value
	TIM2->ARR = 100;												// Value to autoreload
	TIM2->CCR2 = 100;												// fill factor

	TIM1->BDTR |= TIM_BDTR_MOE;										//Main Output enable

	TIM2->CCMR1 |= TIM_CCMR1_OC2M_1									// PWM mode 1
			   |  TIM_CCMR1_OC2M_2;

	TIM2->CCER |= TIM_CCER_CC2E;									// Capture/Compare 2 output enable
	TIM2->CCER &= ~TIM_CCER_CC2P;									// Capture/Compare 2 output Polarity - disable
	TIM2->CR1 &= ~TIM_CR1_DIR;										// Count direction
	TIM2->CR1 |= TIM_CR1_CEN;										// Counter enable
}

void SetFillFactorPWM(int ValCCR2)
{

	TIM2->CCR2 = ValCCR2;											// fill factor

}
/******************************END Functions********************************/
/*=========================================================================*/
/********************************Interrupts*********************************/



/******************************END Interrupts*******************************/

