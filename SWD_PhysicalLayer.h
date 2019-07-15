/******************************************************************************
* File Name: SWD_PhysicalLayer.h
* Version 1.0
*
* Description:
*  This header file contains the macro definitions, function declarations for 
*  the physical layer of the  SWD protocol. These include -
*    a.) Setting a output pin high or low
*    b.) Reading the logic level of an input pin
*    c.) Configuring the drive mode of the programming pin
*
*  The pin manipulation routines are defined both as macros and functions.
*  The macros are used in "Step 1. DeviceAcquire()" as the function has strict
*  timing requirements for execution. Using the macros instead of fuctions 
*  reduces execution overhead.
*
*  The pin manipulation functions are used instead of macros in all other
*  places to save code space.
*
* Note:
*  The macros, functions defined here are specific to PSoC 5LP Host Programmer.
*  Modify them as applicable for your Host Programmer.
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

#ifndef __SWD_PHYSICALLAYER_H
#define __SWD_PHYSICALLAYER_H

/* Host programmer registers, mask values are defined in "RegisterDefines.h" */
//#include "RegisterDefines.h"
#include <Arduino.h>

#define SWDIO_PIN   4
#define SWDCK_PIN   2
#define XRES_PIN    15

/***************************** USER ATTENTION REQUIRED ************************
***************************** HOST PROCESSOR SPECIFIC *************************
**************** Macros for Host Pin Drive mode configuration *****************
*
* Uses the register definitions, mask values in "RegisterDefines.h" to
* configure the pin drive mode
*
* SWDIO pin on host side - CMOS output (host writes data to target PSoC 4),
*                          High Z digital input (host reads data from target 
*						   PSoC 4 or when host is not programming target 
*						   PSoC 4 (idle))
*
* SWDCK pin on host side - CMOS output (when host is programming target PSoC 4),
*                          High Z digital input (when host is not programming 
*						   target PSoC 4 (idle))
*
* XRES pin on host side -  CMOS output (when host is programming target PSoC 4)
*                          High Z digital input (when host is not programming 
*						   target PSoC 4 (idle))
*
* Modify these as applicable to your Host Programmer
******************************************************************************/

#define SWDIO_DRIVEMODE_HIGHZIN         pinMode(SWDIO_PIN, INPUT)
#define SWDIO_DRIVEMODE_CMOSOUT         pinMode(SWDIO_PIN, OUTPUT)

#define SWDCK_DRIVEMODE_HIGHZIN         pinMode(SWDCK_PIN, INPUT)
#define SWDCK_DRIVEMODE_CMOSOUT         pinMode(SWDCK_PIN, OUTPUT)
                                           
#define XRES_DRIVEMODE_HIGHZIN          pinMode(XRES_PIN, INPUT)
#define XRES_DRIVEMODE_CMOSOUT          pinMode(XRES_PIN, OUTPUT)


/***************************** USER ATTENTION REQUIRED ************************
***************************** HOST PROCESSOR SPECIFIC *************************
**************** Macros for driving output pins on host side ******************
*
* Uses the register definitions, mask values in "RegisterDefines.h" to drive
* output pins either to logic high (suffixed by 'HIGH') or
* logic low (suffixed by 'LOW')
*
* Modify these as applicable to your Host Programmer
******************************************************************************/

#define SWDIO_OUTPUT_HIGH      digitalWrite(SWDIO_PIN, HIGH)
#define SWDIO_OUTPUT_LOW       digitalWrite(SWDIO_PIN, LOW)

#define SWDCK_OUTPUT_HIGH      digitalWrite(SWDCK_PIN, HIGH)
#define SWDCK_OUTPUT_LOW       digitalWrite(SWDCK_PIN, LOW)

#define XRES_OUTPUT_HIGH       digitalWrite(XRES_PIN, HIGH)
#define XRES_OUTPUT_LOW        digitalWrite(XRES_PIN, LOW)

/******************************************************************************
*   Function Prototypes
******************************************************************************/
/* The below fuctions are for pin manipulation, and their definitions in
   SWD_PhysicalLayer.c are the same as the corresponding macro defitnions
   above. */

void SetSwdckHigh(void);
void SetSwdckLow(void);
void SetSwdckCmosOutput(void);
void SetSwdckHizInput(void);
void SetSwdioHigh(void);
void SetSwdioLow(void);
void SetSwdioCmosOutput(void);
unsigned char ReadSwdio(void);
void SetSwdioHizInput(void);
void SetXresHigh(void);
void SetXresLow(void);
void SetXresCmosOutput(void);
void SetXresHizInput(void);


#endif /* __SWD_PHYSICALLAYER_H */

/*[] END OF FILE */
