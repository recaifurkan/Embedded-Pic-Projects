/* 
 * File:   ProcessorFunctions.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 19:06
 */
/*
 usart için e?er veri gelirse i?leyecek olan k?s?m?n olu?turulmas? na yarayan fonks?ypn
 
 */

#ifndef PROCESSORFUNCTIONS_H
#define	PROCESSORFUNCTIONS_H

void initProcessor(UsartDataProcessor *processor, void (*callback)(void)){
    processor->process = callback;
}

#endif	/* PROCESSORFUNCTIONS_H */

