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
#include <stdint.h>
#include "../Button/Button.h"

/*
 bu s?n?f bütün inputlar? içinde bar?nd?r?r
 * ana prpcess k?sm? buras? buras? butonu tan?mlar ve butona bas?l?nca ne i? yap?lca??na kara rverir
 
 */

typedef struct {
    uint8_t buttonSize;
    Button *buttons[10];
    
    void (*chectButtons)(void);
} InputController;















#endif	/* INPUTCONTROLLER_H */

