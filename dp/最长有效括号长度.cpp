//
// Created by sooglejay on 17/1/13.
//


/***
 * Longest valid Parentheses
dp  stack      Google
Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring.

Examples:

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()()

Input:  ()(()))))
Output: 6
Explanation:  ()(())

Input:
First line contains the test cases T.  1<=T<=500
Each test case have one line string S of character'(' and ')' of length  N.  1<=N<=10000

Example:
Input:
2
((()
)()())

Output:
2
4

**For More Examples Use Expected Output**



 */
#include <iostream>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

int dp[1001];

int lvp(string a) {
    int len = int(a.size());
    int stack1 = 0;
    int maxR = 0;
    int dp[len + 1];
    dp[0] = 0;
    if (len < 2) {
        return dp[0];
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < len; ++j) {
        if (a[j] == '(') {
            stack1++;
        } else if (stack1 > 0) {
            stack1--;
            dp[j] = dp[j - 1] + 2;
            if (j - dp[j] > 0) {
                dp[j] += dp[j - dp[j]];
            }
        }
        maxR = max(maxR, dp[j]);
    }
    return maxR;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << lvp(a) << endl;
    }

}


// 下面这个解法很聪明，直接使用一个栈结构，利用 栈存储了下标，还有栈顶元素。还有把－1加入栈中，这些技巧！太强大了
// C++ program to find length of the longest valid
// substring
#include <iostream>
#include <stack>

using namespace std;

int findMaxLen(string str) {
    int n = str.length();

    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
    stk.push(-1);

    // Initialize result
    int result = 0;

    // Traverse all characters of given string
    for (int i = 0; i < n; i++) {
        // If opening bracket, push index of it
        if (str[i] == '(')
            stk.push(i);

        else // If closing bracket, i.e.,str[i] = ')'
        {
            // Pop the previous opening bracket's index
            stk.pop();

            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty()) {
                int a = result;
                int b = i;
                int c = stk.top();
                int d = i-c;
                int re = max(a, d);
                result = re;
            }
                // If stack is empty. push current index as
                // base for next valid substring (if any)
            else {
                stk.push(i);
            }
        }
    }

    return result;
}

// Driver program
int main() {
    string str = "(()()";
    cout << findMaxLen(str) << endl;

    str = "(()()(()))";
    cout << findMaxLen(str) << endl;

    return 0;
}
