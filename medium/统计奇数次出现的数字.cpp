//
// Created by sooglejay on 16/12/25.
//

/***
 * Single Number
array      amazon
Given an array of integers, every element appears twice except for one. Find that single one.
Note: There can be an element appearing odd number of times. That element needs to be counted as single number. In case of odd number of copies, the even ones get cancelled out from each other rendering just one element in the end.

Input:

First line will consist  a number T, the number of test cases.
Each test case will then consist of an Integer N depicting the size of array.
Next line will consist of N space separated integers ,the value of array.

Output:

Print the element that appears once in the array in a separate line.


Constraints:

1<=T<=30
1<=N<=100
0<=A[i]<=50

Example:

Input:
2
3
1 1 2
7
8 8 7 7 6 6 1

Output:
2
1

**For More Examples Use Expected Output**


 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int len;
        cin >> len;
        int A[len];
        for (int i = 0; i < len; ++i) {
            cin >> A[i];
        }
        int c = 1, cur = A[0];
        int res = 0, j = 1;
        for (; j < len; ++j) {
            if (cur == A[j]) {
                c++;
            } else {
                if (c % 2 == 1) {
                    res = A[j - 1];
                    break;
                }
                c = 1;
                cur = A[j];
            }
        }
        if (j == len && c % 2 == 1) {
            res = A[j - 1];
        }
        cout << res << endl;
    }
    return 0;
}