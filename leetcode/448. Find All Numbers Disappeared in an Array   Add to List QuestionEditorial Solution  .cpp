//
// Created by sooglejay on 16/12/24.
//

vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> r;
    size_t big = nums.size();
    if (big == 0) {
        return r;
    }
    sort(nums.begin(), nums.end());
    int index = 0;
    for (int i = 1; i <= big;) {
        if (i < nums[index]) {
            r.push_back(i);
            ++i;
        } else if (i == nums[index]) {
            ++i;
            index++;
        } else if (i > nums[index]) {
            index++;
        }
    }
    return r;

}