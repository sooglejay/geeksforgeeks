//
// Created by sooglejay on 16/12/13.
//

/**

 Given an integer array, for each element in the array check whether there exist a smaller element on the next immediate position of the array. If it exist print the smaller element. If there is no smaller element on the immediate next to the element then print -1.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains an integer N, where N is the size of array.
The second line of each test case contains N integers sperated with a space which is input for the array arr[ ]

Output:

For each test case, print in a newline the next immediate smaller elements for each element in the array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ arr[i] ≤ 1000

Example:

Input
2
5
4 2 1 5 3
6
5 6 2 3 1 7

Output
2 1 -1 3 -1
-1 2 -1 1 -1 -1

**For More Examples Use Expected Output**


 **/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>


#include <stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int N;
        cin >> N;
        int pre = 0, cur = 0, i = 0;
        cin >> pre;
        while (i < N - 1) {
            cin >> cur;
            if (cur < pre) {
                cout<<cur<<' ';
            }else{
                cout<<-1<<' ';
            }
            pre = cur;
            i++;
        }
        cout<<-1<<endl;
    }

    return 0;
}
