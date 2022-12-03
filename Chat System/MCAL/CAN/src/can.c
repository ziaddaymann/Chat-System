 /******************************************************************************
 *
 * Module: can
 *
 * File Name: can.c
 *
 * Description: Source file to Initilaze can.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/ 




#include "can.h"



/******************************  Variables  ******************************/
tCANMsgObject sCANMessage;
tCANMsgObject sCANMessage1;
uint8_t pui8MsgData;          // store Transmitted data
uint8_t pui8MsgData1;         // store recived data  
char arrayreceive[200]={0};   // array to recive data 
uint8_t counter=0;            // to detect how many time canrecive function is enterd 
uint8_t indexrecieve=0;       // index for recived data
uint8_t Flag=1;
uint8_t array_flag =0;

//*****************************************************************************
//
// A flag to indicate that some transmission error occurred.
//
//*****************************************************************************
volatile bool g_bErrFlag = 0;
//*****************************************************************************
//
// A flag for the interrupt handler to indicate that a message was received.
//
//*****************************************************************************
volatile bool g_bRXFlag = 0;



/************************************************************************************
* Name: Delay_MS
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: Delay 1 MilliSecond
************************************************************************************/
void Delay_MS(unsigned long long n)
{
  volatile unsigned long long count=0;
  while(count++<(762*n));
}

/************************************************************************************
* Name: initcan
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
************************************************************************************/
void initcan(){
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    uint32_t ui32SysClock;
#endif



    //
    // Set the clocking to run directly from the external crystal/oscillator.
    // TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
    // crystal on your board.
    //
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                       SYSCTL_OSC_MAIN |
                                       SYSCTL_USE_OSC)
                                       25000000);
#else
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
#endif


  
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);

    // Enable the alternate function on the GPIO pins.  The above step selects
    // which alternate function is available.  This step actually enables the
    // alternate function instead of GPIO for these pins.
    // TODO: change this to match the port/pin you are using
    //
    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    //
    // The GPIO port and pins have been set up for CAN.  The CAN peripheral
    // must be enabled.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    //
    // Initialize the CAN controller
    //
    CANInit(CAN0_BASE);

    //
    // Set up the bit rate for the CAN bus.  This function sets up the CAN
    // bus timing for a nominal configuration.  You can achieve more control
    // over the CAN bus timing by using the function CANBitTimingSet() instead
    // of this one, if needed.
    // In this example, the CAN bus is set to 500 kHz.  In the function below,
    // the call to SysCtlClockGet() or ui32SysClock is used to determine the
    // clock rate that is used for clocking the CAN peripheral.  This can be
    // replaced with a  fixed value if you know the value of the system clock,
    // saving the extra function call.  For some parts, the CAN peripheral is
    // clocked by a fixed 8 MHz regardless of the system clock in which case
    // the call to SysCtlClockGet() or ui32SysClock should be replaced with
    // 8000000.  Consult the data sheet for more information about CAN
    // peripheral clocking.
    //
#if defined(TARGET_IS_TM4C129_RA0) ||                                         \
    defined(TARGET_IS_TM4C129_RA1) ||                                         \
    defined(TARGET_IS_TM4C129_RA2)
    CANBitRateSet(CAN0_BASE, ui32SysClock, 500000);
#else
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);
#endif

    //
    // Enable interrupts on the CAN peripheral.  This example uses static
    // allocation of interrupt handlers which means the name of the handler
    // is in the vector table of startup code.  If you want to use dynamic
    // allocation of the vector table, then you must also call CANIntRegister()
    // here.
    //
    // CANIntRegister(CAN0_BASE, CANIntHandler); // if using dynamic vectors
    //
    CANIntEnable(CAN0_BASE, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    //
    // Enable the CAN interrupt on the processor (NVIC).
    //
    IntEnable(INT_CAN0);

    //
    // Enable the CAN for operation.
    //
    CANEnable(CAN0_BASE);
    
     // Initialize a message object to be used for receiving CAN messages with
    // any CAN ID.  In order to receive any CAN ID, the ID and mask must both
    // be set to 0, and the ID filter enabled.
    //
    
    sCANMessage1.ui32MsgID = CAN0RXID;
    sCANMessage1.ui32MsgIDMask = 0;
    sCANMessage1.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
    sCANMessage1.ui32MsgLen = sizeof(pui8MsgData1);

    //
    // Now load the message object into the CAN peripheral.  Once loaded the
    // CAN will receive any message on the bus, and an interrupt will occur.
    // Use message object 1 for receiving messages (this is not the same as
    // the CAN ID which can be any value in this example).
    //
    CANMessageSet(CAN0_BASE, RXOBJECT, &sCANMessage1, MSG_OBJ_TYPE_RX);


    //
    // Initialize the message object that will be used for sending CAN
    // messages.  The message will be 4 bytes that will contain an incrementing
    // value.  Initially it will be set to 0.
    //
    pui8MsgData = 0;
    sCANMessage.ui32MsgID = CAN0TXID;
    sCANMessage.ui32MsgIDMask = 0;
    sCANMessage.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage.ui32MsgLen = sizeof(pui8MsgData);
    sCANMessage.pui8MsgData = (uint8_t *)&pui8MsgData;

    //
    // Enter loop to send messages.  A new message will be sent once per
    // second.  The 4 bytes of message content will be treated as an uint32_t
    // and incremented by one each time.
    //

}

