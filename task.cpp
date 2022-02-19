#include <iostream>
#include "task.h"
using namespace std;

int Circle::numOfCircle=0;

inline  
Circle::Circle(double r=0,double x=0):radius(r),m_x(x){
std::cout<<"You creat a Circle"<<std::endl;
numOfCircle++;
}

inline 
Circle::~Circle()
{
    numOfCircle--;
    
}

inline int
Circle::returnNumOfCircle()
{
    return numOfCircle;
}

inline double 
Circle::returnX()const{
    return m_x;
}

inline void
Circle::setX(double&x){
    m_x=x;
}

inline double
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

inline void
Teacher::getStudentInfo(const Student& st1)
{
    cout<<st1.grade<<endl;
}

void getInfo(Student& st1)
{
    cout<<st1.grade<<" from friend func"<<endl;
}