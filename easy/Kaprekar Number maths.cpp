//
// Created by sooglejay on 16/12/12.
//

/*
A Kaprekar number is a number whose square when divided into two parts the sum of those parts is equal to the original number and none of the parts has value 0.Now given a number, your task is to check if it is Kaprekar number or not.

Examples

        Input :  n = 45
Output : 1
Explanation : 452 = 2025 and 20 + 25 is 45

Input  : n = 297
Output : 1
Explanation:  2972 = 88209 and 88 + 209 is 297

Input  : n = 10
Output : 0
Explanation:  102 = 100. It is not a Kaprekar number even if
sum of 100 + 0 is 100. This is because of the condition that
        none of the parts should have value 0.


Input:
        The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer N.

Output:
        For each test case in a new line print 1 if the no is a Kaprekar number else print 0.

Constraints:
1<=T<=10000
1<=N<=10000

Example:
        Input:
2
45
10
Output:
1
0

**For More Examples Use Expected Output**/


#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);

        int s = k * k;
        int tem = s, base = 10;
        int flag = 0;
        while (tem) {
            int a = tem / base;
            int b = tem % base;
            if (k == 1 || a != 0 && b != 0 && (a + b == k)) {//k = 1 也符合要求
                flag = 1;
                break;
            }
            base *= 10;
            if (s / base > 0) {
                tem = s;
            } else {
                break;
            }
        }
        printf("%d\n", flag);
    }
    return 0;
}
