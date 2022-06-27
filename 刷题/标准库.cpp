#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector<int> a = {1, 2, 3, 4};
    // a.resize(10);
    // for(const auto &num : a) {
    //     cout << num << endl;
    // } 
    // cout << a.front() << endl;

    vector<int> a(100);
    int top = 0;
    for(int i = 0; i < 5; i++) {
        a[top++] = i;
    }
    int k = 5;
    while(k--) {
        cout << a[--top];
    }
}