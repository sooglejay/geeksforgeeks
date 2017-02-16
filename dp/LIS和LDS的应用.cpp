
//
// Created by sooglejay on 17/1/13.
//

/*
Maximum Sum Bitonic Subsequence
array  dp
Given an array of integers. A subsequence of A[] is called Bitonic if it is first increasing, then decreasing.

Examples:

        Input : A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9}
Output : 194
Explanation : Bi-tonic Sub-sequence are :
{1, 51, 9} or {1, 50, 100, 18, 9} or
{1, 15, 51, 100, 18, 9}  or
{1, 15, 45, 100, 12, 9}  or
{1, 15, 45, 100, 18, 9} .. so on
Maximum sum Bi-tonic sub-sequence is 1 + 15 +
51 + 100 + 18 + 9 = 194

Input : A[] = {80, 60, 30, 40, 20, 10}
Output : 210

Input:
        The first line contains an integer T denoting the no of test cases. Each test case consist of two lines. The first line contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A[].


Output:
        For each test case in a new line print the max sum bitonic subsequence.

Constraints:
1<=T<=100
1<=N<=50
1<=A[]<=100

Example:
        Input:
2
6
80 60 30 40 20 10
9
1 15 51 45 33 100 12 18 9

Output:
210
194

**For More Examples Use Expected Output**/
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1595


#include <iostream>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;
int dp1[51];
int dp2[51];

int func(int *A, int n) {
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for (int i = 0; i < n; ++i) {
        dp1[i] = A[i];
        dp2[i] = A[i];
    }
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            if (A[i] < A[j]) {
                dp1[j] = max(dp1[i] + A[j], dp1[j]);
            }
        }
    }
    for (int j = n - 2; j >= 0; --j) {
        for (int i = n - 1; i > j; --i) {
            if (A[i] < A[j]) {
                dp2[j] = max(dp2[i] + A[j], dp2[j]);
            }
        }
    }
    int maxR = 0;
    for (int k = 0; k < n; ++k) {
        maxR = max(dp1[k] + dp2[k] - A[k], maxR);
    }
    return maxR;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << func(A, n) << endl;
    }

}
