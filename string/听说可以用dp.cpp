//
// Created by sooglejay on 17/1/11.
//

#include <iostream>
#include <cstring>
#include <vector>
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1277


//dp:  http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            string tem;
            cin >> tem;
            vec.push_back(tem);
        }
        string s;
        cin >> s;
        size_t j = 0;
        int res = 0;
        size_t LL = s.size();
        size_t NN = vec.size();
        size_t SS = 0;
        while (j < LL) {
            res = 0;
            for (int i = 0; i < NN; ++i) {
                string re = vec[i];
                SS = re.size();
                int k = 0;
                for (k = 0; k < SS; ++k) {
                    if (j + k > LL) {
                        break;
                    }
                    char ch1 = s[j + k];
                    char ch2 = re[k];
                    if (ch1 != ch2) {
                        break;
                    }

                }
                if (k == re.size()) {
                    res = 1;
                    j += k;
                    break;
                }
            }
            if (!res) {
                break;
            }
        }
        cout << res << endl;
    }

}