//
// Created by sooglejay on 16/12/20.
//


/***
 *
 *
A Sphenic Number is a positive integer N which is product of exactly three distinct primes. The first few sphenic numbers are 30, 42, 66, 70, 78, 102, 105, 110, 114, …
Given a number N, your task is to find whether it is a Sphenic Number or not.

Examples:

Input : 30
Output : 1
Explanation : 30 is the smallest Sphenic number,
           30 = 2 × 3 × 5
           the product of the smallest three primes

Input : 60
Output : 0
Explanation : 60 = 22 x 3 x 5
              has exactly 3 prime factors but
              is not a sphenic number

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each line contains an integer N.

Output:
For each test case in a new line print 1 if N is a Sphenic Number else print 0.

Constraints:
1<=T<=100
1<=N<=1000

Example:
Input:
2
30
60
Output:
1
0

**For More Examples Use Expected Output**
 *
 *
 *
 */

#include <iostream>

using namespace std;

int main() {
    //code

    int n;
    cin >> n;
    // 因为输入的最大值 是1000 那么 2*3 应该是最小的 ， 1000/6 比200 小，所以 最大的素数应该在200 以内
    int A[200] = {0,};
    bool B[200] = {true};
    for (int l = 0; l < 201; ++l) {
        B[l] = true;
    }
    B[0] = B[1] = false;
    for (int i = 2; i < 201; ++i) {
        if (B[i]) {
            A[i] = 1;
            for (int j = 2 * i; j < 201; j += i) {
                B[j] = false;
            }
        }
    }
    while (n--) {
        int a;
        cin >> a;

        int count = 0;
        int tem = a, res = 0;
        int x = -1, y = -1;

        for (int i = 2; i < 201; ++i) {
            if (A[i] > 0) {
                if (tem % i == 0) {
                    int tt = i;
                    if (x == -1) {
                        x = tt;
                        tem = tem / tt;
                    } else if (y == -1) {
                        y = tt;
                        tem = tem / tt;
                    } else if (tt != x && tt != y) {
                        tem = tem / tt;
                        if (tem == 1) {
                            res = 1;
                        } else {
                            res = 0;
                        }
                    } else {
                        res = 0;
                        break;
                    }
                }
            }

        }

//        if (tem == 1 && count == 3) {
        cout << res << endl;
//        } else {
//            cout << 0 << endl;
//        }


    }

    return 0;

}