//
// Created by sooglejay on 17/1/10.
//

//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1337

//下面的算法真的太牛逼了，牛逼的地方是 temS   这个神奇 的变量，它统计了 在累加过程中－1 的个数，唉，这个描述还是不到位，可以自己运行代码体会一下，或者review一下
#include <iostream>
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
            if (A[i] == 0) {
                A[i] = -1;
            }
        }
        int maxC = 0, oneC = 0, minusC = 0, temS = 0;
        for (int j = 0; j < n; ++j) {
            temS = temS + A[j];
            if (A[j] > 0) {
                oneC++;
            }
            if (temS > 0) {
                temS = 0;
            }
            maxC = min(maxC, temS);
        }
        maxC = maxC * -1 + oneC;
        cout << maxC << endl;
    }
}