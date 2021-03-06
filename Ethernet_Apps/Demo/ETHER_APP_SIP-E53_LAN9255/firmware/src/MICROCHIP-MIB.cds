 O-- MICROCHIP TECHNOLOGIES SNMP STACK SMIV2 SPECIFICATION DEMO CONTROL MIB
--
   v"This textual convention enumerates the authentication and privledge 
		protocol for USM configuration.
           "                                                             *"The MIB for SNMP stack demo application." "WWW.microchip.com" "201106080000Z" "The MIB module for SMIv2."                   '"Name of product. e.g. PICDEM.net etc."                       "Version string. e.g. 1.0"                       "Date of version"                           7"Trap table for IPv4 Destination address configuration"                       2"Single trap entry containing trap receiver info."                       "Index of trap receiver"                       1"Indicates if this trap entry is enabled or not."                       "Trap receiver IP address"                       1"Trap community to be used by agent to send trap"                       +"Trap table for IPv6 address configuration"                       2"Single trap entry containing trap receiver info."                       "Index of trap receiver"                       1"Indicates if this trap entry is enabled or not."                       "Trap receiver IPv6 address"                       1"Trap community to be used by agent to send trap"                           "D5 LED connected LATA2"                       "D6 LED connected to LATA3"                       "8-bit A/D value"                       "10-bit A/D value"                       "10-bit A/D value"                       ("Second line of LCD on PICDEM.net board"                           �"This table is used to configure microchip USM.
		     To get the SNMPv3 access, user need to configure security 
		     name,authentication,auth password,priv protocol and priv 
                 password.
		     
		    "                       :"User security configurations for USM.
                	"                       "Usm configuration index. "                      �"A human readable string representing the user in
                 Security Model independent format.

                 The default transformation of the User-based Security
                 Model dependent security ID to the securityName and
                 vice versa is the identity function so that the
                 securityName is the same as the userName.
                "                      >"Authentication support to the SNMPv3.
		     If usmAuthProtocol == NoAuthProtocol, then SNMPv3 Stack does 
		     not support/requires authentication.
		     If usmAuthProtocol == HMACMD5Auth , supports MD5 auth
		     If usmAuthProtocol == HMACSHAAuth, supports SHA Auth 	
                 If a set operation tries to set value as
                 NoAuthProtocol while the usmPrivProtocol value
                 for the same userName is not equal to NoPrivProtocol,
                 then an 'inconsistentValue' error must be returned.
                 This implies that SNMP command generator (SNMP Manager)
		     application must first ensure that the usmPrivProtocol is set
                 to NoPrivProtocol value before it can set
                 the usmAuthProtocol value to NoAuthProtocol.
                "                       �"This object in the MIB is associated to usmAuthProtocol.
			A secret authentication key is required to establish a secure connection 
			between snmp agent and manager.
		    "           T-- typically (SIZE (0 | 32)) for HMACMD5
-- typically (SIZE (0 | 40)) for HMACSHA
           `" A privacy protocol to provide encryption and decryption
			of SNMPv3 pdu. 
                "                       �"This object in the MIB is associated to usmPrivProtocol.
			A secret privacy key is required to establish a secure connection 
			between snmp agent and manager.

                "           &-- typically (SIZE (0 | 32)) for DES
               z"A table for SNMP target information. This information is required for
           generation of SNMP trap notifications."                       0"A set of SNMP target information.
           "                       \"The locally arbitrary, but unique identifier associated
            with mchpTargetEntry."                       q"The Message Processing Model to be used when generating/processing
            SNMP messages using this entry."                      O"The Security Model to be used while generating SNMP
             messages using this entry.  An implementation may
             choose to return an inconsistentValue error if an
             attempt is made to set this variable to a value
             for a security model which the implementation does
             not support."                       s"The securityName which identifies the Principal on
            whose behalf SNMP messages will be generated.
		"                       _"The Level of Security to be used when generating
            SNMP messages using this entry."                              /"SMIV2 Trap notification information for the SNMP Manager. 
		The objects used in the demo trap notification are 
		analogPot0,pushButton,ledD5 and trapCommunity. User should modify this object 
		information as per the requirements. These object should 
		have been defined as part of the MIB.
		"                         +"This group is for SNMP demo applications."               +"This group is for trap demo applications."                   X"A collection of objects providing basic product
            and control of a product."                 <"A collection of objects are used for SNMPV3 Configuration."                  "SNMP Trap Notification object."                     X"A collection of objects providing basic product
            and control of a product."                    