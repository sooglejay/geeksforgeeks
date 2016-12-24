//
// Created by sooglejay on 16/12/24.
//

/**
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
 **/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                int index = i + 1;
                while (index < size && nums[index] == 0) {
                    index++;
                }
                if (index < size) {
                    int tem = nums[index];
                    nums[index] = nums[i];
                    nums[i] = tem;
                }
            }
        }
    }
};