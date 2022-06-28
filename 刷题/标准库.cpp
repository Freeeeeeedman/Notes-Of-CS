#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <array>
#include <tuple>
// #include <numeric>
#include <algorithm>
using namespace std;

int main() {
    // vector<int> a = {1, 2, 3, 4};
    // a.resize(10);
    // for(const auto &num : a) {
    //     cout << num << endl;
    // } 
    // cout << a.front() << endl;

    // vector<int> a(100);
    // int top = 0;
    // for(int i = 0; i < 5; i++) {
    //     a[top++] = i;
    // }
    // int k = 5;
    // while(k--) {
    //     cout << a[--top];
    // }

    // map<int, int> mp;
    // for(int i = 0; i <= 3; i++) {
    //     mp[i] = i + 1;
    // }
    // map<int, int>::iterator it;
    // for(it = mp.begin(); it != mp.end(); it++) {
    //     cout << it->second << endl;
    // }
    // map<int, int>::iterator it_2 = mp.find(1);
    // cout << it_2->first << endl;
    // cout << it_2->second << endl;

    // string str("abcdef");
    // str.push_back('1');
    // str.append("123123");
    // str.insert(0, "g");
    // tolower(str[5]);
    // cout << str << endl;
    // vector<string> strs;
    // strs.push_back("abasd");
    // for(const auto &str : strs){
    //     cout << str << endl;
    // }
    
    // array<int, 100> arr({123,4675,123});
    // array<int, 100> arr{123, 465, 12};
    // arr.front() = 2;s
    // cout << arr.front() << endl;

    // tuple<int, int, int, int> t1 = {1, 2, 3, 4};
    // cout << get<0>(t1) << endl;
    // int a, b, c, d;
    // tie(a, b, c, d) = t1;
    // cout << a << b << c << d;

    vector<int> a = {1, 2, 3, 4};
    int c = 0;
    // c = accumulate(a.begin(), a.end(), 0);
    // cout << c << endl;
    fill(a.begin(), a.end(), 5);
    for(const auto & d : a){
        cout << d << endl;
    }
    int e = 0;
    e = is_sorted(a.begin(), a.end());
    cout << e << endl;
}