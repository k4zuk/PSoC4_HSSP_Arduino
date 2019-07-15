/******************************************************************************
* File Name: Timeout.h
* Version 1.0
*
* Description:
*  This header file contains the definitions for timeout parameters, function
*  declaration for the delay routine. These definitions will vary based on host
*  processor used to program target PSoC 5LP. Change the timeout values based on
*  your Host processor.
*
* Note:
* Refer to the TimeoutCalc.h header file in the other project 
* "C_Hssp_TimeoutCalc" for details on the procedure to calculate these 
* parameters for your specific host programmer.
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
#ifndef __TIMEOUT_H
#define __TIMEOUT_H

/******************************************************************************
*   Macro definitions
******************************************************************************/
#include "HexImage.h"
#include "ProgrammingSteps.h"
/***************************** USER ATTENTION REQUIRED ************************
***************************** HOST PROCESSOR SPECIFIC *************************
* The two timeout values namely: DEVICE_ACQUIRE_TIMEOUT,
* and SROM_POLLING_TIMEOUT are for a PSoC 5LP Host programmer 
* running at 63 MHz. Modify these values as required for your host processor. 
* Refer to the TimeoutCalc.h header file in the other project 
* "C_Hssp_TimeoutCalc" for details on the procedure to calculate these 
* parameters for your specific host programmer. These parameters are calculated 
  for both debug mode and release mode. 
******************************************************************************/
/* Debug Mode Settings*/    
#if !defined(NDEBUG)
        
    #if defined (CY8C40xx_FAMILY) || defined (CY8C4xxxM_FAMILY) || defined (CY8C4xx7_BL_FAMILY) \
    ||defined (CY8C4xx8_BL_FAMILY) || defined (CY8C4xxxL_FAMILY)|| defined (CY8C40xxS_FAMILY)|| defined (CY8C41xxS_FAMILY)|| defined(CY8C41xxS_PLUS_FAMILY) || defined (Analog_Coprocessor)
    	#define DEVICE_ACQUIRE_TIMEOUT 60
    #else
    	#define DEVICE_ACQUIRE_TIMEOUT 16
    #endif
    
    #define SROM_POLLING_TIMEOUT 11199
#else 
/* Release Mode Settings */
    
    #if defined (CY8C40xx_FAMILY) || defined (CY8C4xxxM_FAMILY) || defined (CY8C4xx7_BL_FAMILY) \
    || defined (CY8C4xx8_BL_FAMILY) || defined (CY8C4xxxL_FAMILY)|| defined (CY8C40xxS_FAMILY)|| defined (CY8C41xxS_FAMILY) || defined(CY8C41xxS_PLUS_FAMILY) ||defined (Analog_Coprocessor)
    	#define DEVICE_ACQUIRE_TIMEOUT 112
    #else
    	#define DEVICE_ACQUIRE_TIMEOUT 33
    #endif
    
    #define SROM_POLLING_TIMEOUT 22706  
#endif
/******************************************************************************
*   Function Prototypes
******************************************************************************/
void DelayHundredUs(void);

#endif /* __TIMEOUT_H */


/* [] END OF FILE */
