//
// Created by sooglejay on 16/12/26.
//
/*
Count Number
array
        Given an array A consisting of integers of size N and 2 additional integers K and X, you need to find the number of subsets of this array of size K, where Absolute difference between the Maximum and Minimum number of the subset is at most X.

As this number that you need to find can be rather large, print it Modulo 109+7


Input:
        The first line of input contains T denoting the no of test cases . Then T test cases follow . The first line of each test case contains 3 space separated integers denoting N, K and X. The next line contains N space separated values of the array A[ ] .

Output:
        For each test case output the required result in a new line, print it Modulo 109+7.

Constraints:
1≤N≤5×105
1≤K≤N
1≤A[i],X≤109

Example:
        Input:
2
5 3 5
1 2 3 4 5
8 4 6
2 4 6 8 10 12 14 16
Output:
10
5

Explanation :
        For the first test case
Possible subsets of size 3 are {1,2,3} {1,2,4} {1,2,5} {1,3,4} {1,3,5} {1,4,5} {2,3,4} {2,3,5} {2,4,5} {3,4,5} having difference of maximum and minimum element less than equal to 5.

For the second test case
Possible subsets of size 4 are {2,4,6,8} {4,6,8,10} {6,8,10,12} {8,10,12,14} {10,12,14,16} having difference of maximum and minimum element less than equal to 6.



**For More Examples Use Expected Output**/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long pow(int a, int b, int MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>=MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}

long long choose(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);

    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;

    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(){

    long long MOD = 1000000007;
    long long t,n,k,x;
    cin >> t;

    while(t--){

        cin >> n >> k >> x;
        int arr[n];

        for(int i=0;i<n;i++) cin >> arr[i];
        sort(arr,arr+n);

        long long ans = 0;

        if (k==1) {
            cout << n << "\n";
            continue;
        }

        for (int i=0;i<n;i++) {

            int maxElm = arr[i] + x;
            int up = upper_bound (arr+i , arr+n , maxElm) - arr;
            up -- ;

            if (arr[up] - arr[i] <= x && (up-i >= 1) && (k >= 2) && ((up-i) >= (k-1))){
                ans = ((ans % MOD) + (choose(up-i , k-1, MOD) % MOD)) % MOD;
            }
        }
        cout << (ans % MOD) << "\n";
    }
    return 0;
}


