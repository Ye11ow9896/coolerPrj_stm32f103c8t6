#ifndef CODE_INC_PIDREGULATOR_H_
#define CODE_INC_PIDREGULATOR_H_
/*********************************Includes*********************************/

#include "stm32f1xx.h"
#include "main.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/********************************Prototypes********************************/

float PID_Regulation(float coefP,
					 float coefI,
					 float coefD,
					 float currValue,
					 float reqValue);

/******************************END Prototypes******************************/


#endif /* CODE_INC_PIDREGULATOR_H_ */
