//
// Created by sooglejay on 16/12/22.
//
/***
 * Remove character
string      amazon
Given two strings s1 & s2, remove those characters from first string which are present in second string. Both the strings are different and contain only lowercase characters.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is s1,s1 is first string.
The second line of each test case contains s2,s2 is second string.

Output:

Print the modified string(s1). For each test case, print the output in a new line.

Constraints:

1 ≤ T ≤ 15
1 ≤ s2 < s1 ≤ 50

Example:

Input:
2
geeksforgeeks
mask
removeccharaterfrom
string

Output:
geeforgee

emovecchaaefom

**For More Examples Use Expected Output**


 */

#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        int A2[26];
        for (int i = 0; i < 26; ++i) {
            A2[i] = -1;
        }
        for (int j = 0; j < s2.size(); ++j) {
            A2[s2[j] - 'a'] = 1;
        }
        for (int k = 0; k < s1.size(); ++k) {
            if (A2[s1[k] - 'a'] == 1) {
                continue;
            } else {
                cout << s1[k];
            }
        }
        cout << endl;


    }
}