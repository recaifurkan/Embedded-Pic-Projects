/* 
 * File:   ButtonsFunctions.h
 * Author: ByRfb
 *
 * Created on March 10, 2019, 3:48 AM
 */

#ifndef BUTON1_H
#define	BUTON1_H

/*
 bu alttaki fonksyon butona bas?l?nda yap?lacak i?lemlerin yaz?lca?? fonksyonudr
 */
Usart *bUsart;

setButton1Usart(Usart *_usart){
    bUsart = _usart;
}

void btn1Func() {
    LATB = LATB << 1;
    int deger = LATB;
    bUsart->writeInt(deger,2);
    bUsart->writeString("\r\n");
}

/*
 bu alttaki fonksiyonda butonun ba?l? oldu?u pinin kontrolü için bulunmakta
 
 */
int btn1getValue() {
    return PORTDbits.RD0;
}



#endif	/* BUTON1_H */

