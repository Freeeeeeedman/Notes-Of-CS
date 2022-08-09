#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> vec {1, 2, 3, 4, 5};
    for(int i = 0, j = vec.size() - 1; i < vec.size(), j >= 0; ++i, --j) {
        cout << vec[i] << " " << vec[j] << endl;
    }
}
