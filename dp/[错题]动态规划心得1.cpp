//
// Created by sooglejay on 16/12/31.
//

//错题：
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1542

//么有做出来，思想是 每走一步都看看前面是否有可以跳的  节点，如果有，就使用它，不足 但是小于 基数 ，就作当作一步



//https://leetcode.com/problems/ones-and-zeroes/
int findMaxForm(vector <string> &strs, int m, int n) {
    size_t s = strs.size();
    int A[600], B[600];
    int **dp = (int **) malloc(sizeof(int *) * (100));
    for (int j = 0; j < m + 1; ++j) {
        dp[j] = (int *) malloc(sizeof(int) * (100));
        for (int i = 0; i < n + 1; ++i) {
            dp[j][i] = 0;
        }
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    for (int k = 0; k < s; ++k) {
        int a = 0, b = 0;
        string str = strs[k];
        int len = int(str.size());
        for (int i = 0; i < len; ++i) {
            if (str[i] - '0' > 0) {
                a++;
            } else {
                b++;
            }
        }
        A[k] = a;
        B[k] = b;
    }

    // 动态规划的 消费观点，有m,n 两种货币，所以需要双数组分别消费
    for (int l = 0; l < s; ++l) {//每个商品都去看看，至于能不能买得起，下面的循环会解决
        for (int i = m; i >= A[l]; --i) {//消费的条件
            for (int j = n; j >= B[l]; --j) {//消费的条件
                dp[i][j] = max(dp[i][j], 1 + dp[i - A[l]][j - B[l]]);//开始消费
            }
        }
    }

    //一共买了多少商品！
    return dp[m][n];


}
