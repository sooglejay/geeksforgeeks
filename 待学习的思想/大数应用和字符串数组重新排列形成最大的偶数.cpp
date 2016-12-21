//
// Created by sooglejay on 16/12/21.
//


/***
 *
 * Largest Even Number
maths  sorting
As usual Babul is back with his problem but this time with numbers. In his problem there is a number P (always a whole number) with N digits. Now he started finding out the largest possible even number formed by rearranging this N digit number. For example consider number 1324, after rearranging the digits the largest even number possible is 4312.

Note: In case the number does not contain any even digit then output the largest odd number possible.

Input:
The first line of input will contain an integer T which is the no. of test cases. Each of the next T lines will contain a number P.

Output:
For each test case in a new line print the required result.

Constraints:
1<=T<=100
1<=N<=1000

Example:
Input:
5
1324
3415436
1023422
03517
3555

Output:
4312
6543314
4322210
75310
5553



**For More Examples Use Expected Output**


 */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {

        string s;
        cin >> s;

        int A[10] = {0,};
        int len = s.size();

        int min = 10;//先找出最小的偶数
        int j = -1;//及其下标，排除掉这一个位置
        for (int i = 0; i < len; ++i) {
            int tem = s[i] - '0';
            if (tem % 2 == 0) {
                if (min > tem) {
                    min = tem;
                    j = i;
                }

            }
        }

        for (int k = 0; k < len; ++k) {
            if (k == j) {//排除掉这一个位置
                continue;
            }
            int t = s[k] - '0';
            A[t]++;//统计数字出现的个数，后面从大到小 遍历数字即可
        }
        int stringLen = 0;
        for (int l = 9; l >= 0; --l) {
            while (A[l] > 0) {
                char ch = l + '0';
                s[stringLen] = ch;
                stringLen++;
                A[l]--;
            }
        }
        if (min < 10)
            s[stringLen] = min + '0';
        cout << s << endl;
    }
    return 0;
}