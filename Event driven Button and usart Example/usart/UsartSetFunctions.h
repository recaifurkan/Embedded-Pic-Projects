/* 
 * File:   UsartSetFunctions.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 19:05
 */
#include "UsartFunctions.h"
#ifndef USARTSETFUNCTIONS_H
#define	USARTSETFUNCTIONS_H



/*
 usart?n gele veride interrupt olu?turacak ?ekilde
 * olu?turulmas? için registerler de?er atayan ve olu?turran fonksiyonlar?n bulundu?u k?s?m
 
 
 */

void setupFunctions(Usart *usart) {
   
    usart->isDataReady = USARTDataReady;


    usart->readByte = USARTReadByte;
    usart->readChar = USARTReadChar;
    usart->readString = USARTReadString;


    usart->writeByte = USARTWriteByte;
    usart->writeInt = USARTWriteInt;
    usart->writeLine = USARTWriteLine;
    usart->writeString = USARTWriteString;
}



void enableInterrupts() {
    GIE = 1; // enable global interrupt
    PEIE = 1; // unable peripheral interrupt
    RCIE = 1; //enable interrupt. usarttan veri gelme interrupt? aktif edildi
}
long calculateSpbrg(long baudRate) {
    long bolum = 16 * baudRate;
    return ((_XTAL_FREQ / bolum) - 1);
}

void USARTInit(Usart *usart,long baudRate) {

    
    enableInterrupts();

    BRGH = 1; // Set For High-Speed Baud Rate
    SPBRG = calculateSpbrg(baudRate);
    // Set The Baud Rate To Be 9600 bps
    //--[ Enable The Ascynchronous Serial Port ]--
    SYNC = 0;
    SPEN = 1;
    //--[ Set The RX-TX Pins to be in UART mode (not io) ]--
    TRISC6 = 1; // As stated in the datasheet
    TRISC7 = 1; // As stated in the datasheet
    TXEN = 1; // Enable UART Transmission

    CREN = 1; // bu da almak için i?e yarar interrupt devreye sokar
    setupFunctions(usart);

    //    usart.writeInt(calculateSpbrg(9600),5);

    

}



#endif	/* USARTSETFUNCTIONS_H */

