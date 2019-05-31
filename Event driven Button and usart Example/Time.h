/* 
 * File:   Time.h
 * Author: ByRfb
 *
 * Created on March 9, 2019, 11:58 PM
 */

#ifndef TIME_H
#define	TIME_H

long time;

long getTime() {
    return time / 165;
}

void tickTime() {
    time++;
}

void MSdelay(unsigned int val) {
    unsigned int i, j;
    for (i = 0; i < val; i++)
        for (j = 0; j < 165; j++); /*This count Provide delay of 1 ms for 8MHz Frequency */
}
void setWaitTime(long *_waitTime, int setValue) {



    *_waitTime += setValue;


}

void ekleWaitTime(long *_waitTime, int setValue) {

    if (*_waitTime != 500) {
        setWaitTime(_waitTime, setValue);
    }


}

void cikarWaitTime(long *_waitTime, int setValue) {

    if (*_waitTime != 1000) {
        setWaitTime(_waitTime, setValue);
    }



}

#endif	/* TIME_H */

