 /******************************************************************************
 *
 * Module: DataTransmission State
 *
 * File Name: DataTransmission_State.h
 *
 * Description: Header file for DataTransmission State to Transmit data with can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#ifndef DATATRANSMISSION_STATE
#define DATATRANSMISSION_STATE

#include "StandardTypes.h"
#include "UART.h"


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


/************************************************************************************
* Service Name: DataTransmission_State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: responsible for changing the current state machine to Data Transmission State
************************************************************************************/
void DataTransmission_State ();

#endif