/*********************************Includes*********************************/

#include "main.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/*********************************Variables********************************/

volatile uint32_t msTick;

uint8_t tempArr[4];										// Array for send to USART

uint8_t reqTemp = 35;									// Variable for set required temperature for
														// PID_Regulation() func.
float ADCVal;
float VoltageVal;
float TempValue;



/*******************************END Variables******************************/
/*========================================================================*/
/********************************Prototypes********************************/

void delay_ms(uint32_t time_ms);
float GetVoltageFromSensor(uint8_t numberOfSample, float ValueADC);
float GetTemperatureFromSensor(uint8_t numberOfSample, float ValtageValue);

/******************************END Prototypes******************************/
/*========================================================================*/
/***********************************MAIN***********************************/

int main(void)
	{

/******************************Initialization******************************/

		SysTick_Config(SystemCoreClock/1000);			// Time between 2 interrupts = 1 ms
		InitRCC();										// SysClock - 72MHz
		InitGPIO();										// PC13 - internal LED
		InitUSART_1();
		InitPWM();
		InitADC_1();

/***************************END initialization*****************************/


		while(1)
		{
			uint16_t PidValue = 0;

			/*Get values from functions*/

			ADCVal =  GetValueADC(20);
			VoltageVal = GetVoltageFromSensor(20, ADCVal);
			TempValue = GetTemperatureFromSensor(5, VoltageVal);
			PidValue = PID_Regulation(100, 50, 50,
				GetTemperatureFromSensor(20, GetValueADC(20)), reqTemp);

			if(PidValue >= 300 && PidValue >= 5000)
				PidValue = PidValue/50;

			SetFillFactorPWM(PidValue);            		// Send formated PidValue to PWM

/***************************Send DATA to USART****************************/

						sprintf (tempArr , "%0.2f", TempValue);
						SendStringUSART_1("TMP result = ");
						SendStringUSART_1(tempArr);
						SendStringUSART_1("\r");

						sprintf (tempArr , "%0.2f", ADCVal);
						SendStringUSART_1("ADC result = ");
						SendStringUSART_1(tempArr);
						SendStringUSART_1("\r");

						sprintf (tempArr , "%0.2f", VoltageVal);
						SendStringUSART_1("Voltage result = ");
						SendStringUSART_1(tempArr);
						SendStringUSART_1("\r");
		}

	}

/*********************************END MAIN**********************************/
/*=========================================================================*/
/********************************Functions**********************************/

/**
 * Just delay in milli sec.
 **/

void delay_ms(uint32_t time_ms)
	{
		uint32_t i;

		i = msTick;
		while ((msTick - i) < time_ms);
	}
/***************************************************************************/
/*=========================================================================*/
/***************************************************************************/
/*
 * Function calculates and returns value of voltage from sensor.
 * About arguments of functions:
 *
 *  - numberOfSample. White number from 1 to 255. This will mean the number of samples to count.
 *  - ValueADC. You should to use function GetValueADC(). Where is you should to set
 *  numberOfSample also as argument in that function.
 *
 * */
float GetVoltageFromSensor(uint8_t numberOfSample, float ValueADC)
	{

		uint8_t couter = numberOfSample;

		float voltage = 0;
		float averageValueVoltage=0;

/******************Calculate arithmetic mean of voltage********************/

		voltage = (3.3*ValueADC)/4095;						// ADC = (Vin * 2^n)/Vref

		while(couter)
			{
				averageValueVoltage += voltage;
				couter--;
			}

		averageValueVoltage = averageValueVoltage/numberOfSample;

		return averageValueVoltage;
	}
/***************************************************************************/
/*=========================================================================*/
/***************************************************************************/
/*
 * Function calculates and returns value of temperature from sensor.
 * About arguments of functions:
 *
 *  - numberOfSample. White number from 1 to 255. This will mean the number of samples to count.
 *  - ValtageValue. You should to use function GetVoltageFromSensor(). Where is you should to set
 *  numberOfSample also as argument in that function.
 *
 * */
float GetTemperatureFromSensor(uint8_t numberOfSample, float ValtageValue)
	{

		uint8_t couter = numberOfSample;
		float temp = 0;
		float avarageTemp = 0;

		temp = ValtageValue / 0.03;							//	In manual 10mV/C, but chose an experimental number

/******************Calculate arithmetic mean of temperature*****************/
		while(couter)
			{
				avarageTemp += temp;
				couter--;
			}

		avarageTemp = avarageTemp/numberOfSample;
		return avarageTemp;

	}

/******************************END Functions********************************/
/*=========================================================================*/
/********************************Interrupts**********************************/
void SysTick_Handler(void)
{
	msTick++;
}

void USART1_IRQHandler (void){

	if (USART1->SR & USART_CR1_RXNEIE){

		USART1->SR &= ~USART_CR1_RXNEIE;

	}

}

/******************************END Interrupts********************************/
