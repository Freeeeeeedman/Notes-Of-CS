//TODO ACM模式的输入和输出的练习

//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>


using namespace std;

//TODO cin 连续输入a,b,c
void test1() {
    string a, b, c;
    cin >> a >> b >> c;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

//TODO cin, getline连续使用要去除cin保留在缓冲区的\n
//TODO 123 213 123 123
void test2() {
    string a, b, c, d;
    cin >> a >> b >> c;
    getchar();
    getline(cin, d);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;    
}

//TODO getline使用cin流，以'#'分割，但只会输出#前的字符
//TODO 123#123#123#
void test3() {
    string str;
    while(getline(cin, str, '#')) {
        cout << str << endl;
    }
}

//TODO 使用stringstream，getline()分割字符串
void test4() {
    string str;
    string s;
    stringstream ss;
    while(cin >> str) {
        cin.sync();
        ss << str;
        while(getline(ss, s, '#')) {
            cout << s << endl;
            s.clear();
        }
        str.clear();
        ss.clear();
    }
}



int main() {
    test4();
}

