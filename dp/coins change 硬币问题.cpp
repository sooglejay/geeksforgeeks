//
// Created by sooglejay on 17/1/14.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>

//http://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
using namespace std;

//dp[i]：表示i元所需的最小的硬币数量，初始化为无穷大
//则dp[i-A[j]]如果不为无穷大，说明，存在一个表示i-A[j]元的方式，所需硬币为dp[i-A[j]]
// 因为 i= i - A[j] + A[j] 这个看似废话，其实揭示了一个等量关系：dp[i]=dp[i-A[j]]+1
int dp[100001];

int func(int *A, int n, int m) {
    for (int i = 0; i <= m; ++i) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int j = 1; j <= m; ++j) {

        for (int i = 0; i < n; ++i) {

            if (j >= A[i]) {
                if (dp[j - A[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - A[i]] + 1);
                }
            }
        }
    }
    return dp[m] == INT_MAX || dp[m] == 0 ? -1 : dp[m];
}

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << func(A, n, m) << endl;
    }

}
