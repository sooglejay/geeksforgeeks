//
// Created by sooglejay on 17/1/8.
//

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1391

//心得：
// 1、动态规划的难点是难以想到公式，一般求最大值，最小值，都可以使用动态规划
// 2、动态规划的特征是，肯定存在公式，其次是递归和循环；
// 一般，如果逻辑是层层嵌套，需要比较的情况很多，就使用嵌套（递归），然后用表格记下来每一次嵌套的值，下一次再来就会查到表格，已经来过了，不需要再走一遍；如果是层层递进的，后面的情况只是简单需要叠加前面的，则使用循环，一层层叠加前面的表格值就行。


//下面的算法使用的就是递归＋动态规划，因为属于嵌套型，每一次选择都要考虑，那么就存在对每一次选择的结果进行比较，并把比较后的知识存入表格，也就是dp，下一次就不需要再重复工作了
//最优子结构就是  循环出现的相同结构！可以利用数组把出现这些结构的位置纪录下来，以后再来就直接查表了。

#include<iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int max(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    if (c >= a && c >= b) {
        return c;
    }
    return 0;
}

int func(int *dp, int *A, int n, int i) {
    if (i >= n) {
        return 0;
    }
    if (dp[i] > 0) {
        return dp[i];
    }
    //难点是想到公式 ，   把剩下的工作交给递归去执行，
    int a = A[i] + ((i + 1) < n ? A[i + 1] : 0) + func(dp, A, n, i + 3);
    int b = ((i + 1) < n ? A[i + 1] : 0) + ((i + 2) < n ? A[i + 2] : 0) + func(dp, A, n, i + 4);
    int c = A[i] + func(dp, A, n, i + 2);
    dp[i] = max(a, b, c);
    return dp[i];

}



int main() {
    int *dp = (int *) malloc(100000 * sizeof(int));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int j = 0; j < 100000; ++j) {
            dp[j] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cout << func(dp, A, n, 0) << endl;
    }
}




// 下面是我自己某一天自己做出来的。当然算法还是跟上面一样。只是想再多说几句
//不能连续三天吃，就存在三种情况：
// 1 第 i 天不吃
// 2 第i+1天不吃
// 3 第i+2天不吃,
//动态规划算法的精髓就是 后面所有的 情况都脱不掉上面那三种情况，如果脱离，那么公式就没有写全，跟 "公式写对了" 这个假设存在矛盾conflict！
//公式写对了，比如上面三种情况，就能做出来了！

//剩下的工作交给动态规划

//看目的，目的是求最多吃多少，那就取上面三种情况的最大值
#include <iostream>
#include <cstring>

using namespace std;

long solve(long *dp, int *A, int n, int i) {
    if (i >= n) {
        return 0;
    }
    if (dp[i] > 0) {
        return dp[i];
    }
    long a = ((i + 1 < n) ? A[i + 1] : 0) + ((i + 2) < n ? A[i + 2] : 0) + solve(dp, A, n, i + 4);
    long b = A[i] + solve(dp, A, n, i + 2);
    long c = A[i] + ((i + 1 < n) ? A[i + 1] : 0) + solve(dp, A, n, i + 3);
    dp[i] = max(max(a, b), c);
    return dp[i];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        long *dp = (long *) malloc(n * sizeof(long));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << solve(dp, A, n, 0) << endl;


    }
}