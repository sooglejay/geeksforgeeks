/****
Distinct occurrences
dp  
Given two strings S and T, find count of distinct occurrences of T in S as a sub-sequence. Your task is to complete the function subsequenceCount which takes two strings as argument S and T and returns the count of the sub-sequences.

Input:
The first line of input contains an integer t denoting the no of test cases . Then t test cases follow. The first line of each test case contains 2 strings S and T.

Output:
For each test case in a new line print the count of distinct occurrences of T in S as a sub-sequence.

Constraints:
1<=t<=100
1<=length of (S,T)<=100

Example(To be used only for expected output):
Input
2
banana ban
geeksforgeeks ge

Output
3
6

Explanation:
(i) For first test case  S = banana, T = ban there are 3 sub-sequences which are [ban], [ba n], [b an].
(ii) For second test case S = geeksforgeeks, T=ge there are 6 sub-sequences which are  [ge], [ ge], [g e], [g e] [g e] and [ g e].



Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

**For More Examples Use Expected Output**
**/

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
#include <string.h>
using namespace std;

/**
 Example(To be used only for expected output):
 Input
 2
 banana ban
 geeksforgeeks ge
 
 Output
 3
 6
 */
/*You are required to complete this method*/
int subsequenceCount(string S, string T)
{
    
    int s=0,t=0;
    while (S[s++]!='\0');
    while (T[t++]!='\0');
    t--;
    s--;
    int **dp,m,n;
    dp = (int **)malloc(sizeof(int *)*t);
    for(m=0;m<t;m++){
        dp[m] = (int *)malloc(sizeof(int)*s);
        for(n=0;n<s;n++){
            if (S[n]==T[m]) {
                dp[m][n] = 1;
            }else{
                dp[m][n] = 0;
            }
        }
    }
    
//        for(m=0;m<t;m++){
//            for(n=0;n<s;n++){
//                printf(" %d ",dp[m][n]);
//            }
//            printf("\n");
//        }
//
    
    // m 是行号， n 是列号，总共有t行，s列的矩阵，下面的代码片段可以累加求和一个锯齿形的东西，具体可以打开屏蔽的代码查看效果
    int p=0,temp,k=0;
    for(m=t-1;m>=1;m--){
        for(n=s-1-(t-m-1);n>=m;n--){
            temp=0;
            for(k=n;k<s-p;k++){
                temp += dp[m][k];
            }
            if(dp[m-1][n-1]==1){
            	dp[m-1][n-1] = temp;
            }
        }
        p++;
    }
    
//        for(m=0;m<t;m++){
//            for(n=0;n<s;n++){
//                printf(" %d ",dp[m][n]);
//            }
//            printf("\n");
//        }
//    
//   
    temp = 0;
    for(n=0;n<=s-t;n++){
        temp += dp[0][n];
    }
    free(dp);
    return temp;
    
}


int sum(int bit[],int i){
    int s = 0;
    while(i>0){
        s += bit[i];
        i -= i& -i;
    }
    return s;
}
void add(int bit[],int i,int x,int n){
    while (i<=n) {
        bit[i] += x;
        i += i&-i;
    }
}
int main()
{
    
    int testCase,i;
    scanf("%d",&testCase);
    char *S = (char*)malloc(sizeof(char)*101);
    char *T = (char*)malloc(sizeof(char)*101);
    for(i=0;i<testCase;i++){
        scanf("%s",S);
        scanf("%s",T);
        printf("%d\n",subsequenceCount(S,T));
        
        
        
        
    }
}
