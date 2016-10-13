/***
Given a positive integer N, find the Nth fibonacci number. Since the answer can be very large, print the answer modulo 1000000007.

Input:

The first line of input contains T denoting the number of testcases.Then each of the T lines contains a single positive integer N.

Output:

Output the Nth fibonacci number.

Constraints:

1<=T<=100
1<=N<=1000

Example:

Input:
3
1
2
5

Output:
0
1
3

**For More Examples Use Expected Output**
**/

#include <stdio.h>
int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    int table[1001];
    table[0]=0;
    table[1]=0;
    table[2]=1;
    for(i=3;i<1001;i++){
        table[i] = table[i-1]+table[i-2];
        table[i] = table[i]%1000000007;
    }
    for(i=0;i<T;i++){
        scanf("%d",&N);
        printf("%d\n",table[N]);
    }
    return 0;
}