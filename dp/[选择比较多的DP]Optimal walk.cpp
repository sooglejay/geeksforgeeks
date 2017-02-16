//
// Created by sooglejay on 17/1/9.
//

//Given a point on x axis, (N,0), you are standing at origin and you can only move on x-axis. Lets say you are at (x,0), at each step you can either move one step forward ie (x+1,0) or one step backwards (x-1,0) or make a jump to double your current position (2*x,0). One step movement costs you A while a jump costs you B. If your initial position is (0,0) , find the minimum cost to reach (N,0) .
//
//Input:
//        First line of input consist of a single integer T denoting the total number of test case. Then T test cases follow. Each line of test case contains 3 space separated integers N, A, B as described in the problem statement.
//
//Output:
//        For each test case, print a single line containing the minimum cost to reach (N,0).
//
//
//Constraints:
//1<=T<=30
//1<=N<=10^5
//1<=A,B<=10^9
//
//
//Example:
//        Input:
//1
//7 1 100
//
//Output:
//7
//
//**For More Examples Use Expected Output**
//
//
//Contributor: Pranay Pandey

//大意，可以跳着走
//http://www.practice.geeksforgeeks.org/problem-page.php?pid=1388
// 自己想出来的方法，所以难免有点激动，也许以后很快就会忘记，但是
//基本的思想是：考虑所有的情况，然后对他们使用递归加动态规划算法
#include <iostream>
#include <cstring>

#define MAX 100001
long dp[MAX];
using namespace std;

long solve(long dst, long step, long doub) {
    if (dst < 1) {
        return 0;
    }
    if (dst == 1) {
        return step;
    }
    if (dp[dst] > 0) {
        return dp[dst];
    }
    if (dst % 2) {
        //  condition 1
        long c = doub + step + solve((dst - 1), step, doub);
        if ((dst / 2) * step > doub) {
            //  condition 2
            long a = doub + step + solve((dst + 1) / 2, step, doub);
            //  condition 3
            long b = doub + step + solve((dst - 1) / 2, step, doub);
            dp[dst] = min(min(a, b), c);
        } else {
            dp[dst] = min(dst * step, c);
        }
    } else {
        if ((dst / 2) * step > doub) {
            //  condition 4
            dp[dst] = doub + solve(dst / 2, step, doub);
        } else {
            //  condition 5
            dp[dst] = (dst / 2) * step + solve(dst / 2, step, doub);
        }
    }
    return dp[dst];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        long N, A, B;
        cin >> N >> A >> B;
        memset(dp, 0, sizeof(dp));
        dp[1] = A;
        solve(N, A, B);
        cout << dp[N] << endl;
    }
}


//下面 这个家伙的算法是 O(n) ,实在是佩服，其实是你自己没有把情况都考虑全面。下面这个家伙就是把情况都考虑全了。
// 还有一个点，就是 逻辑关系，其实这个题目的逻辑很简单的，就是一点一点的递进，直到N，所求的那个数为止，输出即可。
// 也就是说，为了求到达N的开销，我要先求到达 N／2，N-1,N+1 这三个点，然后比较这个三者情况。唉，还是三种情况啊！！
//都怪我没有考虑全面

#include <iostream>
#include <cstring>

using namespace std;
#define MAXA 1e18
long long int dp[100005];

int main() {
    //code
    long long int t, n, a, b, i;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        dp[0] = 0;
        for (i = 1; i <= n; i++) {
            dp[i] = MAXA;
            dp[i] = min(dp[i], dp[i - 1] + a);
            if (i % 2 == 0)
                dp[i] = min(dp[i], dp[i / 2] + b);
            else
                dp[i] = min(dp[i], min(dp[i / 2] + a + b, dp[(i + 1) / 2] + a + b));
        }
        cout << dp[n] << endl;
    }
    return 0;
}