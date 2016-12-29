//
// Created by sooglejay on 16/12/29.
//
/*
Rearrange an array with O(1) extra space
array  maths
Given an array arr[] of size n where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]]. This should be done with O(1) extra space.


Input:

        First line contains an integer denoting the test cases 'T'. Every test case contains an integer value depicting size of array 'N' and N integer elements are to be inserted in the next line with spaces between them.


Output:

        Print all elements of the array after rearranging, each separated by a space, in separate line for each test case.


Constraints:

1 <= T <= 70
1 <= N<= 100
1 <= Arr[i] <= 100
Arr[i]<=N


        Example:

Input:

3
2
1 0
5
4 0 2 1 3
4
3 2 0 1

Output:

0 1
3 4 2 0 1
1 0 3 2

**For More Examples Use Expected Output**/
//
// Created by sooglejay on 16/12/28.
//

#include<iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include<algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        int len;
        cin >> len;
        int A[len];
        memset(A, 0, sizeof(A));
        for (int i = 0; i < len; ++i) {
            cin >> A[i];
        }

        for (int j = 0; j < len; ++j) {
            if (j > 0) {
                cout << ' ';
            }
            cout << A[A[j]];
        }
        cout << endl;
    }
}

