//
// Created by sooglejay on 16/12/12.
//

/**
 *
 * Given a string which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.

Examples:

Input  :  str = “0102010”
Output :  2
Explanation : Substring str[2, 4] = “102” and
              substring str[4, 6] = “201” has
              equal number of 0, 1 and 2

Input : str = "102100211"
Output : 5


Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of one line. The line contains a string of 0's, 1's and 2's.

Output:

Corresponding to each test case, in a new line, print the count all possible substrings that have same number of 0s, 1s and 2s.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
0102010
102100211

Output
2
5

**For More Examples Use Expected Output**
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>


#include <stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char A[1001];
        scanf("%s", A);
        int len = strlen(A);

        int base = 3;//因为0，1，2有三个数，要判断一个子数组中这三个数字的个数是否相等，肯定要在
        //在3的倍数长自数组中去判断
        int c0, c1, c2, sum = 0;//分别是0，1，2的个数，sum是最终所求
        while (base <= len) {
            for (int i = 0; i <= len - base; ++i) {
                c0 = c1 = c2 = 0;
                for (int j = i; j < i + base; j++) {//每一个子数组都要去判断
                    switch (A[j] - '0') {
                        case 0:
                            c0++;
                            break;
                        case 1:
                            c1++;
                            break;
                        case 2:
                            c2++;
                            break;
                    }
                }
                if (c0 == c1 && c0 == c2) {
                    sum++;
                }
            }
            base += 3;
        }
        cout << sum << endl;

    }

    return 0;
}

