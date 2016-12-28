//
// Created by sooglejay on 16/12/27.
//

/*
Largest power of prime
maths
        Given a positive integer N and a prime p, the task is to print the largest power of prime p that divides N!. Here N! means the factorial of N = 1 x 2 x 3 . . (N-1) x N.
Note that the largest power may be 0 too.


Input:
        The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing a positive integer N and a prime p.


Output:
        Corresponding to each test case, in a new line, print the largest power of prime p that divides N .


Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100000
2 ≤5000 ≤p

        Example:
Input
3
62 7
76 2
3 5

Output
9
73
0



**For More Examples Use Expected Output**/

#include <iostream>

using namespace std;

int get(int n, int p) {
    int c = 0;
    while (n) {
        n /= p;
        c += n;
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, P;
        cin >> N >> P;
        int c = get(N, P);
        cout << c << endl;


    }
    return 0;
}
