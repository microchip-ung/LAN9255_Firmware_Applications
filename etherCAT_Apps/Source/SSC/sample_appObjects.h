/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
* \addtogroup sample_app sample_app
* @{
*/

/**
\file sample_appObjects
\author ET9300Utilities.ApplicationHandler (Version 1.5.0.0) | EthercatSSC@beckhoff.com

\brief sample_app specific objects<br>
\brief NOTE : This file will be overwritten if a new object dictionary is generated!<br>
*/

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

#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
#define PROTO
#else
#define PROTO extern
#endif
/******************************************************************************
*                    Object 0x1600 : configure_uart process data mapping
******************************************************************************/
/**
* \addtogroup 0x1600 0x1600 | configure_uart process data mapping
* @{
* \brief Object 0x1600 (configure_uart process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x8000.1<br>
* SubIndex 2 - Reference to 0x8000.2<br>
* SubIndex 3 - Reference to 0x8000.3<br>
* SubIndex 4 - Reference to 0x8000.4<br>
* SubIndex 5 - Reference to 0x8000.5<br>
* SubIndex 6 - Padding entry (5Bit)<br>
* SubIndex 7 - Padding entry (16Bit)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1600[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x8000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x8000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Reference to 0x8000.3 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex4 - Reference to 0x8000.4 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex5 - Reference to 0x8000.5 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex6 - Padding entry (5Bit) */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex7 - Padding entry (16Bit) */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1600[] = "configure_uart process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000"
"SubIndex 005\000"
"SubIndex 006\000"
"SubIndex 007\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x8000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x8000.2 */
UINT32 SI3; /* Subindex3 - Reference to 0x8000.3 */
UINT32 SI4; /* Subindex4 - Reference to 0x8000.4 */
UINT32 SI5; /* Subindex5 - Reference to 0x8000.5 */
UINT32 SI6; /* Subindex6 - Padding entry (5Bit) */
UINT32 SI7; /* Subindex7 - Padding entry (16Bit) */
} OBJ_STRUCT_PACKED_END
TOBJ1600;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1600 Configure_uartProcessDataMapping0x1600
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={7,0x80000120,0x80000208,0x80000301,0x80000401,0x80000501,0x00000005,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1601 : Outputs process data mapping
******************************************************************************/
/**
* \addtogroup 0x1601 0x1601 | Outputs process data mapping
* @{
* \brief Object 0x1601 (Outputs process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x7010.1<br>
* SubIndex 2 - Reference to 0x7010.2<br>
* SubIndex 3 - Padding entry (8Bit)<br>
* SubIndex 4 - Padding entry (16Bit)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1601[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x7010.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x7010.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Padding entry (8Bit) */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex4 - Padding entry (16Bit) */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1601[] = "Outputs process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x7010.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x7010.2 */
UINT32 SI3; /* Subindex3 - Padding entry (8Bit) */
UINT32 SI4; /* Subindex4 - Padding entry (16Bit) */
} OBJ_STRUCT_PACKED_END
TOBJ1601;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1601 OutputsProcessDataMapping0x1601
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={4,0x70100120,0x70100208,0x00000008,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A00 : Inputs process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A00 0x1A00 | Inputs process data mapping
* @{
* \brief Object 0x1A00 (Inputs process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6000.1<br>
* SubIndex 2 - Reference to 0x6000.2<br>
* SubIndex 3 - Padding entry (8Bit)<br>
* SubIndex 4 - Padding entry (16Bit)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A00[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6000.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Reference to 0x6000.2 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Padding entry (8Bit) */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex4 - Padding entry (16Bit) */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A00[] = "Inputs process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6000.1 */
UINT32 SI2; /* Subindex2 - Reference to 0x6000.2 */
UINT32 SI3; /* Subindex3 - Padding entry (8Bit) */
UINT32 SI4; /* Subindex4 - Padding entry (16Bit) */
} OBJ_STRUCT_PACKED_END
TOBJ1A00;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A00 InputsProcessDataMapping0x1A00
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={4,0x60000120,0x60000208,0x00000008,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1A02 : uart_status process data mapping
******************************************************************************/
/**
* \addtogroup 0x1A02 0x1A02 | uart_status process data mapping
* @{
* \brief Object 0x1A02 (uart_status process data mapping) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Reference to 0x6021.1<br>
* SubIndex 2 - Padding entry (7Bit)<br>
* SubIndex 3 - Padding entry (8Bit)<br>
* SubIndex 4 - Padding entry (16Bit)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1A02[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex1 - Reference to 0x6021.1 */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex2 - Padding entry (7Bit) */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }, /* Subindex3 - Padding entry (8Bit) */
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ }}; /* Subindex4 - Padding entry (16Bit) */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x1A02[] = "uart_status process data mapping\000"
"SubIndex 001\000"
"SubIndex 002\000"
"SubIndex 003\000"
"SubIndex 004\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 SI1; /* Subindex1 - Reference to 0x6021.1 */
UINT32 SI2; /* Subindex2 - Padding entry (7Bit) */
UINT32 SI3; /* Subindex3 - Padding entry (8Bit) */
UINT32 SI4; /* Subindex4 - Padding entry (16Bit) */
} OBJ_STRUCT_PACKED_END
TOBJ1A02;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1A02 Uart_statusProcessDataMapping0x1A02
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={4,0x60210101,0x00000007,0x00000008,0x00000010}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C12 : SyncManager 2 assignment
******************************************************************************/
/**
* \addtogroup 0x1C12 0x1C12 | SyncManager 2 assignment
* @{
* \brief Object 0x1C12 (SyncManager 2 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C12[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C12[] = "SyncManager 2 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[2];  /**< \brief Subindex 1 - 2 */
} OBJ_STRUCT_PACKED_END
TOBJ1C12;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C12 sRxPDOassign
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={2,{0x1600,0x1601}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x1C13 : SyncManager 3 assignment
******************************************************************************/
/**
* \addtogroup 0x1C13 0x1C13 | SyncManager 3 assignment
* @{
* \brief Object 0x1C13 (SyncManager 3 assignment) definition
*/
#ifdef _OBJD_
/**
* \brief Entry descriptions<br>
* 
* Subindex 0<br>
* Subindex 1 - n (the same entry description is used)<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1C13[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ }};

/**
* \brief Object name definition<br>
* For Subindex 1 to n the syntax 'Subindex XXX' is used
*/
OBJCONST UCHAR OBJMEM aName0x1C13[] = "SyncManager 3 assignment\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16   u16SubIndex0;  /**< \brief Subindex 0 */
UINT16 aEntries[2];  /**< \brief Subindex 1 - 2 */
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ1C13 sTxPDOassign
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={2,{0x1A00,0x1A02}}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6000 : Inputs
******************************************************************************/
/**
* \addtogroup 0x6000 0x6000 | Inputs
* @{
* \brief Object 0x6000 (Inputs) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Counter<br>
* SubIndex 2 - uart_read_buffer<br>
* SubIndex 3<br>
* SubIndex 4<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - Counter */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex2 - uart_read_buffer */
{ DEFTYPE_NULL , 0x08 ,  OBJACCESS_TXPDOMAPPING }, /* Subindex3 */
{ DEFTYPE_NULL , 0x10 ,  OBJACCESS_TXPDOMAPPING }}; /* Subindex4 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6000[] = "Inputs\000"
"Counter\000"
"uart_read_buffer\000"
"\000"
"\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 Counter; /* Subindex1 - Counter */
UINT8 Uart_read_buffer; /* Subindex2 - uart_read_buffer */
ALIGN8(SI3) /* Subindex3 */
UINT16 SI4; /* Subindex4 */
} OBJ_STRUCT_PACKED_END
TOBJ6000;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6000 Inputs0x6000
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={2,0x00000000,0x00,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x6021 : uart_status
******************************************************************************/
/**
* \addtogroup 0x6021 0x6021 | uart_status
* @{
* \brief Object 0x6021 (uart_status) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - rx_ready<br>
* SubIndex 2<br>
* SubIndex 3<br>
* SubIndex 4<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6021[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }, /* Subindex1 - rx_ready */
{ DEFTYPE_NULL , 0x07 ,  OBJACCESS_TXPDOMAPPING }, /* Subindex2 */
{ DEFTYPE_NULL , 0x08 ,  OBJACCESS_TXPDOMAPPING }, /* Subindex3 */
{ DEFTYPE_NULL , 0x10 ,  OBJACCESS_TXPDOMAPPING }}; /* Subindex4 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x6021[] = "uart_status\000"
"rx_ready\000"
"\000"
"\000"
"\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
BOOLEAN(Rx_ready); /* Subindex1 - rx_ready */
ALIGN7(SI2) /* Subindex2 */
ALIGN8(SI3) /* Subindex3 */
UINT16 SI4; /* Subindex4 */
} OBJ_STRUCT_PACKED_END
TOBJ6021;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ6021 Uart_status0x6021
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={1,0x00,0,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x7010 : Outputs
******************************************************************************/
/**
* \addtogroup 0x7010 0x7010 | Outputs
* @{
* \brief Object 0x7010 (Outputs) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - Trigger<br>
* SubIndex 2 - uart_write_buffer<br>
* SubIndex 3<br>
* SubIndex 4<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7010[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - Trigger */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - uart_write_buffer */
{ DEFTYPE_NULL , 0x08 ,  OBJACCESS_RXPDOMAPPING }, /* Subindex3 */
{ DEFTYPE_NULL , 0x10 ,  OBJACCESS_RXPDOMAPPING }}; /* Subindex4 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x7010[] = "Outputs\000"
"Trigger\000"
"uart_write_buffer\000"
"\000"
"\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 Trigger; /* Subindex1 - Trigger */
UINT8 Uart_write_buffer; /* Subindex2 - uart_write_buffer */
ALIGN8(SI3) /* Subindex3 */
UINT16 SI4; /* Subindex4 */
} OBJ_STRUCT_PACKED_END
TOBJ7010;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ7010 Outputs0x7010
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={2,0x00000000,0x00,0,0}
#endif
;
/** @}*/



