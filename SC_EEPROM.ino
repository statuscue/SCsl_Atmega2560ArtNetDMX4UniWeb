/*
 Name:		SC_EEPROM.ino
 Created:	09-Mar-19 16:38:06
 Author:	statuscue
 Editor:	http://hes.od.ua
*/

/*
	Copyright 2019-2019 by Yevhen Mykhailov
	Art-Net(TM) Designed by and Copyright Artistic Licence Holdings Ltd.
*/

// Libraries

#include <EEPROM.h>

uint32_t eeVolume;	// Объем памяти
uint8_t eeAddress;	// Сссылка на адрес памяти


void SC_eepromInit() {
	eeVolume = EEPROM.length();

}

