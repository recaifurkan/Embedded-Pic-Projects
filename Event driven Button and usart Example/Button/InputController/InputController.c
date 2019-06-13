

#include "InputController.h"



/*
 buras? e?er butona i?lem için bas?ld?ysa 
 * belirlene  metdou çal??t?r?r
 
 */
void handleButtonEvents(Button *buton) {
//     LATB = LATB << 1;
//    if(Button_getValue(buton) ==1){
//    getUsart().writeInt(PORTD,2);
//    getUsart().writeInt(*(buton->port),2);
//    getUsart().writeLine("");

//    if(&PORTD != buton->port){
//        getUsart().writeLine("same");
//    }
//    }
           

    if (Button_getValue(buton) == 1) {

//         LATB = LATB << 1;
         
        if (buton->isPressed == 0) {
            buton->onPressed();
            getUsart().writeInt(buton->isPressed,2);
    getUsart().writeLine("");
            
//            LATB = LATB << 1;

        }
        buton->isPressed = 1;
          


    } 
    else{
         buton->isPressed = 0;
    }
   
    
    
}

/*
 butona bas?ld? m? diue kontrol eder
 
 */
void InputController_checkButtons(InputController *controller ) {
    int i;
    //    direkButonunBasiliOlmasinaGore();
// LATB = LATB << 1;
    for (i = 0; i < controller->buttonSize; i++) {
//         LATB = LATB << 1;
        Button buton = controller->buttons[i];
        
        handleButtonEvents(&buton);
        

    }




}

/*
 buton ekleme i?ini yapar
 
 */
 InputController addButton(InputController *controller , Button *button){
     controller->buttons[(controller->buttonSize)] = *button;
     (controller->buttonSize) = (controller->buttonSize)+1;
     return *controller;
     
 }
 
 /*
  
  
  button 1 için onpressed metodu giriliyor
  */
 


void btn1Func() {
    LATB = LATB << 1;
    int deger = 5;
    getUsart().writeInt(deger,2);
    getUsart().writeString("\r\n");
}
/*
 bu alttaki de button 2 ye ba?l?nca yap?lacak i?lemi giriyor
 */

void btn2Func() {

    LATB = LATB >> 1;
     int deger = -5;
    getUsart().writeInt(deger,2);
    getUsart().writeString("\r\n");
//    usart.writeLine("2ye bas?ld?");
}
 
 
/*
 kendisi 2 tane buton olu?turup controllri geri döndürür
 
 */
 InputController initInputController() {
    InputController controller;

    
    Button button1 = (Button_initButton(&PORTD,0, btn1Func));
    Button button2 = (Button_initButton(&PORTD,1, btn2Func));
    addButton(&controller,&button1);
    addButton(&controller,&button2);
    return controller;

}
 

