#include <iostream>
#include <vector>
using namespace std;

void bag01_2d() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    for(int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }
    for(int i = 1; i < weight.size(); i++) {
        for(int j = 0; j <= bagweight; j++) {
            if(weight[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        } 
    }
    cout << dp[weight.size() - 1][bagweight] << endl;
}

void bag01_1d() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    vector<int> dp(bagweight + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = bagweight; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagweight] << endl;
}

void bag01_1d_() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20 ,30};
    int bagweight = 4;
    vector<int> dp(bagweight + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = bagweight; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagweight] <<endl;
}

void bagmuti_01() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    vector<int> nums = {2, 3, 2};
    int bagWeight = 10;
    for(int i = 0; i < nums.size(); i++) {
        while(nums[i] > 1) {
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) {
        for(int j = bagWeight; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] <<endl;
}


int main() {
    bagmuti_01();
}