/******************************************************************************
*                    Object 0x8000 : configure_uart
******************************************************************************/
/**
* \addtogroup 0x8000 0x8000 | configure_uart
* @{
* \brief Object 0x8000 (configure_uart) definition
*/
#ifdef _OBJD_
/**
* \brief Object entry descriptions<br>
* <br>
* SubIndex 0<br>
* SubIndex 1 - buadrate<br>
* SubIndex 2 - parity and data selection bits<br>
* SubIndex 3 - enable uart<br>
* SubIndex 4 - tx_ready<br>
* SubIndex 5 - stop selection bit<br>
* SubIndex 6<br>
* SubIndex 7<br>
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8000[] = {
{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex1 - buadrate */
{ DEFTYPE_UNSIGNED8 , 0x08 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex2 - parity and data selection bits */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex3 - enable uart */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex4 - tx_ready */
{ DEFTYPE_BOOLEAN , 0x01 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }, /* Subindex5 - stop selection bit */
{ DEFTYPE_NULL , 0x05 ,  OBJACCESS_RXPDOMAPPING }, /* Subindex6 */
{ DEFTYPE_NULL , 0x10 ,  OBJACCESS_RXPDOMAPPING }}; /* Subindex7 */

/**
* \brief Object/Entry names
*/
OBJCONST UCHAR OBJMEM aName0x8000[] = "configure_uart\000"
"buadrate\000"
"parity and data selection bits\000"
"enable uart\000"
"tx_ready\000"
"stop selection bit\000"
"\000"
"\000\377";
#endif //#ifdef _OBJD_

