//
// Created by sooglejay on 16/12/29.
//

//
// Created by sooglejay on 16/12/28.
//

/***
 * Largest Number formed from an Array
array      Amazon    Paytm
Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.

The result is going to be very large, hence return the result in the form of a string.

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.


Output:

In each separate line print the largest number formed by arranging the elements of the array in the form of a string.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 1000


Example:

Input:

2
5
3 30 34 5 9
4
54 546 548 60

Output:

9534330
6054854654

**For More Examples Use Expected Output**
 */

#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(string a, string b)//定义比较规则
{
    string ab = a + b;
    string ba = b + a;
    return ab > ba;

}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int l;
        cin >> l;
        vector <string> v;
        for (int i = 0; i < l; ++i) {
            string a;
            cin >> a;
            v.push_back(a);

        }
        sort(v.begin(), v.end(), cmp);
        for (int j = 0; j < l; ++j) {

            cout << v[j];
        }
        cout << endl;
    }
}
