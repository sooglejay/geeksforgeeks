#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); ++j) {
            for (int i = j + 1; i < nums.size(); ++i) {
                int sum = nums[i] + nums[j];
                sum *= -1;
                if (find(nums.begin(), nums.end(), sum) != nums.end()) {
                    vector<int> vec;
                    if (sum > nums[i]) {
                        vec.push_back(nums[j]);
                        vec.push_back(nums[i]);
                        vec.push_back(sum);
                    } else if (sum < nums[j]) {
                        vec.push_back(sum);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[i]);
                    } else {
                        if (nums[j] == nums[i] && nums[i] == 0) {
                            int c = count(nums.begin(), nums.end(), 0);
                            if (c < 3)
                                continue;
                        }
                        if (sum == nums[i] || sum == nums[j]) {
                            int c = count(nums.begin(), nums.end(), sum);
                            if (c == 1) {
                                continue;
                            }
                        }
                        vec.push_back(nums[j]);
                        vec.push_back(sum);
                        vec.push_back(nums[i]);
                    }
                    if (find(res.begin(), res.end(), vec) == res.end()) {
                        res.push_back(vec);
                    }
                }
            }
        }
        return res;


    }
};


int main() {

    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    v.push_back(0);
//    v.push_back(-1);
//    v.push_back(4);
//    v.push_back(5);
//    v.push_back(-11);
//    v.push_back(7);
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(-7);
//    v.push_back(-1);
//    v.push_back(-2);
//    v.push_back(-3);
//    v.push_back(-4);
//    v.push_back(-5);
    Solution s = Solution();
    vector<vector<int> > res = s.threeSum(v);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << endl;
        }
    }


}