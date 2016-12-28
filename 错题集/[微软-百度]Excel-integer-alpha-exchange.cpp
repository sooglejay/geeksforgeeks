//
// Created by sooglejay on 16/12/28.
//

/**
 * Excel Sheet
number theory      Microsoft
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB

NOTE: The alphabets are all in uppercase.



Input:

The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.


Output:

Print the string corrosponding to the column number.


Constraints:

1 ≤ T ≤ 40
1 ≤ N ≤ 10000000

Example:

Input
1
51
Output
AY

**For More Examples Use Expected Output**
 *
 * 实质是 26进制 跟10进制的转换
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>


using namespace std;

int get(int n) {
    int s = 0;
    while (n >= 26) {
        n /= 26;
        s++;
    }
    return s;
}

// 获得特定 进制位的系数，并修改 源数值，意思是每转换一位，就要减去该位的数值
int getM(int *num, int i) {
    int b = 1;
    for (int j = 0; j < i; ++j) {
        b = b * 26;
    }
    int res = *num / b;//获得该位的系数，意思是存在多少个 26^b
    *num = *num - b * res;//减去 系数乘以权重，这样就是 转换之后，还剩下的数值
    if (res == 0) {
        res = *num;// 如果res为0，说明 num<b, 换句话说，已经是最后一个 26^0 这一个位了，只需要把num送出去就行了。
        // 能够进入这里都是 输入的数值 超过了26的，i＝0时，我特定让它变成了1，这样，这个函数不用任何变动。
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int len = get(n) + 1;
        char s[len + 1];
        memset(s, 0, sizeof(s));
        int j = 0;
        for (int i = len - 1; i >= 0; --i) {
            int dif = getM(&n, i == 0 ? 1 : i);
            char ch = char(dif + 'A' - 1);//因为A 算作1，所以要减去1 ，dif就代表字母表中第dif个字母啦！
            s[j++] = ch;
        }
        s[j] = '\0';
        cout << s << endl;
    }
}