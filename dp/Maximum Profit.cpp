//
// Created by sooglejay on 17/1/11.
//

/*
Maximum Profit
dp  maths
In stock market , a person buys a stock and sells it on some future date. Given the stock prices of N days in an form of an array A[ ] and a positive integer K, find out the maximum profit a person can make in atmost K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

Input
        The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains a positve integer K, denoting the number of transactions.
The second line of each test case contains a positve integer N, denoting the length of the array A[ ].
The third line of each test case contains a N space separated positive integers, denoting the prices of each day in the array A[ ].


Output
        Print out the maximum profit earned by the person.
No profit will be equivalent to 0.


Constraints
1 <= T <= 100
0 <   K <= 10
2 <= N <=30
0 <= A[ ] <= 1000

Examples

        Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25

Output
87
1040
0


Explanation:
        Output 1: Trader earns 87 as sum of 12 and 75  i.e. Buy at price 10, sell at 22, buy at  5 and sell at 80
Output 2: Trader earns 1040 as sum of 560 and 480 i.e. Buy at price 20, sell at 580, buy at 420 and sell at 900
Output 3: Trader cannot make any profit as selling price is decreasing day by day.Hence, it is not possible to earn anything.


**For More Examples Use Expected Output**/


#include <iostream>
#include <limits.h>
#include <cstring>

#define MAX_N 31
#define MAX_K 11
using namespace std;
int memo[MAX_N][MAX_N];
int dp[MAX_N][MAX_K];

//构造 收益数组，每一天买入，每一天卖出都算一下收益存起来
int construct(int *A, int n) {
    for (int j = 0; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            if (A[i] < A[j]) {
                memo[j][i] = 0;
            } else {
                memo[j][i] = A[i] - A[j];
            }
        }
    }

}

//我这边的时间复杂度就比较大了
int func(int n, int k) {
    //第 ith 买入
    for (int i = n - 1; i >= 0; i--) {
        // transaction k次，所以每一次都要去计算一下，求出最大值
        for (int c = 1; c <= k; ++c) {
            // 在买入的点的前面，找出收益最大的卖点。
            for (int j = i + 1; j < n; ++j) {
                //情况 1
                // 在 第 jth 个卖出去 ，算一次 transaction
                int kk = memo[i][j];
                // 然后，还要加上剩下的 从(j+1)th开始的股票，还可以transaction(c-1)次
                int ll = ((j + 1) < n ? dp[j + 1][c - 1] : 0);
                // 把上面两个加起来，就是在i 这一点买入，在j这一点卖出的收益了。
                int a = kk + ll;

                // 情况2 ，我不想在j这一点卖出，意思就是跳过j这一支股票，那么，我可以从(j+1)开始还能transaction c次
                int b = ((j + 1) < n ? dp[j + 1][c] : 0);

                // 情况3 , 我什么都不干，我可能已经transaction过了几次了，我现在觉得收益很大了。
                int mm = dp[i][c];
                // 比较这三种情况，求出最大值
                int res = max(max(a, b), mm);
                dp[i][c] = res;

                // 但是我发现，事情并没有按照上面三种情况来发展，还需要进行下面的操作
                // 这是为什么呢？我后来打印 dp这个数组才发现，原来，有可能最大的情况出现在前面，而不是后面！！这个问题我没有考虑到。所以需要下面这句代码
                dp[i][c] = max((i + 1) < n ? dp[i + 1][c] : 0, max(dp[i][c], (i - 1) >= 0 ? dp[i - 1][c] : 0));

            }
        }

    }
    return dp[0][k];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        int A[n];
        memset(memo, 0, sizeof(memo));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        construct(A, n);
        int maxRes = func(n, k);
        cout << maxRes << endl;
    }
}


//下面是比较简洁的代码，而是O(n*k)复杂度 ，空间复杂度也是O(n*K)
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int display(int arr[], int n, int k) {
    int dp[k + 1][n], i, j;
    for (i = 0; i <= k; i++)
        dp[i][0] = 0;
    for (i = 0; i < n; i++)
        dp[0][i] = 0;
    for (i = 1; i <= k; i++) {
        int prev_diff = INT_MIN;
        for (j = 1; j < n; j++) {
            prev_diff = max(prev_diff, dp[i - 1][j - 1] - arr[j - 1]);
            dp[i][j] = max(dp[i][j - 1], prev_diff + arr[j]);
        }
    }
    return dp[k][n - 1];
}

int main() {
    //code
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> k;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << display(a, n, k) << endl;
    }
    return 0;
}