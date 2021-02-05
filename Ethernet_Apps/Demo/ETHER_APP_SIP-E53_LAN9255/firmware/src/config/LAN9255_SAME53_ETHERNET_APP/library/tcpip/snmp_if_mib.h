/*******************************************************************************
  SNMP Definitions for the Microchip TCP/IP Stack

  Company:
    Microchip Technology Inc.
    
  File Name:
    snmp_if_mib.h

  Summary:
    Simple Network Management Protocol(SNMP) IF-MIB API header file.
    
  Description:
    Simple Network Management Protocol (SNMP) IF-MIB is a interface mib object.
*******************************************************************************/
//DOM-IGNORE-BEGIN
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








//DOM-IGNORE-END

#ifndef __SNMP_IF_MIB_H
#define __SNMP_IF_MIB_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END  

// *****************************************************************************
// *****************************************************************************
// Section: SNMP Agent IF-MIB OBJECT Macros and Definition
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* This Macro is used for both SNMP IF_TYPE variable processing to indicate 
   the SNMP IF_TYPE value.  */
#define SNMP_IFMIB_ETH_MAC_TYPE (6)

/* This Macro is used for both SNMP IF_SPEED variable processing to indicate 
   the SNMP IF_SPEED value for 10Mbps.  */
#define SNMP_IFMIB_ETH_SPEED_10_MBPS   (10000000)

/* This Macro is used for both SNMP IF_SPEED variable processing to indicate 
   the SNMP IF_SPEED value for 100Mbps.  */
#define SNMP_IFMIB_ETH_SPEED_100_MBPS       (100000000)
        
#define SNMP_IFMIB_LINKUP                   (1)

#define SNMP_IFMIB_LINKDOWN                 (0)
        
#define SNMP_IFMIB_ADMINSTATUS_LINKDOWN     (2)
#define SNMP_IFMIB_ADMINSTATUS_LINKUP       (1)
#define SNMP_IFMIB_ADMINSTATUS_LINKTESTING  (3)
        
#define SNMP_IFMIB_ETH_RX_OCTECTS   (20)
#define SNMP_IFMIB_ETH_RX_FRAME     (22)
#define SNMP_IFMIB_ETH_RX_BCAST     (23)
#define SNMP_IFMIB_ETH_RX_MCAST     (24)
#define SNMP_IFMIB_ETH_TX_OCTECTS   (0)
#define SNMP_IFMIB_ETH_TX_FRAME     (2)
#define SNMP_IFMIB_ETH_TX_BCAST     (3)
#define SNMP_IFMIB_ETH_TX_MCAST     (4)
        

/**
 * Statistic Structure of hardware register in GMAC for SNMP IF-MIB.
 */
        
typedef struct
{	
	/** RX Octet count */
	uint32_t nRxOctets;
    /** RX Frame count */
	uint32_t nRxFrame;
    /** RX broadcast packet count */
	uint32_t nRxBcast;
    /** RX multicast packet count */
	uint32_t nRxMcast;
    /** TX Octet count */
	uint32_t nTxOctets;
    /** TX Frame count */
	uint32_t nTxFrame;
    /** TX broadcast packet count */
	uint32_t nTxBcast;
    /** TX multicast packet count */
	uint32_t nTxMcast;
} SNMP_IFMIB_MODULE_HARDWARE_REGISTER_STATS;

/**
 * Structure of IFMIB object.
 */        
typedef struct{
    SNMP_IFMIB_MODULE_HARDWARE_REGISTER_STATS   IfMibHdrRegStats;
    bool                                        LinkStatus;
    uint32_t                                    LastChanged; //Units in Ticks
    uint16_t                                    AdminStatusReqFlag; // Set admin status to down
}SNMP_IFMIB_OBJECT;

uint32_t SNMP_IFMIB_NetGetMTU(TCPIP_NET_HANDLE netH);
uint16_t SNMP_IFMIB_NetGetIfType(TCPIP_NET_HANDLE netH);
uint16_t SNMP_IFMIB_NetGetIfOperStatus(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfSpeed(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfInError(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfInDiscards(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfOutError(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfOutDiscards(TCPIP_NET_HANDLE netH);
uint8_t SNMP_IFMIB_NetGetPhyAddr(TCPIP_NET_HANDLE netH, uint8_t index);
bool SNMP_IFMIB_NetUpdateStats(TCPIP_NET_HANDLE netH,TCPIP_MAC_STATISTICS_REG_ENTRY *regEntries, uint8_t Maxindex);
uint8_t SNMP_IFMIB_NetGetIfname(TCPIP_NET_HANDLE netH, uint8_t index);
uint8_t SNMP_IFMIB_NetGetIfnameLen(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfInOctets(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfInUcastPkts(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfOutOctets(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfOutUcastPkts(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_NetGetIfLastChange(TCPIP_NET_HANDLE netH);
void SNMP_IFMIB_NetSetAdminStatus(TCPIP_NET_HANDLE netH, uint16_t Status);
void SNMP_IFMIB_NetUpCallback(TCPIP_NET_HANDLE netH);
void SNMP_IFMIB_NetDownCallback(TCPIP_NET_HANDLE netH);
uint32_t SNMP_IFMIB_SysUpTime(void);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif  // __SNMP_IF_MIB_H