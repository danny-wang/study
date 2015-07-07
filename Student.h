/* 
 * File:   Student.h
 * Author: danny
 *
 * Created on March 17, 2015, 4:51 PM
 */

#ifndef STUDENT_H
#define	STUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(int,string,char);
    Student(const Student& orig);
    virtual ~Student();
    void get_value()
    {
        cin>>num>>name>>sex;
    }
    void display()
    {
        cout<<" num: "<<num<<endl;
        cout<<" name: "<<name<<endl;
        cout<<" sex: "<<sex<<endl;
    }
    int getNum()
    {
        return num;
    }
    void setNum(int i)
    {
        this->num=i;
    }
private:
    int num;
    string name;
    char sex;

};

#endif	/* STUDENT_H */

