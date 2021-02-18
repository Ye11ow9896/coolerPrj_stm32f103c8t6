/**
 *  PID regulator. Description:
 *  	Function PID_Regulation conteins a transfer function for
 *  	calculating fan speed depending on temperature. You must
 *  	specify the following values ​​as arguments to the function:
 *
 *  	- coefP (proportional factor)
 *  	- coefI (constant of integration)
 *      - coefD (differentiation constant)
 *      - currValue (current value from sensor (callback))
 *      - reqValue (required value)
 * /

/*********************************Includes*********************************/

#include "pidRegulator.h"

/*******************************END Includes*******************************/
/*========================================================================*/
/*********************************Variables********************************/

	volatile float lastError;									// Last error
	volatile float error; 										// Curr error

	volatile float Int;											// Value of float type for storage
	volatile float calcInt;										// calculations
	volatile float calcDif;
	volatile float PID;

/*******************************END Variables******************************/
/*========================================================================*/
/********************************Functions*********************************/

float PID_Regulation(float coefP, float coefI, float coefD, float currValue, float reqValue)
{

	lastError = error;
	error = currValue - reqValue;								// Calculate curr error
	Int = Int + (error + lastError)/2; 							// Integral
	calcInt = Int*(1/coefI); 									// Calculate integral

	calcDif = coefD*(error-lastError); 							// Calculate deffirincial

	return PID = (coefP * error + calcInt + calcDif);			// Output PID value

}

/******************************END Functions********************************/
/*=========================================================================*/
/********************************Interrupts*********************************/



/******************************END Interrupts*******************************/
