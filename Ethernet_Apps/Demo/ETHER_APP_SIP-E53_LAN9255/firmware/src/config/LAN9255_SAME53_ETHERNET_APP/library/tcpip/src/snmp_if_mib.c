/*******************************************************************************
  Simple Network Management Protocol (SNMP) Interface MIB object
 

  Summary:
    Module for Microchip TCP/IP Stack
    
  Description:
    -Provides SNMP API for doing stuff
    -Reference: RFC 2863 (for IF-MIB)
*******************************************************************************/

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

#include "tcpip/src/tcpip_private.h"
#if defined(TCPIP_STACK_USE_SNMP_SERVER)
#include "tcpip/src/snmp_private.h"
#if defined(TCPIP_STACK_USE_SNMPV3_SERVER)
#include "tcpip/src/snmpv3_private.h"
#endif
#include "tcpip/src/common/sys_fs_shell.h"
#include "tcpip/snmp.h"
#include "mib.h"
#include "tcpip/snmp_if_mib.h"
#ifdef TCPIP_STACK_USE_SNMPV3_SERVER
#include "tcpip/snmpv3.h"
#endif


/****************************************************************************
  Section:
	Global Variables
  ***************************************************************************/
static uint16_t SNMPTxOffset;	//Snmp udp buffer tx offset
SNMP_IFMIB_OBJECT gIfMibObj={0};

/****************************************************************************
  Section:
	Function Prototypes
  ***************************************************************************/


/****************************************************************************
  ===========================================================================
  Section:
	SNMP v1 and v2c Agent Routines
  ===========================================================================
  ***************************************************************************/
/*********************************************************************
 * Function:        uint32_t SNMP_IFMIB_NetGetMTU(TCPIP_NET_HANDLE netH)
 *
 * PreCondition:    TCPIP stack should have been initialized by TCPIP_STACK_Initialize()
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
uint32_t SNMP_IFMIB_NetGetMTU(TCPIP_NET_HANDLE netH)
{
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);

    if(pNetIf != 0)
    {
        return pNetIf->linkMtu;
    }

    return 0;
}

uint16_t SNMP_IFMIB_NetGetIfType(TCPIP_NET_HANDLE netH)
{
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);

    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
            return SNMP_IFMIB_ETH_MAC_TYPE;
        }
    }

    return 0;
}

uint8_t SNMP_IFMIB_NetGetIfnameLen(TCPIP_NET_HANDLE netH)
{
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);

    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
            return strlen(pNetIf->ifName);
        }
    }

    return 0;
}

uint8_t SNMP_IFMIB_NetGetIfname(TCPIP_NET_HANDLE netH, uint8_t index)
{
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);

    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
            return pNetIf->ifName[index];
        }
    }

    return 0;
}

uint8_t SNMP_IFMIB_NetGetPhyAddr(TCPIP_NET_HANDLE netH, uint8_t index)
{
    static char MacAddrStr[19];
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);
    
    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
          if(index == 0){
            sprintf(MacAddrStr, "%02x-%02x-%02x-%02x-%02x-%02x-%02x",pNetIf->netMACAddr.v[0], 
                      pNetIf->netMACAddr.v[1], pNetIf->netMACAddr.v[2], pNetIf->netMACAddr.v[3], 
                      pNetIf->netMACAddr.v[4],pNetIf->netMACAddr.v[5]); 
          }
    
            return MacAddrStr[index];
        }
    }

    return 0;
}

uint16_t SNMP_IFMIB_NetGetIfOperStatus(TCPIP_NET_HANDLE netH)
{
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);
    bool bOperStatus = false;
    uint16_t wOperStatus;
    
    if(pNetIf != 0)
    {
        bOperStatus = TCPIP_STACK_NetIsLinked(netH);
        wOperStatus = bOperStatus?1:2;
        return wOperStatus;
    }

    return 0;
}

uint32_t SNMP_IFMIB_NetGetIfSpeed(TCPIP_NET_HANDLE netH)
{
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);
    uint32_t IfSpeed = 0;
    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
             IfSpeed = SNMP_IFMIB_ETH_SPEED_100_MBPS;
        }
        return IfSpeed;
    }

    return 0;
}


uint32_t SNMP_IFMIB_NetGetIfInError(TCPIP_NET_HANDLE netH)
{
    TCPIP_MAC_RX_STATISTICS rxStatistics;
    TCPIP_MAC_TX_STATISTICS txStatistics;

    if(TCPIP_STACK_NetMACStatisticsGet(netH, &rxStatistics, &txStatistics)){
        /* Need to check sign logic*/
        if(rxStatistics.nRxErrorPackets != 0xFFFFFFFF){
            return (uint32_t)rxStatistics.nRxErrorPackets ;
        }
    }
    return 0;
}

