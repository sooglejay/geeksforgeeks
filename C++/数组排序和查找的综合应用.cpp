//
// Created by sooglejay on 16/12/13.
//
// Equal to product


/***
 * Given an array of integers check whether there are two numbers present with given product.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and a product p.
The second line of each test case contain N number of a[].

Output:
Print Yes if two numbers product is equal to p else No.

Constraints:

1 ≤ T ≤ 51
1 ≤ N ≤ 200
0 ≤ a[] ≤ 1000
1 ≤ pro ≤ 2000000

Example:

Input:

2

5 2

1 2 3 4 5

8 46

5 7 9 22 15 344 92 8

Output:

Yes

No

**For More Examples Use Expected Output**
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include<algorithm>

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int cmp(const int *a, const int *b) {
    if (*a > *b) {
        return 1;
    } else if (*a == *b) {
        return 0;
    } else
        return -1;
}

int binarySearch(int A[],int n,int k){
    int low=0,high = n;
    while(high-low>=1){
        int mid = (low+high)/2;
        if(A[mid]>k){
            high = mid;
        }else if(A[mid]==k){
            return 1;
        }else {
            low = mid+1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, p;
        cin >> N >> p;

        int A[N];
        memset(A, 0, sizeof(A));

        int i = 0;
        while (i < N) {
            cin >> A[i];
            i++;
        }
        qsort(A, N, sizeof(int), (int (*)(const void *, const void *)) cmp);


        i = 0;
        int flag = 0;

        while (i < N) {
            if (!A[i]) {
                i++;
                continue;
            }
            if (p / A[i] > A[N - 1]) {
                i++;
                continue;
            }
            if (p % A[i] == 0) {
                int ll = p / A[i];
                int *k = upper_bound(A, A + N, ll);
                int *m = lower_bound(A, A + N, ll);
                if (k-m>0) {
                    flag = 1;
                    break;
                }
            }
            i++;

        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }


    }

    return 0;
}
