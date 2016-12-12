//
// Created by sooglejay on 16/12/12.
//

/**
 * A Lucas Number is a number which is represented by the following recurrence
Ln = Ln-1 + Ln-2 for n>1
L0 = 2
L1 = 1

Now given a number n your task is to find the nth lucas number.

Note: Since the output could be very long take mod 1000000007

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer n.

Output:
For each test case in a new line print the nth lucas no.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
9
3
Output:
76
4


**For More Examples Use Expected Output**
 */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int t7(int j) {
    int n = 101;
    int A[n];
    memset(A, 0, sizeof(A));
    A[0] = 2;
    A[1] = 1;
    for (int i = 2; i < 101; ++i) {
        A[i] = A[i - 1] + A[i - 2];
        A[i] %= 1000000007;
    }
    return A[j];
}

int main() {
//    void uva_1583();
//    uva_1583();
    int n;
    scanf("%d", &n);
    while (n--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", t7(k));
    }
    return 0;
}
