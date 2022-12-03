 /******************************************************************************
 *
 * Module: Presenting State
 *
 * File Name: PresentingState.c
 *
 * Description: Source file for Presenting State to view data with uart on putty.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/
#include "PresentingState.h"
#include "tm4c123gh6pm_registers.h"
#include "can.h"
#include "UART.h"
#include "timer.h"  

extern uint8 state_flag;
extern uint8 indexrecieve;



/************************************************************************************
* Service Name: Presenting State
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Responsible for changing the current state machine to Presenting State
************************************************************************************/
void PresentingState(void)
{
  uint8 i,j,k;
  RED_ON();
  state_flag=FOUR;
  UARTEnable(UART0_BASE);
  UARTFIFODisable(UART0_BASE);
  
  print("\n\r");
  print("Message Recieved from Tiva-1 encrypted : ");
  print("\n\r");
  print("\n\r");
  print("\n\r");
  
  for (j=0;j<indexrecieve;j++)
  {
    if ((j%8 == 0) && (j != 0 ))
    {
      TIMER_Start(100);
      print("\n\r");
    }
     printByte (arrayreceive[j]);
    
  }
    
  decrypt(arrayreceive , indexrecieve );
  
  print("\n\r");
  print("\n\r");
  print("\n\r");
  print("\n\r");
  print("\n\r");
  print("Message Recieved from Tiva-1 decrypted : ");
  print("\n\r");
  print("\n\r");
  print("\n\r");
  
  for (k=0;k<indexrecieve;k++)
  {
    if ((k%8 == 0) && (k != 0 ))
    {
      TIMER_Start(100);
      print("\n\r");
    }
  printByte (arrayreceive[k]);
  
  }
  
  for(i=0;i<indexrecieve;i++)
     {
       arrayreceive[i]=0;
     }
  indexrecieve=0;
  IdealState();
  
  
}