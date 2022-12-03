 /******************************************************************************
 *
 * Module: DataTransmission State
 *
 * File Name: DataTransmission_State.c
 *
 * Description: Source file for DataTransmission State to Transmit data with can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/
#include "DataTransmission_State.h"
#include "tm4c123gh6pm_registers.h"
#include "can.h"
#include "UART.h"



extern uint8 state_flag;

/************************************************************************************
* Service Name: DataTransmission_State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: responsible for changing the current state machine to Data Transmission State
************************************************************************************/
void DataTransmission_State ()
{
   uint8 i,j;
   UARTDisable(UART0_BASE);  
   state_flag = TWO;
   GREEN_ON();
   encrypt (buffer,index);
   cantransmit(buffer,index);

   for(uint8 i=0;i<index;i++)
    {
      buffer[i]=0;
    }
   index=0;
   IdealState();
}  