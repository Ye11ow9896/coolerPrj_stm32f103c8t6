#ifndef CODE_INC_ADC_H_
#define CODE_INC_ADC_H_
/*********************************Includes*********************************/

#include "stm32f1xx.h"
#include "main.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/********************************Prototypes********************************/

void InitADC_1(void);
float GetValueADC(uint8_t numberOfSample);

/******************************END Prototypes******************************/
#endif /* CODE_INC_ADC_H_ */
