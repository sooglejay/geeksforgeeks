
//
// Created by sooglejay on 16/12/25.
//

/***
 * Case-specific Sorting of Strings
sorting  string
Given a string consisting of uppercase and lowercase characters, you need to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Input: The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the length of string.

The second line contains a string of length N, consisting of uppercase and lowercase characters.


Output: Print T lines consisting of a sorted strings for the particular test case.


Constraints:

1 ≤ T ≤ 50

1 ≤ N ≤ 1000


Example:

Input:

1

12

defRTSersUXI

Output:

deeIRSfrsTUX

**For More Examples Use Expected Output**
 */
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int len;
        string s;
        cin >> len >> s;
        char upLoc[len + 1];
        memset(upLoc, 0, sizeof(upLoc));
        int lA[26], uA[26];
        for (int j = 0; j < 26; ++j) {
            lA[j] = -1;
            uA[j] = -1;
        }
        for (int i = 0; i < len; ++i) {
            if (s[i] > 96) {
                lA[s[i] - 'a']++;
            } else {
                uA[s[i] - 'A']++;
                upLoc[i] = '1';
            }
        }
        for (int k = 0; k < len; ++k) {
            if (upLoc[k] == '1') {
                int i = 0;
                while (i < 26 && uA[i] < 0) {
                    i++;
                }
                if (i < 26) {
                    uA[i]--;
                    cout << char(i + 'A');
                }

            } else {
                int i = 0;
                while (i < 26 && lA[i] < 0) {
                    i++;
                }
                if (i < 26) {
                    lA[i]--;
                    cout << char(i + 'a');
                }
            }
        }
        cout << endl;

    }
    return 0;
}