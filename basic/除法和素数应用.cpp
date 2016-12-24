//
// Created by sooglejay on 16/12/24.
//


/**
 * Pairs of prime number
maths      Amazon
Print all pairs(sets) of prime numbers (p,q) such that p*q <= n, where n is given number.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the all pairs of prime numbers in increasing order and in single line.

Example:

15 :- 2 2 2 3 2 5 2 7 3 2 3 3 3 5 5 2 5 3 7 2

42 :-  2 2 2 3 2 5 2 7 2 11 2 13 2 17 2 19 3 2 3 3 3 5 3 7 3 11 3 13 5 2 5 3 5 5 5 7 7 2 7 3 7 5 11 2 11 3 13 2 13 3 17 2 19 2

Constraints:

1 ≤ T ≤ 50
4 ≤ N ≤ 400

Example:

Input
2
4
8

Output
2 2
2 2 2 3 3 2


**For More Examples Use Expected Output**
 */
#include <iostream>

using namespace std;

int main() {
    //code
    int MAX = 401;
    bool B[MAX] = {true};
    for (int l = 0; l < MAX; ++l) {
        B[l] = true;
    }
    B[0] = B[1] = false;
    for (int i = 2; i < MAX; ++i) {
        if (B[i]) {
            for (int j = 2 * i; j < MAX; j += i) {
                B[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int len;
        cin >> len;
        int flag = 0;
        for (int i = 2; i <= len; ++i) {
            int d = len / i;
            for (int j = 2; j <= d; ++j) {
                if (B[j] && B[i]) {
                    if (flag == 0) {
                        cout << i << ' ' << j;
                    } else {
                        cout << ' ' << i << ' ' << j;
                    }
                    flag = 1;
                }

            }

        }
        cout << endl;

    }
    return 0;
}