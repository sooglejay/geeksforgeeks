//
// Created by sooglejay on 16/12/13.
//

/**
 *
Consider Ø(n) as the Euler Totient Function for n. You will be given a positive integer N and you have to find the smallest positive integer n, n <= N for which the ratio n/Ø(n) is maximized.

Input:
First line of input consist of a single integer T denoting the total number of test case. Then T test cases follow. Each test case consists of a line with a positive integer N.

Output:
For each test case, in a new line print the smallest value of n, n <= N for which the ratio n/Ø(n) is maximized.


Constraints:
1<=T<=500
1<=N<=1012


Example:
Input:
2
6
50

Output:
6
30

Explanation:
First test Case
For n = 1, 2, 3, 4, 5 and 6 the values of the ratio are 1, 2, 1.5, 2, 1.25 and 3 respectively. The maximum is obtained at 6.
Second test Case
For n = 1 to 50, the maximum value of the ratio is 3.75 which is obtained at n = 30.



**For More Examples Use Expected Output**
 */
#include <iostream>

using namespace std;



int main() {
    int t;
    scanf("%d", &t);
    int p[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    while (t--) {
        long N;
        cin >> N;

        int i;
        long max = 1, pre = 1;
        for (i = 0; i < 13; i++) {
            pre = pre * p[i];
            if (pre <= N) {
                max = pre;
            } else {
                break;
            }
        }
        cout << max << endl;
    }

    return 0;
}
