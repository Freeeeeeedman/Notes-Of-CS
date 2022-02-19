#include<iostream>
#include"task.h"
#include"task.cpp"
using namespace std;

int main()
{

Circle circle1;
Circle circle2(2,4);
cout<<circle1.returnX()<<endl;
double a=100;
circle1.setX(a);
cout<<circle1.returnX()<<endl;
cout<<Circle::returnNumOfCircle()<<endl;
return 0;

}
