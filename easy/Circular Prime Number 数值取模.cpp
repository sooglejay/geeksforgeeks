//
// Created by sooglejay on 16/12/22.
//

/****
 * A prime number is a Circular Prime Number if all of its possible rotations are itself prime numbers. Now given a number N check if it is Circular Prime or Not.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print 1 if the number is circular prime else 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
197
101

Output:
1
0

Explanation:
For first test case:
197 is a Circular Prime because all rotations of 197 are
197, 719, 971 all of the 3 are prime number's
hence 197 is a circular prime

For second test case:
101 isn't a prime number as
rotation of 101 yields 110 which isn't a prime number
hence 101 isn't circular prime

**For More Examples Use Expected Output**
 */

#include <iostream>

using namespace std;


int main() {
    bool B[10001] = {true};
    for (int l = 0; l < 10001; ++l) {
        B[l] = true;
    }
    B[0] = B[1] = false;
    for (int i = 2; i < 10001; ++i) {
        if (B[i]) {
            for (int j = 2 * i; j < 10001; j += i) {
                B[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (!B[a]) {
            cout << 0 << endl;
            continue;
        }
        int tem = a, i = 0;
        while (tem > 0) {
            tem /= 10;
            i++;
        }
        int sum = 1;
        if (sum == i) {
            cout << 1 << endl;
            continue;
        }
        int g = 0, s = 0, ta = 0, res = 0;


        switch (i) {
            case 2:
                g = a / 10;
                s = a % 10;
                ta = s * 10 + g;
                if (B[ta]) {
                    res = 1;
                }
                break;
            case 3:
                g = a / 100;
                s = a % 100;
                ta = s * 10 + g;
                if (B[ta]) {
                    g = a / 10;
                    s = a % 10;
                    ta = s * 100 + g;
                    if (B[ta]) {
                        res = 1;
                    }
                }
                break;
            case 4:
                g = a / 1000;
                s = a % 1000;
                ta = s * 10 + g;
                if (B[ta]) {
                    g = a / 100;
                    s = a % 100;
                    ta = s * 100 + g;
                    if (B[ta]) {
                        g = a / 10;
                        s = a % 10;
                        ta = s * 1000 + g;
                        if (B[ta]) {
                            res = 1;
                        }
                    }
                }
                break;
        }
        cout << res << endl;

    }
}
