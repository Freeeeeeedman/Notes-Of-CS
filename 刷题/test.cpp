#include <iostream>
#include "student.h"
using namespace std;

class Base
{
public:
    void fun(int a){
        cout << "call in Base Fun";
    }
};

class Derived : public Base
{
public:
    // using Base::fun;
};

int main()
{
    Derived d1;
    d1.fun(4);
    return 0;
}
