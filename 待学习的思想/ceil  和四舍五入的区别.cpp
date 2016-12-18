//
// Created by sooglejay on 16/12/18.
//
/**
 * Sherlock is going to walk to the store. On his way to the store he likes to visit his friends and stop at various other interesting places.On his way back he is carrying heavy bags and therefore he walks straight home. Sherlock's walk from his home to the store consists of M parts. In the i-th part (0-based index) sherlock will walk a[i] meters in the direction indicated by the character dir[i]. That character is one of 'N', 'S', 'W', 'E', denoting North, South, West, and East, respectively. On his way back home, Sherlock follows a straight line from the store to his home​.

Input:
Each test case contains an integer T denoting the no of test cases, then T test cases follow. First line of each test case contains an integer M. In the next two line you are given the description of Sherlock's way to the store, the array with M integers and the string with M uppercase characters. Your task is to print the total distance Sherlock will walk on his way to the store and back.

Output:
For each test case output will be an integer which represents the ceil of the total distance covered by Sherlock.

Constraints:
1<=T<=15
1<=M<=100

Example:
Input:
2
3
1 3 3
NES
4
10 10 10 10
NWSE

Output:
11
40

Explanation :
For test case 1
In total, Sherlock's walk consists of four parts: He goes 1 meter North. 3
meters East. 3 meters South. He goes straight to his home. The total distance is 1 + 3 + 3 + 3.6056 = 10.6056. so the ceil of it is 11.

For test case 2
In this test case the store is located at the same place as Sherlock's home. Thus, the length of
Sherlock's walk from the store back home is 0 meters.

**For More Examples Use Expected Output**
 */
#include <iostream>
#include <cmath>

using namespace std;

//floor(5.9)=5    ceil(5.1) = 6   四舍五入就是你懂的 5.6 = 6

int main() {
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        int A[c];
        for (int i = 0; i < c; ++i) {
            cin >> A[i];
        }
        char dir[c + 1];
        for (int j = 0; j < c; ++j) {
            cin >> dir[j];
        }
        int x = 0, y = 0;
        int sum = 0;
        for (int k = 0; k < c; ++k) {
            sum += A[k];
            switch (dir[k]) {
                case 'W':
                    x -= A[k];
                    break;
                case 'E':
                    x += A[k];
                    break;
                case 'N':
                    y += A[k];
                    break;
                case 'S':
                    y -= A[k];
                    break;
            }
        }


        sum += ceil(sqrt(x * x + y * y));

        //此时 sum是363.34  ceil 的结果就是 364  四舍五入的结果就是363
        cout << sum << endl;

    }
    return 0;
}



