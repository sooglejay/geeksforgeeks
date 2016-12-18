//
// Created by sooglejay on 16/12/18.
//

/***
 * Juggler Sequence
maths  series
Juggler Sequence is a series of integer number in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

 a_(k+1)={|_a_k^(1/2)_|   for even a_k; |_a_k^(3/2)_|   for odd a_k,

Given a number N your task is to print the space separated Juggler Sequence for this number as the first term of the sequence.


Examples:

Input: 9
Output: 9, 27, 140, 11, 36, 6, 2, 1
We start with 9 and use above formula to get
next terms.

Input: 6
Output: 6, 2, 1

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer N.

Output:
For each test case in a new line print the space separated juggler sequence for  number N as the first term of the sequence.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
9
6
Output:
9  27 140 11 36 6 2 1
6 2 1

**For More Examples Use Expected Output**


 */
#include <iostream>
#include <cmath>

using namespace std;

int getCul(int c) {

    float res;
    int r;
    if (c % 2 == 0) {
        res = pow(c, 1 / 2.0);
        r = floor(res);
    } else {
        //c的3/2此方，注意要float 类型
        res = pow(c, 3 / 2.0);
        //向下去整      ceil是向上取整
        r = floor(res);
    }
    return r;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        if (c > 1)
            cout << c << ' ';
        c = getCul(c);
        while (c > 1) {
            cout << c << ' ';
            if (c == 1) {
                break;
            }
            c = getCul(c);
        }
        cout << 1 << endl;
    }
    return 0;
}

