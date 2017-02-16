//
// Created by sooglejay on 17/1/14.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace std;
// 大意：-1,99,100 返回9900; -2，0,-1返回 0; -4,-3,-2,返回12；即连续元素乘积最大值

//这道题目坐下来感受深刻，我之前的朴素的O（n*n）时间 算法不行。下面的算法只需 O(n)

//这道题目，利用 min_ending_here 和max_ending_here很巧妙的记住了在第ith个元素时刻，各种乘积的情况，应该好好体会

//有几个变量是为了对付 不存在正数的情况。
int maxProduct(int *nums, int n) {
    if (n == 1) {
        return nums[0];
    }
    // 这个变量永远存储正数
    int max_ending_here = 1;
    // 这个变量永远存储负数
    int min_ending_here = 1;
    // 存储最大的乘积结果
    int max_so_far = 1;
    // 这几个变量是为了对付 不存在正数的情况，依次为负数的个数、零的个数、正数的个数
    int negativeC = 0, zeroC = 0, positiveC = 0;
    // 如果不存在正数，并且连续出现负数的个数又不超过1个，就返回最大的元素，因为
    int maxTicky = INT_MIN;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {//如果是正数
            positiveC++;
            max_ending_here = max_ending_here * nums[i];
            min_ending_here = min(min_ending_here * nums[i], 1);
        } else if (nums[i] == 0) {
            //如果是0，一切重新开始。因为任何数乘以0都归零。记住，我们已经存储了这之前的最大值到max_so_far中去了
            zeroC++;
            negativeC = 0;
            max_ending_here = 1;
            min_ending_here = 1;
        } else {
            negativeC++;
            if (negativeC >= 2) {//说明存在连续的负数，那么下面的max_ending_here就能得到正确的更新了
                //而不会是1跟负数比较，结果最大还是1
                flag = 1;
            }
            int temp = max_ending_here;
            //负数乘以负数 结果是正数。
            max_ending_here = max(min_ending_here * nums[i], 1);
            min_ending_here = temp * nums[i];
        }
        //每次迭代都会更新 最大值，所以不用担心漏掉
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    if (!positiveC) {
        if (flag) {
            return max_so_far;
        } else {
            //这里直接返回0，因为如果只有一个元素，早就在程序开始就返回了。
            return 0;
        }
    }
    return max_so_far;
}

int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//
//        int n, m;
//        cin >> n >> m;
//        int A[n];
//        for (int i = 0; i < n; ++i) {
//            cin >> A[i];
//        }
////        cout << func(A, n, m) << endl;
//    }

    int nums[] = {-1, 99, 100};
//    int nums[] = {-4,-3};
//    int nums[] = {-2};

    cout << maxProduct(nums, sizeof(nums) / sizeof(int)) << endl;


}

//下面是http://bangbingsyb.blogspot.com/2014/11/leetcode-maximum-product-subarray.html
//这个家伙写出了非常简洁的算法

//它的思路：
//
//Maximum Subarray那题的变种。由于正负得负，负负得正的关系。以A[i]结尾的max product subarray同时取决于以A[i-1]结尾的max / min product subarray以及A[i]本身。因此，对每个i，需要记录min/max product两个状态：
//
//max_product[i] = max(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i])
//min_product[i] = min(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i])
//


int maxProduct(vector<int> &A) {
    size_t n = A.size();
    if (n <= 0) return 0;
    int ret, curMax, curMin;
    ret = curMax = curMin = A[0];
    for (int i = 1; i < n; i++) {
        int temp = curMax;
        int a = A[i];
        int b1 = curMax * A[i];
        int b2 = curMin * A[i];
        int b3 = max(b1, b2);
        int b4 = max(b3, A[i]);
        curMax = b4;

        int e1 = temp * A[i];
        int e2 = curMin * A[i];
        int e3 = min(temp * A[i], curMin * A[i]);
        int r = min(e3, A[i]);
        curMin = r;
        int r2 = max(ret, curMax);
        ret = r2;
    }
    return ret;
}

