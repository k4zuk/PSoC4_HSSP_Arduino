/*******************************************************************************
* File Name: SWD_PhysicalLayer.c
* Version 1.0
*
* Description:
*  This file provides the source code for the physical layer functions of the
*  SWD protocol. These function definitions are the same as the corresponding
*  macro definitions in SWD_PhysicalLayer.h
*
* Owner:
*	Tushar Rastogi, Application Engineer (tusr@cypress.com)
*
* Related Document:
*	AN84858 - PSoC 4 Programming using an External Microcontroller (HSSP)
*
* Hardware Dependency:
*   CY8CKIT - 040 / CY8CKIT - 042 / CY8CKIT - 044 PSoC 4 M / CY8CKIT - 042 BLE / 
*   CY8CKIT - 046 / CY8CKIT - 048 / CY8CKIT - 41-40xx
*
* Code Tested With:
*	PSoC Creator 4.0
*	ARM GCC 4.9-2015-q1-update
*
* Note:
*  The functions defined here are specific to PSoC 5LP Host Programmer.
*  Modify the definitions as applicable for your Host Programmer.
*
******************************************************************************
* Copyright (c) 2013-2016, Cypress Semiconductor Corporation.
******************************************************************************
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

*******************************************************************************/

/********************************************************************************
*   Header file Inclusion
********************************************************************************/
#include "SWD_PhysicalLayer.h"

/********************************************************************************
*   Function Definitions
********************************************************************************/

/***************************** USER ATTENTION REQUIRED **************************
***************************** HOST PROCESSOR SPECIFIC ***************************
******************* SWD Protocol Physical Layer functions ***********************
*
* All of the function definitions below are for a PSoC 5LP host programmer.
* Modify the definitions as applicable for the specific host programmer.
********************************************************************************/

/*******************************************************************************
* Function Name: SetSwdckCmosOutput
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin drive mode as CMOS drive mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_DRIVEMODE_CMOSOUT in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdckCmosOutput()
{
//    SWDCK_PIN_DM_REG = (SWDCK_PIN_DM_REG & CMOSOUT_DM_ANDMASK) | CMOSOUT_DM_ORMASK;
    SWDCK_DRIVEMODE_CMOSOUT;
}

/*******************************************************************************
* Function Name: SetSwdckHizInput
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin drive mode as High impedance digital input.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_DRIVEMODE_HIGHZIN in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdckHizInput()
{
//    SWDCK_PIN_DM_REG = (SWDCK_PIN_DM_REG & HIGHZIN_DM_ANDMASK) | HIGHZIN_DM_ORMASK;
    SWDCK_DRIVEMODE_HIGHZIN;
}

/*******************************************************************************
* Function Name: SetSwdioCmosOutput
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin drive mode as CMOS drive mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_DRIVEMODE_CMOSOUT in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdioCmosOutput()
{
//    SWDIO_PIN_DM_REG = (SWDIO_PIN_DM_REG & CMOSOUT_DM_ANDMASK) | CMOSOUT_DM_ORMASK;
    SWDIO_DRIVEMODE_CMOSOUT;
}

/*******************************************************************************
* Function Name: SetSwdioHizInput
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin drive mode as High impedance digital input.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_DRIVEMODE_HIGHZIN in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdioHizInput()
{
//    SWDIO_PIN_DM_REG = (SWDIO_PIN_DM_REG & HIGHZIN_DM_ANDMASK) | HIGHZIN_DM_ORMASK;
    SWDIO_DRIVEMODE_HIGHZIN;
}

/*******************************************************************************
* Function Name: SetXresCmosOutput
********************************************************************************
*
* Summary:
*  Sets the XRES pin drive mode as CMOS drive mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_DRIVEMODE_CMOSOUT in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetXresCmosOutput()
{
//    XRES_PIN_DM_REG = (XRES_PIN_DM_REG & CMOSOUT_DM_ANDMASK) | CMOSOUT_DM_ORMASK;
    XRES_DRIVEMODE_CMOSOUT;
}

/*******************************************************************************
* Function Name: SetXresHizInput
********************************************************************************
*
* Summary:
*  Sets the XRES pin drive mode as High impedance digital input.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_DRIVEMODE_HIGHZIN in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetXresHizInput()
{
//    XRES_PIN_DM_REG = (XRES_PIN_DM_REG & HIGHZIN_DM_ANDMASK) | HIGHZIN_DM_ORMASK;
    XRES_DRIVEMODE_HIGHZIN;
}

/*******************************************************************************
* Function Name: SetSwdckHigh
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_OUTPUT_HIGH in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdckHigh()
{
//    SWDCK_PRT_OUT_REG = SWDCK_PRT_OUT_REG | SWDCK_PIN_MASK;
    SWDCK_OUTPUT_HIGH;
}

/*******************************************************************************
* Function Name: SetSwdckLow
********************************************************************************
*
* Summary:
*  Sets the SWDCK pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDCK_OUTPUT_LOW in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdckLow()
{
//    SWDCK_PRT_OUT_REG = SWDCK_PRT_OUT_REG & (~SWDCK_PIN_MASK);
    SWDCK_OUTPUT_LOW;
}

/*******************************************************************************
* Function Name: SetSwdioHigh
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_OUTPUT_HIGH in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdioHigh()
{
//    SWDIO_PRT_OUT_REG = SWDIO_PRT_OUT_REG | SWDIO_PIN_MASK;
    SWDIO_OUTPUT_HIGH;
}

/*******************************************************************************
* Function Name: SetSwdioLow
********************************************************************************
*
* Summary:
*  Sets the SWDIO pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition SWDIO_OUTPUT_LOW in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetSwdioLow()
{
//    SWDIO_PRT_OUT_REG = SWDIO_PRT_OUT_REG & (~SWDIO_PIN_MASK);
    SWDIO_OUTPUT_LOW;
}

/*******************************************************************************
* Function Name: SetXresHigh
********************************************************************************
*
* Summary:
*  Sets the XRES pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_OUTPUT_HIGH in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetXresHigh()
{
//    XRES_PRT_OUT_REG = XRES_PRT_OUT_REG | XRES_PIN_MASK;
    XRES_OUTPUT_HIGH;
}

/*******************************************************************************
* Function Name: SetXresLow
********************************************************************************
*
* Summary:
*  Sets the XRES pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_OUTPUT_LOW in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
void SetXresLow()
{
//    XRES_PRT_OUT_REG = XRES_PRT_OUT_REG & (~XRES_PIN_MASK);
    XRES_OUTPUT_LOW;
}

/*******************************************************************************
* Function Name: ReadSwdio
********************************************************************************
*
* Summary:
*  Returns the state of the SWDIO input pin
*
* Parameters:
*  None.
*
* Return:
*  unsigned char (only one of the two values as given below)
*   0x00 - If the SWDIO pin state is low
*   0x01 - If the SWDIO pin state is high
*
* Note:
*  The function definition is the same as the macro definition SWDIO_INPUT_READ in
*  SWD_PhysicalLayer.h.
*
*******************************************************************************/
unsigned char ReadSwdio()
{
    return(digitalRead(SWDIO_PIN));
}

/* [] END OF FILE */
