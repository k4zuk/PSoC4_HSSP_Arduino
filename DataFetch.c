/******************************************************************************
* File Name: DataFetch.c
* Version 1.0
*
* Description:
*  This source file contains the functions to fetch data from the Hex image and 
*  load in to the arrays used for Programming.
*
* Owner:
*	Tushar Rastogi, Application Engineer (tusr@cypress.com)
*
* Related Document:
*	AN84858 - PSoC 4 and PSoC Analog Coprocessor Programming using an External Microcontroller (HSSP)
*
* Hardware Dependency:
*   Family specific Pioneer kit:
*       CY8CKIT - 040 / CY8CKIT - 042 / CY8CKIT - 044 PSoC 4 M / CY8CKIT - 042 BLE /
*       CY8CKIT - 046 / CY8CKIT - 048 / CY8CKIT - 41-40xx/ CY8CKIT-149
*
* Code Tested With:
*	PSoC Creator 4.0
*	ARM GCC 4.9-2015-q1-update
*
* Note:
*  The definitions of the functions used in this file will change based on the
*  interface used to get Hex file data.
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
#include "DataFetch.h"
#include "HexImage.h"
#include "ProgrammingSteps.h"
//#include <device.h>

/******************************************************************************
*   Global Constant declaration
******************************************************************************/

/***************************** USER ATTENTION REQUIRED ************************
**************** DEPENDS ON INTERFACE USED TO GET HEX FILE DATA **************/
/* The below Global constants are from HexImage.h. The data from these array of
   constants are loaded in to the arrays passed a parameters to function.
   These should be modified if different interface is used to get hex file data */

extern unsigned char const deviceSiliconId_HexFile[SILICON_ID_BYTE_LENGTH]; 
extern unsigned char const checksumData_HexFile[CHECKSUM_BYTE_LENGTH]; 

/* PSoC 5LP cannot hold 256 KB of target flash data. Logic to truncate 256 rows */
#if defined (CY_PSOC5)
	#if defined (CY8C4xxxL_FAMILY) || defined (CY8C4xx8_BL_FAMILY) || defined(CY8C41xxS_PLUS_FAMILY)
		extern unsigned char const flashData_HexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE - 256][FLASH_ROW_BYTE_SIZE_HEX_FILE];
	#else
		extern unsigned char const flashData_HexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE];
	#endif
#else
	extern unsigned char const flashData_HexFile[NUMBER_OF_FLASH_ROWS_HEX_FILE][FLASH_ROW_BYTE_SIZE_HEX_FILE];
#endif

extern unsigned char const flashProtectionData_HexFile[FLASH_PROTECTION_BYTE_SIZE_HEX_FILE];
extern unsigned char const chipProtectionData_HexFile; 

/******************************************************************************
*   Function Definitions
******************************************************************************/

/***************************** USER ATTENTION REQUIRED ************************
**************** DEPENDS ON INTERFACE USED TO GET HEX FILE DATA ***************
All the function definitions below should be modified based on the interface 
used to get Hex file data to be programmed. If a protocol like I2C, UART is 
used to get the hex file data, change the function definitions accordingly */

/******************************************************************************
* Function Name: HEX_ReadSiliconId
*******************************************************************************
*
* Summary:
*  Loads the Device Silicon ID data in to an array 
*
* Parameters:
*  unsigned long *hexSiliconId - Address of variable which will store the
*								 Silicon ID fetched
*
* Return:
*  None.
*
* Note:
*  Modify definition based on method of getting programming data
*
******************************************************************************/
void HEX_ReadSiliconId(unsigned long *hexSiliconId)
{
    unsigned char i = 0;
    
    for(i = 0; i < SILICON_ID_BYTE_LENGTH; i++)
    {
        *hexSiliconId = *hexSiliconId | ((unsigned long)(deviceSiliconId_HexFile[i]) << (8*i));		
    }
}


