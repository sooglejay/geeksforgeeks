//
// Created by sooglejay on 16/12/18.
//

/**


 Given an array of integers, the task is to find count of elements before which all the elements are smaller. First element is always counted as there is no other element before it.

Input:

The first line of input will contain no of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer N denoting the number of elements in the array, the next line contains N space separated integer's denoting the elements of the array.


Output:

For each test case in new line print the Number of Elements before which no element is bigger


Constraints:

1<=T<=100

1<=N<=1000


Example:

Input

2
6
10 40 23 35 50 7
3
5 4 1

Output

3
1

Explanation:

Test Case 1
Input: arr[] =  {10, 40, 23, 35, 50, 7}
Output: 3
The elements are 10, 40 and 50.
No of elements is 3

Test Case 2
Input: arr[] = {5, 4, 1}
Output: 1
There is only one element 5
No of element is 1

**For More Examples Use Expected Output**


 */

//统计当前输入的数的最大值，找出最大值变化的次数
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        int max = -1, sum = 1;
        cin >> max;
        A[0] = max;

        for (int i = 1; i < n; ++i) {
            cin >> A[i];
            if (max < A[i]) {
                max = A[i];
                sum++;
            }
        }


        cout << sum<<endl;

    }
    return 0;
}