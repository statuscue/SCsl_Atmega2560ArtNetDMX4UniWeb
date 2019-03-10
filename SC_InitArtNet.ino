/*
 Name:		SC_InitArtNet.ino
 Created:	09-Mar-19 16:38:06
 Author:	statuscue
 Editor:	http://hes.od.ua
*/

/*
	Copyright 2019-2019 by Yevhen Mykhailov
	Art-Net(TM) Designed by and Copyright Artistic Licence Holdings Ltd.
*/

// Libraries

#include <SClb_Arduino_DMXEthernet.h>
#include <SClb_ArtNetNode1.h>

#define ARTNET_NODE_NAME "STATUCUE ArtNET"

uint8_t artnetBuffer[ARTNET_BUFFER_MAX];
SCArtNet1* artNetInterface_0_0;
SCArtNet1* artNetInterface_0_1;
SCArtNet1* artNetInterface_0_2;
SCArtNet1* artNetInterface_0_3;

void SC_artnetInit() {

	artNetInterface_0_0 = new SCArtNet1(Ethernet.localIP(), Ethernet.subnetMask(), artnetBuffer);
	artNetInterface_0_0->setSubnetUniverse(0, 0);
	artNetInterface_0_1 = new SCArtNet1(Ethernet.localIP(), Ethernet.subnetMask(), artnetBuffer);
	artNetInterface_0_1->setSubnetUniverse(0, 1);
	artNetInterface_0_2 = new SCArtNet1(Ethernet.localIP(), Ethernet.subnetMask(), artnetBuffer);
	artNetInterface_0_2->setSubnetUniverse(0, 2);
	artNetInterface_0_3 = new SCArtNet1(Ethernet.localIP(), Ethernet.subnetMask(), artnetBuffer);
	artNetInterface_0_3->setSubnetUniverse(0, 3);

	eUDP.begin(artNetInterface_0_0->dmxPort());
	((SCArtNet1*)artNetInterface_0_0)->setNodeName(ARTNET_NODE_NAME);
	((SCArtNet1*)artNetInterface_0_0)->send_art_poll_reply(&eUDP);
	eUDP.begin(artNetInterface_0_1->dmxPort());
	((SCArtNet1*)artNetInterface_0_1)->setNodeName(ARTNET_NODE_NAME);
	((SCArtNet1*)artNetInterface_0_1)->send_art_poll_reply(&eUDP);
	eUDP.begin(artNetInterface_0_2->dmxPort());
	((SCArtNet1*)artNetInterface_0_2)->setNodeName(ARTNET_NODE_NAME);
	((SCArtNet1*)artNetInterface_0_2)->send_art_poll_reply(&eUDP);
	eUDP.begin(artNetInterface_0_3->dmxPort());
	((SCArtNet1*)artNetInterface_0_3)->setNodeName(ARTNET_NODE_NAME);
	((SCArtNet1*)artNetInterface_0_3)->send_art_poll_reply(&eUDP);
}