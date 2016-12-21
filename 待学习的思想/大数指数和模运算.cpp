//
// Created by sooglejay on 16/12/21.
//

/***

Geometric Progression
modular arithmetic
Given a Geometric Progression with first term as 1, common ratio as 2 and a number N. Find out the sum of all the terms of this geometric progression if there are total 2N terms in GP.

Note: Since the answer can be very large, print the answer modulo 109+7

Input:
        First line of input consist of a single integer T denoting the total number of test case. Then T test cases follow. Each line of test case contains a single integer N,as described in the problem statement.

Output:
        For each test case, print a single line containing the required answer.

Constraints:
1<=T<=100
1<=N<=10^18

Example:
        Input:
2
1
3

Output:
3
255

**For More Examples Use Expected Output**/

/***
 *
 *
From the formula of sum of GP, sum of 2N terms of given GP will be 1*(2^(2^(N-1))-1)/(2-1) =2^(2^N)-1.

We have to calculate the answer modulo M (M=10^9+7), According to Fermat's little theorem ,
 2^(2^N) mod M = (2^(2^N mod M-1) )mod M.

 */

#include <iostream>

using namespace std;

long int power2(long int n, bool flag) {
    long int MOD = 1000000007;
    if (flag)
        MOD--;
    long int res;
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    res = power2(n / 2, flag);
    res = (res * res) % MOD;
    if (n & 1)
        res = (2 * res) % MOD;
    return res;
}

int main() {
    int t, T;
    long int N, k, res;
    cin >> T;
    for (t = 1; t <= T; t++) {
        cin >> N;
        k = power2(N, true);
        res = power2(k, false) - 1;
        cout << res << "\n";
    }

    return 0;
}

