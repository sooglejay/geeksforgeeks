//
// Created by sooglejay on 17/5/3.
//




vector<int> fun(int n) {
    int cur = 1;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        vec.push_back(cur);
        if (cur * 10 <= n) {
            cur = cur * 10;
        } else {
            if (cur % 10 != 9&&(cur+1)<=n) {
                cur++;
            }
            else {
                while ((cur/10) % 10 == 9) {
                    cur /= 10;
                }
                cur = cur/10+1;
            }
        }
    }
    return vec;
}
