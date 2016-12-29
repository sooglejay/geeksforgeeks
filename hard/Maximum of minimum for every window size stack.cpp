//
// Created by sooglejay on 16/12/30.
//

/*
 * Given an integer array of size n, find the maximum of the minimum’s of every window size in the array. Note that window size varies from 1 to n.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print the array of numbers of size n for each of the considered window size 1,2,...,n respectively.


Constraints:
1<=T<=30
1<=N<=100
1<=A[I]<=5000


Example:
Input:
2
7
10 20 30 50 10 70 30
3
10 20 30

Output:
70 30 20 10 10 10 10
30 20 10

Explaination:


Input:  arr[] = {10, 20, 30, 50, 10, 70, 30}
Output:         70, 30, 20, 10, 10, 10, 10

First element in output indicates maximum of minimums of all
windows of size 1.
Minimums of windows of size 1 are {10}, {20}, {30}, {50}, {10},
{70} and {30}.  Maximum of these minimums is 70

Second element in output indicates maximum of minimums of all
windows of size 2.
Minimums of windows of size 2 are {10}, {20}, {30}, {10}, {10},
and {30}.  Maximum of these minimums is 30

Third element in output indicates maximum of minimums of all
windows of size 3.
Minimums of windows of size 3 are {10}, {20}, {10}, {10} and {10}.
Maximum of these minimums is 20

Similarly other elements of output are computed.
**For More Examples Use Expected Output**


 */



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
        int N;
        cin >> N;
        int A[N];
        int m2 = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            m2 = m2 > A[i] ? m2 : A[i];
        }
        cout << m2 << ' ';
        for (int j = 2; j <= N; ++j) {
            int m = 0;
            for (int k = 0; k < N - j + 1; ++k) {
                int temp = A[k];
                for (int i = k; i < k + j; ++i) {
                    if (temp > A[i]) {
                        temp = A[i];
                    }
                }
                m = m > temp ? m : temp;
            }
            cout << m;
            if (j < N) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
