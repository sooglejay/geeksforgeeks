/**
Longest Consecutive 1's
bit  
Given a number N, Your task is to find the  length of the longest consecutive 1's in its binary representation.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case in a new line print the length of the longest consecutive 1's in N's binary representation.

Constraints:
1<=T<100
1<=N<=1000

Example:
Input
2
14
222
Output
3 
4

**For More Examples Use Expected Output**
***/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set> 
using namespace std;

int main()
{
   
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        int sum = 0,temp =0;
        while (N>0) {
            if ((N&1)==1) {
                temp++;
            }else{
                sum = temp>=sum?temp:sum;
                temp = 0;
            }
            N = N>>1;
        }
        printf("%d\n",temp>=sum?temp:sum);
    }
}