uint32_t SNMP_IFMIB_NetGetIfInDiscards(TCPIP_NET_HANDLE netH)
{
    TCPIP_MAC_RX_STATISTICS rxStatistics;
    TCPIP_MAC_TX_STATISTICS txStatistics;

    if(TCPIP_STACK_NetMACStatisticsGet(netH, &rxStatistics, &txStatistics)){
        /* Need to check sign logic*/
        return (uint32_t)rxStatistics.nRxBuffNotAvailable;
    }
    return 0;
}

uint32_t SNMP_IFMIB_NetGetIfOutError(TCPIP_NET_HANDLE netH)
{
    TCPIP_MAC_RX_STATISTICS rxStatistics;
    TCPIP_MAC_TX_STATISTICS txStatistics;

    if(TCPIP_STACK_NetMACStatisticsGet(netH, &rxStatistics, &txStatistics)){
        /* Need to check sign logic*/
        return (uint32_t)txStatistics.nTxErrorPackets;
    }
    return 0;
}

uint32_t SNMP_IFMIB_NetGetIfOutDiscards(TCPIP_NET_HANDLE netH)
{
    TCPIP_MAC_RX_STATISTICS rxStatistics;
    TCPIP_MAC_TX_STATISTICS txStatistics;

    if(TCPIP_STACK_NetMACStatisticsGet(netH, &rxStatistics, &txStatistics)){
        /* Need to check sign logic*/
        return (uint32_t)txStatistics.nTxQueueFull;
    }
    return 0;
}

uint32_t SNMP_IFMIB_NetGetIfInOctets(TCPIP_NET_HANDLE netH)
{
    int                    hwEntries,i=0;
    TCPIP_MAC_STATISTICS_REG_ENTRY  regEntries[50];
    if(TCPIP_STACK_NetMACRegisterStatisticsGet(netH, regEntries, sizeof(regEntries)/sizeof(*regEntries), &hwEntries)){
        SNMP_IFMIB_NetUpdateStats(netH, regEntries, hwEntries);
        /* Need to check sign logic*/
      /*  for(i=0;i<hwEntries;i++){
            SYS_CONSOLE_PRINT("Index[%d] %s - %d \r\n",i ,regEntries[i].registerName,
                    regEntries[i].registerValue);
        }*/
        return (uint32_t)gIfMibObj.IfMibHdrRegStats.nRxOctets;
    }
    return 0;
}
bool SNMP_IFMIB_NetUpdateStats(TCPIP_NET_HANDLE netH,TCPIP_MAC_STATISTICS_REG_ENTRY *regEntries, uint8_t Maxindex){
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);
     SNMP_IFMIB_MODULE_HARDWARE_REGISTER_STATS   *IfMibHdrRegStats = &gIfMibObj.IfMibHdrRegStats;
    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
            IfMibHdrRegStats->nRxOctets += regEntries[SNMP_IFMIB_ETH_RX_OCTECTS].registerValue; 
            IfMibHdrRegStats->nRxFrame += regEntries[SNMP_IFMIB_ETH_RX_FRAME].registerValue; 
            IfMibHdrRegStats->nRxBcast += regEntries[SNMP_IFMIB_ETH_RX_BCAST].registerValue; 
            IfMibHdrRegStats->nRxMcast += regEntries[SNMP_IFMIB_ETH_RX_MCAST].registerValue; 
            IfMibHdrRegStats->nTxOctets += regEntries[SNMP_IFMIB_ETH_TX_OCTECTS].registerValue; 
            IfMibHdrRegStats->nTxFrame += regEntries[SNMP_IFMIB_ETH_TX_FRAME].registerValue; 
            IfMibHdrRegStats->nTxBcast += regEntries[SNMP_IFMIB_ETH_TX_BCAST].registerValue; 
            IfMibHdrRegStats->nTxMcast += regEntries[SNMP_IFMIB_ETH_TX_MCAST].registerValue; 
        }
    }
}
uint32_t SNMP_IFMIB_NetGetIfInUcastPkts(TCPIP_NET_HANDLE netH)
{
    int                    hwEntries;
    TCPIP_MAC_STATISTICS_REG_ENTRY  regEntries[50];
    if(TCPIP_STACK_NetMACRegisterStatisticsGet(netH, regEntries, sizeof(regEntries)/sizeof(*regEntries), &hwEntries)){
        /* Need to check sign logic*/
        SNMP_IFMIB_NetUpdateStats(netH, regEntries, hwEntries);
        return (uint32_t)(gIfMibObj.IfMibHdrRegStats.nRxFrame - (gIfMibObj.IfMibHdrRegStats.nRxMcast + gIfMibObj.IfMibHdrRegStats.nRxBcast));
    }
    return 0;
}
uint32_t SNMP_IFMIB_NetGetIfOutOctets(TCPIP_NET_HANDLE netH)
{
    int                    hwEntries;
    TCPIP_MAC_STATISTICS_REG_ENTRY  regEntries[50];
    if(TCPIP_STACK_NetMACRegisterStatisticsGet(netH, regEntries, sizeof(regEntries)/sizeof(*regEntries), &hwEntries)){
        /* Need to check sign logic*/
        SNMP_IFMIB_NetUpdateStats(netH, regEntries, hwEntries);
        return (uint32_t)gIfMibObj.IfMibHdrRegStats.nTxOctets;
    }
    return 0;
}
uint32_t SNMP_IFMIB_NetGetIfOutUcastPkts(TCPIP_NET_HANDLE netH)
{
    int                    hwEntries;
    TCPIP_MAC_STATISTICS_REG_ENTRY  regEntries[50];
    if(TCPIP_STACK_NetMACRegisterStatisticsGet(netH, regEntries, sizeof(regEntries)/sizeof(*regEntries), &hwEntries)){
        /* Need to check sign logic*/
        SNMP_IFMIB_NetUpdateStats(netH, regEntries, hwEntries);
        return (uint32_t)(gIfMibObj.IfMibHdrRegStats.nTxFrame - (gIfMibObj.IfMibHdrRegStats.nTxMcast + gIfMibObj.IfMibHdrRegStats.nTxBcast));
    }
    return 0;
}

