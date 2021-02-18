#ifndef CODE_INC_USART_H_
#define CODE_INC_USART_H_
/*********************************Includes*********************************/

#include "stm32f1xx.h"
#include "main.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/********************************Prototypes********************************/

void InitUSART_1(void);
void TransmitUSART_1(char chr);
void SendStringUSART_1(char* str);

/******************************END Prototypes******************************/
#endif /* CODE_INC_USART_H_ */
