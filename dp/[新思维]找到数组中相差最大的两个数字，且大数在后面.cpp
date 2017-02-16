//
// Created by sooglejay on 17/1/11.
//

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=567

//通过不限制次数买卖股票的那一道题,就是 while 寻找到一个点，然后就开始变量递增的寻找
#include <iostream>

using namespace std;

int func(int *A, int n) {
    int i = 0;
    while ((i + 1) < n && A[i + 1] <= A[i]) {
        i++;
    }
    int min = A[i];
    int maxDiff = -1;
    while ((i + 1) < n) {
        if (A[i + 1] > min) {
            maxDiff = max(maxDiff, A[i + 1] - min);
        } else if (A[i + 1] < min) {
            min = A[i + 1];
        }
        i++;
    }
    return maxDiff;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << func(A, n) << endl;
    }

}