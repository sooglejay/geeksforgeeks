//
// Created by sooglejay on 17/1/7.
//


//https://www.youtube.com/watch?v=BysNXJHzCEs&index=15&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr

// 思想：
// 1  画表格然后写公式
// 2  从简单的情况入手 ，比如只有一个元素的情况 然后 spread by 1
#include<iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string A, B;
        cin >> A >> B;
        int dp[b + 1][a + 1];
        for (int k = 0; k <= b; ++k) {
            for (int i = 0; i <= a; ++i) {
                dp[k][i] = 0;
            }
        }
        int max = 0;
        for (int i = 1; i <= b; ++i) {
            for (int j = 1; j <= a; ++j) {
                if (B[i - 1] == A[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
                max = max < dp[i][j] ? dp[i][j] : max;
            }
        }
        cout << max << endl;

    }
}





#include<iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;

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
        int sum = 0, sm, flag = 0;
        int B[3] = {0, 0, 0};
        for (int j = 0; j < n; ++j) {
            sum += A[j];
            B[flag++] = A[j];
            if (flag == 3) {
                sm = min(min(B[0], B[1]), B[2]);
                sum -= sm;
                int i = 0;
                for (i = 0; i < 3; ++i) {
                    if (B[i] == sm) {
                        break;
                    }
                }
                for (int k = i; k < 3 - 1; ++k) {
                    B[k] = B[k + 1];
                }
                flag = 3 - 1 - i;
            }
        }
        cout << sum << endl;
    }
}