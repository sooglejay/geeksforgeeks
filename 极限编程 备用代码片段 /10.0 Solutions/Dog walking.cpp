//
// Created by sooglejay on 17/4/16.
//


//https://www.hackerrank.com/contests/ieeextreme-challenges/challenges/dog-walking

//
//            Your friend, Alice, is starting a dog walking business. She already has K dog walkers employed, and today there are N dogs that need to be walked. Each dog walker can walk multiple dogs at the same time, so the dogs will be arranged into K nonempty groups, and each group will then be walked by a single dog walker. However, smaller dogs can be aggressive towards larger dogs, and that makes it harder to walk them together.
//
//            More formally, if the smallest dog in a group has size a, and the largest dog in the group has size b, then the range of the group is defined as b-a. In particular, the range of a group consisting of a single dog is 0. The smaller the range of a group is, the easier it is to walk that particular group. Hence Alice would like to distribute the dogs among the dog walkers so that the sum of ranges of the groups is minimized. Also, since she doesn't want any of the dog walkers to feel left out, she makes sure each dog walker gets to walk at least one dog.
//
//            Given N, K and the sizes of the dogs, can you help Alice determine what is the minimum sum of ranges over the K groups if the dogs are arranged optimally?
//
//            Input Format
//
//            The first line of input contains t, 1 ≤ t ≤ 5, which gives the number of test cases.
//
//            Each test case starts with a line containing two integers N, the number of dogs, and K, the number of employees, separated by a single space. Then N lines follow, one for each dog, containing an integer x representing the size of the corresponding dog.
//
//            Constraints
//
//            1 ≤ K ≤ N ≤ 105, 0 ≤ x ≤ 109
//
//            Output Format
//
//            For each test case, you should output, on a line by itself, the minimum sum of ranges over the K groups if the dogs are arranged optimally.
//
//            Sample Input
//
//            2
//            4 2
//            3
//            5
//            1
//            1
//            5 4
//            30
//            40
//            20
//            41
//            50
//            Sample Output
//
//            2
//            1
//            Explanation
//
//                    In the first test case there are four dogs: one of size 3, one of size 5, and two of size 1. There are two dog walkers, and we want to distribute the dogs among them. One optimal way to do this is to make one dog walker walk the dogs of size 3 and 5, and the other dog walker walk the two dogs of size 1. Then the first group has range 5-3=2, while the second group has range 1-1=0, giving a total of 2+0=2.
//
//            In the second test case there are dogs of size 30, 40, 20, 41 and 50, and four dog walkers. There are so many dog walkers that we can ask all but one of them to walk a single dog. We will make the last dog walker walk the dogs of size 40 and 41, which gives a range of 41-40=1. All other groups have range 0, so the total is 1.
//


//每只狗有一个数值，人要溜狗，至少溜同时一只，每人溜的狗中，狗的数值最大者减最小者 得到一个遛狗group的x，所有x相加，和最少是多少？




这道题目我用了dp数组，加三层循环。我日，得了15分。后来发现别人github传的解决方案，只需要O（n）代价，我日



#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>


using namespace std;

long func(int n, int k, long *a) {
    if (k == n)return 0;
    long dp[k + 1][n + 1];
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    sort(a, a + n);
    for (int l = n - 1; l >= 0; --l) {
        dp[1][l] = a[n - 1] - a[l];

    }

    for (int m = 1; m <= k; ++m) {
        for (int i = n - 1; i >= 0; --i) {
            int disI = (n - 1) - (i) + 1;
            if (m == disI) {
                dp[m][i] = 0;
                continue;
            }
            if (m > disI) {
                dp[m][i] = INT_MAX;
                continue;
            }
            for (int j = i; j <= n - m; ++j) {
                int dis = (n - 1) - (j + 1) + 1;
                if (m - 1 == dis) {
                    dp[m - 1][j + 1] = 0;
                } else if (m - 1 > dis) {
                    dp[m - 1][j + 1] = INT_MAX;
                    continue;
                }
                if (dp[m - 1][j + 1] == INT_MAX) {
                    continue;
                }
                if(m>1){
                    dp[m][i] = min(dp[m][i], a[j] - a[i] + dp[m - 1][j + 1]);
                }
            }
        }
    }
    return dp[k][0];
}

int main() {
    //code
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> k;
        long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << func(n, k, a) << endl;
    }
    return 0;
}



//牛逼的思路
long func(int n, int k, long *a) {
    if (n == k)return 0;
    sort(a, a + n);
    long dp[n - 1];
    for (int i = 0; i < n - 1; ++i) {
        dp[i] = a[i + 1] - a[i];
    }
    sort(dp, dp + (n - 1));
    int reduce = n - k;
    long sum = 0;
    for (int j = 0; j < reduce; ++j) {
        sum += dp[j];
    }
    return sum;
}










