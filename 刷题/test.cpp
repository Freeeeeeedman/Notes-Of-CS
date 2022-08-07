#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main() {
    set<int> st;
    st.insert(1);
    st.insert(2);
    cout << int(st.find(123) != st.end()) << endl;
}
