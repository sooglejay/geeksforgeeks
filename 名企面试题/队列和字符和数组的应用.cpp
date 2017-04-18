//
// Created by sooglejay on 17/4/15.
//


/***
 *
 *

         Given an input stream of n characters consisting only of small case alphabets the task is to find the first non repeating character each time a character is inserted to the stream.

Example

        Flow in stream : a, a, b, c
        a goes to stream : 1st non repeating element a (a)
        a goes to stream : no non repeating element -1 (5, 15)
        b goes to stream : 1st non repeating element is b (a, a, b)
        c goes to stream : 1st non repeating element is b (a, a, b, c)

Input:
        The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream.

Output:
       For each test case in a new line print the first non repeating elements separated by spaces present in the stream at every instinct when a character is added to the stream, if no such element is present print -1.

Constraints:
        1<=T<=200
        1<=N<=500

Example:
Input:
        2
        4
        a a b c
        3
        a a c
Output:
        a -1 b b
        a -1 c


**For More Examples Use Expected Output**
 *
 */
#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

void func(int *a, int n) {
    queue<int> que;//存储孤立字符的队列
    int b[27];
    memset(b, 0, sizeof(b));
    int rev[502];//结果输出
    int k = 0;
    memset(rev, 0, sizeof(rev));
    for (int i = 0; i < n; ++i) {
        b[a[i]-'a'] ++;//统计每一个字符出现的次数
        if (b[a[i]-'a'] == 1 && que.empty()) {
            //如果只出现一次，并且队列为空，说明这个
            que.push(a[i]-'a');
            rev[k++] = a[i]-'a';
            continue;
        }
        int res = -1;//默认是不存在
        while (!que.empty()) {
            int top = que.front();
            if (b[top] > 1) {//如果队列头已经重复，就剔除
                que.pop();
            } else if (b[top] == 1) {//如果是孤立元素，就输出
                res = top;
                break;
            }
        }
        if (b[a[i]-'a'] == 1) {
            que.push(a[i]-'a');//如果是一个新的孤立元素，就添加到队列
        }
        rev[k++] = res;
    }
    //输出
    for (int j = 0; j < k; ++j) {
        if (rev[j] == -1) {
            cout << -1;
        } else {
            cout << char(rev[j] + 'a');
        }
        if (j < k - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            char ch;
            cin >> ch;
            arr[i] = ch;
        }
        func(arr, n);
    }
    return 0;
}


