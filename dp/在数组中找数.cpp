//
// Created by sooglejay on 17/1/8.
//


//http://www.practice.geeksforgeeks.org/problem-page.php?pid=351
//使用了深度优先查找DFS
#include<iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool solve(int A[], int n, int i, int sum) {
    if (sum == 0 && i <= n) {
        return true;
    }
    if (sum > 0 && i >= n) {
        return false;
    }
    if (sum < 0) {
        return false;
    }

    if (!solve(A, n, i + 1, sum - A[i])) {
        return solve(A, n, i + 1, sum);
    }
    return true;


}


int main() {
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            sum += A[i];
        }
        if (sum % 2) {
            cout << "NO\n";
            continue;
        }
        if (solve(A, n, 0, sum / 2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}