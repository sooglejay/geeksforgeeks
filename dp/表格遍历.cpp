//
// Created by sooglejay on 16/12/22.
//

/***
 * Number of paths
recursion      Amazon    microsoft
The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move only to right or down.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:

Print the number of paths.

Constraints:

1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:

Input
2
3 3
2 8

Output
6
8


**For More Examples Use Expected Output**


 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int row, column;
        cin >> row >> column;
        int A[row][column];

        for (int j = 0; j < column; ++j) {
            A[0][j] = 1;
        }
        for (int i = 0; i < row; ++i) {
            A[i][0] = 1;
        }
        for (int k = 1; k < row; ++k) {
            for (int i = 1; i < column; ++i) {
                A[k][i] = A[k][i - 1] + A[k - 1][i];
            }
        }
        cout << A[row - 1][column - 1] << endl;


    }
}