uint32_t SNMP_IFMIB_NetGetIfLastChange(TCPIP_NET_HANDLE netH)
{
    uint32_t IfLastChange=0;
    uint32_t *Ticks = &gIfMibObj.LastChanged;
    TCPIP_NET_IF*  pNetIf = _TCPIPStackHandleToNet(netH);
    
    if(pNetIf != 0)
    {
        if(pNetIf->macType == TCPIP_MAC_TYPE_ETH){
            IfLastChange = (SNMP_IFMIB_SysUpTime() - (*Ticks));
            return IfLastChange;
        }
    }
    return 0;
}
void SNMP_IFMIB_NetSetAdminStatus(TCPIP_NET_HANDLE netH, uint16_t Status){
    uint16_t *AdminStatus = &gIfMibObj.AdminStatusReqFlag;
    *AdminStatus = Status;
}
void SNMP_IFMIB_NetDownCallback(TCPIP_NET_HANDLE netH){
    bool *LinkStatus = &gIfMibObj.LinkStatus;
    uint32_t *Ticks = &gIfMibObj.LastChanged;
    
    if(*LinkStatus == SNMP_IFMIB_LINKUP){
        memset(&gIfMibObj.IfMibHdrRegStats,0,sizeof(SNMP_IFMIB_MODULE_HARDWARE_REGISTER_STATS));
        *Ticks = SNMP_IFMIB_SysUpTime();
        *LinkStatus = SNMP_IFMIB_LINKDOWN;

    }
}
void SNMP_IFMIB_NetUpCallback(TCPIP_NET_HANDLE netH){
    bool *LinkStatus = &gIfMibObj.LinkStatus;
    uint32_t *Ticks = &gIfMibObj.LastChanged;
    uint16_t *AdminStatus = &gIfMibObj.AdminStatusReqFlag;
    bool res=false;
    
    if(*LinkStatus == SNMP_IFMIB_LINKDOWN){
        *Ticks = SNMP_IFMIB_SysUpTime();
        *LinkStatus = SNMP_IFMIB_LINKUP;
    }
    if(*AdminStatus == SNMP_IFMIB_ADMINSTATUS_LINKDOWN){
        res = TCPIP_STACK_NetDown(netH);
        if(res)
            *AdminStatus = 0;
    }
}
uint32_t SNMP_IFMIB_SysUpTime(void){
    uint32_t dw10msTicks;
    
    dw10msTicks = (SYS_TMR_TickCountGet()*100ull)/SYS_TMR_TickCounterFrequencyGet(); 
    return dw10msTicks;
}
#endif //#if defined(TCPIP_STACK_USE_SNMP_SERVER)

