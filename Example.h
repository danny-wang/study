/* 
 * File:   Example.h
 * Author: danny
 *
 * Created on July 7, 2015, 3:50 PM
 */

#ifndef EXAMPLE_H
#define	EXAMPLE_H
#include <iostream>
int numAdd(int ,int );

int numMinus(int, int);

typedef int (*PtrFuncTwo)(int ,int);

int algo(int a, int b, PtrFuncTwo pft);

class CA
{
public:
    int caAdd(int a,int b){return a+b;}
    int caMinus(int a,int b){return a-b;}
};

typedef int (CA::*PtrCaFuncTwo)(int,int);


class FuncT
{
public:
    template <typename T>
    T operator()(T i,T j)
    {
        std::cout<<i<<"+"<<j<<"="<<i+j<<std::endl;
        return i;
    }
};

template <typename T>
T addFuncT(T i, T j,FuncT& funct)
{
    funct(i,j);
    return i;
}
#endif	/* EXAMPLE_H */

/**
 how to use it:
 * 
 * int a=algo(1,2,numAdd);
   cout<<a<<endl;
 * 
 *  PtrCaFuncTwo pFunction=&CA::caAdd;
    CA ab;
    int c=(ab.*pFunction)(1,2);
    cout<<c<<endl;
 * 
 * 
 *  FuncT funct;
    addFuncT(2,4,funct);
    addFuncT(1.2,5.6,funct);
 */