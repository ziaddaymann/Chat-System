 /******************************************************************************
 *
 * Module: Reception State
 *
 * File Name: ReceptionState.c
 *
 * Description: Source file for receiving data from can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#include "ReceptionState.h"
#include "tm4c123gh6pm_registers.h"
#include "can.h"
#include "UART.h" 


extern uint8 state_flag;

/************************************************************************************
* Service Name: Reception State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for changing the current state machine to Reception State
************************************************************************************/
void ReceptionState(void)
{
  RED_ON();
  state_flag=THREE;
  canrecieve();
  if(counter>indexrecieve)
  {
    PresentingState();
    
  }
  
}