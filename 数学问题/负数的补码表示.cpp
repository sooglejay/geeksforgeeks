//
// Created by sooglejay on 16/12/25.
//

#include <iostream>
#include <cmath>

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
using namespace std;

int foo(int x) {
    int a = x;
    int b = -x;
    int c = a & b;
    return c;
}

int main() {
    //code
    //code
    for (int i = 0; i < 20; ++i) {
        cout << i << '-' << foo(i) << endl;
    }
    return 0;

}