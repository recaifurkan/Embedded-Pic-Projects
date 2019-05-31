/* 
 * File:   Settings.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 17:20
 */
/*
 
 uygulama için internal ossicalorun kullan?ld??? ve b d portlar?na ç?k?? atayan i?lemler
 * burada yap?lmakta
 */
#ifndef SETTINGS_H
#define	SETTINGS_H

void setupSettings() {
    OSCCON = 0x72; //   Use internal oscillator of 8MHz Frequency 

}

void setPortInputsOutputs(){
    TRISB = 0x00;
    //    TRISC = 0x00;
    TRISD = 0x03;
}

#endif	/* SETTINGS_H */

