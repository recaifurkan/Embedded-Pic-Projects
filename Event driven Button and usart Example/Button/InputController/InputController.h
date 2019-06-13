/* 
 * File:   InputController.h
 * Author: ByRfb
 *
 * Created on March 10, 2019, 12:26 AM
 */


/*
 burada butonlar initialize edilip 
 * her döngüde check ediliyor bas?lma ilemi yap?ld? k? diye
 
 */
#ifndef INPUTCONTROLLER_H
#define	INPUTCONTROLLER_H


#include "../../usart/Usart.h"
#include "../Button/Button.h"





/*
 bu s?n?f bütün inputlar? içinde bar?nd?r?r
 * ana prpcess k?sm? buras? buras? butonu tan?mlar ve butona bas?l?nca ne i? yap?lca??na kara rverir
 
 */

typedef struct {
    int buttonSize;
    Button buttons[2];

} InputController;

void handleButtonEvents(Button *buton);

void InputController_checkButtons(InputController *controller ) ;



InputController addButton(InputController *controller , Button *button);

 InputController initInputController();
 
















#endif	/* INPUTCONTROLLER_H */

