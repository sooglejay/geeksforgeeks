//
// Created by sooglejay on 16/12/22.
//

/***
 * Swap two nibbles in a byte
bit      Samsung
Given a byte, swap the two nibbles in it. For example 100 is be represented as 01100100 in a byte (or 8 bits). The two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.

Input:

The first line contains 'T' denoting the number of testcases. Each testcase contains a single positive integer X.


Output:

In each separate line print the result after swapping the nibbles.


Constraints:

1 ≤ T ≤ 70
1 ≤ X ≤ 255


Example:

Input:

2
100
129

Output:

70
24

**For More Examples Use Expected Output**


 */

#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        int N;
        char bits[9];
        for (int k = 0; k < 8; ++k) {
            bits[k] = '0';
        }
        bits[8] = '\0';
        cin >> N;
        int tem = N;
        while (tem > 0) {
            if (tem >= 128) {
                bits[7] = '1';
                tem -= 128;
            } else if (tem >= 64) {
                bits[6] = '1';
                tem -= 64;
            } else if (tem >= 32) {
                bits[5] = '1';
                tem -= 32;
            } else if (tem >= 16) {
                bits[4] = '1';
                tem -= 16;
            } else if (tem >= 8) {
                bits[3] = '1';
                tem -= 8;
            } else if (tem >= 4) {
                bits[2] = '1';
                tem -= 4;
            } else if (tem >= 2) {
                bits[1] = '1';
                tem -= 2;
            } else if (tem >= 1) {
                bits[0] = '1';
                tem -= 1;
            }
        }
        int j = 0;


        int sum = 0;
        int base = 1;
        int i;
        for (i = 4; i <= 7; ++i) {
            if (bits[i] == '1') {
                sum += base * 1;
            }
            base *= 2;
        }
        for (i = 0; i <= 3; ++i) {
            if (bits[i] == '1') {
                sum += base * 1;
            }
            base *= 2;
        }
        cout << sum << endl;
    }
}