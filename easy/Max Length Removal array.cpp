//
// Created by sooglejay on 16/12/12.
//

/**
 * Given a binary string (consists of only 0 and 1). If there is “100” as a sub-string in the string, then we can delete this sub-string. The task is to find the length of longest sub-string which can be make removed?

Examples:

Input  : str = "1011100000100"
Output : 6
// Sub-strings present in str that can be make removed
// 101{110000}0{100}. First sub-string 110000-->100-->null,
// length is = 6. Second sub-string 100-->null, length is = 3

Input  : str = "111011"
Output : 0
// There is no sub-string which can be make null
Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of one line. The line contains a string of 0's and 1's.

Output:

Length of the longest string that can be removed.

Constraints:

1 ≤ T ≤ 100
1 ≤ string length ≤ 1000

Example:

Input
2
010010
1011110000

Output
3
6

**For More Examples Use Expected Output**
 */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char A[1000];
        scanf("%s", A);
        int len = strlen(A);

        int index1 = 0, index2 = 0;

        for (int j = 0; j < len - 2; ++j) {
            //如果是1就进入算法
            if (A[j] == '1') {
                index1 = j + 1;
                //找第一个0元素，注意有可能是2，2代表已经被removed的元素
                while (index1 < len - 1) {
                    if (A[index1] == '2') {
                        index1++;
                        continue;
                    } else {
                        break;
                    }
                }

                //开始找第二个
                index2 = index1 + 1;
                while (index2 < len) {
                    if (A[index2] == '2') {
                        index2++;
                        continue;
                    } else if (A[index2] == '0' && A[index1] == '0') {
                        A[index2] = '2';
                        A[index1] = '2';
                        A[j] = '2';
                        //注意，这里需要把指针指向往前面移动一下
                        j -= 3;
                        if (j < -1) {
                            j = -1;
                        }
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
        int sum = 0;
        int temp = 0;
        for (int i = 0; i < len; ++i) {
            if (A[i] == '2') {
                temp++;
            } else {
                sum = sum > temp ? sum : temp;
                temp = 0;
            }
        }
        sum = sum > temp ? sum : temp;
        printf("%d\n", sum);
    }


    return 0;
}
