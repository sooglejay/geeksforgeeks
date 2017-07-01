#include <iostream>
#include <string.h>
/**
 * 观察并寻找规律
 *
 * 给定一个数列，各行 如下

   第1行                    1  2
   第2行                 3  4  5  6
   第3行              7  8  9 10 11 12
   第4行          13 14 15 16 17 18 19 20

    。。。
    。。。
    。。。
     要求 输入一个 行号，求出该行的数字的和，
     比如
        输入 1，输出3
        输入 2，输出18
        等等
 */
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = n * (n - 1) + 1;
        int e = n * (n + 1);
        int sum = 0;
        for (int i = s; i <= e; ++i) {
            sum += i;
        }
        cout << sum << endl;

    }
}