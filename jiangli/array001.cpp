#include <iostream>
#include <string.h>
/**
 * 第一行 输入 一个数字 t，代表接下来有 t个测试用例
 *
 * 接下来每一个测试用例：
 *          第一行 输入一个数字 n， 代表接下来要输入n 个数，
 *          第二行 输入n个数
 *
 *          判断输入的 n 个数中， 是否存在一个数，在它左边的数都小于它，在它右边的数都比他大，如果存在，就输出它；
 *                             如果不存在输出－1
 *
 *  。。。
 *  。。。
 */
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int j = 0;
        for (j = 0; j < n; ++j) {
            int b = arr[j];
            bool sm = true;
            for (int i = 0; i < j; ++i) {
                if (arr[i] >= b) {
                    sm = false;
                    break;
                }
            }
            if (!sm)continue;
            bool bg = true;
            for (int k = j + 1; k < n; ++k) {
                if (arr[k] <= b) {
                    bg = false;
                    break;
                }
            }
            if (bg)break;
        }
        if (j ==n)cout << -1 << endl;
        else cout << arr[j] << endl;
    }
}