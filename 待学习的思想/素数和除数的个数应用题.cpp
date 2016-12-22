//
// Created by sooglejay on 16/12/22.
//

/***
 * Odd Divisors
maths
Given a natural number n, print count of numbers from 1 to n that have odd number of divisors.  For example,  4 has odd number of divisors (1, 2, 4), but 8 doesn't (1, 2, 4, 8)

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is n.

Output:
Count of numbers from 1 to n with odd divisors.

Constraints:
1 <= T <= 30
1 <= N <= 100000

Example:
Input:
3
1
4
5

Output:
1
2
2

**For More Examples Use Expected Output**
 */
#include <iostream>

using namespace std;

bool oddNumDivisors(int n) {
    if (n == 0 || n == 2) {
        return false;
    } else if (n == 1) {
        return true;
    }
    int i = 2;
    for (int j = 2; j < n / 2 + 2; ++j) {
        if (n % j == 0) {
            i++;
        }
    }
    return i % 2 == 1;
}

int main() {

    int MAX = 100001;
    bool B[100001] = {true};
    for (int l = 0; l < MAX; ++l) {
        B[l] = true;
    }
    B[0] = B[1] = false;
    for (int i = 2; i < MAX; ++i) {
        if (B[i]) {
            for (int j = 2 * i; j < MAX; j += i) {
                B[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    while (n--) {

        int N;
        cin >> N;
        int sum = 0;
        for (int i = 0; i <= N; ++i) {
            if (!B[i] && oddNumDivisors(i)) {
                sum++;
            }
        }
        cout << sum << endl;

    }
}