//
// Created by sooglejay on 17/1/9.
//
//
//Letter Writer
//dp
//        LOBO is a letter writer and he is  working in shop near post office. He has to write two types of letters which are:
//
//Corporate Letters: 12 letters of this type can be written in an hour.
//Informal Letters: 10 letters of this type can be written in an hour.
//
//You are to help him to save time. Given N number of letters, print the minimum number of hours he needs to put for combination of both the letters, so that no time is wasted.
//
//
//Input:
//        The first line will contain T  denoting number of test cases. Then T test cases follow . Each test case will have an integer N.
//
//Output:
//        For each test case in a new line , print the minimum number of hours LOBO needs to write the combination of both the letters. If it is NOT possible, print "−1".
//
//Constraints:
//1≤T≤100
//1≤N≤150
//
//
//Example
//        Input:
//
//2
//33
//36
//
//Output:
//-1
//3
//
//**For More Examples Use Expected Output**

///是根据 测试用例找到的规律，然后做出来的


#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int dp[N + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i * 10 <= N; i++) {
            dp[i * 10] = i;
        }
        for (int i = 1; i * 12 <= N; i++) {
            dp[i * 12] = i;
        }
        for (int j = 0; j * 10 <= N; ++j) {
            int i = 0;
            while (j * 10 + i * 12 <= N) {
                if (dp[j * 10] > -1 && dp[i * 12] > -1)
                    dp[j * 10 + i * 12] = dp[j * 10] + dp[i * 12];
                else{
                    dp[j * 10 + i * 12] = max(dp[j * 10], dp[i * 12]);
                }
                i++;
            }
        }
        cout << dp[N] << endl;
    }
}




//下面这个家伙使用 O(n)就解决了问题，思想非常值得借鉴， 也就是如何计算新值时使用旧值。
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dp[300];
    for(int i=0;i<=12;i++)
        dp[i]=INT_MAX;
    dp[10]=1;
    dp[12]=1;
    for(int i=13;i<=200;i++)
    {
        int p=min(dp[i-10],dp[i-12]);
        if(p==INT_MAX)
            dp[i]=p;
        else
            dp[i]=p+1;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(dp[n]==INT_MAX)
            cout<<"-1\n";
        else
            cout<<dp[n]<<endl;
    }
}
//下面是题目可以找出的测试用例，分别是1-44，最后一个值本来是44，但是我用30替换了。
//-1
//-1
//-1
//-1
//-1
//-1
//-1
//-1
//-1
//1
//-1
//1
//-1
//-1
//-1
//-1
//-1
//-1
//-1
//2
//-1
//2
//-1
//2
//-1
//-1
//-1
//-1
//-1
//3
//-1
//3
//-1
//3
//-1
//3
//-1
//-1
//-1
//4
//-1
//4
//-1
//3