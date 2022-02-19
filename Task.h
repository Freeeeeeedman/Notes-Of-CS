#ifndef _TASK_
#define _TASK_
using namespace std;

class Circle
{
    public:
  
        Circle(double,double);
        double returnR()const;
        double returnX()const;    
        void setX(double&);
        static int returnNumOfCircle();
        ~Circle();
    private:
        double radius;
        double m_x;
        static int numOfCircle;
    protected:
      

};


class IntArray
{
    public:
        IntArray(int size=10):msize(size){
            mptr=new int[msize];
            
        }
        ~IntArray(){
            delete[]mptr;
            std::cout<<"delete it"<<std::endl;
        }
        IntArray(const IntArray &arr){
            msize=arr.msize;
            mptr= new int[msize];
        }
        IntArray& operator=(const IntArray& arr)
        {
            if(this==&arr){return *this;}
            delete[]mptr;
            mptr=new int(arr.msize);
            msize=arr.msize;
            return *this;
        }



        int returnSize()const{return msize;}
    private:
        int msize;
        int *mptr;
      
};

class Point
{
    public:
        Point(int x_=0,int y_=0):x(x_),y(y_){}
        int returnX()const{return x;}
        Point& returnPoint(){return *this;}
        const Point* returnPointp()const {return this;}
    private:
        int x;
        const int y;

};


class Student;
void getinfo(Student&);
class Teacher
{
    public:
       void getStudentInfo(const Student&);
};


class Point1
{
    public:
        Point1(int x_=0,int y_=0):x(x_),y(y_){cout<<"you create a point"<<"x="<<x<<endl;}
        
    private:
        int x,y;
};

class Ofpoint
{
    public:
        Ofpoint(int data_=0):p1(data_,1),data(data_){}
    private:
        Point1 p1;
        int data;
};

class Person
{
    
    private:
        
    
    protect:
        int height;
        char* name;


}





















#endif