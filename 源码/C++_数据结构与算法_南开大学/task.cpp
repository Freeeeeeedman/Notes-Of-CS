#include <iostream>
#include "task.h"
using namespace std;

int Circle::numOfCircle=0;


Circle::Circle(double r=0,double x=0):radius(r),m_x(x){
std::cout<<"You creat a Circle"<<std::endl;
numOfCircle++;
}


Circle::~Circle()
{
    numOfCircle--;
    
}

int
Circle::returnNumOfCircle()
{
    return numOfCircle;
}

double 
Circle::returnX()const{
    return m_x;
}

void
Circle::setX(double&x){
    m_x=x;
}
double
Circle::returnR()const{
    return radius;
}

class Student
{
    private:
        double grade= 100;
    friend void getInfo(Student&);
    friend class Teacher;
};

void
Teacher::getStudentInfo(const Student& st1)
{
    cout<<st1.grade<<endl;
}

void getInfo(Student& st1)
{
    cout<<st1.grade<<" from friend func"<<endl;
}