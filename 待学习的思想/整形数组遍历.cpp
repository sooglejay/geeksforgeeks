//
// Created by sooglejay on 16/12/21.
//

/**
 *
 * Count Pairs in an Array
array
Given an array of integers arr[0..n-1], count all pairs (arr[i], arr[j]) in the such that i*arr[i] > j*arr[j], 0 =< i < j < n.

Example:

Input: arr[] = {5, 0, 10, 2, 4, 1, 6}

Output: 5

Explanation:

Pairs which hold condition i*arr[i] > j*arr[j] are
(10, 2) (10, 4) (10, 1) (2, 1) (4, 1)
Input:

The first line of input contains T denoting the no. of test cases . Then T test cases follow . The first line of each test case contains an Integer N and the next line contains N space separated values of the array A[ ] .


Output:

For each test case output the required result in a new line.


Constraints:

1<=T<=100
1<=N<=100
1<=A[ ] <=1000


Example:

Input:

2

7

5 0 10 2 4 1 6

4

8 4 2 1

Output:

5

2

**For More Examples Use Expected Output**
 *
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int size;
        cin >> size;
        int A[size];
        for (int i = 0; i < size; ++i) {
            cin >> A[i];
        }

        int count = 0;
        for (int j = size - 1; j >= 0; --j) {
            int sum = A[j] * j;
            for (int i = j - 1; i >= 0; --i) {
                int tem = A[i] * i;
                if (tem > sum) {
                    count++;
                }
            }
        }
        cout << count << endl;

    }
    return 0;
}