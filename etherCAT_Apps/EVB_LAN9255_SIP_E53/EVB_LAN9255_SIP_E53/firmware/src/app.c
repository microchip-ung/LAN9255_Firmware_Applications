/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*****************************************************************************
 *****************************************************************************
 Section: Included Files
 *****************************************************************************
 *****************************************************************************/

#include "app.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "ESC_Utils.h"
#include "Drivers.h"
#include "applInterface.h"
#include "sample_app.h"
#include "Developer_Test.h"
#include "oledc_driver.h"
#include "fonts.h"
#include "plib_sercom4_spi_master.h"

#if defined(ETHERCAT_USE_FOE)  
//-----------------------------------------------------------------------------
const uint32_t gAppBankBOffsetAddr = APP_NVM_BANKB_START_ADDRESS;
// Bank B application need to started from this below location.
const uint32_t gApplicationStartAddr   = (uint32_t)(APP_NVM_BANKB_START_ADDRESS + APP_BOOTLOADER_SIZE);

void APP_FlashWrite( uint32_t startAddress,uint8_t *flash_data )
{
    uint32_t   flashStartAddress=0;
    int         pageCnt=0;
    
    flashStartAddress = gAppBankBOffsetAddr+startAddress;
	while(NVMCTRL_IsBusy()){}

    /* Erase the block */
    NVMCTRL_BlockErase((uint32_t)flashStartAddress);

    while(NVMCTRL_IsBusy()){}

    for (pageCnt=0; pageCnt < APP_PAGES_IN_ERASE_BLOCK; pageCnt++)
	{
        /* If write mode is manual, */
        /* Program 512 byte page */
        NVMCTRL_PageWrite((uint32_t *)flash_data, (uint32_t)flashStartAddress);
        while(NVMCTRL_IsBusy()){}

        flash_data = flash_data + APP_PAGE_SIZE;
        flashStartAddress = flashStartAddress + APP_PAGE_SIZE;        
	}
}

static void APP_BankSwitch(void)
{
	/* wait until it is ready to accept a new command */
	while (NVMCTRL_IsBusy());
	
	/* execute the command BKSWRST (Bank swap and system reset) */
	NVMCTRL_BankSwap();
	
	/* wait until command done */
	while (NVMCTRL_IsBusy());    
    
	/* At the end of this command, code starts running from 0x00000 upon reset*/
}

//-----------------------------------------------------------------------------
static void APP_RunApplication(void)
{
	UINT32 u32StackPointer = *(UINT32 *)(gApplicationStartAddr);
	UINT32 u32ResetVector = *(UINT32 *)(gApplicationStartAddr + 4);

    /* if Stack pointer is valid, then execute the Application*/
	if (0xffffffff != u32StackPointer)
    {
        __set_MSP(u32StackPointer);

        asm("bx %0"::"r" (u32ResetVector));
    }
	
}
#endif

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/
APP_DATA appData;

#ifdef _OLED_APP_EN
void Oled_cb (uintptr_t context);
void applicationTask();
volatile uint8_t spi_sync = 1;

uint8_t text1[7] = {'H','e','l','l','o',',',0};
uint8_t text2[17] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','d','e','m','o',0};
uint8_t text3[17] = {'f','o','r',' ','O','L','E','D',' ','C',' ','c','l','i','c','k',0};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// ****************************************************************************

void Oled_cb (uintptr_t context)
{
    spi_sync = 0;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


void applicationTask()
{
#ifdef DEVELOPER_TEST_EN
    oledc_fill_screen( 0xFFFF );
    Delay_ms(100);

    /* Rectangle demo*/
    oledc_rectangle( 0, 0, 96, 96, 0xF000 );
    Delay_ms( 500 );
    oledc_rectangle( 5, 5, 91, 91, 0xFF00 );
    Delay_ms( 500 );
    oledc_rectangle( 10, 10, 86, 86, 0x00F0 );
    Delay_ms( 500 );
    oledc_rectangle( 15, 15, 81, 81, 0x0F0F );
    Delay_ms( 500 );
    oledc_rectangle( 20, 20, 76, 76, 0xF000 );
    Delay_ms( 500 );
    oledc_rectangle( 25, 25, 71, 71, 0xFF00 );
    Delay_ms(100);

    /* Line demo */
    oledc_rectangle( 25, 25, 71, 27, 0 );
    Delay_ms(100);
    oledc_rectangle( 25, 71, 71, 73, 0 );
    Delay_ms(100);
    oledc_rectangle( 25, 25, 27, 71, 0 );
    Delay_ms(100);
    oledc_rectangle( 68, 25, 71, 71, 0 );
    Delay_ms( 100 );
#endif
    char str[32] = {0};

    sprintf ((char *)&str[0], "%lu", Inputs0x6000.Counter);
    oledc_text((uint8_t *)"Counter Value: ", 5, 25 );
    box_area( 25, 55, 90, 80, 0xFFFF );
    oledc_text((uint8_t *)str, 25, 55 );
}
#endif /* _OLED_APP_EN */

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;   
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            ESF_PDI_Init();
#ifdef DEVELOPER_TEST_EN
#ifdef DIRECT_MODE
            test_direct_mode();
#else
            test_indirect_mode();
#endif
#endif
#ifdef _OLED_APP_EN
			SERCOM4_SPI_CallbackRegister(Oled_cb, 0);
            oledc_spiDriverInit();
            oledc_init();
            oledc_fill_screen( 0xFFFF );
#endif
            /* EtherCAT Initialization after NVIC initialization */
            ESC_Init();
#ifdef _OLED_APP_EN
            oledc_set_font( &guiFont_Tahoma_8_Regular[0], 0, _OLEDC_FO_HORIZONTAL );
            oledc_text( &text1[0], 15, 10 );
            oledc_text( &text2[0], 5, 30 );
            oledc_text( &text3[0], 5, 45 );
            Delay_ms( 100 );
            oledc_fill_screen( 0xFFFF );
#endif
            MainInit();
#if defined(ETHERCAT_USE_FOE)  
            BL_FOE_Application();
                
            bRunApplication = TRUE;
#endif                
            appData.state = APP_STATE_SERVICE_TASKS;
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            do
            {		
#if defined(ETHERCAT_USE_FOE)                
                if(1 == APP_FW_GetDownloadStateFinished())
                {
                    APP_BankSwitch();
                    APP_RunApplication();
                }
#endif                
                MainLoop();
#ifdef _OLED_APP_EN
                applicationTask();
#endif

            } while (bRunApplication == TRUE);
            break;
        }

        /* The default state should never be executed. */
        default:
        {
            break;
        }
    }
}
/*******************************************************************************
 End of File
 */
