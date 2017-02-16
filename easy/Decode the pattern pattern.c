/**
Decode the pattern
pattern  string      Amazon    Facebook
Given a pattern as below and an integer n your task is to decode it and print nth row of it. The pattern follows as :
1
11
21
1211
111221
............

Input:
The first line of input is the number of test cases .  Then T test cases follow . The first line of each test case is an integer N.

Output:
For each test case print the required nth row of the pattern.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
2
2
3
Output:
11
21
 

**For More Examples Use Expected Output**
*/




#include <iostream>

using namespace std;

string sf(string pre) {
    char ch = pre[0];
    int len = int(pre.size()), i, c = 1;
    string res = "";
    if (len == 1) {
        return to_string(1) + to_string(ch - '0');
    }
    for (i = 1; i < pre.size(); ++i) {
        if (pre[i] == ch) {
            c++;
        } else {
            res = res + to_string(c) + to_string(ch - '0');
            c = 1;
        }
        ch = pre[i];
    }
    res += to_string(c) + to_string(ch - '0');
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string res = "1";
        for (int i = 1; i < n; ++i) {
            res = sf(res);
        }
        cout << res << endl;
    }
}



