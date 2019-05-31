

#include <stdint.h>
#include "ConfigBits.h"
#include "Settings.h"

#include "Application/Application.h"
/*
 
 ana atamalar? yapt?ktan sonra application?n haz?rland??? main dosya
 
 */
void main(void) {
    setupSettings();
    setPortInputsOutputs();

    LATB = 0x01;

    //    setController(controller);
    //    setUsart(usart); // applicationda kullanbilmek için bunu buaray koyduk
    setup();

    while (1) {

        //      
        loop();

        //        
        //    }


        //        LATB s= 0x01;
    }

    return;
}