#ifndef _SAMPLE_APP_OBJECTS_H_
/**
* \brief Object structure
*/
typedef struct OBJ_STRUCT_PACKED_START {
UINT16 u16SubIndex0;
UINT32 Buadrate; /* Subindex1 - buadrate */
UINT8 ParityAndDataSelectionBits; /* Subindex2 - parity and data selection bits */
BOOLEAN(EnableUart); /* Subindex3 - enable uart */
BOOLEAN(Tx_ready); /* Subindex4 - tx_ready */
BOOLEAN(StopSelectionBit); /* Subindex5 - stop selection bit */
ALIGN5(SI6) /* Subindex6 */
UINT16 SI7; /* Subindex7 */
} OBJ_STRUCT_PACKED_END
TOBJ8000;
#endif //#ifndef _SAMPLE_APP_OBJECTS_H_

/**
* \brief Object variable
*/
PROTO TOBJ8000 Configure_uart0x8000
#if defined(_SAMPLE_APP_) && (_SAMPLE_APP_ == 1)
={5,0x00000096,0x00,0x01,0x00,0x00,0,0}
#endif
;
/** @}*/







#ifdef _OBJD_
TOBJECT    OBJMEM ApplicationObjDic[] = {
/* Object 0x1600 */
{NULL , NULL ,  0x1600 , {DEFTYPE_PDOMAPPING , 7 | (OBJCODE_REC << 8)} , asEntryDesc0x1600 , aName0x1600 , &Configure_uartProcessDataMapping0x1600 , NULL , NULL , 0x0000 },
/* Object 0x1601 */
{NULL , NULL ,  0x1601 , {DEFTYPE_PDOMAPPING , 4 | (OBJCODE_REC << 8)} , asEntryDesc0x1601 , aName0x1601 , &OutputsProcessDataMapping0x1601 , NULL , NULL , 0x0000 },
/* Object 0x1A00 */
{NULL , NULL ,  0x1A00 , {DEFTYPE_PDOMAPPING , 4 | (OBJCODE_REC << 8)} , asEntryDesc0x1A00 , aName0x1A00 , &InputsProcessDataMapping0x1A00 , NULL , NULL , 0x0000 },
/* Object 0x1A02 */
{NULL , NULL ,  0x1A02 , {DEFTYPE_PDOMAPPING , 4 | (OBJCODE_REC << 8)} , asEntryDesc0x1A02 , aName0x1A02 , &Uart_statusProcessDataMapping0x1A02 , NULL , NULL , 0x0000 },
/* Object 0x1C12 */
{NULL , NULL ,  0x1C12 , {DEFTYPE_UNSIGNED16 , 2 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C12 , aName0x1C12 , &sRxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x1C13 */
{NULL , NULL ,  0x1C13 , {DEFTYPE_UNSIGNED16 , 2 | (OBJCODE_ARR << 8)} , asEntryDesc0x1C13 , aName0x1C13 , &sTxPDOassign , NULL , NULL , 0x0000 },
/* Object 0x6000 */
{NULL , NULL ,  0x6000 , {DEFTYPE_RECORD , 4 | (OBJCODE_REC << 8)} , asEntryDesc0x6000 , aName0x6000 , &Inputs0x6000 , NULL , NULL , 0x0000 },
/* Object 0x6021 */
{NULL , NULL ,  0x6021 , {DEFTYPE_RECORD , 4 | (OBJCODE_REC << 8)} , asEntryDesc0x6021 , aName0x6021 , &Uart_status0x6021 , NULL , NULL , 0x0000 },
/* Object 0x7010 */
{NULL , NULL ,  0x7010 , {DEFTYPE_RECORD , 4 | (OBJCODE_REC << 8)} , asEntryDesc0x7010 , aName0x7010 , &Outputs0x7010 , NULL , NULL , 0x0000 },
/* Object 0x8000 */
{NULL , NULL ,  0x8000 , {DEFTYPE_RECORD , 7 | (OBJCODE_REC << 8)} , asEntryDesc0x8000 , aName0x8000 , &Configure_uart0x8000 , NULL , NULL , 0x0000 },
{NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_
#undef PROTO

/** @}*/
#define _SAMPLE_APP_OBJECTS_H_
