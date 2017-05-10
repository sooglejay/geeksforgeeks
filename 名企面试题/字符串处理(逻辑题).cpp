//
// Created by sooglejay on 17/5/10.
//

#include <iostream>
#include <string.h>

using namespace std;


string func(string s) {
    char vowelsCh[] = {'a', 'e', 'i', 'o', 'u'};
    int vowel[5];//a e i o u
    int con[28];
    memset(vowel, 0, sizeof(vowel));
    memset(con, 0, sizeof(con));
    bool vowelFlag = true;
    for (int i = 0; i < s.size(); ++i) {
        int j = 0;
        for (; j < 5; ++j) {
            if (s[i] == vowelsCh[j]) {
                vowel[j]++;
                break;
            }
        }
        if (j == 5) {
            if (i == 0)vowelFlag = false;
            con[s[i] - 'a']++;
        }
    }

    string res;
    for (int j = 0; j < s.size();) {
        if (vowelFlag) {
            for (int i = 0; i < 5; i++) {
                if (vowel[i] > 0) {
                    res += vowelsCh[i];
                    vowel[i]--;
                    j++;
                    break;
                }
            }
            for (int i = 0; i < 28; ++i) {
                if (con[i] > 0) {
                    con[i]--;
                    res += char('a' + i);
                    j++;
                    break;

                }
            }
        } else {
            for (int i = 0; i < 28; ++i) {
                if (con[i] > 0) {
                    con[i]--;
                    res += char('a' + i);
                    j++;
                    break;
                }
            }
            for (int i = 0; i < 5; i++) {
                if (vowel[i] > 0) {
                    res += vowelsCh[i];
                    vowel[i]--;
                    j++;
                    break;
                }
            }
        }
    }
    return res;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << func(s) << endl;
    }
}