/*
    __oledc_driver.h
-----------------------------------------------------------------------------
  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com
  All rights reserved.
----------------------------------------------------------------------------- */

/**
@file   __oledc_driver.h
@brief    OLED_C Driver
@mainpage OLED_C Click
@{
@image html libstock_fb_view.jpg
@}
@defgroup   OLEDC
@brief      OLED_C Click Driver
@{
| Global Library Prefix | **OLEDC** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2018.**      |
| Developer             | **MikroE Team**     |
*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"
#include "stdbool.h"

#ifndef _OLEDC_H_
#define _OLEDC_H_

/** 
 * @macro T_OLEDC_P
 * @brief Driver Abstract type 
 */
#define T_OLEDC_P    const uint8_t*

/** @defgroup OLEDC_VAR Variables */                           /** @{ */

///@}
/**
 * @name                 Font Direction
 ******************************************************************************/
///@{
#define _OLEDC_FO_HORIZONTAL        0x00
#define _OLEDC_FO_VERTICAL          0x01
#define _OLEDC_FO_VERTICAL_COLUMN   0x02

/**
 * @name                 Remamp set
 ******************************************************************************/
///@{
#define _OLEDC_RMP_INC_HOR       0x00
#define _OLEDC_RMP_INC_VER       0x01
#define _OLEDC_RMP_COLOR_NOR     0x00
#define _OLEDC_RMP_COLOR_REV     0x02
#define _OLEDC_RMP_SEQ_RGB       0x00
#define _OLEDC_RMP_SEQ_BGR       0x04
#define _OLEDC_RMP_SCAN_NOR      0x00
#define _OLEDC_RMP_SCAN_REV      0x10
#define _OLEDC_RMP_SPLIT_DISABLE 0x00
#define _OLEDC_RMP_SPLIT_ENABLE  0x20
#define _OLEDC_COLOR_65K         0x00
#define _OLEDC_COLOR_262K        0x80
#define _OLEDC_IMG_HEAD          0x06

/**
 * @name                 Device Properties
 ******************************************************************************/
///@{
#define  _OLEDC_SCREEN_WIDTH    0x60
#define  _OLEDC_SCREEN_HEIGHT   0x60
#define _OLEDC_SCREEN_SIZE      0x2400
#define  _OLEDC_ROW_OFF         0x00
#define  _OLEDC_COL_OFF         0x10

///@}
/**
 * @name                 SSD1355 Commands
 ******************************************************************************/
///@{
#define  _OLEDC_SET_COL_ADDRESS 0x15
#define  _OLEDC_SET_ROW_ADDRESS 0x75
#define  _OLEDC_WRITE_RAM       0x5C
#define  _OLEDC_READ_RAM        0x5D
#define  _OLEDC_SET_REMAP       0xA0
#define  _OLEDC_SET_START_LINE  0xA1
#define  _OLEDC_SET_OFFSET      0xA2
#define  _OLEDC_MODE_OFF        0xA4
#define  _OLEDC_MODE_ON         0xA5
#define  _OLEDC_MODE_NORMAL     0xA6
#define  _OLEDC_MODE_INVERSE    0xA7
#define  _OLEDC_FUNCTION        0xAB
#define  _OLEDC_SLEEP_ON        0xAE
#define  _OLEDC_SLEEP_OFF       0xAF
#define  _OLEDC_NOP             0xB0
#define  _OLEDC_SET_RESET_PRECH 0xB1
#define  _OLEDC_ENHANCEMENT     0xB2
#define  _OLEDC_CLOCK_DIV       0xB3
#define  _OLEDC_VSL             0xB4
#define  _OLEDC_GPIO            0xB5
#define  _OLEDC_SETSEC_PRECH    0xB6
#define  _OLEDC_GREY_SCALE      0xB8
#define  _OLEDC_LUT             0xB9
#define  _OLEDC_PRECH_VOL       0xBB
#define  _OLEDC_VCOMH           0xBE
#define  _OLEDC_CONTRAST        0xC1
#define  _OLEDC_MASTER_CONTRAST 0xC7
#define  _OLEDC_MUX_RATIO       0xCA
#define  _OLEDC_COMMAND_LOCK    0xFD
#define  _OLEDC_SCROLL_HOR      0x96
#define  _OLEDC_START_MOV       0x9E
#define  _OLEDC_STOP_MOV        0x9F
///@}

/* ------------------------------------------------------------------- MACROS */

/** @} */


#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup OLEDC_INIT Driver Initialization */              /** @{ */

void oledc_spiDriverInit();
                                                                                                                     
/** @defgroup OLEDC_FUNC Driver Functions */                   /** @{ */

