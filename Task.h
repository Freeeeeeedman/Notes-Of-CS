#ifndef _TASK_
#define _TASK_
#include <iostream>
/*
class Circle
{
    public:
        //Circle();
        //Circle(double,double);
        Circle(double r=0,double x=0):radius(r),m_x(x){
            std::cout<<"You creat a Circle"<<std::endl;
        }
        double returnR()const;
        double returnX()const;    
        void setX(double&);
        //static int returnNumOfCircle();
        //~Circle();
    private:
        double radius;
        double m_x;
        //static int numOfCircle;
    protected:
      

};

*/















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



















#endif