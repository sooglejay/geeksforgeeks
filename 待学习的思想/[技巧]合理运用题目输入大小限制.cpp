//
// Created by sooglejay on 16/12/22.
//

/**

 Check if the number is Fibonacci
fibonacci  maths
Check if a given number is Fibonacci number. Fibonacci number is a number which occurs in Fibonacci series.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case contains a number.

Output:
Print "Yes" if the entered number is Fibonacci number else "No".

Constraints:
1<=t<=100
1<=n<=100

Example:

Input
2
34
41

Output
Yes
No

**For More Examples Use Expected Output**

 */

// 此处n 最大为100，而斐波那契 数列 第12th 的值好像为144，所以，下面的f函数第一个参数设为12即可
#include <iostream>

using namespace std;

int f(int n, int *A) {
    int res = 0;
    if (n <= 1) {
        res = n;
    } else {
        res = f(n - 1, A) + f(n - 2, A);
    }
    A[res] = 1;
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int N;
        cin >> N;
        int A[101] = {0,};
        int B = f(12, A);
        if (A[N] == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}