/**
 * ADC Setting:
 *
 *  - Use ADC1
 *  - Freq 12 MHz
 *  - Used channel is 0
 *  - Trigger SWSTART
 *  - Pin for ADC is PA0
 *
 * /

/*********************************Includes*********************************/

#include "adc.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/*********************************Variables********************************/


/*******************************END Variables******************************/
/*========================================================================*/
/********************************Functions*********************************/

void InitADC_1(void)
	{

		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

		GPIOA->CRL &= ~GPIO_CRL_CNF0;
		GPIOA->CRL &= ~GPIO_CRL_MODE0;

		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
		RCC->APB2ENR |= RCC_CFGR_ADCPRE_DIV6;					// Prescalet 6. 72MHz/6 = 12MHz

		ADC1->CR2 |= ADC_CR2_CAL; 								// start calibration
		while (!(ADC1->CR2 & ADC_CR2_CAL));                		// waiting end calibration

		ADC1->CR2 |= ADC_CR2_ADON;     							// enable ADC
		ADC1->CR2 &= ~ADC_CR2_CONT;								// 0 - single conversion, 1 - continuous conversion
		ADC1->CR2 |= ADC_CR2_EXTSEL;      						// event start conversion SWSTART
		ADC1->CR2 |= ADC_CR2_EXTTRIG;                       	// enable start conversion external signal
		ADC1->SMPR1 |= ADC_SMPR1_SMP16; 						// sempling 239.5 cycle
		ADC1->SQR3 &= ~ADC_SQR3_SQ1;    						// selection channel 0

	}

float GetValueADC(uint8_t numberOfSample)
	{

		uint8_t couter = numberOfSample;
		float averageValueADC = 0;

		ADC1->CR2 |= ADC_CR2_SWSTART;							// ADC start
		while (!(ADC1->SR & ADC_SR_EOC));						// Wait for End Of Convertation

		while(couter)											// Calculate arithmetic mean
			{
				averageValueADC += (ADC1->DR);
				couter--;
			}
		averageValueADC = averageValueADC/numberOfSample;

		return averageValueADC;									// Return arithmetic mean

	}
/******************************END Functions********************************/
/*=========================================================================*/
/********************************Interrupts*********************************/



/******************************END Interrupts*******************************/
