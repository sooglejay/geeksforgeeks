//
// Created by sooglejay on 16/12/25.
//
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=626
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

        for (int i = 7; i >= 0; --i) {
            if (i % 2 == 1) {
                bits2[i] = bits[i - 1];
            } else {
                bits2[i] = bits[i + 1];
            }
        }
        bits2[8] = '\0';




        int base = 1, sum = 0;
        for (int l = 0; l < 8; ++l) {
            if (bits2[l] == '1') {
                sum += 1 * base;
            }
            base *= 2;
        }
        cout<<sum<<endl;


    }
}