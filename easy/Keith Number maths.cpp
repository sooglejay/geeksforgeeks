//
// Created by sooglejay on 16/12/12.
//


/***
 *
A n digit number x is called Keith number if it appears in a special sequence (defined below) generated using its digits. The special sequence has first n terms as digits of x and other terms are recursively evaluated as sum of previous n terms.The task is to find if a given number is Keith Number or not.

Examples

Input : x = 197
Output : 1
197 has 3 digits, so n = 3
The number is Keith because it appears in the special
sequence that has first three terms as 1, 9, 7 and
remaining terms evaluated using sum of previous 3 terms.
1, 9, 7, 17, 33, 57, 107, 197, .....

Input : x = 12
Output : 0
The number is not Keith because it doesn't appear in
the special sequence generated using its digits.
1, 2, 3, 5, 8, 13, 21, .....

Input : x = 14
Output : 1
14 is a Keith number since it appears in the sequence,
1, 4, 5, 9, 14, ...

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer x.

Output:
For each test case in a new line print 1 if the no is a Keith number else print 0.

Constraints:
1<=T<=10000
1<=x<=10000

Example:
Input:
2
14
10
Output:
1
0

**For More Examples Use Expected Output**
 */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    int t;

    int A[10001];
    memset(A, 0, sizeof(A));

    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        int temp = k, i = 0;

        int sumD = 0;
        while (temp) {
            A[i] = temp % 10;
            sumD += A[i];
            temp /= 10;
            i++;
        }

        int ki = 0, kj = i - 1;
        for (ki = 0; ki < kj; ki++, kj--) {
            int a = A[kj];
            A[kj] = A[ki];
            A[ki] = a;
        }


        A[i] = sumD;
        int j = i, p = 0, u = 0;
        int tempSum = 0;

        int flag = (A[0] == k);
        if (flag == 0) {
            for (p = 1; p + j < 10001; p++) {
                tempSum = 0;
                for (u = 0; u < j; u++) {//求n个元素之和
                    if (A[p + u] > k) {//如果已经超过了，后面的肯定也是超过了，就不需要比较了
                        break;
                    } else if (A[p + u] == k) {//如果已经找到，temSum肯定大于k，循环会全部结束
                        // flag＝1
                        flag = 1;
                    }
                    tempSum += A[p + u];
                }
                A[p + j] = tempSum;
                if (tempSum > k) {//同上
                    break;
                }
            }
        }
        printf("%d\n", flag);
    }
    return 0;
}

