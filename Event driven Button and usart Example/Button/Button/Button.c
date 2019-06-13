#include "Button.h"
#include "../../usart/Usart.h"

/*
 butonun olu?turlmas? ile ve kulan?lmas? ile ilgili fokstyionlar burada bulunmakta
 * buton olu?tururken ba?l? oldu?u portu ve hangi pine ba?l? oldu?jnuu giriyoun
 
 */
Button Button_initButton(volatile unsigned char *portName,unsigned char pin, void (*onPressed)(void) ){
    Button buton;
    buton.port = portName;
    buton.pin = pin;
    buton.isPressed = 0;
    buton.onPressed = onPressed;
    return buton;
}

int getThBit(char port, char connectedBit){
    return (port & (1 << connectedBit)) > 0 ? 1 : 0;
    
}

int Button_getValue(Button *button){
    
    int value =  *(button->port) ;
    
    return getThBit(value,button->pin);
}
