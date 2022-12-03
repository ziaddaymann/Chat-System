 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.h
 *
 * Description: Header file for intialize UART.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/ 


#ifndef UART_H
#define UART_H

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "StandardTypes.h"
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm_registers.h"
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h" 
#include "driverlib/pin_map.h"

/*********************** extern Variables **************************/

extern uint8 buffer[200];  // buffer to store the charchters with max limit 200
extern uint8 index ;       // index for buffer array
extern uint8 c;




/*******************************************************************************
 *                      Function Prototypes                                    *
*******************************************************************************/


/************************************************************************************
* Name: UART0Init
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Function to Initialize UART0 
************************************************************************************/
void UART0Init(void);

/************************************************************************************
* Name: printByte
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Function to print charchters in putty
************************************************************************************/
void printByte (uint8 data);


/************************************************************************************
* Name: print
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Function to print String in putty
************************************************************************************/
void print(uint8 *s);






#endif
