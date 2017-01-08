//
// Created by sooglejay on 17/1/8.
//

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1542
//思想就是： 走一步看一步，总有一步是最优的
#include<iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int func(int dp[], int p, int x, int y) {

    int sm = x < y ? x : y;
    for (int m = 0; m <= p; ++m) {
        dp[m] = m;
    }
    for (int l = sm; l <= p; ++l) {
        for (int i = x; i <= l && i != 1; i = i * x) {
            dp[l] = min(dp[l], dp[l - i] + 1);
        }
        for (int i = y; i <= l && i != 1; i = i * y) {
            dp[l] = min(dp[l], dp[l - i] + 1);
        }
    }
    return dp[p];
}

int main() {
    int t;
    int dp[100001];
    cin >> t;
    while (t--) {
        int p, x, y;
        cin >> p >> x >> y;
        cout << func(dp, p, x, y) << endl;
    }
}