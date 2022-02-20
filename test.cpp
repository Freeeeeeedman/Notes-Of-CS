#include <iostream>
#include "task.h"
#include "task.cpp"
using namespace std;
void test1(),test2(),test3(),test4(),test5(),Print(const Base&,const int),test6(),test7();
int main()
{
   test6();


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

void test5()
{   Base base1;
    Derive1 derive1;
    derive1.showData(100);
    Print(base1,-100);
    Print(derive1,100);

}

void Print(const Base& base,const int data_)
{
    base.show(data_);

}

void test6()
{
    Derive3 derive3;
    derive3.show(300);
}

void test7()
{
    //Test test1;
}