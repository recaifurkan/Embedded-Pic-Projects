/* 
 * File:   ButtonsGetValues.h
 * Author: ByRfb
 *
 * Created on March 10, 2019, 3:47 AM
 */

/*
 burada port atamas?n? fonksiyondan yapamad???n için bu ?ekilde ay?rarak i?lem yapt?r?yorsun
 
 
 */

#ifndef BUTON2_H
#define	BUTON2_H

void btn2Func() {

    LATB = LATB >> 1;
//    usart.writeLine("2ye bas?ld?");
}

int btn2getValue() {
    return PORTDbits.RD1;
}

#endif	/* BUTON2_H */

