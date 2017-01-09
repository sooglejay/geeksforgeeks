//
// Created by sooglejay on 17/1/9.
//


//http://www.geeksforgeeks.org/print-longest-common-sub-sequences-lexicographical-order/
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1448
#include <iostream>

using namespace std;
// length of lcs
int lcslen = 0;
#define MAX 100

// dp matrix to store result of sub calls for lcs
int dp[MAX][MAX];

// A memoization based function that returns LCS of
// str1[i..len1-1] and str2[j..len2-1]
int lcs(string str1, string str2, int len1, int len2,
        int i, int j) {
    int &ret = dp[i][j];

    // base condition
    if (i == len1 || j == len2)
        return ret = 0;

    // if lcs has been computed
    if (ret != -1)
        return ret;

    ret = 0;

    // if characters are same return previous + 1 else
    // max of two sequences after removing i'th and j'th
    // char one by one
    if (str1[i] == str2[j])
        ret = 1 + lcs(str1, str2, len1, len2, i + 1, j + 1);
    else
        ret = max(lcs(str1, str2, len1, len2, i + 1, j),
                  lcs(str1, str2, len1, len2, i, j + 1));
    return ret;
}

void back(string A, string B, int index1, int index2, int lA, int lB, char *z, int cunt) {
    if (cunt == maxLen) {
        z[cunt] = '\0';
        cout << z << endl;
        return;
    }
    if (index1 == lA || index2 == lB)
        return;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        // done is a flag to tell that we have printed all the
        // subsequences corresponding to current character
        bool done = false;

        for (int i = index1; i < lA; i++) {
            // if character ch is present in str1 then check if
            // it is present in str2
            if (ch == A[i]) {
                for (int j = index2; j < lB; j++) {
                    // if ch is present in both of them and
                    // remaining length is equal to remaining
                    // lcs length then add ch in sub-sequenece
                    if (ch == B[j] &&
                        lcs(A, B, lA, lB, i, j) == lcslen - cunt) {
                        z[cunt] = ch;
                        //注意 下面的 i和j 我错写为 index1和index2
                        back(A, B, i + 1, j + 1, lA, lB, z, cunt + 1);
                        done = true;
                        break;
                    }
                }
            }

            // If we found LCS beginning with current character.
            if (done)
                break;
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        int len1 = int(A.length()), len2 = int(B.length());

        // Find length of LCS
        memset(dp, -1, sizeof(dp));

        lcslen = lcs(A, B, len1, len2, 0, 0);

        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        char z[103];
        back(A, B, 0, 0, len1, len2, z, 0);
        cout << endl;
    }

}