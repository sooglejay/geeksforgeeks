//
// Created by sooglejay on 17/4/15.
//
//http://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

//
//        Input  : abbc
//        Output : 3
//        Subsequences are abc, abc and abbc
//
//        Input  : abcabc
//        Output : 7
//        Subsequences are abc, abc, abbc, aabc
//                abcc, abc and abc
//

#include <iostream>
#include <cmath>

using namespace std;

int func(string s) {
    int aC = 0, bC = 0, cC = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') {
            aC = 1 + 2 * aC;
        } else if (s[i] == 'b') {
            bC = aC + 2 * bC;
        } else {
            cC = bC + 2 * cC;
        }
    }
    return cC;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << func(s) << endl;

    }
    return 0;
}

