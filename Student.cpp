/* 
 * File:   Student.cpp
 * Author: danny
 * 
 * Created on March 17, 2015, 4:51 PM
 */

#include "Student.h"

Student::Student(int n,string nm,char x) {
    num=n;
    name=nm;
    sex=x;
}

Student::Student(const Student& orig) {
}

Student::~Student() {
}

