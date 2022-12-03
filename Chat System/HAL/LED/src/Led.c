 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: Led.c
 *
 * Description: Source file to Initilaze Leds.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/
#include "Led.h"

/***	Description: Function to all led   ***/
void Led_Init() 
{
  GPIO_setupPinDirection (LED1_PORT , LED1_PIN , PIN_OUTPUT);
  GPIO_setupPinDirection (LED2_PORT , LED2_PIN , PIN_OUTPUT);
  GPIO_setupPinDirection (LED3_PORT , LED3_PIN , PIN_OUTPUT);
}
 
/***	Description: Function to red led on  ***/
void RED_ON(void)
{
  GPIO_writePin (LED1_PORT, LED1_PIN , LOGIC_HIGH);
  GPIO_writePin (LED2_PORT, LED2_PIN , LOGIC_LOW);
  GPIO_writePin (LED3_PORT, LED3_PIN , LOGIC_LOW);
}

/***	Description: Function to Green led on  ***/
void GREEN_ON(void)
{
  GPIO_writePin (LED1_PORT, LED1_PIN , LOGIC_LOW);
  GPIO_writePin (LED2_PORT, LED2_PIN , LOGIC_LOW);
  GPIO_writePin (LED3_PORT, LED3_PIN , LOGIC_HIGH);
}

/***	Description: Function to blue led on  ***/
void BLUE_ON(void)
{
  GPIO_writePin (LED1_PORT, LED1_PIN , LOGIC_LOW);
  GPIO_writePin (LED2_PORT, LED2_PIN , LOGIC_HIGH);
  GPIO_writePin (LED3_PORT, LED3_PIN , LOGIC_LOW);
}

/***	Description: Function to white led on  ***/
void WHITE_ON(void)
{
  GPIO_writePin (LED1_PORT, LED1_PIN , LOGIC_HIGH);
  GPIO_writePin (LED2_PORT, LED2_PIN , LOGIC_HIGH);
  GPIO_writePin (LED3_PORT, LED3_PIN , LOGIC_HIGH);
}
