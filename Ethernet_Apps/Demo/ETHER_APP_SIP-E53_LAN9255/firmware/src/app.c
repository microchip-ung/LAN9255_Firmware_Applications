/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

extern void SNMPV2TrapDemo(void);
extern void SNMPTrapDemo(void);
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

APP_LED_STATE LEDstate = APP_LED_STATE_OFF;
//TCP/IP Stack initialization parameters
TCPIP_STACK_INIT    tcpipAltInit;
extern const TCPIP_STACK_MODULE_CONFIG TCPIP_STACK_MODULE_CONFIG_TBL[];
extern const size_t TCPIP_STACK_MODULE_CONFIG_TBL_SIZE;

/*Bug#UNG_J2_SIP-65*/
char macAddr[EUI48_MAC_ADDR_LENGTH] = {0x00, 0x04, 0x25, 0xff, 0xff, 0xff};
char macAddrString[18];

/*Bug#UNG_J2_SIP-65*/    
TCPIP_NETWORK_CONFIG TCPIP_HOSTS_ALT_CONFIGURATION[] =
{
    /*** Network Configuration Index 0 ***/
    {
        TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX0,       // interface
        TCPIP_NETWORK_DEFAULT_HOST_NAME_IDX0,            // hostName
        TCPIP_NETWORK_DEFAULT_MAC_ADDR_IDX0,             // macAddr
        TCPIP_NETWORK_DEFAULT_IP_ADDRESS_IDX0,           // ipAddr
        TCPIP_NETWORK_DEFAULT_IP_MASK_IDX0,              // ipMask
        TCPIP_NETWORK_DEFAULT_GATEWAY_IDX0,              // gateway
        TCPIP_NETWORK_DEFAULT_DNS_IDX0,                  // priDNS
        TCPIP_NETWORK_DEFAULT_SECOND_DNS_IDX0,           // secondDNS
        TCPIP_NETWORK_DEFAULT_POWER_MODE_IDX0,           // powerMode
        TCPIP_NETWORK_DEFAULT_INTERFACE_FLAGS_IDX0,      // startFlags
       &TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX0,           // pMacObject
    },
};
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/
/*Bug#UNG_J2_SIP-65*/
int TCPIP_STACK_InitCallback(const struct TCPIP_STACK_INIT** ppStackInit)
{
    uint8_t volatile *DynMacAddrPtr;
    DynMacAddrPtr = MEMBP(SERIAL_NO_WORD0_ADDR);
    
    macAddr[3] = DynMacAddrPtr[0];
    macAddr[4] = DynMacAddrPtr[1];
    macAddr[5] = DynMacAddrPtr[2];
    //ATMAC read success; convert MAC address to string format
    TCPIP_Helper_MACAddressToString((const TCPIP_MAC_ADDR*)macAddr, macAddrString, 18);
   /* SYS_CONSOLE_PRINT("  sno_w0 = %x w0[0] = %.2x %.2x %.2x", MEMDW(SERIAL_NO_WORD0_ADDR)
            ,DynMacAddrPtr[0], DynMacAddrPtr[1], DynMacAddrPtr[2]);
    SYS_CONSOLE_PRINT(" Macaddress %s\r\n", macAddrString);*/
    if ( true )
    {        
        //update host configuration with alternate MAC address, read from AT24MAC402
        (TCPIP_HOSTS_ALT_CONFIGURATION[0].macAddr) = (char*)macAddrString;
        tcpipAltInit.pNetConf = TCPIP_HOSTS_ALT_CONFIGURATION;
        tcpipAltInit.nNets = sizeof (TCPIP_HOSTS_ALT_CONFIGURATION) / sizeof (*TCPIP_HOSTS_ALT_CONFIGURATION);
        tcpipAltInit.pModConfig = TCPIP_STACK_MODULE_CONFIG_TBL;
        tcpipAltInit.nModules = TCPIP_STACK_MODULE_CONFIG_TBL_SIZE;
        tcpipAltInit.initCback = 0;

        *ppStackInit = &tcpipAltInit;        
    }    
    
    return 0;
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


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
    appData.state = APP_TCPIP_WAIT_INIT;
    
    /* Place the application state machine in its initial state. */
    appData.state = APP_MOUNT_DISK;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void APP_Tasks ( void )
{
    SYS_STATUS          tcpipStat;
    TCPIP_NET_HANDLE    netH;
    int                 nNets;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr;
    int                 i;
    const char          *netName, *netBiosName;
    bool                authTrapFlag = false;
    static uint32_t     startTick = 0;


    switch(appData.state)
    {
        case APP_MOUNT_DISK:
            if(SYS_FS_Mount(APP_SYS_FS_NVM_VOL, APP_SYS_FS_MOUNT_POINT, APP_SYS_FS_TYPE, 0, NULL) == 0)
            {
                SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted\r\n", APP_SYS_FS_TYPE_STRING);
                appData.state = APP_TCPIP_WAIT_INIT;
            }
            break;

        case APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE("APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_TCPIP_ERROR;
            }
            else if(tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the
                // available interfaces and register
                // a Bonjour service

                nNets = TCPIP_STACK_NumberOfNetworksGet();

                for(i = 0; i < nNets; i++)
                {
                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

#if defined(TCPIP_STACK_USE_NBNS)
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS enabled\r\n", netName, netBiosName);
#else
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS disabled\r\n", netName, netBiosName);
#endif // defined(TCPIP_STACK_USE_NBNS)
                    (void)netName;          // avoid compiler warning 
                    (void)netBiosName;      // if SYS_CONSOLE_PRINT is null macro

#if defined(TCPIP_STACK_USE_ZEROCONF_MDNS_SD)
                    // base name of the service Must not exceed 16 bytes long
                    // the last digit will be incremented by interface
                    char mDNSServiceName[] = "MyWebServiceNameX ";

                    mDNSServiceName[sizeof(mDNSServiceName) - 2] = '1' + i;
                    TCPIP_MDNS_ServiceRegister(netH
                            , mDNSServiceName                     // name of the service
                            ,"_http._tcp.local"                   // type of the service
                            ,80                                   // TCP or UDP port, at which this service is available
                            ,((const uint8_t *)"path=/index.htm") // TXT info
                            ,1                                    // auto rename the service when if needed
                            ,NULL                                 // no callback function
                            ,NULL);                               // no application context
#endif // defined(TCPIP_STACK_USE_ZEROCONF_MDNS_SD)
                }

#if defined(TCPIP_STACK_USE_HTTP_NET_SERVER)
                // register the application HTTP processing
                HTTP_APP_Initialize();
#endif // defined(TCPIP_STACK_USE_HTTP_NET_SERVER)

                appData.state = APP_TCPIP_TRANSACT;
            }

            break;

        case APP_TCPIP_TRANSACT:
            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();
#if defined(TCPIP_STACK_USE_SNMP_SERVER)
            if(TCPIP_SNMP_IsTrapEnabled())
            {
            // User should use one of the following SNMP demo
            // This routine demonstrates V1 or V2 trap formats with one variable binding.

                //SNMPTrapDemo(); //This function sends the both SNMP trap version 1 and 2 type of notifications

                if(TCPIP_SNMPV3_TrapTypeGet() || TCPIP_SNMP_TRAPTypeGet())
                {
                    //This routine provides V2 format notifications with multiple (3) variable bindings
                    //User should modify this routine to send v2 trap format notifications with the required varbinds.
                    SNMPV2TrapDemo(); //This function sends the SNMP trap version 2 type of notifications
                }
                else
                {
                    SNMPTrapDemo(); //This function sends the both SNMP trap version1 and 2 type of notifications
                }

        /*
             TCPIP_SNMP_SendFailureTrap() is used to send trap notification to previously configured ip address if trap notification is enabled.
             There are different trap notification code. The current implementation sends trap for authentication failure (4).
             PreCondition: If application defined event occurs to send the trap. Declare a notification flag and update as the event occurs.
             Uncomment the below function if the application requires.

         * */
                TCPIP_SNMP_AuthTrapFlagGet(&authTrapFlag);
                if(authTrapFlag)
                //if(true)
                {
                    TCPIP_SNMP_SendFailureTrap();
                }
            }
#endif
            for (i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                if(!TCPIP_STACK_NetIsReady(netH))
                {
                    return;    // interface not ready yet!
                }
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if(dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val;
                    SYS_CONSOLE_PRINT("%s IP Address: %d.%d.%d.%d \r\n",
                            TCPIP_STACK_NetNameGet(netH),
                            ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
                }
            }

            break;

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
