#include "Application.h"


#include "../Button/InputController/InputControllerFunctions.h"
#include "../usart/UsartSetFunctions.h"




Usart usart;
InputController controller;

void setProcessor() {
    UsartDataProcessor _processor;
    _processor.process = usartOccured;

    usart.processor = _processor;



}

void setup() {
    controller = initInputControllerDefaultFunction();
    USARTInit(&usart, 9600);

    setProcessor();
    setButton1Usart(&usart);
//    bUsart = &usart;

}

void loop() {
    chectButtons(&controller);
    //    usart.writeLine("recai");
    //    LATB = LATB << 1;


}

void usartOccured() {

    if (usart.isDataReady) {
        char text[20] = "";
        usart.readString(text, 20);

        int i = atoi(text);

        LATB = i;

        usart.writeInt(i, 3);
        usart.writeLine("");
    }

}

__interrupt() void ISR(void) // interrupt için bu kullan?l?yor
{
    if (usart.isDataReady) //Polling for reception interrupt
    {
        usart.processor.process();
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


