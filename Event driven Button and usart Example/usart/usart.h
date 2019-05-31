#include "UsartDataProcesser.h"
#ifndef USART_H
#define USART_H



/*
 as?l usart için gereken fonksiyonlar?n bulundu?u ve bas?ld? m? bas?lmad? m? verisini 
 * tutan s?n?f
 
 */

typedef struct {
    uint8_t(*isDataReady)(void);
    UsartDataProcessor processor;
    
    char (*readChar)(void);
    uint8_t(*readString)(char *buf, uint8_t max_length);
    void (*writeByte)(char ch);
    void (*writeString)(const char *str);
    void (*writeLine)(const char *ln);
    void (*writeInt)(int val, unsigned char field_length);
    unsigned char (*readByte)(void);
} Usart;




#endif
