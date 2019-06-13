#include "Application.h"


InputController controller;






void setProcessor() {
    UsartDataProcessor _processor;
    _processor.process = usartOccured;
    Usart us = getUsart();
    us.processor = _processor;



}







void Application_setup() {
    
    Usart usart;
    USARTInit(&usart, 9600);
    
    
    setProcessor();
    controller = initInputController();

//    bUsart = &usart;

    

}

void Application_loop() {
//    usart.writeLine(value(denemem));
//    usart.writeInt(value(denemem),3);
//    usart.writeLine("");
//    getUsart().writeString("recai");

    
    InputController_checkButtons(&controller);
    //    usart.writeLine("recai");
    //    LATB = LATB << 1;


}



void usartOccured() {

    if (getUsart().isDataReady) {
        char text[20] = "";
        getUsart().readString(text, 20);

        int i = atoi(text);

        LATB = i;

        getUsart().writeInt(i, 3);
        getUsart().writeLine("");
    }

}

__interrupt() void ISR(void) // interrupt için bu kullan?l?yor
{
    if (getUsart().isDataReady) //Polling for reception interrupt
    {
        getUsart().processor.process();
    }
}




//
//
//void setController(InputController _cont){
//    controller = _cont;
//}
//
//
//
/*
 bu alttaki usarttan gelen yaz?n?n veya verini i?lenmesi için 
 * yap?lacak i?lemlerin metodu
 */

//
//void setUsart(Usart _usart){
//    usart = _usart;
//}


