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
        student() {cout << "���ù��캯��\n";} 
        student(int id, string name, int age): id_(id),name_(name), age_(age) {
            cout << "���ô��ι��캯��\n" << endl;
            cout << id_ << endl;
            cout << name_ << endl;
            cout << age_ << endl;
        }
        ~student() {cout << "������������\n";}
        void setData(int id, string name, int age) {
        }

};

#endif