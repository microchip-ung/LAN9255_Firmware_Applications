/*
    __oledc_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "oledc_driver.h"
#include "plib_sercom4_spi_master.h"
#include "plib_port.h"
#include "app.h"

static uint8_t _OLEDC_DEFAULT_MUX_RATIO      = 95;
static uint8_t _OLEDC_DEFAULT_START_LINE     = 0x80;
static uint8_t _OLEDC_DEFAULT_OFFSET         = 0x20;

static uint8_t _OLEDC_DEFAULT_OLED_LOCK      = 0x12;
static uint8_t _OLEDC_DEFAULT_CMD_LOCK       = 0xB1;
static uint8_t _OLEDC_DEFAULT_DIVSET         = 0xF1;
static uint8_t _OLEDC_DEFAULT_PRECHARGE      = 0x32;
static uint8_t _OLEDC_DEFAULT_VCOMH          = 0x05;
static uint8_t _OLEDC_DEFAULT_MASTER_CONT    = 0xCF;
static uint8_t _OLEDC_DEFAULT_PRECHARGE_2    = 0x01;

static uint8_t cols[ 2 ]    = { _OLEDC_COL_OFF, _OLEDC_COL_OFF + 95 };          
static uint8_t rows[ 2 ]    = { _OLEDC_ROW_OFF, _OLEDC_ROW_OFF + 95 };

static uint8_t _OLEDC_DEFAULT_REMAP = _OLEDC_RMP_INC_HOR | _OLEDC_RMP_COLOR_REV |\
  _OLEDC_RMP_SEQ_RGB | _OLEDC_RMP_SCAN_REV |\
 _OLEDC_RMP_SPLIT_ENABLE | _OLEDC_COLOR_65K;

static  uint8_t _OLEDC_DEFAULT_VSL[ 3 ]       = { 0xA0, 0xB5, 0x55 };
static  uint8_t _OLEDC_DEFAULT_CONTRAST[ 3 ]  = { 0x8A, 0x51, 0x8A };

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __OLEDC_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static const uint8_t*   _font;
static uint16_t         _font_color;
static uint8_t          _font_orientation;
static uint16_t         _font_first_char;
static uint16_t         _font_last_char;
static uint16_t         _font_height;
static uint16_t         x_cord;
static uint16_t         y_cord;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

static void pixel( uint8_t col, uint8_t row, uint16_t color );

static void character( uint16_t ch );


static void draw_area( uint8_t start_col, uint8_t start_row,
                       uint8_t end_col, uint8_t end_row,
                       const uint8_t *img );
                                           

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */

static void pixel( uint8_t col, uint8_t row, uint16_t color )
{
    uint8_t cmd       = _OLEDC_WRITE_RAM;
    uint8_t clr[ 2 ]  = { 0 };

    if( ( col > _OLEDC_SCREEN_WIDTH ) || ( row > _OLEDC_SCREEN_HEIGHT ) )
        return;

    cols[ 0 ] = _OLEDC_COL_OFF + col;
    cols[ 1 ] = _OLEDC_COL_OFF + col;
    rows[ 0 ] = _OLEDC_ROW_OFF + row;
    rows[ 1 ] = _OLEDC_ROW_OFF + row;
    clr[ 0 ] |= color >> 8;
    clr[ 1 ] |= color & 0x00FF;

    oledc_command( _OLEDC_SET_COL_ADDRESS, cols, 2 );
    oledc_command( _OLEDC_SET_ROW_ADDRESS, rows, 2 );
    
    MIKRO_BUS_CS_Clear();
    MIKRO_BUS_PWM_DC_Clear();
    SERCOM4_SPI_Write( &cmd, 1 );
    SPI_SYNC_WAIT();
    MIKRO_BUS_PWM_DC_Set();
    SERCOM4_SPI_Write( clr, 2 );  
    SPI_SYNC_WAIT();
    MIKRO_BUS_CS_Set();
}

