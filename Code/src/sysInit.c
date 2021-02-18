/*********************************Includes*********************************/
#include "sysInit.h"
/*******************************END Includes*******************************/
/*========================================================================*/
/********************************Functions**********************************/
void InitRCC(void)
{

	RCC->CR |= (uint32_t)RCC_CR_HSEON;						//source freq is HSE
	while(!(RCC->CR & RCC_CR_HSERDY));						//we wait for sourse freq change. Default - HSI, but we have activated HSE

	FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;		//clock flash memory

	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;						//AHB = SYSCLK/1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;						//APB1 = HCLK/1
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;                       //APB2 = HCLK/1

	RCC->CFGR &= ~RCC_CFGR_PLLMULL;	                        //CLEAR REGISTERS
	RCC->CFGR &= ~RCC_CFGR_PLLSRC;                          //CLEAR REGISTERS
	RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;                        //CLEAR REGISTERS

	RCC->CFGR |= RCC_CFGR_PLLSRC;							//Clock from PREDIV1 selected as PLL input clock
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE ;						//Config predivision
	RCC->CFGR |= RCC_CFGR_PLLMULL9;							//PLLx9. 8 MHz * 9 = 72 MHz

	RCC->CR |= RCC_CR_PLLON;								//PLL enable
	while((RCC->CR & RCC_CR_PLLRDY) == 0) {}				//we are waiting for PLL enable

	RCC->CFGR &= ~RCC_CFGR_SW;								//CLEAR_BIT SW bits
	RCC->CFGR |= RCC_CFGR_SW_PLL;							//select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {}	//wait till PLL is used

}

void InitGPIO(void)
{
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;						//enable clock for PORT C

		GPIOC->CRH &= ~GPIO_CRH_CNF13;
		GPIOC->CRH |=  GPIO_CRH_MODE13;
}

/******************************END Functions********************************/


