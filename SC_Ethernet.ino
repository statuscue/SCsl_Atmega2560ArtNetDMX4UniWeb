/*
 Name:		SC_Ethernet.ino
 Created:	09-Mar-19 16:38:06
 Author:	statuscue
 Editor:	http://hes.od.ua
*/

/*
	Copyright 2019-2019 by Yevhen Mykhailov
	Art-Net(TM) Designed by and Copyright Artistic Licence Holdings Ltd.
*/


// Hardware
//#define ETHERNET_SHIELD_2

// Libraries

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#define USE_DHCP 0

#define MAC_ADDRESS 0x90, 0xA2, 0xDA, 0x10, 0x6C, 0xA8
#define IP_ADDRESS 192,168,0,77
#define GATEWAY_IP 192,168,0,1
#define SUBNET_MASK 255,255,255,0
#define BROADCAST_IP 192,168,0,255

#define ARTNET_NODE_NAME "STATUCUE ArtNET"

#define SDSELECT_PIN 4

//*********************** globals ***********************

//network addresses
byte mac[] = { MAC_ADDRESS };
IPAddress ip(IP_ADDRESS);
IPAddress gateway(GATEWAY_IP);
IPAddress subnet_mask(SUBNET_MASK);

#if defined( BROADCAST_IP )
IPAddress broadcast_ip(BROADCAST_IP);
#else
IPAddress broadcast_ip = INADDR_NONE;
#endif

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP eUDP;


void SC_ethernetInit() {

#if defined(SDSELECT_PIN)
	pinMode(SDSELECT_PIN, OUTPUT);
#endif
	// Initialize Ethernet
	if (USE_DHCP) {
		Ethernet.begin(mac);										// DHCP
	}
	else {
		Ethernet.begin(mac, ip, gateway, gateway, subnet_mask);		// Static
	}
	
}