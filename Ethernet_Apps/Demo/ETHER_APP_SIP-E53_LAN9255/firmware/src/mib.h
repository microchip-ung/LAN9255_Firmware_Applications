/*******************************************************************
* FileName: mib.h
* This file was automatically generated on Fri Feb 05 2021 01:34:51 
* by mib2bib utility.
* This file contains 'C' defines for dynamic OIDs and AgentID only.
* Do not modify this file manually.
* Include this file in your application source file that handles SNMP callbacks and TRAP.

*******************************************************************/
/*****************************************************************************
Copyright (C) 2012-2018 Microchip Technology Inc. and its subsidiaries.

 Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software
and any derivatives exclusively with Microchip products. It is your
responsibility to comply with third party license terms applicable to your
use of third party software (including open source software) that may 
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
PURPOSE.
IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/
#define MICROCHIP      255		// This is an Agent ID for use in SNMPNotify() only.
#define SYS_UP_TIME      250			//43.6.1.2.1.1.3 :  READONLY TIME_TICKS.
#define IF_NUMBER      100			//43.6.1.2.1.2.1 :  READONLY BYTE.
#define IF_INDEX      101			//43.6.1.2.1.2.2.1.1 :  READONLY BYTE.
#define IF_DESCR      102			//43.6.1.2.1.2.2.1.2 :  READONLY ASCII_STRING.
#define IF_TYPE      103			//43.6.1.2.1.2.2.1.3 :  READONLY BYTE.
#define IF_MTU      104			//43.6.1.2.1.2.2.1.4 :  READONLY DWORD.
#define IF_SPEED      105			//43.6.1.2.1.2.2.1.5 :  READONLY GAUGE32.
#define IF_PHYSADDRESS      106			//43.6.1.2.1.2.2.1.6 :  READONLY ASCII_STRING.
#define IF_ADMIN_STATUS      107			//43.6.1.2.1.2.2.1.7 :  READWRITE BYTE.
#define IF_OPER_STATUS      108			//43.6.1.2.1.2.2.1.8 :  READONLY BYTE.
#define IF_LAST_CHANGE      109			//43.6.1.2.1.2.2.1.9 :  READONLY TIME_TICKS.
#define IF_IN_OCTETS      110			//43.6.1.2.1.2.2.1.10 :  READONLY COUNTER32.
#define IF_IN_UCAST_PKTS      111			//43.6.1.2.1.2.2.1.11 :  READONLY COUNTER32.
#define IF_IN_NUCAST_PKTS      112			//43.6.1.2.1.2.2.1.12 :  READONLY COUNTER32.
#define IF_IN_DISCARDS      113			//43.6.1.2.1.2.2.1.13 :  READONLY COUNTER32.
#define IF_IN_ERRORS      114			//43.6.1.2.1.2.2.1.14 :  READONLY COUNTER32.
#define IF_IN_UNKNOWN_PROTOS      115			//43.6.1.2.1.2.2.1.15 :  READONLY COUNTER32.
#define IF_OUT_OCTETS      116			//43.6.1.2.1.2.2.1.16 :  READONLY COUNTER32.
#define IF_OUT_UCAST_PKTS      117			//43.6.1.2.1.2.2.1.17 :  READONLY COUNTER32.
#define IF_OUT_NUCAST_PKTS      118			//43.6.1.2.1.2.2.1.18 :  READONLY COUNTER32.
#define IF_OUT_DISCARDS      119			//43.6.1.2.1.2.2.1.19 :  READONLY COUNTER32.
#define IF_OUT_ERRORS      120			//43.6.1.2.1.2.2.1.20 :  READONLY COUNTER32.
#define IF_OUT_QLEN      121			//43.6.1.2.1.2.2.1.21 :  READONLY GAUGE32.
#define IF_SPECIFIC      122			//43.6.1.2.1.2.2.1.22 :  READONLY DWORD.
#define SNMP_DEMO_TRAP      500			//43.6.1.4.1.17095.1.0.1 :  READONLY BYTE.
#define TRAP_RECEIVER_ID      1			//43.6.1.4.1.17095.1.2.1.1.1 :  READWRITE BYTE.
#define TRAP_RECEIVER_ENABLED      2			//43.6.1.4.1.17095.1.2.1.1.2 :  READWRITE BYTE.
#define TRAP_RECEIVER_IP      3			//43.6.1.4.1.17095.1.2.1.1.3 :  READWRITE IP_ADDRESS.
#define TRAP_COMMUNITY      4			//43.6.1.4.1.17095.1.2.1.1.4 :  READWRITE ASCII_STRING.
#define IPV6_TRAP_RECEIVER_ID      31			//43.6.1.4.1.17095.1.2.2.1.1 :  READWRITE BYTE.
#define IPV6_TRAP_ENABLED      32			//43.6.1.4.1.17095.1.2.2.1.2 :  READWRITE BYTE.
#define IPV6_TRAP_RECEIVER_IP      33			//43.6.1.4.1.17095.1.2.2.1.3 :  READWRITE OCTET_STRING.
#define IPV6_TRAP_COMMUNITY      34			//43.6.1.4.1.17095.1.2.2.1.4 :  READWRITE ASCII_STRING.
#define LED_D6      5			//43.6.1.4.1.17095.1.3.1 :  READWRITE BYTE.
#define PUSH_BUTTON      6			//43.6.1.4.1.17095.1.3.2 :  READONLY BYTE.
#define USM_INDEX_ID      11			//43.6.1.4.1.17095.1.4.1.1.1 :  READONLY BYTE.
#define USER_SECURITY_NAME      12			//43.6.1.4.1.17095.1.4.1.1.2 :  READWRITE ASCII_STRING.
#define USM_AUTH_PROT      13			//43.6.1.4.1.17095.1.4.1.1.3 :  READWRITE BYTE.
#define USM_AUTH_KEY      14			//43.6.1.4.1.17095.1.4.1.1.4 :  READWRITE ASCII_STRING.
#define USM_PRIV_PROT      15			//43.6.1.4.1.17095.1.4.1.1.5 :  READWRITE BYTE.
#define USM_PRIV_KEY      16			//43.6.1.4.1.17095.1.4.1.1.6 :  READWRITE ASCII_STRING.
#define SNMP_TARGET_INDEX_ID      17			//43.6.1.4.1.17095.1.5.1.1.1 :  READONLY BYTE.
#define SNMP_TARGET_MP_MODEL      18			//43.6.1.4.1.17095.1.5.1.1.2 :  READWRITE BYTE.
#define SNMP_TARGET_SECURITY_MODEL      19			//43.6.1.4.1.17095.1.5.1.1.3 :  READWRITE BYTE.
#define SNMP_TARGET_SECURITY_NAME      20			//43.6.1.4.1.17095.1.5.1.1.4 :  READWRITE ASCII_STRING.
#define SNMP_TARGET_SECURITY_LEVEL      21			//43.6.1.4.1.17095.1.5.1.1.5 :  READWRITE BYTE.
#define ENGINE_ID      249			//43.6.1.6.3.10.2.1.1 :  READONLY ASCII_STRING.
#define ENGINE_BOOT      248			//43.6.1.6.3.10.2.1.2 :  READONLY DWORD.
#define ENGINE_TIME      247			//43.6.1.6.3.10.2.1.3 :  READONLY DWORD.
#define ENGINE_MAX_MSG      246			//43.6.1.6.3.10.2.1.4 :  READONLY WORD.
