//
// Created by sooglejay on 17/4/15.
//

//http://practice.geeksforgeeks.org/problems/find-the-largest-number/0


//        Input  : n = 200
//        Output : 199
//        If the given number is 200, the largest
//        number which is smaller or equal to it
//                having digits in non decreasing order is
//        199.
//
//        Input  : n = 139
//        Output : 139


#include <iostream>
#include <sstream>

using namespace std;

long func(long s) {
    if (s < 10)return s;
    string str = to_string(s);
    int len = int(str.size());
    int start = 0;
    if (len > 0) {
        start = str[0] - '0';
    }
    int index = -1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] - '0' >= start) {
            start = str[i] - '0';
        } else {
            index = i - 1;
            break;
        }
    }
    if (index == -1)return s;
    stringstream stringstream1;
    start = index - 1;
    while (str[start] == str[index])start--;
    index = start + 1;
    for (int j = 0; j < index; ++j) {
        stringstream1 << str[j];
    }
    stringstream1 << (str[index] - '1');
    for (int i = index + 1; i < len; ++i) {
        stringstream1 << 9;
    }
    long ret = stol(stringstream1.str());
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long s;
        cin >> s;
        cout << func(s) << endl;

    }
    return 0;
}

//去掉各种转换，优化后的代码

#include <iostream>
#include <string.h>

using namespace std;

long func(long s) {
    if (s < 10) {
        return s;
    }
    long temp = s;
    int arr[11];
    memset(arr, 0, sizeof arr);
    int i = 0;
    while (s) {
        arr[i++] = int(s % 10);
        s /= 10;
    }
    int start = arr[i - 1], index = -1;
    for (int j = i - 2; j >= 0; --j) {
        if (arr[j] >= start) {
            start = arr[j];
        } else {
            index = j + 1;
            break;
        }
    }
    if (index == -1) {
        return temp;
    }
    temp = 0;
    start = index + 1;
    while (arr[start] == arr[index])start++;
    index = start - 1;
    for (int k = i - 1; k >=0; --k) {
        if (k > index) {
            temp = temp * 10 + arr[k];
        } else if (k == index) {
            temp = temp * 10 + arr[k] - 1;
        } else {
            temp = temp * 10 + 9;
        }
    }
    return temp;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long s;
        cin >> s;
        cout << func(s) << endl;
    }
    return 0;
}



