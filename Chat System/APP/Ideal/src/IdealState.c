/******************************************************************************
 *
 * Module: IDEAL State
 *
 * File Name: IdealState.c
 *
 * Description: Source file for Ideal Leds .
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/


#include "IdealState.h"
#include "tm4c123gh6pm_registers.h"
#include "UART.h"
uint8 state_flag;

/************************************************************************************
* Service Name: IdealState
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for changing the current state machine to Ideal State
************************************************************************************/
void IdealState(void)
{
  state_flag = ZERO;
  UARTDisable(UART0_BASE);   
  BLUE_ON();
}