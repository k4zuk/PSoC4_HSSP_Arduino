/******************************************************************************
* File Name: DataFetch.h
* Version 1.0
*
* Description:
*  This header file contains the definitions for the size of Programming data,
*  and declarations for the functions used in getting the Programming data
*  from Hex file image. The fuction definitions in corresponding
*  DataFetch.c file will have to be modified if the method of getting 
*  programming data is changed.
*
* Note:
*
*******************************************************************************
* Copyright (c) 2013-2016, Cypress Semiconductor Corporation
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
#ifndef __DATAFETCH_H
#define __DATAFETCH_H

#include "HexImage.h"
/******************************************************************************
*   Macro definitions
******************************************************************************/

/* The below definitions are not dependent on hex file and are always 
   constant */
#define SILICON_ID_BYTE_LENGTH          4
#define CHECKSUM_BYTE_LENGTH            2
#if defined (CY8C4xxxM_FAMILY) || defined (CY8C4xx7_BL_FAMILY) || defined (CY8C4xx8_BL_FAMILY) || defined (CY8C4xxxL_FAMILY) || defined (CY8C41xxS_FAMILY) || defined (CY8C41xxS_PLUS_FAMILY)
    #define MAXIMUM_ROW_PROTECTION_BYTE_LENGTH 64
#else
    #define MAXIMUM_ROW_PROTECTION_BYTE_LENGTH 32
#endif


/******************************************************************************
*        Function Prototypes
******************************************************************************/
void HEX_ReadSiliconId(unsigned long * hexSiliconId);
void HEX_ReadRowData(unsigned short rowCount, unsigned char * rowData);
void HEX_ReadChipProtectionData(unsigned char * chipProtectionData);
void HEX_ReadRowProtectionData(unsigned char rowProtectionByteSize, unsigned char * rowProtectionData, unsigned char arrayID);
void HEX_ReadChecksumData(unsigned short * checksumData);
unsigned short GetFlashRowCount(void);

#endif /* __DATAFETCH_H */


/* [] END OF FILE */