/**
 * @brief OLED C Initialization
 *
 * Function initializes function pointers and perform setup of the SSD1351
 * must be called first
 */
void oledc_init( void );

/**
 * @brief OLED C Hardware Reset
 *
 * Performs hardware reset of the click board. Init function calling executin
 * of this function.
 */
void oledc_reset( void );

/**
 * @brief OLED C Enable
 *
 * @param[in] state ( 1 ON / 0 OFF )
 *
 * Enable or disable the display usinf EN pin on the clickboard.
 */
void oledc_enable( uint8_t state );

/**
 * @brief OLED C Command
 *
 * @param[in] command   valid command
 * @param[in] args      pointer to command argument
 * @param[in] args_len  arguments size in bytes
 *
 * Executes provided comman.
 */
void oledc_command( uint8_t command, uint8_t *args, uint16_t args_len );

/**
 * @brief OLED C Fill Scren
 *
 * @param[in] color     RGB color
 *
 * Fills whole screen with provided color.
 */
void oledc_fill_screen( uint16_t color );

/**
 * @brief OLED C Draw Rectangle
 *
 * @param[in] col_off   column offset from the left border of the screen
 * @param[in] row_off   row offset from the top border of the screen
 * @param[in] col_end   column end offset also counted from the left border
 * @param[in] row_end   row offset also counted from the top border
 * @param[in] color     RGB color
 *
 * Function allows you to draw retcangles which can be used to draw lines
 * clean specific regions of the screen.
 */
void oledc_rectangle( uint8_t col_off, uint8_t row_off,
                       uint8_t col_end, uint8_t row_end, uint16_t color );

/**
 * @brief OLED C Draw BMP Image
 *
 * @param[in] col_off   column offset from the left border of the screen
 * @param[in] row_off   row offset from the top border of the screen
 * @param[in] img       pointer to bmp image
 *
 * Function draws image on the screen. Provided image must be in .bmp format
 * with 6 bytes header size. Providing image of any other format may result in
 * unpredictable behaviour.
 */
void oledc_image( const uint8_t *img, uint8_t column_off, uint8_t row_off );

/**
 * @brief OLED C Draw Text
 *
 * @param[in] text      text string
 * @param[in] col_off   column offset from the left border of the screen
 * @param[in] row_off   row offset from the top border of the screen
 *
 * Function writes text on the screen.
 */
void oledc_text( uint8_t *text, uint16_t col_off, uint16_t row_off );

/**
 * @brief OLED C Font Setup
 *
 * @param[in] font          pointer to font definition
 * @param[in] color         text color
 * @param[in] orientation   text orientation
 *
 * Function setup the parameters needed for @c oled_c_text. Before first usage
 * of @c oled_c_text it is needed to call this function and setup all
 * parameters.
 */
void oledc_set_font( const uint8_t *font, uint16_t color, uint8_t orientation );

void Delay_ms(int val);

void box_area( uint8_t start_col, uint8_t start_row,
                      uint8_t end_col, uint8_t end_row,
                      uint16_t color );

/** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_OLED_C_STM.c
    @example Click_OLED_C_TIVA.c
    @example Click_OLED_C_CEC.c
    @example Click_OLED_C_KINETIS.c
    @example Click_OLED_C_MSP.c
    @example Click_OLED_C_PIC.c
    @example Click_OLED_C_PIC32.c
    @example Click_OLED_C_DSPIC.c
    @example Click_OLED_C_AVR.c
    @example Click_OLED_C_FT90x.c
    @example Click_OLED_C_STM.mbas
    @example Click_OLED_C_TIVA.mbas
    @example Click_OLED_C_CEC.mbas
    @example Click_OLED_C_KINETIS.mbas
    @example Click_OLED_C_MSP.mbas
    @example Click_OLED_C_PIC.mbas
    @example Click_OLED_C_PIC32.mbas
    @example Click_OLED_C_DSPIC.mbas
    @example Click_OLED_C_AVR.mbas
    @example Click_OLED_C_FT90x.mbas
    @example Click_OLED_C_STM.mpas
    @example Click_OLED_C_TIVA.mpas
    @example Click_OLED_C_CEC.mpas
    @example Click_OLED_C_KINETIS.mpas
    @example Click_OLED_C_MSP.mpas
    @example Click_OLED_C_PIC.mpas
    @example Click_OLED_C_PIC32.mpas
    @example Click_OLED_C_DSPIC.mpas
    @example Click_OLED_C_AVR.mpas
    @example Click_OLED_C_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __oledc_driver.h
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com
  All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.
4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
----------------------------------------------------------------------------- */