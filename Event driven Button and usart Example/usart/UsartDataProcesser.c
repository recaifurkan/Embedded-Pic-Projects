#include "UsartDataProcesser.h"


void initProcessor(UsartDataProcessor *processor, void (*callback)(void)){
    processor->process = callback;
}
