/**
 * USART Setting:
 *
 *  - Use USART1
 *  - Speed is 9600 baud
 *  - TX PA9
 *  - RX PA10
 *
 * */
/*********************************Includes*********************************/

#include "usart.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/*********************************Variables********************************/



/*******************************END Variables******************************/
/*========================================================================*/
/********************************Functions*********************************/

void InitUSART_1(void)
{

		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;					// Clock UART is enable
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;						// Clock port A is enable
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;						// Alternative funct clock is enable

		/*Setting PIN9 PORTA - TX*/
		GPIOA->CRH &= ~GPIO_CRH_CNF9;							// Clear bits
		GPIOA->CRH &= ~GPIO_CRH_MODE9;						// Clear bits
		GPIOA->CRH |= GPIO_CRH_MODE9_0 							// Output mode, 10 MHz.
				   |  GPIO_CRH_CNF9_1;							// Setting AF Push-Pull output (TX)

		/*Setting PIN10 PORTA - RX*/
		GPIOA->CRH &= ~GPIO_CRH_CNF10;							// Clear bits
		GPIOA->CRH &= ~GPIO_CRH_MODE10;						// Clear bits also use mode Input
		GPIOA->CRH |=  GPIO_CRH_CNF10_1;						// Setting Push-Up input (RX)
		GPIOA->BSRR |= GPIO_ODR_ODR10;

		USART1->BRR = 0x1D4D;									//Speed is 9600 baud

		USART1->CR1 |= USART_CR1_TE 							// Transmitter enable
					|  USART_CR1_RE 							// Receiver enable
					|  USART_CR1_UE 							// USART1 enable
					|  USART_CR1_RXNEIE;						// Interrupt for receive enable

		NVIC_EnableIRQ(USART1_IRQn);							// Enable a device specific interrupt in the NVIC interrupt controller.

}

void TransmitUSART_1(char chr)
{

	while (!(USART1->SR & USART_SR_TC));						// Wait for transmission copleting
	USART1->DR = chr;											// Transfer data to DR (data registr)

}

void SendStringUSART_1(char* str)
{
	uint8_t i = 0;

	while(str[i])
		TransmitUSART_1(str[i++]);
}

/******************************END Functions********************************/
/*=========================================================================*/
/********************************Interrupts*********************************/



/******************************END Interrupts*******************************/

