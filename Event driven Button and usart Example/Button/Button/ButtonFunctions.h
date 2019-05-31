/* 
 * File:   ButtonFunctions.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 18:21
 */
#include "Button.h"
#ifndef BUTTONFUNCTIONS_H
#define	BUTTONFUNCTIONS_H

/*
 butonun olu?turlmas? ile ve kulan?lmas? ile ilgili fokstyionlar burada bulunmakta
 
 */
Button initButton(char *portName, int (*getValue)(void),void (*onPressed)(void) ){
    Button buton;
    buton.portName = portName;
    buton.getValue = getValue;
    buton.onPressed = onPressed;
    return buton;
}













#endif	/* BUTTONFUNCTIONS_H */

