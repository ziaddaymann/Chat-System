 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.c
 *
 * Description: Source file for intialize UART.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/ 


#include "UART.h"


/**************************** Variables ***************************************/
uint8 index = 0 ; 
uint8 buffer[200]={0};
uint8 c;

/************************************************************************************
* Name: print
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Function to print charchters in putty
************************************************************************************/

void print(uint8 *s)
{
  while(*s != '\0')
  {
      UARTCharPut(UART0_BASE,*s);
      s++;
  }
}

/************************************************************************************
* Name: printByte
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Function to print charchters in putty
************************************************************************************/
void printByte (uint8 data)
{
  UARTCharPut(UART0_BASE,data);
}

/************************************************************************************
* Name: UART0Init
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Function to Initialize UART0 
************************************************************************************/
void UART0Init()
{
   SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
   while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)){}  
   SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
   while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){}  
   UARTClockSourceSet(UART0_BASE,UART_CLOCK_SYSTEM);                       
   GPIOPinConfigure(GPIO_PA0_U0RX);                                               
   GPIOPinConfigure(GPIO_PA1_U0TX);                                            
   GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);  
   IntMasterEnable();
   UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
   UARTIntEnable(UART0_BASE,UART_INT_RX);
   UARTDisable(UART0_BASE);   
}

     
            