/******************************************************************************
* Function Name: HEX_ReadRowData
*******************************************************************************
*
* Summary:
*  Loads the row data from hex file in to an array 
*
* Parameters:
*  unsigned short rowCount      - Flash row count for which the data has to be
*								  fetched 
*  unsigned char * rowData      - Base address of array which will store the
*								  Flash row data fetched
*
* Return:
*  None.
*
* Note:
*  Modify definition based on the method of getting programming data
*  
*  REMOVE THIS LOGIC WHILE PORTING THE HSSP CODE TO OTHER HOST PROGRAMMER
*
******************************************************************************/
void HEX_ReadRowData(unsigned short rowCount, unsigned char * rowData)
{
    unsigned short i = 0; /* Maximum value of 'i' can be 256 */
    
	#if defined (CY_PSOC5)
		#if defined (CY8C4xxxL_FAMILY) || defined (CY8C4xx8_BL_FAMILY) || defined(CY8C41xxS_PLUS_FAMILY)
			/* PSoC 5LP cannot hold 256 KB of target flash data. Logic to truncate 256 rows */
			if(rowCount < (NUMBER_OF_FLASH_ROWS_HEX_FILE - 256))
			{
                /* Flash data from HeXFile is stored  except for last 256 rows  */
			    
                for(i = 0; i < FLASH_ROW_BYTE_SIZE_HEX_FILE; i++)
			    {
			        rowData[i] = flashData_HexFile[rowCount][i];
			    }
			}
			else
			{   
                /* Last 256 rows are filled with zeros*/
                
				for(i = 0; i < FLASH_ROW_BYTE_SIZE_HEX_FILE; i++)
			    {
			        rowData[i] = 0;
			    }
			}
		#else
			if(rowCount < (NUMBER_OF_FLASH_ROWS_HEX_FILE))
			{
			    for(i = 0; i < FLASH_ROW_BYTE_SIZE_HEX_FILE; i++)
			    {
			        rowData[i] = flashData_HexFile[rowCount][i];
			    }
			}
		#endif
	#else
		if(rowCount < (NUMBER_OF_FLASH_ROWS_HEX_FILE))
			{
			    for(i = 0; i < FLASH_ROW_BYTE_SIZE_HEX_FILE; i++)
			    {
			        rowData[i] = flashData_HexFile[rowCount][i];
			    }
			}
	#endif
}

/******************************************************************************
* Function Name: HEX_ReadChipProtectionData
*******************************************************************************
*
* Summary:
*  Loads the Chip Protection data in to an array 
*
* Parameters:
*
*  unsigned char * chipProtectionData - Address of variable which will store
*										the Chip Protection data fetched
*
* Return:
*  None.
*
* Note:
*  Modify definition based on the method of getting programming data
*
******************************************************************************/
void HEX_ReadChipProtectionData(unsigned char * chipProtectionData)
{
    *chipProtectionData = chipProtectionData_HexFile;
}


/******************************************************************************
* Function Name: HEX_ReadRowProtectionData
*******************************************************************************
*
* Summary:
*  Loads the Flash Row Protection data in to an array 
*
* Parameters:
*
*  unsigned char * rowProtectionData  - Base address of array which will store
*									    the Flash Row Protection data fetched
*  unsigned char rowProtectionByteSize - Size of flash row protection settings
*										 in bytes
*
* Return:
*  None.
*
* Note:
*  Modify definition based on the method of getting programming data
*
******************************************************************************/
void HEX_ReadRowProtectionData(unsigned char rowProtectionByteSize, unsigned char * rowProtectionData, unsigned char arrayID)
{
    unsigned short i = 0;
    
    unsigned short offset;
    
    offset = arrayID * (ROWS_PER_ARRAY / 8);
    
    for(i = 0; i < rowProtectionByteSize; i++)
    {
        rowProtectionData[i] = flashProtectionData_HexFile[i + offset];
    }    
}


/******************************************************************************
* Function Name: HEX_ReadChecksumData
*******************************************************************************
*
* Summary:
*  Loads the Checksum data in to an array 
*
* Parameters:
*  unsigned short * checksumData - Base address of the array which will store
*								   the Checksum data fetched
*
* Return:
*  None.
*
* Note:
*  Modify definition based on the method of getting programming data
*
******************************************************************************/
void HEX_ReadChecksumData(unsigned short * checksumData)
{
    unsigned char i = 0;

    for(i = 0; i < CHECKSUM_BYTE_LENGTH; i++)
    {
        *checksumData |= (checksumData_HexFile[i] << (8*i));
    }
}

/******************************************************************************
* Function Name: GetFlashRowCount
*******************************************************************************
*
* Summary:
*  Returns the total number of Flash rows in the target PSoC 4 device
*
* Parameters:
*  None
*
* Return:
*  unsigned short
*   Total number of Flash rows in target PSoC 4
*
* Note:
*  The Flash row count is from the HexImage.h file. Modify the definition based
*  on the method of getting programming data
*
******************************************************************************/
unsigned short GetFlashRowCount(void)
{
    return(NUMBER_OF_FLASH_ROWS_HEX_FILE);
}

/* [] END OF FILE */
