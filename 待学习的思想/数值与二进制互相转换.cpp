//
// Created by sooglejay on 16/12/22.
//


/**
 * Swap all odd and even bits
bit
Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 ( 0 0 0 1 0 1 1 1 ), it should be converted to 43 ( 0 0 1 0 1 0 1 1 ). Here every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N, where N is the number of coins.

Output:

Corresponding to each test case, print in a new line, the converted number .

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input
2
23
2

Output
43
1


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
        char bits2[9];
        for (int k = 0; k < 8; ++k) {
            bits[k] = '0';
            bits2[k] = '0';
        }
        bits[8] = '\0';
        bits2[8] = '\0';
        cin >> N;
        int tem = N;
        while (tem > 0) {
            if (tem >= 64) {
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


        //题目要求的算法
        for (int i = 7; i >= 0; --i) {
            if (i % 2 == 1) {
                bits2[i] = bits[i - 1];
            } else {
                bits2[i] = bits[i + 1];
            }
        }
        bits2[8] = '\0';

        for (int i = 7; i >= 0; --i) {
            cout << bits[i] << ' ';
        }

        cout << endl;
        for (int i = 7; i >= 0; --i) {
            cout << bits2[i] << ' ';
        }


        int base = 1, sum = 0;
        for (int l = 0; l < 8; ++l) {
            if (bits2[l] == '1') {
                sum += 1 * base;
            }
            base *= 2;
        }
        cout << sum << endl;


    }
}