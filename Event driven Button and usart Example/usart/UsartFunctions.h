/* 
 * File:   UsartFunctions.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 13:25
 */

#ifndef USARTFUNCTIONS_H
#define	USARTFUNCTIONS_H

/*
 
 usart? arkda çal??t?rd??? fonksyionlar?n bulundu?u k?s?m
 
 */



uint8_t USARTDataReady() {
    return PIR1bits.RCIF;
}

unsigned char USARTReadByte() {
    while (!RCIF); //Wait for a byte

    return RCREG;
}

char USARTReadChar() {
    while (!USARTDataReady()); // Wait for data to be available
    return RCREG;
}

uint8_t USARTReadString(char *buf, uint8_t max_length) {
    uint8_t i = 0;
    char tmp = 1;
    for (i = 0; i < max_length - 1; i++) {
        tmp = USARTReadChar();
        // Stop reading if end of string is read
        if (tmp == '\0' || tmp == '\n' || tmp == '\r') {
            break;
        }
        buf[i] = tmp;
    }

    buf[i + 1] = '\0';

    return i;
}

/**
 * Determines whether a new data is available to read
 * @return
 */


void USARTWriteByte(char ch) {
    //Wait for TXREG Buffer to become available
    while (!TXIF);

    //Write data
    TXREG = ch;
}

void USARTWriteString(const char *str) {
    while ((*str) != '\0') {
        //Wait for TXREG Buffer to become available
        while (!TXIF);

        //Write data
        TXREG = (*str);

        //Next goto char
        str++;
    }
}

/*

Writes a line of text to USART and goes to new line
The new line is Windows style CR/LF pair.

This will work on Hyper Terminal Only NOT on Linux

 */

void USARTWriteLine(const char *ln) {
    USARTWriteString(ln);
    USARTWriteString("\r\n");
}

void USARTWriteInt(int val, unsigned char field_length) {
    if (val < 0) {
        USARTWriteByte('-'); //Write '-' sign for negative numbers.
        val = (val * (-1)); //Make it positive.
    }

    //Convert Number To String and pump over Tx Channel.
    char str[5] = {0, 0, 0, 0, 0};
    int i = 4, j = 0;
    while (val) {
        str[i] = val % 10;
        val = val / 10;
        i--;
    }
    if (field_length > 5)
        while (str[j] == 0) j++;
    else
        j = 5 - field_length;

    for (i = j; i < 5; i++) {
        USARTWriteByte('0' + str[i] );
    }
}






#endif	/* USARTFUNCTIONS_H */

