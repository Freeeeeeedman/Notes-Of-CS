#include <iostream>
#include "task.h"
#include "task.cpp"
using namespace std;
void test1(),test2(),test3(),test4();
int main()
{
   test4();


}

void test1()
{
    Circle circle1;
    Circle circle2(2, 4);
    cout << circle1.returnX() << endl;
    double a = 100;
    circle1.setX(a);
    cout << circle1.returnX() << endl;
    cout << Circle::returnNumOfCircle() << endl;
}

void test2()
{
    Point p1(1, 2);
    cout << p1.returnPointp() << endl;
}

void test3()
{
   Student st1;
    Student*st2=&st1;
    Teacher te1;
    te1.getStudentInfo(st1);
    getInfo(*st2); 
}

void test4()
{
    Ofpoint(2);
}