//
// Created by sooglejay on 16/12/12.
//
/*

Given an array of integers A[] and a number k.You can pair two number of array if difference between them is strictly less than k. The task is to find maximum possible sum of such disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs.

Examples:

        Input  : A[] = {3, 5, 10, 15, 17, 12, 9}, K = 4
Output : 62
Then disjoint pairs with difference less than K are,
(3, 5), (10, 12), (15, 17)
max sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62
Note that an alternate way to form disjoint pairs is,
(3, 5), (9, 12), (15, 17), but this pairing produces less sum.

Input  : A[] = {5, 15, 10, 300}, k = 12
Output : 25
Input:
        The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains 3 lines . The first line of each test case is an integer N denoting the size of the array A. In the next line are N space separated values of the array A. In the next line is an integer x.


Output:
        For each test case output in a new line the maximum possible sum of disjoint pairs

Constraints:
1<=T<100
1<=N<=100
1<=A[] <=1000

Example:
        Input:
2
7
3 5 10 15 17 12 9
4
4
5 15 10 300
12

Output:
62
25

**For More Examples Use Expected Output**

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
int cmp(const int *a, const int *b) {
    if (*a > *b) {
        return -1;
    } else if (*a == *b) {
        return 0;
    } else
        return 1;
}

void t6() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int l, i = 0;
        scanf("%d", &l);
        int A[l];
        while (i < l) {
            scanf("%d", &A[i]);
            i++;
        }
        int k;
        scanf("%d", &k);
        qsort(A, l, sizeof(int), (int (*)(const void *, const void *)) cmp);
        i = 0;
        int sum = 0;
        while (i < l - 1) {
            if (A[i] - A[i + 1] < k) {
                sum = sum + A[i] + A[i + 1];
                i += 2;
            } else {
                i++;
            }
        }
        printf("%d\n", sum);

    }
}

int main() {
//    void uva_1583();
//    uva_1583();
    t6();
    return 0;
}


