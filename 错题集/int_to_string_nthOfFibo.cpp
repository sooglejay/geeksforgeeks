
//
// Created by sooglejay on 16/12/24.
//

/**
 * nth digit of Fibonacci
fibonacci  maths  series
A Fibonacci series (starting from 1) written in order without any spaces in between, thus producing a sequence of digits. Find the Nth digit in the sequence.

Input:
First line of input contains number of test cases T. Each line of test case contain a number N.

Output:
Display the Nth digit in the sequence.

Constraints:
1 <=T<= 30
1 <= N<= 100

Example:

Input:
3
10
3
25

Output:
1
2
7

**For More Examples Use Expected Output**
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int fibonacci(int n) {
    // write your code here
    double Phi = 1.61803398874989484820, phi = 0.61803398874989484820;
    return (int) ((pow(Phi, n) - pow((-phi), n)) / pow(5.0, 1.0 / 2.0));
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char array[104];
        int a, i, j = 0;
        cin >> a;
        for (int k = 1; k < 50; ++k) {
            int tem = fibonacci(k);
            string str = to_string(tem);
            tem = 0;
            while (str[tem] != '\0') {
                array[j++] = str[tem];
                tem++;
                if (j >= 102) {
                    break;
                }
            }
            if (j >= 102) {
                break;
            }

        }
        cout << array[a - 1] << endl;

    }
    return 0;
}