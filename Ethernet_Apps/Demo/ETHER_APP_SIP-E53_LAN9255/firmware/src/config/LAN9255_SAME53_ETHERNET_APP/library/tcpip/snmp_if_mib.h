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

/* This Macro is used for to indicate the SNMP IFMIB_LINKUP value as 1.  */        
#define SNMP_IFMIB_LINKUP                   (1)
        
/* This Macro is used for to indicate the SNMP IFMIB_LINKDOWN value as 0.  */        
#define SNMP_IFMIB_LINKDOWN                 (0)
/* This Macro is used for to indicate the SNMP ADMINSTATUS LINKDOWN value 
   as 2.  */                
#define SNMP_IFMIB_ADMINSTATUS_LINKDOWN     (2)

/* This Macro is used for to indicate the SNMP ADMINSTATUS LINKUP value 
   as 1.  */ 
#define SNMP_IFMIB_ADMINSTATUS_LINKUP       (1)

/* This Macro is used for to indicate the SNMP ADMINSTATUS LINKTESTING value 
   as 3.  */ 
#define SNMP_IFMIB_ADMINSTATUS_LINKTESTING  (3)

/* This Macro is used for both ETH_RX_OCTECTS variable processing to indicate 
   the SNMP ETH_RX_OCTECTS Register array index value as 20.  */        
#define SNMP_IFMIB_ETH_RX_OCTECTS   (20)

/* This Macro is used for both ETH_RX_FRAME variable processing to indicate 
   the SNMP ETH_RX_FRAME Register array index value as 22.  */  
#define SNMP_IFMIB_ETH_RX_FRAME     (22)

/* This Macro is used for both ETH_RX_BCAST variable processing to indicate 
   the SNMP ETH_RX_BCAST Register array index value as 23.  */  
#define SNMP_IFMIB_ETH_RX_BCAST     (23)

/* This Macro is used for both ETH_RX_MCAST variable processing to indicate 
   the SNMP ETH_RX_MCAST Register array index value as 24.  */  
#define SNMP_IFMIB_ETH_RX_MCAST     (24)

/* This Macro is used for both ETH_TX_OCTECTS variable processing to indicate 
   the SNMP ETH_TX_OCTECTS Register array index value as 0.  */  
#define SNMP_IFMIB_ETH_TX_OCTECTS   (0)

/* This Macro is used for both ETH_TX_FRAME variable processing to indicate 
   the SNMP ETH_TX_FRAME Register array index value as 2.  */  
#define SNMP_IFMIB_ETH_TX_FRAME     (2)

/* This Macro is used for both ETH_TX_BCAST variable processing to indicate 
   the SNMP ETH_TX_BCAST Register array index value as 3.  */  
#define SNMP_IFMIB_ETH_TX_BCAST     (3)

