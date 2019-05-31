/* 
 * File:   InputControllerFunctions.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 18:19
 */
#include "../Button/Button.h"


#include "../Button/ButtonFunctions.h"


#include "InputController.h"
#include "../ButonlarSpesific/Buton1.h"
#include "../ButonlarSpesific/Buton2.h"
#ifndef INPUTCONTROLLERFUNCTIONS_H
#define	INPUTCONTROLLERFUNCTIONS_H


/*
 buras? e?er butona i?lem için bas?ld?ysa 
 * belirlene  metdou çal??t?r?r
 
 */
void handleButtonEvents(Button *buton) {
//     LATB = LATB << 1;
    if (buton->getValue()) {
//         LATB = LATB << 1;
        if (buton->isPressed == 0) {
            buton->onPressed();
//            LATB = LATB << 1;

        }
        buton->isPressed = 1;


    } else {
        buton->isPressed = 0;
    }
}

/*
 butona bas?ld? m? diue kontrol eder
 
 */
void chectButtons(InputController *controller ) {
    int i;
    //    direkButonunBasiliOlmasinaGore();
// LATB = LATB << 1;
    for (i = 0; i < controller->buttonSize; i++) {
//         LATB = LATB << 1;
        Button *buton = controller->buttons[i];
        handleButtonEvents(buton);

    }




}

/*
 buton ekleme i?ini yapar
 
 */
 InputController addButton(InputController *controller , Button *button){
     controller->buttons[(controller->buttonSize)] = button;
     (controller->buttonSize) = (controller->buttonSize)+1;
     return *controller;
     
 }
/*
 kendisi 2 tane buton olu?turup controllri geri döndürür
 
 */
 InputController initInputController( void (*_chectButtons)(void)) {
    InputController controller;
    controller.chectButtons = _chectButtons;
    Button button1 = initButton("PORTDbits.RD0",btn1getValue, btn1Func);
    Button button2 = initButton("PORTDbits.RD1",btn2getValue, btn2Func);
    addButton(&controller,&button1);
    addButton(&controller,&button2);
    return controller;

}
 
/*
 
 butona bas?ld? m? kontrol edecek olan metodun kendsi otomatik belirlendi?i fonksyion
 
 */
 InputController initInputControllerDefaultFunction(void) {
    
    return initInputController(chectButtons);

}

#endif	/* INPUTCONTROLLERFUNCTIONS_H */

