/*
 Name:		SC_InitUARTDMX.ino
 Created:	09-Mar-19 16:38:06
 Author:	statuscue
 Editor:	http://hes.od.ua
*/

/*
	Copyright 2019-2019 by Yevhen Mykhailov
	Art-Net(TM) Designed by and Copyright Artistic Licence Holdings Ltd.
*/

//#define USE_UART_0

#ifdef USE_UART_0
	#include <SClb_Atmega2560_DMXUART_C0.h>
#endif // USE_UART_0

#include <SClb_Atmega2560_DMXUART_C1.h>
#include <SClb_Atmega2560_DMXUART_C2.h>
#include <SClb_Atmega2560_DMXUART_C3.h>

void SC_uartdmxInit() {

#ifdef USE_UART_0
	SCDMXUSART0.startOutput();
#endif // USE_UART_0
	SCDMXUSART1.startOutput();
	SCDMXUSART2.startOutput();
	SCDMXUSART3.startOutput();
}