#include <iostream>

using namespace std;

class Animal {
    public:
        void showA() {
            cout << "Animal!" << endl; 
        }
        virtual void show() {
            cout << "Animal!" << endl;
        }
};

class Cat : public Animal{
    public:
        void showCat() {
            cout << "Cat!" << endl;
        }
        virtual void show() {
            cout << "Cat!" << endl;
        }
        void showA() {
            cout << "Cat!" << endl;            
        }        
};

int tmpValue() {
    int *p = new int(1);
    int q = *p;
    return q;
}

class Person{
public:
    Person()
    {   
        cout << "无参构造函数!" << endl;
    }   
    Person(int a)
    { 
        m_age = a;
        cout << "有参构造函数!" << endl;
    }
    Person(const Person &p)
    { 
        m_age = p.m_age;
        cout << "拷贝构造函数!" << endl;
    }
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
    int fun(Person p) //普通的成员函数，注意参数是以值的方式调用的
    {
        p.m_age = 20; //这里修改对外界没有印象
        return p.m_age;
    }
    int m_age;  
};
 

int main() {
    // Cat c;
    // Animal *a = &c;
    // a->show();
    // a->showA();
    // Animal &x = c;
    // x.show();
    // x.showA();
    // int a = tmpValue();
    // cout << a << endl;
    Person p;
    p = 1000; 

    // Person per = 1000;
    return 0;
}
