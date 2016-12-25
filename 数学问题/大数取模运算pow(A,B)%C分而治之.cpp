//
// Created by sooglejay on 16/12/25.
//

/***
 * Modular Exponentiation for large numbers
divide-and-conquer      Google
Implement pow(A, B) % C.

In other words, given A, B and C, find (AB)%C.



Input:

The first line of input consists number of the test cases.

 The following T lines consist of 3 numbers each separated by a space and in the following order:

A B C

'A' being the base number, 'B' the exponent (power to the base number) and 'C' the modular.



Output:

In each separate line print the modular exponent of the given numbers in the test case.


Constraints:

1 ≤ T ≤ 70

1 ≤ A ≤ 10^5

1 ≤ B ≤ 10^5

1 ≤ C ≤ 10^5


Example:

Input:

3
3 2 4
10 9 6
450 768 517

Output:

1
4
34

**For More Examples Use Expected Output**


 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //code
    //code
    int T;
    cin >> T;
    while (T--) {
        size_t A, B;
        size_t C;
        cin >> A >> B >> C;
        size_t tem = A;
        A = 1;
        while (B > 2) {
            //每次使用A的平凡运算，不会越界
            B -= 2;
            A *= tem * tem;
            A %= C;
        }
        while (B--) {
            A *= tem;
            A %= C;
        }
        cout << A << endl;
    }
    return 0;
}