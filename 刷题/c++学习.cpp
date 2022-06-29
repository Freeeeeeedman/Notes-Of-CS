#include <bits/stdc++.h>
#include "student.h"
using namespace std;

int i = 114514;
int sum(int a, int b);
int sum(int);
// #define DEBUG
int main() {

    #ifdef DEBUG
        student a;
        student b(10, "sun", 10);
        student *c = &b;
    #endif

    // int i = 1919810;
    // cout << i << endl;
    // cout << ::i << endl;
    // cout << sum(2) << endl;



}

int sum(int a, int b) {
    return a + b;
}

int sum(int a) {
    return a + 3;
}

template <class T>
T max(T a, T b) {
    return a > b ? a : b;
}