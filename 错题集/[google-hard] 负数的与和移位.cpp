//
// Created by sooglejay on 16/12/30.
//

//
// Created by sooglejay on 16/12/28.
//

/**
 * We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f (2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f (2, 7) = 2.

You are given an array of N integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

Input:

The first line of each input consists of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.


Output:

In each separate line print sum of all pairs for (i, j) such that 1 ≤ i, j ≤ N and return the answer modulo 109+7.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
-2,147,483,648 ≤ A[i] ≤ 2,147,483,647


Example:

Input:

2
2
2 4
3
1 3 5

Output:

4
8

Working:

A = [1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) +
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8

**For More Examples Use Expected Output**
 */

#include<iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include<algorithm>

using namespace std;


void get(long a, char *A) {
    long teJ = a;
    if (teJ < 0) {
        teJ *= -1;
    }

    int jj = 63;
    while (teJ > 0) {
        char ch = teJ & 1 ? '1' : '0';
        A[jj--] = ch;
        teJ >>= 1;
    }
    while (jj) {
        A[jj--] = '0';

    }
    if (a < 0) {
        A[0] = '1';
        for (int k = 1; k < 64; ++k) {
            A[k] = A[k] == '1' ? '0' : '1';
        }

        int cal = 1;
        for (int i = 63; i >= 0; --i) {
            if (A[i] == '1') {
                if (cal == 1) {
                    A[i] = '0';
                }
            } else {
                if (cal == 1) {
                    A[i] = '1';
                    cal = 0;
                }
            }
        }


    }
}

int main() {
    int n;

    cin >> n;

    while (n--) {
        int N;
        cin >> N;
        long A[N];
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        long sum = 0;
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {

                char sJ[65];
                char sI[65];

                memset(sJ, 0, sizeof(sJ));
                memset(sI, 0, sizeof(sI));
                sJ[64] = '\0';
                sI[64] = '\0';

                get(A[j], sJ);
                get(A[i], sI);


                for (int l = 0; l < 64; ++l) {
                    if (sJ[l] != sI[l]) {
                        sum++;
                    }
                }
                sum %= 1000000007;
            }
        }
        cout << sum << endl;
    }
}
