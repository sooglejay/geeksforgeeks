//
// Created by sooglejay on 16/12/25.
//

/***
 * Time Difference
maths
Given the start time and end time of a race in the format hh:mm:ss. You task is to print the time taken to complete the race.

Input :
The first line of input contains an integer T, denoting number of test case. Then T test cases follow. The first line of each test case contains string s, denoting the start time of the race. The second line of each test case contains a string e, denoting the end time of the race.


Output :
For each test case in a new line print the time taken to complete the race in the format hh:mm:ss.

Constraints :
1<=T<=100
0<=hh<=23
0<=mm<=59
0<=ss<=59
start time<=end time


Example:
Input :
2
13:50:45
14:55:50
12:00:00
24:00:00

Output:
01:05:05
12:00:00




**For More Examples Use Expected Output**
 */
#include <iostream>

using namespace std;

int cmp(const int *a, const int *b) {
    if (*a > *b) {
        return 1;
    } else if (*a < *b) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        int hour = 0, min = 0, sec = 0;
        char array[9];
        for (int i = 0; i < 2; ++i) {
            int aH = a[i] - '0';
            int bH = b[i] - '0';
            hour = hour * 10 + bH - aH;
        }

        for (int i = 3; i < 5; ++i) {
            int aM = a[i] - '0';
            int bM = b[i] - '0';
            min = min * 10 + bM - aM;
        }

        for (int i = 6; i < 8; ++i) {
            int aS = a[i] - '0';
            int bS = b[i] - '0';
            sec = sec * 10 + bS - aS;
        }

        if (sec < 0) {
            min--;
            sec += 60;
        }
        if (min < 0) {
            hour--;
            min += 60;
        }
        array[0] = char(hour / 10 + '0');
        array[1] = char(hour % 10 + '0');
        array[2] = ':';
        array[3] = char(min / 10 + '0');
        array[4] = char(min % 10 + '0');
        array[5] = ':';
        array[6] = char(sec / 10 + '0');
        array[7] = char(sec % 10 + '0');
        array[8] = '\0';


        cout << array << endl;
    }
}