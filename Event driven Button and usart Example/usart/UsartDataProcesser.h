/* 
 * File:   UsartDataProcesser.h
 * Author: ByRfb
 *
 * Created on 10 Mart 2019 Pazar, 13:12
 */

#ifndef USARTDATAPROCESSER_H
#define	USARTDATAPROCESSER_H
/*
 process ediecek olan metodun i�inde bulundu s?n?f
 
 */

typedef struct{
     void (*process)(void);
}UsartDataProcessor;
// e?er usarttan bilgi geli?i olmu?sa bu fonksiyona d�?er





#endif	/* USARTDATAPROCESSER_H */

