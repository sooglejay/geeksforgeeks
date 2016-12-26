//
// Created by sooglejay on 16/12/26.
//
/*
Minimum steps to get desired array
array  Maths
Consider an array with n elements and value of all the elements is zero. We can perform following operations on the array.

1. Incremental operations: Choose 1 element from the array and increment its value by 1.
2. Doubling operation: Double the values of all the elements of array.

Given an array of integers of size N. Print the smallest possible number of operations needed to change the array from all zeros to desired array.


Input:
        The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is an integer N  where N is the size of array .
The second line of each test case contains N input A[i].

Output:
        Print the smallest possible number of the operations needed to change the array from all zeros to desired array.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ A[i] ≤ 200

Example:

        Input:
3
3
16 16 16
2
2 3
2
2 1

Output:
7
4
3

Explanation :
        In first test case, the output solution looks as follows. First apply an incremental operation to each element. Then apply the doubling operation four times. Total number of operations is 3+4 = 7

In second test case, to get the target array from {0, 0}, we first increment both elements by 1 (2 operations), then double the array (1 operation). Finally increment second element (1 more operation)  Total number of operations is 2+1+1 = 4

In third test case , one of the optimal solution is to apply the incremental operation 2 times to first and once on second element.Total number of operations is 1+1+1 = 3



**For More Examples Use Expected Output**/
//思想是找到最大的值，然后求出从0到达它需要进行的乘法操作次数
// 这里的技巧是，大数的乘法次数包括了小数的乘法次数，所以不用累计。只需要计一次

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {

        int len;
        cin >> len;
        int A[len];
        int max = -1;
        for (int i = 0; i < len; ++i) {
            cin >> A[i];
            max = max < A[i] ? A[i] : max;
        }
        int sum = 0;
        int c = 0, b = 0;
        while (max > 0) {
            c += max % 2;
            b++;
            max /= 2;
        }

        for (int k = 0; k < len; ++k) {
            while (A[k] > 0) {
                sum += A[k] % 2;//如果是奇数，需要一次加法操作
                A[k] /= 2;
            }
        }
        //b表示乘法的次数，sum表示加法的次数
        //减1的原因是 由于当 max ＝ 1时也进入了while循环，也就是说，0-1应该算作加法，此时b不应该增加。
        //也可以在while循环时的终止条件设为 while（max>1）
        cout << (sum + b - 1) << endl;


    }
    return 0;
}


