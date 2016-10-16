/***
Prime Factors
maths  prime  sieve  
Given a number N, print all its unique prime factors in increasing order.

Input : N = 100
Output: 2 5

Input : N = 35
Output: 5 7
Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:
Print all prime factors in increasing order.

Constraints:
1 ≤ T ≤ 200
2 ≤ N ≤ 10000

Example:
Input:
2
100
35

Output:
2 5
5 7

**For More Examples Use Expected Output**

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isPrime(int n){
    if (n==2) {
        return 1;
    }
    int i = sqrt(n),j=0,r=0;
    for(j=2;j<=i;j++){
        if (n%j==0) {
            r=1;
        }
    }
    return !r;
}
void func(int n)
{
    int j=0,k=0;
    int *B = (int *)malloc(sizeof(int)*(n+1));
    for(j=2;j<=n;j++){
        if (n%j==0) {
            B[k++]=j;
        }
    }
    for(j=0;j<k;j++){
        if (isPrime(B[j])) {
            printf("%d ",B[j]);
        }
    }
    free(B);
    printf("\n");
    
}


int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        func(N);
    }
    return 0;
}