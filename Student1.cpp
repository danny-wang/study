/* 
 * File:   Student1.cpp
 * Author: danny
 * 
 * Created on March 17, 2015, 4:55 PM
 */

#include "Student1.h"

Student1::Student1(int a,string b,char c ,int d ,string e,char f,int g,string h) :Student(a,b,c),monitor(d,e,f){
    age=g;
    addr=h;

}



Student1::~Student1() {
}

