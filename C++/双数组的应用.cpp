//
// Created by sooglejay on 16/12/18.
//

/***
 * Equal Point in Sorted Array
array
Given a sorted array A of size N, the task is to find whether an element exists in the array from where number of smaller elements is equal to number of greater elements. If Equal Point appears multiple times in input array, print the index of its first occurrence. If Equal Point doesn't exists then print -1.

Examples :

Input  : arr[] = {1, 2, 3, 3, 3, 3}
Output : 1
Equal Point is arr[1] which is 2. Number of
elements smaller than 2 and greater than 2
are same.

Input  : arr[] = {1, 2, 3, 3, 3, 3, 4, 4}
Output : -1

Input : arr[] = {1, 2, 3, 4, 4, 5, 6, 6, 6, 7}
Output : 3
First occurrence of equal point is arr[3]

Input:
The first line of input contains T denoting the no of test cases . Then T test cases follow . The first line of each test case contains an Integer N and the next line contains N space separated values of the array A[ ] .

Output:
For each test case output the required result in a new line.

Constraints:
1<=T<=100
1<=N<=100
1<=A[ ] <=100

Example:
Input:
2
6
1 2 3 3 3 3
8
1 2 3 3 3 3 4 4
Output:
1
-1

**For More Examples Use Expected Output**


 */


#include <iostream>
#include <cstdlib>
#include<string.h>

using namespace std;
//题目要求 满足左边 比自己小的元素个数，右边比自己大的元素个数 相等  的元素的下标
int main() {
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        int A[c];
        int cur;
        cin >> cur;
        A[0] = cur;
        int j = 1, res = -1;
        int B[101];//存输入的 元素值所在的 下标，由于输入序列是非递减的，所以，存储过的就不需要更新
        memset(B, 0, sizeof(B));
        for (int i = 1; i < c; ++i) {
            int tem;
            cin >> tem;
            if (B[tem] == 0) {//如果出现过，就不更新了，保留第一次的位置
                B[tem] = i;
            }
            if (tem > cur) {
                A[j] = tem;//A数组始终是严格单调递增的，所以，只需要找它的中间的元素 就行了
                cur = tem;
                j++;
            }
        }
        if (j % 2 == 0) {
            res = -1;
        } else {
            res = j / 2;
        }
        //获得A中间元素的元素值，然后在B数组中找该值 在输入序列中第一次出现的位置。
        res = B[A[res]] == 0 ? -1 : B[A[res]];
        if (c == 1) {
            res = 0;
        }
        cout << res << endl;
    }
    return 0;
}
