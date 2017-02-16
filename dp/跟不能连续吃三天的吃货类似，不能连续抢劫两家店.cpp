//
// Created by sooglejay on 17/1/14.
//

//https://leetcode.com/problems/house-robber/

//我忘记了 在geeksforgeeks上 哪里看到 一个sum数组，sum[i]表示在第ith家店时，可以抢到的最大的财富

class Solution {
public:
    int rob(vector<int> &nums) {
        size_t len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for (int i = 2; i < len; ++i) {
                     // 这家店不抢      //这家店抢
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return max(dp[len - 1], dp[len - 2]);
    }
};