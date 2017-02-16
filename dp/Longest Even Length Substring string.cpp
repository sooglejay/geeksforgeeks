//
// Created by sooglejay on 17/1/13.
//


/*
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.


Input:

        The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string string of length N.

Output:

        Print length of the longest substring of length 2k such that sum of left k elements is equal to right k elements and if there is no such substring print 0.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

        Input:
2
000000
1234123

Output:
6
4

**For More Examples Use Expected Output**/

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=270

//此题 根据印度大神的 表格法，计算 [i,j]内的和，然后再取其中间元素k,
// 即观察[i,k]是否是[i,j]的一半即可



//感谢印度大神！

#include <iostream>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;
int dp[101][101];
int func(string a) {
    int len = int(a.size());

    memset(dp, 0, sizeof(dp));
    for (int l = 0; l <= len; ++l) {
        dp[l][0] = 0;
    }
    for (int l = 0; l <= len; ++l) {
        dp[0][l] = 0;
    }
    for (int k = 1; k <= len; ++k) {
        dp[k][k] = a[k - 1] - '0';
    }
    int maxR = 0;
    for (int i = len; i > 0; --i) {
        for (int j = i; j <= len; ++j) {
            int pre = dp[i][j - 1];
            int curr = (a[j-1] - '0');
            int sum = pre + curr;
            dp[i][j] = sum;
            int ind = (j - i);
            if (ind % 2 == 1) {
                ind = ind / 2 +i;
                int half = dp[i][ind];
                half *= 2;
                if (dp[i][j] == half) {
                    int minus = j - i + 1;
                    maxR = max(maxR, minus);
                }
            }
        }
    }
    return maxR;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << func(a) << endl;

    }

}


