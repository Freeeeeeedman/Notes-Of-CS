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


class Base
{
    public:
        Base(int data_=0):base_data(data_){cout<<"调用了Base的构造函数"<<endl;}
        ~Base(){cout<<"调用了Base的析构函数"<<endl;}
        void showData()const{cout<<"base_data="<<base_data<<endl;}
        virtual void show(const int data_)const{cout<<"这是Base.show(),输入值为"<<data_<<endl;}
    private:
        int base_data;
    protected:
        int protect_data;
};

class Derive1:virtual public Base
{
    public:
        Derive1(int data_=1):derived1_data(data_){cout<<"调用了Derived1的构造函数"<<endl;}
        ~Derive1(){cout<<"调用了Derived1的析构函数"<<endl;}
        void showData(const int data_)const{cout<<"这是函数重定义,"<<"输入值="<<data_<<endl<<"derived1_data="<<derived1_data<<endl;}
        void show(const int data_)const{cout<<"这是Drived1.show(),输入值为"<<data_<<endl;}
    private:
        int derived1_data;
};

class Derive2:virtual public Base
{
    public:
        Derive2(int data_=1):derived2_data(data_){cout<<"调用了Derived2的构造函数"<<endl;}
        ~Derive2(){cout<<"调用了Derived2的析构函数"<<endl;}
        void showData(const int data_)const{cout<<"这是函数重定义,"<<"输入值="<<data_<<endl<<"derived2_data="<<derived2_data<<endl;}
        void show(const int data_)const{cout<<"这是Drived2.show(),输入值为"<<data_<<endl;}
    private:
        int derived2_data;
};


class Derive3:public Derive1,public Derive2
{
    public:
        Derive3(int data_=1000,int data_1=1001,int data_2=1002):Derive1(),Base(data_1),Derive2(data_2){cout<<"调用了Derived3的构造函数"<<endl;}
        ~Derive3(){cout<<"调用了Derived3的析构函数"<<endl;}
        void show(const int data_)const{cout<<"这是Drived3.show(),输入值为"<<data_<<endl;}
    private:
        int derived3_data;
};





















#endif