/* This Macro is used for both ETH_TX_MCAST variable processing to indicate 
   the SNMP ETH_TX_MCAST Register array index value as 4.  */  
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

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetMTU(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by
 *                   TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle to get the name of.
 *
 * Output:          it returns the Link Mtu associated to that interface handle
 *                     returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:            TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                     uint32_t LinkMtu = SNMP_IFMIB_NetGetMTU(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetMTU(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint16_t SNMP_IFMIB_NetGetIfType(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the IfType associated to that interface handle
 *                     returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:            TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                     uint16_t IfType = SNMP_IFMIB_NetGetIfType(netH);
 *
 * Note:            None
 ********************************************************************/
uint16_t SNMP_IFMIB_NetGetIfType(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint8_t SNMP_IFMIB_NetGetIfnameLen(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the Length of ifname associated to that interface
 *                  handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:            TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                     uint8_t IfnameLen = SNMP_IFMIB_NetGetIfnameLen(netH);
 *
 * Note:            None
 ********************************************************************/
uint8_t SNMP_IFMIB_NetGetIfnameLen(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint8_t SNMP_IFMIB_NetGetIfname(TCPIP_NET_HANDLE netH, 
 *                             uint8_t index)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the indexed character of Interface name
 *                  associated to that interface handle returns 0 if no
 *                  such name
 *
 * Side Effects:    None
 *
 * Example:            TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                     uint8_t ifname = SNMP_IFMIB_NetGetIfname(netH,index);
 *
 * Note:            None
 ****************************** **************************************/
uint8_t SNMP_IFMIB_NetGetIfname(TCPIP_NET_HANDLE netH, uint8_t index);

/*********************************************************************
 * Function:        uint8_t SNMP_IFMIB_NetGetPhyAddr(TCPIP_NET_HANDLE netH, 
 *                              uint8_t index)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the indexed character of Interface PhyAddress
 *                  associated to that interface handle returns 0 if no
 *                  such name
 *
 * Side Effects:    None
 *
 * Example:            TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                     uint8_t ifname = SNMP_IFMIB_NetGetPhyAddr(netH,index);
 *
 * Note:            None
 ****************************** **************************************/
uint8_t SNMP_IFMIB_NetGetPhyAddr(TCPIP_NET_HANDLE netH, uint8_t index);

/*********************************************************************
 * Function:        uint16_t SNMP_IFMIB_NetGetIfOperStatus(TCPIP_NET_HANDLE 
 *                              netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the interface operation status of associated to  
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint16_t IfOperStatus = SNMP_IFMIB_NetGetIfOperStatus(netH);
 *
 * Note:            None
 ********************************************************************/
uint16_t SNMP_IFMIB_NetGetIfOperStatus(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfSpeed(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the interface speed associated to that 
 *                  interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfSpeed = SNMP_IFMIB_NetGetIfSpeed(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfSpeed(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfInError(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the input error packet counts associated to that 
 *                  interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfInError = SNMP_IFMIB_NetGetIfInError(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfInError(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfInDiscards(TCPIP_NET_HANDLE 
 *                              netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the input discard packet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfInDiscards = SNMP_IFMIB_NetGetIfInDiscards(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfInDiscards(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfOutError(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the output error packet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfOutError = SNMP_IFMIB_NetGetIfOutError(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfOutError(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfOutDiscards(TCPIP_NET_HANDLE 
 *                              netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the output discard packet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfOutDiscards = SNMP_IFMIB_NetGetIfOutDiscards(
 *                                              netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfOutDiscards(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfInOctets(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the received octet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfInOctets = SNMP_IFMIB_NetGetIfInOctets(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfInOctets(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfInUcastPkts(TCPIP_NET_HANDLE
 *                               netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the input unicast packet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfInUcastPkts = SNMP_IFMIB_NetGetIfInUcastPkts(
 *                                              netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfInUcastPkts(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfOutOctets(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the transmit octet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfOutOctets = SNMP_IFMIB_NetGetIfOutOctets(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfOutOctets(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfOutUcastPkts(TCPIP_NET_HANDLE 
 *                              netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the output unicast packet counts associated to 
 *                  that interface handle returns 0 if no such name
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfOutUcastPkts = SNMP_IFMIB_NetGetIfOutUcastPkts(
 *                                              netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfOutUcastPkts(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetIfLastChange(TCPIP_NET_HANDLE 
 *                              netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          it returns the sysUpTime since last interface state change
 *                  associated to that interface handle returns 0 if no such 
 *                  name
  *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  uint32_t IfLastChange = SNMP_IFMIB_NetGetIfLastChange(netH);
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_NetGetIfLastChange(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        void SNMP_IFMIB_NetSetAdminStatus(TCPIP_NET_HANDLE netH,
 *                           uint16_t Status)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle, status - admin status.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  SNMP_IFMIB_NetSetAdminStatus(netH, Status);
 *
 * Note:            This function saves the admin status to set in next routine.
 *                  If admin status is set to down on reception of request, then
 *                  SNMP response cannot be sent out. So, setting Admin status 
 *                  shall be handled in next routine
 ********************************************************************/
void SNMP_IFMIB_NetSetAdminStatus(TCPIP_NET_HANDLE netH, uint16_t Status);

/*********************************************************************
 * Function:        void SNMP_IFMIB_NetDownCallback(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  SNMP_IFMIB_NetDownCallback(netH);
 *
 * Note:            This will be called from TCPIP_SNMP_Task function when 
 *                  interface0 link is down.
 ********************************************************************/
void SNMP_IFMIB_NetUpCallback(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        void SNMP_IFMIB_NetUpCallback(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  SNMP_IFMIB_NetUpCallback(netH);
 *
 * Note:            This will be called from TCPIP_SNMP_Task function when 
 *                  interface0 Link is up.
 ********************************************************************/
void SNMP_IFMIB_NetDownCallback(TCPIP_NET_HANDLE netH);

/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_SysUpTime()
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           None
 *
 * Output:          it returns the system uptime value
 *
 * Side Effects:    None
 *
 * Example:         uint32_t SysUpTime = SNMP_IFMIB_SysUpTime();
 *
 * Note:            None
 ********************************************************************/
uint32_t SNMP_IFMIB_SysUpTime(void);

/*********************************************************************
 * Function:        void SNMP_IFMIB_NetUpdateStats(TCPIP_NET_HANDLE netH,
 *                          TCPIP_MAC_STATISTICS_REG_ENTRY *regEntries, 
 *                          uint8_t Maxindex)
 *
 * PreCondition:    TCPIP stack should have been initialized by 
 *                  TCPIP_STACK_Initialize()
 *
 * Input:           netH - Interface handle, regEntries- pointer to hardware 
 *                  register stats
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Example:         TCPIP_NET_HANDLE netH = TCPIP_STACK_IndexToNet(0);
 *                  SNMP_IFMIB_NetUpdateStats(netH, &regEntries, Maxindex);
 *
 * Note:            This function accumulates necessary hardware register 
 *                  statistics
 ********************************************************************/
void SNMP_IFMIB_NetUpdateStats(TCPIP_NET_HANDLE netH,
        TCPIP_MAC_STATISTICS_REG_ENTRY *regEntries, uint8_t Maxindex);
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif  // __SNMP_IF_MIB_H