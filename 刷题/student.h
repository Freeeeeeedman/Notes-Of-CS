#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <bits/stdc++.h>
using namespace std;
extern int a;
const int b = 1;
class student {
    private:
        int id_;
        string name_;
        int age_;
    public:
        student() {cout << "调用构造函数\n";} 
        student(int id, string name, int age): id_(id),name_(name), age_(age) {
            cout << "调用带参构造函数\n" << endl;
            cout << id_ << endl;
            cout << name_ << endl;
            cout << age_ << endl;
        }
        ~student() {cout << "调用析构函数\n";}
        void setData(int id, string name, int age) {
        }

};

#endif