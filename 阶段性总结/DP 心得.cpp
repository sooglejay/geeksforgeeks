//
// Created by sooglejay on 17/1/12.
//

根据印度大神的DP算法，还有结合几道题目：
//  http://www.practice.geeksforgeeks.org/problem-page.php?pid=1248
上面这道题目，你最好做一下，
因为这个题目 才有了这篇阶段性总结
。
我经常犯的一个错误就是太在意逻辑，而轻视数据。
废话不多说，直接干货DP的解题方式：
0、加上一句话：下面的基础情况和逻辑，还有已知条件一起分析！

这个是心得来源于如下代码


我的解法是O(n *n)

而利用了已知的fact后，只需要O(n)所以，涉及到数字，字母的题目，也要考虑数组
        用好数组下标这个工具，会事半功倍
//
// Created by sooglejay on 17/1/13.
//Given an array of digits (values lie in range from 0 to 9). The task is to count all the sub sequences possible in array such that in each subsequence every digit is greater than its previous digits in the subsequence.
//        http://www.geeksforgeeks.org/count-all-increasing-subsequences/
//        http://www.practice.geeksforgeeks.org/problem-page.php?pid=1393
/*
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

**For More Examples Use Expected Output**/



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
int countSub(int arr[], int n) {
    // count[] array is used to store all sub-
    // sequences possible using that digit
    // count[] array covers all the digit
    // from 0 to 9
    int count[10] = {0};

    // scan each digit in arr[]
    for (int i = 0; i < n; i++) {
        // count all possible sub-sequences by
        // the digits less than arr[i] digit
        for (int j = arr[i] - 1; j >= 0; j--)
            count[arr[i]] += count[j];

        // store sum of all sub-sequences plus
        // 1 in count[] array
        count[arr[i]]++;
    }

    // now sum up the all sequences possible in
    // count[] array
    int result = 0;
    for (int i = 0; i < 10; i++)
        result += count[i];

    return result;
}

// Driver program to run the test case
int main() {
    int arr[] = {3, 2, 4, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countSub(arr, n);
    return 0;
}


1、首先，分析基础的情况，从最简单的情况入手分析，
弄清楚自己的head thing
method，然后接下来就是把它翻译为代码实现
2、印度大神的终极技巧：表格法。但是切记，
我们是根据head thinking
把结果写出来，
然后再根据head thing
去分析dp[i][j]跟dp[i-1][j-1],dp[i][j-1],dp[i-1][j]这三者的关系，
而这个关系，就是传说中的公式，这个公式得出来了，题目就解决了99%。
剩下的1％也非常关键，成败在此一举！剩下的1%究竟是什么呢？就是基础条件！
比如dp[0][0-j]
和 dp[0 - i][0]
的值。

3、上面三点如果自己已经理解了，那么还有最后一点要特别强调一下，
就是dp 中的下标问题
。
先上一段代码：

这段代码是上面那道题目的核心算法部分，注意看两次for循环的语句部分，dp始终用的是从1开始，
这是因为 dp[0][0 - j]
或dp[0-i][0]是作为基础条件已经要被事先解决的，这也体现了重复利用的DP思想。
所以，for循环里面，dp都是从1开始，在dp[0][0-j]或dp[0-i][0]的基础上计算，而与此同时，要注意数据源A，

B的下标引用要减去一
void func(string a, string b) {
    memset(dp, 0, sizeof(dp));
    // 首先就是 确定初试 的状态，比如可以找几个非常简单的 测试用例，和最基础的情况，分析
    //如下两个for循环就是考虑了基础的情况：
    //1、如果B只有空字符串""，A任意；
    for (int k = 0; k <= a.size(); ++k) {
        dp[0][k] = 1;
    }
    //2、如果A只有空字符串，B任意
    for (int l = 1; l <= b.size(); ++l) {
        dp[l][0] = 0;
    }
    //下面的算法，就必须要借助印度大神的 画表格法了！
    for (int i = 1; i <= b.size(); ++i) {
        for (int j = i; j <= a.size(); ++j) {
            if (b[i - 1] == a[j - 1]) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i][j]);
            }
        }
    }
    cout << dp[b.size()][a.size()] << endl;
}

总结：以上三点应该足够应付一些dp的题目了。还有一些略带数据思想和技巧的DP，需要慢慢积累。比如买卖股票DP算法问题
