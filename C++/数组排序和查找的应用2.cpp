//
// Created by sooglejay on 16/12/18.
//

/**
 *

Pairs with given XOR
bits


 Given an array of distinct +ve integers A[] and a number x, your task is to find the number of pairs of integers in the array whose XOR is equal to x.
Examples:

Input : A[] = {5, 4, 10, 15, 7, 6}, x = 5
Output : 1
Explanation :  (10 ^ 15) = 5

Input : A[] = {3, 6, 8, 10, 15, 50}, x = 5
Output : 2
Explanation : (3 ^ 6) = 5 and (10 ^ 15) = 5

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains 3 lines . The first line of each test case is an integer N denoting the size of the array A. In the next line are N space separated values of the array A. In the next line is an integer x.

Output:
For each test case output in a new line  the number of pairs of integers in the array whose XOR is equal to x.

Constraints:
1<=T<100
1<=N<=100
1<=A[] <=1000

Example:
Input:
2
6
3  6 8 10 15 50
5
6
5 4 10 15 7 6
5

Output:
2
1

**For More Examples Use Expected Output
 * ***/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(const int *a, const int *b) {
    if (*a > *b) {
        return 1;
    } else if (*a == *b) {
        return 0;
    } else
        return -1;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int c;
        cin >> c;
        int A[c];
        int max = 0;
        for (int i = 0; i < c; ++i) {
            cin >> A[i];
        }
        qsort(A, c, sizeof(int), (int (*)(const void *, const void *)) cmp);

        int x;
        cin >> x;
        int tem = 0, sum = 0;
        for (int j = 0; j < c; ++j) {
            int ll = x^A[j];//查找 数组中属否存在ll这个数字
            if(ll==A[j]){
                continue;
            }
            int *k = upper_bound(A, A+c, ll);
            int *m = lower_bound(A, A+c,ll);
            if (k - m > 0) {//说明存在值为ll的元素
                sum ++;
                A[j] = 0;
            }
        }
        cout<<sum<<endl;



    }
    return 0;
}