static void character( uint16_t ch )
{
    uint8_t     ch_width = 0;
    uint8_t     x_cnt;
    uint8_t     y_cnt;
    uint16_t    x = 0;
    uint16_t    y = 0;
    uint16_t    tmp;
    uint8_t     temp = 0;
    uint8_t     mask = 0;
    uint32_t    offset;
    const uint8_t *ch_table;
    const uint8_t *ch_bitmap;

    if( ch < _font_first_char )
        return;

    if( ch > _font_last_char )
        return;

    offset = 0;
    tmp = (ch - _font_first_char) << 2;
    ch_table = _font + 8 + tmp;
    ch_width = *ch_table;

    offset = (uint32_t)ch_table[1] + ((uint32_t)ch_table[2] << 8) + ((uint32_t)ch_table[3] << 16);

    ch_bitmap = _font + offset;

    if( ( _font_orientation == _OLEDC_FO_HORIZONTAL ) ||
        ( _font_orientation == _OLEDC_FO_VERTICAL_COLUMN ) )
    {
        y = y_cord;
        for (y_cnt = 0; y_cnt < _font_height; y_cnt++)
        {
            x = x_cord;
            mask = 0;
            for( x_cnt = 0; x_cnt < ch_width; x_cnt++ )
            {
                if( !mask )
                {
                    temp = *ch_bitmap++;
                    mask = 0x01;
                }

                if( temp & mask )
                    pixel( x, y, _font_color );

                x++;
                mask <<= 1;
            }
            y++;
        }

        if ( _font_orientation == _OLEDC_FO_HORIZONTAL )
            x_cord = x + 1;
        else
            y_cord = y;
    }
    else
    {
        y = x_cord;

        for( y_cnt = 0; y_cnt < _font_height; y_cnt++ )
        {
            x = y_cord;
            mask = 0;

            for( x_cnt = 0; x_cnt < ch_width; x_cnt++ )
            {
                if( mask == 0 )
                {
                    temp = *ch_bitmap++;
                    mask = 0x01;
                }

                if( temp & mask )
                {
                    pixel( y, x, _font_color );
                }

                x--;
                mask <<= 1;
            }
            y++;
        }
        y_cord = x - 1;
    }
}
void box_area( uint8_t start_col, uint8_t start_row, uint8_t end_col, uint8_t end_row, uint16_t color )
{
    uint8_t   cmd       = _OLEDC_WRITE_RAM;
    uint16_t  cnt       = ( end_col - start_col ) * ( end_row - start_row );
    uint8_t   clr[ 2 ]  = { 0 };

    if( ( start_col > _OLEDC_SCREEN_WIDTH ) ||
        ( end_col > _OLEDC_SCREEN_WIDTH ) )
        return;

    if( ( start_row > _OLEDC_SCREEN_HEIGHT ) ||
        ( end_row > _OLEDC_SCREEN_HEIGHT ) )
        return;

    if( ( end_col < start_col ) ||
        ( end_row < start_row ) )
        return;

    cols[ 0 ] = _OLEDC_COL_OFF + start_col;
    cols[ 1 ] = _OLEDC_COL_OFF + end_col - 1;
    rows[ 0 ] = _OLEDC_ROW_OFF + start_row;
    rows[ 1 ] = _OLEDC_ROW_OFF + end_row - 1;
    clr[ 0 ] |= color >> 8;
    clr[ 1 ] |= color & 0x00FF;

    oledc_command( _OLEDC_SET_COL_ADDRESS, cols, 2 );
    oledc_command( _OLEDC_SET_ROW_ADDRESS, rows, 2 );
    MIKRO_BUS_CS_Clear();
    MIKRO_BUS_PWM_DC_Clear();
    SERCOM4_SPI_Write( &cmd, 1 );
    SPI_SYNC_WAIT();
    MIKRO_BUS_PWM_DC_Set();
    
    while( cnt-- ) {
        SERCOM4_SPI_Write( clr, 2 );
        SPI_SYNC_WAIT();
    }
    MIKRO_BUS_CS_Set();
}

static void draw_area( uint8_t start_col, uint8_t start_row, uint8_t end_col, uint8_t end_row, const uint8_t *img )
{
    uint16_t    tmp  = 0;
    uint8_t     cmd  = _OLEDC_WRITE_RAM;
    uint8_t     frb  = 0;
    uint8_t     srb  = 0;
    uint16_t    cnt  = ( end_col - start_col ) * ( end_row - start_row );
    
    const uint8_t*  ptr = img + _OLEDC_IMG_HEAD;

    if( ( start_col > _OLEDC_SCREEN_WIDTH ) ||
        ( end_col > _OLEDC_SCREEN_WIDTH ) )
        return;

    if( ( start_row > _OLEDC_SCREEN_HEIGHT ) ||
        ( end_row > _OLEDC_SCREEN_HEIGHT ) )
        return;

    if( ( end_col < start_col ) ||
        ( end_row < start_row ) )
        return;

    cols[ 0 ] = _OLEDC_COL_OFF + start_col;
    cols[ 1 ] = _OLEDC_COL_OFF + end_col - 1;
    rows[ 0 ] = _OLEDC_ROW_OFF + start_row;
    rows[ 1 ] = _OLEDC_ROW_OFF + end_row - 1;

    oledc_command( _OLEDC_SET_COL_ADDRESS, cols, 2 );
    oledc_command( _OLEDC_SET_ROW_ADDRESS, rows, 2 );
    MIKRO_BUS_CS_Clear();
    MIKRO_BUS_PWM_DC_Clear();
    SERCOM4_SPI_Write( &cmd, 1 );
    SPI_SYNC_WAIT();
    MIKRO_BUS_PWM_DC_Set();
    
    while( cnt-- )
    {
        frb = ptr[ tmp + 1 ];
        srb = ptr[ tmp ];
        SERCOM4_SPI_Write( &frb, 1 );
        SPI_SYNC_WAIT();
        SERCOM4_SPI_Write( &srb, 1 );
        SPI_SYNC_WAIT();
        tmp += 2;
    }
    MIKRO_BUS_CS_Set();
}


/* --------------------------------------------------------- PUBLIC FUNCTIONS */