/************************************************************************************
* Name: CAN0IntHandler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Initilaize can
************************************************************************************/

void CAN0IntHandler(void)
{
    uint32_t ui32Status;

    //
    // Read the CAN interrupt status to find the cause of the interrupt
    //
    ui32Status = CANIntStatus(CAN0_BASE, CAN_INT_STS_CAUSE);

    //
    // If the cause is a controller status interrupt, then get the status
    //
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
        //
        // Read the controller status.  This will return a field of status
        // error bits that can indicate various errors.  Error processing
        // is not done in this example for simplicity.  Refer to the
        // API documentation for details about the error status bits.
        // The act of reading this status will clear the interrupt.  If the
        // CAN peripheral is not connected to a CAN bus with other CAN devices
        // present, then errors will occur and will be indicated in the
        // controller status.
        //
        ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);

        //
        // Set a flag to indicate some errors may have occurred.
        //
        g_bErrFlag = 1;
    }

    //
    // Check if the cause is message object 1, which what we are using for
    // sending messages.
    //
    else if(ui32Status == RXOBJECT)
    {
        //
        // Getting to this point means that the RX interrupt occurred on
        // message object RXOBJECT, and the message reception is complete.
        // Clear the message object interrupt.
        //
        CANIntClear(CAN0_BASE, RXOBJECT);

          //
        // Set flag to indicate received message is pending.
        //
        g_bRXFlag = 1;
        ReceptionState();
        

        //
        // Since the message was recived, clear any error flags.
        //
        g_bErrFlag = 0;
    }
    
    else if(ui32Status == TXOBJECT)
    {
        //
        // Getting to this point means that the TX interrupt occurred on
        // message object TXOBJECT, and the message reception is complete.
        // Clear the message object interrupt.
        //
        CANIntClear(CAN0_BASE, TXOBJECT);

        //
        // Since a message was transmitted, clear any error flags.
        // This is done because before the message is transmitted it triggers
        // a Status Interrupt for TX complete. by clearing the flag here we
        // prevent unnecessary error handling from happeneing
        //
        g_bErrFlag  = 0;
    }

    //
    // Otherwise, something unexpected caused the interrupt.  This should
    // never happen.
    //
    else
    {
        //
        // Spurious interrupt handling can go here.
        //
    }
}

/************************************************************************************
* Name: canrecieve
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description:Recive data with can bus
************************************************************************************/

void canrecieve(){
   if(g_bRXFlag)
        {    
            //
            // Reuse the same message object that was used earlier to configure
            // the CAN for receiving messages.  A buffer for storing the
            // received data must also be provided, so set the buffer pointer
            // within the message object.
            //
            sCANMessage1.pui8MsgData = (uint8_t *)&pui8MsgData1;

            //
            // Read the message from the CAN.  Message object number 1 is used
            // (which is not the same thing as CAN ID).  The interrupt clearing
            // flag is not set because this interrupt was already cleared in
            // the interrupt handler.
            //
            CANMessageGet(CAN0_BASE, RXOBJECT, &sCANMessage1, 0);
           if(array_flag==2)
            {
              if(counter<=indexrecieve)
              {
            arrayreceive[counter]=pui8MsgData1;
            counter++;
              }
            else
            {
                counter=0;
                indexrecieve=0;
                Flag=1;
                array_flag=0;
            }
            }
            if(Flag==1){
              indexrecieve = pui8MsgData1;
              Flag=0;
              array_flag=2;
            }
            
            //
            // Clear the pending message flag so that the interrupt handler can
            // set it again when the next message arrives.
            //
            g_bRXFlag = 0;
            }
        
        }

/************************************************************************************
* Name: cantransmit
* Reentrancy: reentrant
* Parameters (in):  pointer,index
* Return value: None
* Description:Transmit data with can bus
************************************************************************************/

void cantransmit(char *pointer,char index)
{
  pui8MsgData=index; 
  CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
  Delay_MS(5);
  for (char y=0;y<=index;y++)
  {
      pui8MsgData= *pointer;    
      CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
      Delay_MS(5);
      pointer++;
  }
}
