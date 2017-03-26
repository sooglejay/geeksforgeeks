//
// Created by sooglejay on 17/3/5.
//

#include<iostream>

using namespace std;

bool isNum(char ch) {
    if (ch >= '1' && ch <= '9')return true;
    return false;
}

int main() {
    string str;
    cin >> str;
    int lenStr = int(str.length());
    char ip1[33];
    int c = 0;
    for (int i = 0; i < lenStr; ++i) {
        if (isNum(str[i])) {
            ip1[c++] = str[i];
            ip1[c++] = str[i + 1];
            i++;
        } else {
            ip1[c++] = '1';
            ip1[c++] = str[i];
        }
    }
    char ip2[33];
    int c2 = 0;
    for (int j = 0; j < c; j = j + 2) {
        if (isNum(ip1[j])) {
            int flag = ip1[j + 1] - 'a';
            for (int i = 0; i < ip1[j] - '0'; ++i) {
                ip2[c2++] = flag + '0';
            }
        }
    }

    int lIP[4], l = 0;
    int base = 1;
    c = 1;
    int sum = 0;
    for (int k = c2-1; k >= 0; --k) {
        if (ip2[k] == '1') {
            sum += 1 * base;
        }
        base *= 2;
        if (k % 8 == 0) {
            lIP[l++] = sum;
            sum = 0;
            base = 1;
        }
    }
    for (int m = 3; m >= 0; --m) {

        cout << lIP[m];
        if (m > 0) {
            cout << '.';
        }
    }

}