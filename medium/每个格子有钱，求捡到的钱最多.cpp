//
// Created by sooglejay on 17/4/15.
//

#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;
//
//
//        Gold Mine Problem
//                dp      Flipkart
//                Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Your task is to find out maximum amount of gold which he can collect.
//
//    Examples:
//
//    Input : M[][] = {{1, 3, 3},
//        {2, 1, 4},
//        {0, 6, 4}};
//        Output : 12
//        {(1,0)->(2,1)->(2,2)}
//
//    Input: M[][] = {{1, 3, 1, 5},
//        {2, 2, 4, 1},
//        {5, 0, 2, 3},
//        {0, 6, 1, 2}};
//    Output : 16
//        (2,0) -> (1,1) -> (1,2) -> (0,3) OR
//        (2,0) -> (3,1) -> (2,2) -> (2,3)
//
//
//    Input:
//                The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix.
//
//    Output:
//                For each test case in a new line print an integer denoting the max gold the miner could collect.
//
//    Constraints:
//        1<=T<=100
//        1<=n,m<=20
//        1<=M[][]<=100
//
//    Example:
//    Input:
//        2
//        3 3
//        1 3 3 2 1 4 0 6 4
//        2 2
//        1 2 3 4
//    Output:
//        12
//        7
//
//        **For More Examples Use Expected Output**
//

//http://practice.geeksforgeeks.org/problems/gold-mine-problem/0
//非常典型的 动态规划题目
int doDp(int i, int j, int n, int m, int **arr, int **dp) {
    if (i < 0 || i >= n || j >= m) {
        return 0;
    }
    if (dp[i][j] > 0) {
        return dp[i][j];
    }
    int right = arr[i][j] + doDp(i, j + 1, n, m, arr, dp);//右边
    int rightUp = arr[i][j] + doDp(i - 1, j + 1, n, m, arr, dp);//右上
    int rightDown = arr[i][j] + doDp(i + 1, j + 1, n, m, arr, dp);//右下
    dp[i][j] = max(rightDown, max(right, rightUp));//合并
    return dp[i][j];
}

int func(int n, int m, int **arr) {
    int **dp = (int **) malloc(sizeof(int *) * n);
    for (int k = 0; k < n; ++k) {
        dp[k] = (int *) malloc(sizeof(int) * m);
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            dp[j][i] = 0;
        }
    }
    int ret = INT_MIN;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, doDp(i, 0, n, m, arr, dp));
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int **dp = (int **) malloc(sizeof(int *) * n);
        for (int k = 0; k < n; ++k) {
            dp[k] = (int *) malloc(sizeof(int) * m);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> dp[i][j];
            }
        }
        cout << func(n, m, dp) << endl;
    }
    return 0;
}


