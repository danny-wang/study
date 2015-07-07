/* 
 * File:   Example.cpp
 * Author: danny
 * 
 * Created on July 7, 2015, 3:50 PM
 */

#include "Example.h"

int numAdd(int a,int b)
{   
    return a+b;
}
int numMinus(int a, int b)
{
    return a-b;
}

int algo(int a, int b, PtrFuncTwo pft)
{
    return pft(a,b);
}