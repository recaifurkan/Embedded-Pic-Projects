# 1 "usart/UsartDataProcesser.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "E:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "usart/UsartDataProcesser.c" 2
# 1 "usart/UsartDataProcesser.h" 1
# 15 "usart/UsartDataProcesser.h"
typedef struct{
     void (*process)(void);
}UsartDataProcessor;



void initProcessor(UsartDataProcessor *processor, void (*callback)(void));
# 1 "usart/UsartDataProcesser.c" 2



void initProcessor(UsartDataProcessor *processor, void (*callback)(void)){
    processor->process = callback;
}
