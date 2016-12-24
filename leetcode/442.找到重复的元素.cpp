//
// Created by sooglejay on 16/12/24.
//

vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> r;
    size_t size = nums.size();
    if (size == 0) {
        return r;
    }
    sort(nums.begin(), nums.end());
    int cur = nums[0];
    for (int i = 1; i < size; ++i) {
        if (cur != nums[i]) {
            cur = nums[i];
        } else {
            i++;
            r.push_back(cur);
        }

    }
    return r;

}
