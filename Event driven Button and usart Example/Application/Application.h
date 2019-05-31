/* 
 * File:   Application.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 17:47
 */


#define _XTAL_FREQ 8000000
#include "../ConfigBits.h"
#include <stdint.h>
#include "../usart/usart.h"
#include "../Button/InputController/InputController.h"


#ifndef APPLICATION_H
#define	APPLICATION_H



__interrupt() void ISR(void);

void usartOccured();
//void setController(InputController _cont);
//
//
void setProcessor();
//
//void setUsart(Usart _usart);

void setup();

void loop();

#endif	/* APPLICATION_H */

