 /******************************************************************************
 *
 * Module: IDEAL State
 *
 * File Name: IdealState.h
 *
 * Description: Header file for Ideal Leds .
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#ifndef IDEALSTATE_H
#define IDEALSTATE_H

#include "StandardTypes.h"
extern uint8 state_flag;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: IdealState
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for changing the current state machine to Ideal State
************************************************************************************/
void IdealState(void);


#endif