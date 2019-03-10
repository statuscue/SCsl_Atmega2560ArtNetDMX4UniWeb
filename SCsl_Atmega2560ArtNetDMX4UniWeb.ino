/*
 Name:		SCsl_Atmega2560ArtNetDMX4UniWeb.ino
 Created:	09-Mar-19 16:38:06
 Author:	statuscue
 Editor:	http://hes.od.ua
*/

/*
	Copyright 2019-2019 by Yevhen Mykhailov
	Art-Net(TM) Designed by and Copyright Artistic Licence Holdings Ltd.
*/


// Library

// the setup function runs once when you press reset or power the board
void setup() {
	SC_ethernetInit();
	SC_eepromInit();
	SC_artnetInit();
	SC_uartdmxInit();
}

// the loop function runs over and over again until power down or reset
void loop() {
	freeMem();
	SC_uartdmxSend();
}
