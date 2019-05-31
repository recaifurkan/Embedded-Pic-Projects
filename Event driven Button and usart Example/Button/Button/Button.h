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
    char * portName;
    int isPressed;
    int (*getValue)(void);
    void (*onPressed)(void);
} Button;






#endif	/* BUTTON_H */

