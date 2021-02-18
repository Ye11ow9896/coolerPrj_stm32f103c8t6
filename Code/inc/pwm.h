#ifndef CODE_INC_PWM_H_
#define CODE_INC_PWM_H_
/*********************************Includes*********************************/

#include "stm32f1xx.h"
#include "main.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/********************************Prototypes********************************/

void InitPWM(void);
void SetFillFactorPWM(int ValCCR2);

/******************************END Prototypes******************************/
#endif /* CODE_INC_PWM_H_ */
