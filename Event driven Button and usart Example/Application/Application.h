/* 
 * File:   Application.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 17:47
 */



#define _XTAL_FREQ 8000000

#ifndef APPLICATION_H
#define	APPLICATION_H




#include "../ConfigBits.h"

#include "../usart/Usart.h"
#include "../Button/InputController/InputController.h"





__interrupt() void ISR(void);

void usartOccured();
//void setController(InputController _cont);
//
//
void setProcessor();
//
//void setUsart(Usart _usart);

void Application_setup();

void Application_loop();

#endif	/* APPLICATION_H */


/*
 sistemin tan?ml? usart varsa onu getirir
 */


