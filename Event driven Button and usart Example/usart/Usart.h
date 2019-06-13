#include "UsartDataProcesser.h"
#include "../ConfigBits.h"
#include "../Application/Application.h"


#ifndef USART_H
#define USART_H




/*
 as?l usart için gereken fonksiyonlar?n bulundu?u ve bas?ld? m? bas?lmad? m? verisini 
 * tutan s?n?f
 
 */

typedef struct {
    int(*isDataReady)(void);
    UsartDataProcessor processor;
    
    char (*readChar)(void);
    int(*readString)(char *buf, int max_length);
    void (*writeByte)(char ch);
    void (*writeString)(const char *str);
    void (*writeLine)(const char *ln);
    void (*writeInt)(int val, unsigned char field_length);
    unsigned char (*readByte)(void);
} Usart;

Usart *applicationUsart;

Usart getUsart();

void setUsart(Usart *usart);



void USARTInit(Usart *usart,long baudRate) ;

#endif
