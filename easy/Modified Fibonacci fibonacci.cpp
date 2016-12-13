//
// Created by sooglejay on 16/12/12.
//

/**
Given a number n,  print the value of F(n) given that

F(1) = A + B and
F(2) = B + C.
Here A, B and C are integer inputs provided to the program.
For n > 2, F(n) = F(n-1) - F(n-2)

Since F(n) can be large, print the answer modulo (10^9+7).


Input :
The first line contains integer T, denoting number of test cases.Then T test cases follow. The first line of each test case contains integer N A B C, denoting the number and values of constant A,B,C respectively.


Output :
Print the answer of each test case in a new line.


Constraints :
1 <= T <= 10
1 <= A,B,C <= 10^9
1 <= n <= 10^12

Example:
Input :
2
2 2 3 4
3 2 3 4

Output :
7
2

**For More Examples Use Expected Output**
**/



//找规律 题
#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long n, a, b, c;
        cin >> n >> a >> b >> c;
        // 0,1,2,3 号元素对应 0, A1,A2,A3
        long B[] = {0, (a + b), (b + c), (c - a)};
        if (n < 4) {
            cout << B[n] << endl;
            continue;
        }
        // -A1,-A2,A1-A2,A1,A2,A2-A1
        long A[] = {-1 * B[1], -1 * B[2], B[1] - B[2], B[1], B[2], B[2] - B[1]};
        // 这里需要注意，一个负数 对一个 正数取莫运算，结果是两者之和
        // 这里的规律是  4为首项，6为公差的等差数列
        cout << (A[(n + 2) % 6] < 0 ?  A[(n + 2) % 6]+1000000007 : A[(n + 2) % 6]%1000000007 ) << endl;
    }

    return 0;
}



