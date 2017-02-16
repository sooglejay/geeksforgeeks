//
// Created by sooglejay on 17/1/12.
//
#include <iostream>
//http://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
using namespace std;

void func(string A, int n, int k, string &maxR) {
    if (k == 0) {
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[j] > A[i]) {
                swap(A[i], A[j]);
                if (A.compare(maxR)> 0) {
                    maxR = A;
                }
                func(A, n, k - 1, maxR);
                swap(A[i], A[j]);
            }
        }
    }

}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        string A;
        cin >> k >> A;
        string maxR = A;
        func(A, int(A.size()), k, maxR);
        cout << maxR << endl;
    }
}
