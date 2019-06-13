/* 
 * File:   Button.h
 * Author: ByRfb
 *
 * Created on March 10, 2019, 12:32 AM
 */
#include <stdio.h>
#ifndef BUTTON_H
#define	BUTTON_H

/*
 bu class buton yerine kullan?lmaktad?r altta zaten
 * hangi verileri tuutu?u yazmakta
 
 
 */

typedef struct {
    unsigned char *port;
    unsigned char pin;
    int isPressed;
    void (*onPressed)(void);
} Button;

Button Button_initButton(volatile unsigned char *portName,unsigned char pin, void (*onPressed)(void) );


int Button_getValue(Button *button);






#endif	/* BUTTON_H */

