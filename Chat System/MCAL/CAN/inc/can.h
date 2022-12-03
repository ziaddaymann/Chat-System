 /******************************************************************************
 *
 * Module: can
 *
 * File Name: can.h
 *
 * Description: Header file to Initilaze can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/ 


#ifndef CAN
#define CAN

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom_map.h"

#define CAN0RXID                0
#define RXOBJECT                2
#define CAN0TXID                2
#define TXOBJECT                1

extern char arrayreceive[200];
extern uint8_t counter;
extern uint8_t indexrecieve;


/************************************************************************************\
* Name: Delay_MS
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Delay 1 MilliSecond
***********************************************************************************/
void Delay_ms(long milliseconds);

/************************************************************************************
* Name: CAN0IntHandler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
************************************************************************************/

void CAN0IntHandler(void);
/************************************************************************************
* Name: initcan
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
***********************************************************************************/
void initcan();

/************************************************************************************
* Name: canrecieve
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Recive data with can bus
************************************************************************************/
void canrecieve();

/************************************************************************************
* Name: cantransmit
* Reentrancy: reentrant
* Parameters (in):  pointer,index
* Return value: None
* Description:Transmit data with can bus
********************************************************************************/
void cantransmit(char *pointer,char index);

#endif