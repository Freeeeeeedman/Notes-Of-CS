#ifndef _TASK_
#define _TASK_


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


#endif