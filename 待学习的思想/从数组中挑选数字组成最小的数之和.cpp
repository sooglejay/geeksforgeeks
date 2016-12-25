//
// Created by sooglejay on 16/12/25.
//

/***
 *
 * Min sum formed by digits
array  heap  queue
Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Next line of each test contains N space seperated integers denoting the elements of the array.
Output:

For each test case output a single line containing the required sum.
Constraints:

1<=T<=100
1<=N<=50
Example:

Input

2
6
6 8 4 5 2 3
5
5 3 0 7 4

Output

604
82

Explanation:

Test Case 1-

The minimum sum is formed by numbers
358 and 246
Test Case 2 -

The minimum sum is formed by numbers
35 and 047
**For More Examples Use Expected Output**
 */
#include <iostream>
using namespace std;
int cmp(const int *a, const int *b) {
    if (*a > *b) {
        return 1;
    } else if (*a < *b) {
        return -1;
    } else {
        return 0;
    }

}
int main() {
    int n;
    cin >> n;
    while (n--) {
        size_t len;
        cin >> len;
        int A[len];
        for (int i = 0; i < len; ++i) {
            cin >> A[i];
        }
        qsort(A, len, sizeof(int),  (int (*)(const void *, const void *)) cmp);

        int a = 0, b=0, sum=0;
        for (int j = 0; j < len; ++j) {
            if(j%2==0) {
                a = a * 10 + A[j];
            }else{
                b = b * 10 + A[j];
            }
        }
        sum = a + b;
        cout << sum << endl;
    }
}