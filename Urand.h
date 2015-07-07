/* 
 * File:   Urand.h
 * Author: danny
 *
 * Created on April 21, 2015, 5:09 PM
 */

#ifndef URAND_H
#define	URAND_H
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;
template<int upperBound>
class Urand {
public:
   
    Urand(bool recycle=false);
    int operator()();
    void printContent();
   
  
private:
    int used[upperBound];
    bool recycle;
};

template<int upperBound>
Urand<upperBound>::Urand(bool recyc): recycle(recyc) {
    memset(used, 0, upperBound * sizeof (int));
    srand(time(0)); // Seed random number generator
}

template<int upperBound>
int Urand<upperBound>::operator()() {
    if (!memchr(used, 0, upperBound)) {
        if (recycle)
            memset(used, 0, sizeof (used) * sizeof (int));
        else
            return -1; // No more spaces left
    }
    int newval;
    while (used[newval = rand() % upperBound])
        ; // Until unique value is found
    used[newval]++; // Set flag
    return newval;
}

template<int upperBound>
void Urand<upperBound>::printContent(){
 for(int i=0; i<upperBound;i++)
        cout<<used[i]<<" ";
}
#endif	/* URAND_H */

