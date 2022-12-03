 /******************************************************************************
 *
 * Module: Presenting State
 *
 * File Name: PresentingState.h
 *
 * Description: Header file for Presenting State to view data with uart on putty.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#ifndef PRESENTINGSTATE_H
#define PRESENTINGSTATE_H

#include "StandardTypes.h"
#include "decryption.h"
#include "IdealState.h"

extern uint8 state_flag;

/*******************************************************************************
 *                      Function Prototypes                                    *
*******************************************************************************/

/************************************************************************************
* Service Name: Presenting State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for changing the current state machine to Presenting State
************************************************************************************/
void PresentingState(void);


#endif