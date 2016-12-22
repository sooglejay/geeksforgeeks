//
// Created by sooglejay on 16/12/22.
//
/**
 *
 * Min Number of Flips
binary  string
Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.
Examples:

Input : str = “001”
Output : 1
Minimum number of flips required = 1
We can flip 1st bit from 0 to 1

Input : str = “0001010111”
Output : 2
Minimum number of flips required = 2
We can flip 2nd bit from 0 to 1 and 9th
bit from 1 to 0 to make alternate
string “0101010101”.
Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.

Output:

Minimum number of characters to be removed to make string alternate.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
01010
1111

Output
0
2

**For More Examples Use Expected Output**
 */

#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        string A;
        cin >> A;
        size_t len = A.size();
        char target1[len + 1];
        char target2[len + 1];
        bool flag = true;
        for (int i = 0; i < len; ++i) {
            target1[i] = flag ? '1' : '0';
            target2[i] = flag ? '0' : '1';
            flag = !flag;
        }
        target1[len] = '\0';
        target2[len] = '\0';
        int dif1 = 0, dif2 = 0;
        for (int j = 0; j < len; ++j) {
            if (target1[j] != A[j]) {
                dif1++;
            }
            if (target2[j] != A[j]) {
                dif2++;
            }
        }
        cout << (dif1 > dif2 ? dif2 : dif1) << endl;

    }
}