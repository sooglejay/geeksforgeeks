//
// Created by sooglejay on 17/1/13.
//

Given an array of digits (values lie in range from 0 to 9). The task is to count all the sub sequences possible in array such that in each subsequence every digit is greater than its previous digits in the subsequence.

Examples:

        Input : arr[] = {1, 2, 3, 4}
Output: 15
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4},
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4},
{1,3,4}, {2,3,4}, {1,2,3,4}

Input : arr[] = {4, 3, 6, 5}
Output: 8
Sub-sequences are {4}, {3}, {6}, {5},
{4,6}, {4,5}, {3,6}, {3,5}

Input : arr[] = {3, 2, 4, 5, 4}
Output : 14
Sub-sequences are {3}, {2}, {4}, {3,4},
{2,4}, {5}, {3,5}, {2,5}, {4,5}, {3,2,5}
{3,4,5}, {4}, {3,4}, {2,4}
Input:

        The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of digits.
The second line contains N space-separated digits.

Output:

        Count of all increasing subsequences in given array of digits.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 500



Example:

        Input:
2
5
3 2 4 5 4
3
1 2 4
Output:
14
7

**For More Examples Use Expected Output**



#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int dp[501];

//LIS  以 A[i] 结尾的递增序列的个数
void func(int *A, int n) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    long long int sum = dp[0];
    for (int i = 1; i < n; ++i) {
        int j = 0;
        for (; j < i; ++j) {
            if (A[j] < A[i]) {
                dp[i] += dp[j];
            }
        }
        sum += ++dp[i];
    }
    cout << sum << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        func(A, n);
    }

}


//下面是 O(n)算法，利用了 数字0-9 这个已知条件


// C++ program to count increasing subsequences
// in an array of digits.
#include<bits/stdc++.h>
using namespace std;

// Function To Count all the sub-sequences
// possible in which digit is greater than
// all previous digits arr[] is array of n
// digits
int countSub(int arr[], int n)
{
    // count[] array is used to store all sub-
    // sequences possible using that digit
    // count[] array covers all the digit
    // from 0 to 9
    int count[10] = {0};

    // scan each digit in arr[]
    for (int i=0; i<n; i++)
    {
        // count all possible sub-sequences by
        // the digits less than arr[i] digit
        for (int j=arr[i]-1; j>=0; j--)
            count[arr[i]] += count[j];

        // store sum of all sub-sequences plus
        // 1 in count[] array
        count[arr[i]]++;
    }

    // now sum up the all sequences possible in
    // count[] array
    int result = 0;
    for (int i=0; i<10; i++)
        result += count[i];

    return result;
}

// Driver program to run the test case
int main()
{
    int arr[] = {3, 2, 4, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << countSub(arr,n);
    return 0;
}