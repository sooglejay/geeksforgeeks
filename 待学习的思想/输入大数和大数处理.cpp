//
// Created by sooglejay on 16/12/21.
//

/***
 * Find (a^b)%m
modular arithmetic
Given three numbers a, b and m where 1<=b,m<=10^6 and ‘a’ may be very large and contains upto 10^6 digits. The task is to find (a^b)%m.

Examples:

Input  : a = 3, b = 2, m = 4
Output : 1
Explanation : (3^2)%4 = 9%4 = 1

Input : a = 987584345091051645734583954832576, b = 3, m = 11
Output: 10

Input:
The first line of input contains T denoting the no of test cases . Then T test cases follow . The first line of each test case contains 3  separated integers denoting a, b and m.

Output:
For each test case output the required result in a new line.

Constraints:
1<=T<=100
1<=b,m<=10^6

Example:
Input:
2
3 2 4
2 10 6
Output:
1
4

**For More Examples Use Expected Output**
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


int main() {
    //code
    int n;
    cin >> n;
    while (n--) {

        string a;
        int b;
        int m;
        cin >> a;
        cin >> b;
        cin >> m;
        int len = a.size();
        int num = 0;
        for (int i = 0; i < len; ++i) {
            num = num * 10 + (a[i] - '0');
            num %= m;
        }
        size_t res = num;
        for (int j = 1; j < b; ++j) {
            res = (res * num) % m;
        }
        cout << res << endl;


    }
    return 0;

}