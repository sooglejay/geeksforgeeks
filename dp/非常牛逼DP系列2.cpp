//
// Created by sooglejay on 17/1/10.
//

#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;
// mine: 0.082
int func(int *dp, int *A, int n, int i) {
    if (n == 1) {
        return A[0];
    } else if (n == 2) {
        return min(A[0], A[1]);
    }
    if (i + 2 >= n) {
        return 0;
    }
    if (dp[i] > 0) {
        return dp[i];
    }

    int a = A[i] + func(dp, A, n, i + 1);
    int b = INT_MAX, c = INT_MAX;
    if ((i + 1) < n) {
        b = A[i + 1] + func(dp, A, n, i + 2);
    }
    if ((i + 2) < n) {
        c = A[i + 2] + func(dp, A, n, i + 3);
    }
    dp[i] = min(dp[i] < 0 ? INT_MAX : dp[i], min(min(a, b), c));
    return dp[i];

}


// 0.074s , which is 0.008s faster than mine
int func_ex(int *dp, int *A, int n) {
    if (n == 1) {
        return A[0];
    } else if (n == 2) {
        return min(A[0], A[1]);
    }
    dp[0] = A[0];
    dp[1] = A[1];
    dp[2] = A[2];
    for (int i = 3; i < n; ++i) {
        dp[i] = A[i] + min(dp[i - 3], min(dp[i - 1], dp[i - 2]));
    }
    return min(dp[n - 3], min(dp[n - 2], dp[n - 1]));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        //   cout << func(dp, A, n, 0) << endl;
        cout << func_ex(dp, A, n) << endl;
    }
}