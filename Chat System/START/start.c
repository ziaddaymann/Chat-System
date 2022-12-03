 /******************************************************************************
 *
 * Module: START
 *
 * File Name: start.h
 *
 * Description: Source file to start the app.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

/*******************************************************************************
 *                                  INCLUDES                                   *
 *******************************************************************************/

#include "tm4c123gh6pm_registers.h"
#include "States.h"
#include "StandardTypes.h"
#include "Common_Macros.h"
#include "button.h"
#include "can.h"
#include "timer.h"
#include "interrupt.h"
#include "PresentingState.h"



/************************************************************************************
* Name: RX_INT_Handler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
************************************************************************************/
void RX_INT_Handler()
{

while(UARTCharsAvail(UART0_BASE))
  {
 uint16 x = 0;

    if(index==200)
      {    
        print("\n\r");
        print(" Max. Message length is 200 Byte");
        DataTransmission_State();
       x=1;

      }
    
       c=UARTCharGet(UART0_BASE);  
       UARTCharPut(UART0_BASE,c);
       buffer[index]=c;
       index++; 
      
        if(x==1)
        {
          index=0;
        }
  }
} 

/************************************************************************************
* Service Name: buttoms_Handler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
************************************************************************************/
void Buttom_Handler(void)
{
  
  uint16 state=0;
  if(GPIO_PORTF_RIS_REG)
  {
   if(GPIO_PORTF_RIS_REG)
   {
   state = GPIO_PORTF_RIS_REG & 0x11 ;
   }
  }
 /*** If condition to check if button 1 is pressed and wait for interrupt to call the DataClloection which send data throw putty ***/
 if(state==0x01)
 {
  
  if(state_flag!=1)
  {
    DataCollection_State();
  }
  

  }
  
   /*** If condition to check if button 2 is pressed and wait for interrupt to send data throw can ***/

 if(state==0x10)
 { 
   if(state_flag==1)
   {
     DataTransmission_State();
   }
   
  }
   GPIO_PORTF_ICR_REG   |= (1<<0); 
   GPIO_PORTF_ICR_REG   |= (1<<4);
}

int main(void)
{ 
    Enable_Interrupts();
    UART0Init();
    initcan();
    GPIO_init();
    Buttom_Init();
    Led_Init();
    UARTIntRegister(UART0_BASE,RX_INT_Handler); 
 
    IdealState();
    
    while(1)
    { 
      Wait_For_Interrupt();

    }
}

