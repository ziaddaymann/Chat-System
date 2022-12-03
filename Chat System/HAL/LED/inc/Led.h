 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: Led.h
 *
 * Description: Header file to Initilaze Leds.
 *
 * Author: Ziad Ayman
 *
 *******************************************************************************/

#ifndef DATACOLLECTION_STATE
#define DATACOLLECTION_STATE

#include "tm4c123gh6pm_registers.h"
#include "gpio.h"


#define LED1_PORT     PORTF_ID
#define LED2_PORT     PORTF_ID
#define LED3_PORT     PORTF_ID


#define LED1_PIN      PIN1_ID
#define LED2_PIN      PIN2_ID
#define LED3_PIN      PIN3_ID

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/***	Description: Function to initilaize all led   ***/
void Led_Init(void);

/***	Description: Function to Red led on  ***/
void RED_ON(void);

/***	Description: Function to Green led on  ***/
void GREEN_ON(void);

/***	Description: Function to Blue led on  ***/
void BLUE_ON(void);

/***	Description: Function to White led on  ***/
void WHITE_ON(void);
#endif