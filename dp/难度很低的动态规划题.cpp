//
// Created by sooglejay on 17/4/18.
//

//http://practice.geeksforgeeks.org/problems/largest-zigzag-sequence/0

#include <iostream>
#include <string.h>

#define MAX 101
using namespace std;

int walk(int arr[MAX][MAX], int n) {
    int dp[MAX][MAX];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[n - 1][i] = arr[n - 1][i];
    }
    for (int j = n - 2; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            int row = j + 1;
            for (int k = 0; k < n; ++k) {
                if (k == i)continue;
                sum = max(sum, dp[row][k]);
            }
            dp[j][i] = sum + arr[j][i];
        }
    }
    int res = 0;
    for (int l = 0; l < n; ++l) {
        res = max(res, dp[0][l]);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int arr[MAX][MAX];
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << walk(arr, n) << endl;
    }
}