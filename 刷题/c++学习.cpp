#include <bits/stdc++.h>
#include "student.h"
using namespace std;
// #define DEBUG

int i = 114514;
int sum(int a, int b);
int sum(int);

template <class T>
T max_(T, T);


class SubObject {
    private: 
        int num_;
    public: 
        SubObject(int num): num_(num) {}
        void getNum() {cout << num_ << endl;}

};


template <class T>
class Base {
    public: 
        Base(): id_(1) {}
        Base(int id, int a): id_(id), a_(a) {}
        void getId() {cout << id_ << endl;}
        int a_;
        friend void friendFunc(Base<T> base) {
            cout << base.id_ << endl;
        }
    protected:
        void getInfo() {cout << "getInfo" << endl;}
    
    private:
        int id_;
        T test_;
};

class Base2 {
    private:
        int id_;
    public:
        Base2(int a): a_(a){}
        int a_;

};

// class Child : public Base<int>{
template <class T1, class T2> 
class Child : private Base<T2>, public Base2{
    private:
        T1 x_;
        SubObject subObj;
    public:
        Child(int x, int id, int a, int num) : x_(x), Base<T2>::Base(id, a), Base2(a), subObj(num){}//将名字引入到当前的作用域中
        void getCId() {this->getId();}
        void getCInfo() {this->getInfo();}//隐形依赖，二步查询
        void getX() {cout << x_ << endl;}
        void showNum() {subObj.getNum();}
        void getA() {cout << Base2::a_ << endl;}//解决二义性问题
};  

class Test {
    private: 
        int i_;

    public:
        static int n_; 
        static void printN();   
        int j_;
        Test(): i_(0), j_(0){}
        Test(int i, int j): i_(i), j_(j) {} 
        void set(const int &i_) {
            this->i_ = i_;
        }
        const int &get() {
            return i_;
        }
        void showI() const{
            cout << this->i_ << endl;
        }
};

int Test::n_ = 114514;
void Test::printN() {
    cout << n_ << endl;
}

int sum(int a, int b) {
    return a + b;
}

int sum(int a) {
    return a + 3;
}

template <class T>
T max_(T a, T b) {
    return a > b ? a : b;
}


class Complex {
    private:
        double real_;
        double imag_;
    
    public:
        Complex(double real, double imag): real_(real), imag_(imag){}
        ~Complex(){}
        const double &getReal() const{return real_;}
        const double &getImag() const{return imag_;} 
        Complex operator+(const Complex &a);
        friend Complex operator-(const Complex &a, const Complex &b);
        friend ostream& operator<< (ostream &output, const Complex &a);
        operator double() const; 
};

inline Complex
Complex::operator+(const Complex &a) {
    return Complex(a.real_ + this->real_, a.imag_ + imag_);
}

Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.real_ - b.real_, a.imag_ - b.imag_);
}

ostream& operator<<(ostream &output, const Complex &a) {
    output << "real = " << a.real_ << endl;
    output << "imag = " << a.imag_ << endl;
    return output;
}

inline 
Complex::operator double() const {
    return this->real_;
}

class B0 {
    private:
        int b0_;
        virtual void printB() {
            cout << "B0::printB()" << endl;
        }        
    public:
        B0(int b0): b0_(b0){} 

        virtual ~B0() {
            cout << "调用了B0的析构函数" << endl;
        }
        virtual void show() = 0;
};

class B1:public B0{
    private:
        int b1_;
    public:
        B1(int b0, int b1):B0(b0), b1_(b1){} 
        virtual void printB() {
            cout << "B1::printB()" << endl;
        }
        virtual ~B1() {
            cout << "调用了B1的析构函数" << endl;            
        }
        virtual void show() {
            cout << "show" << endl;
        }    
};

    return Complex(a.real_ + real_, a.imag_ + imag_);
}


int main() {

    #ifdef DEBUG
        student a;
        student b(10, "sun", 10);
        student *c = &b;
        // int i = 1919810;
        // cout << i << endl;
        // cout << ::i << endl;
        // cout << sum(2) << endl;
        // cout << max_(1.2, 1.34) << endl;

        // Child<int, int> child(10, 100, 50, 1000);
        // child.getX();
        // child.getCId();
        // child.getCInfo();
        // child.showNum();
        // child.getA();
        // child.getId();

        // Base<int> bases[3] = {Base<int>(0, 1), Base<int>(1, 2)};
        // Child<int, int> *cd = &child;
        // cout << cd->Base2::a_ << endl;
        // void (Child<int, int>::*p1)();
        // p1 = &Child<int, int>::getCId;
        // (child.*p1)();

        // Test t1(10, 11);
        // Test t3(1000, 1001);
        // const Test &t2 = t1;
        // t2.showI();
        // Test *const pt1 = &t1;
        // // pt1 = &t2;
        // pt1->set(100);
        // pt1->showI();
        // const Test *pt = &t3;
        // cout << pt->j_ << endl;
        // pt->showI();

        // const int &a = t1.get();
        // cout << ++a << endl;

        // Base<int> b1(10, 11);
        // friendFunc(b1);

        // cout << Test::n_ << endl;
        // cout << t1.n_ << endl;
        // Test::printN();
        // t1.printN();

        // int *ptr = new int(5);
        // cout << *ptr << endl;
        // delete ptr; 

        // int *p = new int[20];
        // p[10] = 100;
        // delete []p;

        // Complex c1(1, 2);
        // Complex c2(2, 3);
        // Complex c3 = c1 + c2;
        // double real = c3.getReal();
        // cout << real << endl;
        // Complex c4 = c1 - c2;
        // double real4 = c4.getReal();
        // cout << real4 << endl;
        // cout << c1 << endl;

        // Complex c5(1.2, 2.3);
        // double a = 1.7 + 2 + c5;
        // cout << a << endl;

        // B0 b0(1);
        // B1 b1(1, 0);
        // b0.printB();
        // b1.printB(); 

        // B0 *p;
        // p = new B1(1, 0);
        // delete p;                   

        // B1 b1(1, 2);
        // b1.printB();
        // // b1.show();   

        // Complex c1(1, 2);
        // Complex c2(2, 3);
        // Complex c3 = c1 + c2;
        // double real = c3.getReal();
        // cout << real << endl;        
    #endif




    


}




