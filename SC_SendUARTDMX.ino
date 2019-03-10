/*
 Name:		SC_SendUARTDMX.ino
 Created:	09-Mar-19 16:38:06
 Author:	statuscue
 Editor:	http://hes.od.ua
*/

/*
	Copyright 2019-2019 by Yevhen Mykhailov
	Art-Net(TM) Designed by and Copyright Artistic Licence Holdings Ltd.
*/


void SC_uartdmxSend() {

	uint16_t packetSize = eUDP.parsePacket();

	if (packetSize) {
		packetSize = eUDP.read(artnetBuffer, ARTNET_BUFFER_MAX);

		uint8_t read_result_artnet_0_0 = artNetInterface_0_0->readDMXPacketContents(&eUDP, packetSize);
		uint8_t read_result_artnet_0_1 = artNetInterface_0_1->readDMXPacketContents(&eUDP, packetSize);
		uint8_t read_result_artnet_0_2 = artNetInterface_0_2->readDMXPacketContents(&eUDP, packetSize);
		uint8_t read_result_artnet_0_3 = artNetInterface_0_3->readDMXPacketContents(&eUDP, packetSize);

#ifdef USE_UART_0
		if (read_result_artnet_0_0 == RESULT_DMX_RECEIVED) {
			for (int i = 1; i <= artNetInterface_0_0->numberOfSlots(); i++) {
				SCDMXUSART0.setSlot(i, artNetInterface_0_0->getSlot(i));
			}
		}
#endif // USE_UART_0
		if (read_result_artnet_0_1 == RESULT_DMX_RECEIVED) {
			for (int i = 1; i <= artNetInterface_0_1->numberOfSlots(); i++) {
				SCDMXUSART1.setSlot(i, artNetInterface_0_1->getSlot(i));
			}
		}
		if (read_result_artnet_0_2 == RESULT_DMX_RECEIVED) {
			for (int i = 1; i <= artNetInterface_0_2->numberOfSlots(); i++) {
				SCDMXUSART2.setSlot(i, artNetInterface_0_2->getSlot(i));
			}
		}
		if (read_result_artnet_0_3 == RESULT_DMX_RECEIVED) {
			for (int i = 1; i <= artNetInterface_0_3->numberOfSlots(); i++) {
				SCDMXUSART3.setSlot(i, artNetInterface_0_3->getSlot(i));
			}
		}
	}

}