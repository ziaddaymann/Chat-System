 /******************************************************************************
 *
 * Module: Reception State
 *
 * File Name: ReceptionState.h
 *
 * Description: Header file for receiving data from can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#ifndef RECEPTIONSTATE_H
#define RECEPTIONSTATE_H


#include "StandardTypes.h"
extern uint8 state_flag;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Reception State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for changing the current state machine to Reception State
************************************************************************************/
void ReceptionState(void);


#endif