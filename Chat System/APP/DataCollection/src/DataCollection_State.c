 /******************************************************************************
 *
 * Module: DataCollection_State
 *
 * File Name: DataCollection_State.c
 *
 * Description: Source file for DataCollection State to collect data from uart
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#include "DataCollection_State.h"
#include "tm4c123gh6pm_registers.h"
#include "UART.h"

extern uint8 state_flag;

/************************************************************************************
* Service Name: DataCOllection_State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: responsible for changing the current state machine to Data Collection State
************************************************************************************/
void DataCollection_State ()
{
    GREEN_ON();
    state_flag = ONE;
    UARTEnable(UART0_BASE);
    UARTFIFODisable(UART0_BASE);
    print("\n\r");
    print("Message Sent from Tiva-2 : ");
    
}