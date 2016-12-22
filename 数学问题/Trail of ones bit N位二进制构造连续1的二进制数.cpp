//
// Created by sooglejay on 16/12/22.
//

/**
 * f ones Submissions : 107 Accuracy : 68.22
Trail of ones
bit
Given a number N, find the number of binary strings of length N that contains consecutive 1's in them.


Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains a positve integer N, denoting the length of the binary string.


Output
Print out the count of strings having consecutive 1's in them.


Constraints
1 <= T <= 200
2 <= N <=30



Examples

Input
3
2
5
15

Output
1
19
31171


Expaination
In the above first testcase there are 4 strings of length 2, the strings are 00, 01, 10 and 11. Only the string 11 has consecutive 1's.


Expected Complexity
Time: O(N)


**For More Examples Use Expected Output**
 *
 * 算法解释
 * http://www.geeksforgeeks.org/count-strings-with-consecutive-1s/
 */
#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int N;
        cin >> N;
        int res = (1 << N) - fib(N + 2);
        cout << res << endl;
    }
}