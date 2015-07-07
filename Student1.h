/* 
 * File:   Student1.h
 * Author: danny
 *
 * Created on March 17, 2015, 4:55 PM
 */

#ifndef STUDENT1_H
#define	STUDENT1_H
#include "Student.h"
class Student1:public Student {
public:
    Student1(int,string,char,int ,string,char,int,string);
   
    void show_monitor(){
        cout<<endl<<"Class monitor is:"<<endl;
        monitor.display();
    }
    virtual ~Student1();
private:
    Student monitor;
    int age;
    string addr;
};

#endif	/* STUDENT1_H */

