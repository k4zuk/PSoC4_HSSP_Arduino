/******************************************************************************
* File Name: Timeout.c
* Version 1.0
*
* Description:
*  This file provides source code for the delay routine used in the HSSP 
*  application
*
* Owner:
*	Tushar Rastogi, Application Engineer (tusr@cypress.com)
*
* Related Document:
*	AN84858 - PSoC 4 Programming using an External Microcontroller (HSSP)
*
* Hardware Dependency:
*   Family specific Pioneer kit:
*       CY8CKIT - 040 / CY8CKIT - 042 / CY8CKIT - 044 PSoC 4 M / CY8CKIT - 042 BLE 
*       / CY8CKIT - 046 / CY8CKIT - 048 / CY8CKIT - 41-40xx / CY8CKIT-149
*
* Code Tested With:
*	PSoC Creator 4.0
*	ARM GCC 4.9-2015-q1-update
*
*******************************************************************************
* Copyright (c) 2013-2016, Cypress Semiconductor Corporation.
*******************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.

******************************************************************************/

/******************************************************************************
*   Header file Inclusion
******************************************************************************/
#include "Timeout.h"
//#include "CyLib.h"
#include <Arduino.h>

/******************************************************************************
*   Function Definitions
******************************************************************************/

/******************************************************************************
* Function Name: DelayHundredUs
*******************************************************************************
*
* Summary:
*  Generates an approximate delay for 100 microseconds
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The delay is introduced by using CyDelay API
*   
******************************************************************************/

void DelayHundredUs(void)
{
//    CyDelayUs(100);      
  delay(100);
}

/* [] END OF FILE */
