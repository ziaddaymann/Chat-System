 /******************************************************************************
 *
 * Module: DataCollection_State
 *
 * File Name: DataCollection_State.h
 *
 * Description: Header file for DataCollection State to collect data from uart
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#ifndef DATACOLLECTION_STATE
#define DATACOLLECTION_STATE



#include "UART.h"
#include "StandardTypes.h"
#include "encryption.h"
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: DataCOllection_State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: responsible for changing the current state machine to Data Collection State
************************************************************************************/
void DataCollection_State ();


#endif