void oledc_spiDriverInit()
{
    MIKRO_BUS_AN_R_WC_OutputEnable();
    MIKRO_BUS_RST_OutputEnable();
    MIKRO_BUS_CS_OutputEnable();
    MIKRO_BUS_PWM_DC_OutputEnable();
    MIKRO_BUS_INT_EN_OutputEnable();

    MIKRO_BUS_CS_Set();
    MIKRO_BUS_AN_R_WC_Clear();
    MIKRO_BUS_PWM_DC_Set();
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void oledc_enable( uint8_t state )
{
    if (state) {
        MIKRO_BUS_INT_EN_Set();
    } else {
        MIKRO_BUS_INT_EN_Clear();
    }
}

void oledc_reset( void )
{
    MIKRO_BUS_RST_Set();
    Delay_ms(1);
    MIKRO_BUS_RST_Clear();
    Delay_ms(1);
    MIKRO_BUS_RST_Set();
    Delay_ms(100);
}


void oledc_command( uint8_t command, uint8_t *args, uint16_t args_len )
{
    uint8_t *ptr = args;

    MIKRO_BUS_CS_Clear();
    MIKRO_BUS_PWM_DC_Clear();
    SERCOM4_SPI_Write( &command, 1 );
    SPI_SYNC_WAIT();
    MIKRO_BUS_PWM_DC_Set();
    if( args_len ) {
        SERCOM4_SPI_Write( ptr, args_len );
        SPI_SYNC_WAIT();
    }
    MIKRO_BUS_CS_Set();
}

void oledc_init()
{
    oledc_enable(1); 
    oledc_reset();

    /* Unlock display and turn off */
    oledc_command( _OLEDC_COMMAND_LOCK,    &_OLEDC_DEFAULT_OLED_LOCK,     1 );
    oledc_command( _OLEDC_COMMAND_LOCK,    &_OLEDC_DEFAULT_CMD_LOCK,      1 );
    oledc_command( _OLEDC_SLEEP_ON,        0,                      0 );

    /* Setup SSD1351 */
    oledc_command( _OLEDC_SET_REMAP,       &_OLEDC_DEFAULT_REMAP,         1 );
    oledc_command( _OLEDC_MUX_RATIO,       &_OLEDC_DEFAULT_MUX_RATIO,     1 );
    oledc_command( _OLEDC_SET_START_LINE,  &_OLEDC_DEFAULT_START_LINE,    1 );
    oledc_command( _OLEDC_SET_OFFSET,      &_OLEDC_DEFAULT_OFFSET,        1 );
    oledc_command( _OLEDC_VCOMH,           &_OLEDC_DEFAULT_VCOMH,         1 );
    oledc_command( _OLEDC_CLOCK_DIV,       &_OLEDC_DEFAULT_DIVSET,        1 );
    oledc_command( _OLEDC_SET_RESET_PRECH, &_OLEDC_DEFAULT_PRECHARGE,     1 );
    oledc_command( _OLEDC_SETSEC_PRECH,    &_OLEDC_DEFAULT_PRECHARGE_2,   1 );
    oledc_command( _OLEDC_MASTER_CONTRAST, &_OLEDC_DEFAULT_MASTER_CONT,   1 );
    oledc_command( _OLEDC_CONTRAST,        _OLEDC_DEFAULT_CONTRAST,       3 );
    oledc_command( _OLEDC_VSL,             _OLEDC_DEFAULT_VSL,            3 );

    /* Set normal mode and turn on display */
    oledc_command( _OLEDC_MODE_NORMAL, 0, 0 );
    oledc_command( _OLEDC_SLEEP_OFF,   0, 0 );

    oledc_fill_screen( 0 );
}


void oledc_fill_screen( uint16_t color )
{
    box_area( 0, 0, 96, 96, color );
}

void oledc_rectangle( uint8_t col_off, uint8_t row_off, uint8_t col_end, uint8_t row_end, uint16_t color )
{
    box_area( col_off, row_off, col_end, row_end, color );
}

void oledc_image( const uint8_t* img, uint8_t col_off, uint8_t row_off )
{
    const uint8_t *ptr = img;
    draw_area( col_off, row_off, col_off + ptr[2], row_off + ptr[4], ptr );
}

void oledc_text( uint8_t *text, uint16_t x, uint16_t y )
{
    uint8_t *ptr = text;

    if( ( x >= _OLEDC_SCREEN_WIDTH ) || (y >= _OLEDC_SCREEN_HEIGHT ) )
        return;

    x_cord = x;
    y_cord = y;

    while( *ptr )
        character( *ptr++ );
}

void oledc_set_font( const uint8_t *font, uint16_t color, uint8_t orientation )
{
    _font               = font;
    _font_first_char    = font[2] + (font[3] << 8);
    _font_last_char     = font[4] + (font[5] << 8);
    _font_height        = font[6];
    _font_color         = color;
    _font_orientation   = orientation ;
}

void Delay_ms(int delay)
{
    int i, j;

    while(delay--) {
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 10; j++);
        }
    }
}

/* -------------------------------------------------------------------------- */
/*
  __oledc_driver.c

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