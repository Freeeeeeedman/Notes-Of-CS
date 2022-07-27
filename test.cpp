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
        cout << "�޲ι��캯��!" << endl;
    }   
    Person(int a)
    { 
        m_age = a;
        cout << "�вι��캯��!" << endl;
    }
    Person(const Person &p)
    { 
        m_age = p.m_age;
        cout << "�������캯��!" << endl;
    }
    ~Person()
    {
        cout << "��������!" << endl;
    }
    int fun(Person p) //��ͨ�ĳ�Ա������ע���������ֵ�ķ�ʽ���õ�
    {
        p.m_age = 20; //�����޸Ķ����û��ӡ��
        return p.m_age;
    }
    int m_age;  
};
 


class Man {
    public:
    Man(){
        cout << "call Man::Man()" << endl;
    }
    Man(string n, int a):name(n),age(a) {
        cout << "call Man::Man(string, int)" << endl;
    }
    Man(const Man& a) {
        cout << "call Man::Man(const Man&)" << endl;
    }
    Man& operator=(const Man& a) {
        name = a.name;
        age = a.age;
        cout << "call Man::operator=(const Man& a)" << endl;
        return *this;
    }
    private:
    string  name;
    int   age;
};

// class ChineseMan {
//     public:
//     ChineseMan(Man a, string i) {
//         man = a;
//         id = i;
//     }
//     private:
//     string  id;
//     Man   man;
// };

class ChineseMan {
public:
  ChineseMan(Man a, string i):man(a), id(i) {}
private:
  string  id;
  Man   man;
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
    // Person p;
    // p = 1000; 

    Man vincent("vincent", 26);
    cout << "-----------" << endl;
    ChineseMan vincent_CN(vincent, "001");
    return 0;
}
