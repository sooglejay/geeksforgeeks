/****

Write a program to check whether a number is wierd or not. A weird number is weird if the sum of the proper divisors (divisors including 1 but not itself) of the number is greater than the number, but no subset of those divisors sums to the number itself.

Example:

The smallest weird number is 70. Its proper divisors are 1, 2, 5, 7, 10, 14, and 35; these sum to 74, but no subset of these sums to 70. The number 12, for example, is not weird, because the proper divisors of 12 are 1, 2, 3, 4, and 6, sum of divisors is 16; but there is a subset {2, 4, 6} with sum 12, i.e., 2+4+6 = 12.

Input:

First line contains number of test cases T. Then following T lines contains an integer N.


Output:

Output "Weird" if given number is strong else "Not Weird" .


Constraints:

1<=T<=100
2<=N<=10000


Example:

Input:
2
5
70

Output:
Not Weird
Weird

**For More Examples Use Expected Output****/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int bfs(int *A,int sum,int N,int i,int k){
    if(i>=k){
        return sum==N;
    }
    if(bfs(A, sum, N, i+1,k))return 1;
    if(bfs(A, sum+A[i+1],N,i+1, k))return 1;
    return 0;
}
void sovle(int N){
    int *A = (int *)malloc(sizeof(int)*N);
    memset(A, 0, sizeof(int)*N);
    int i=0,k=0;
    A[0]=1;
    k=1;
    for(i=2;i<N;i++){
        if(N%i==0){
            A[k++] = i;
        }
    }
    
    int sum = 0;
    for(i=0;i<k;i++){
        sum += A[i];
    }
    if (sum>N&&bfs(A, 0, N,0, k)<1){
        printf("Weird\n");
    }else {
        printf("Not Weird\n");
    }
    free(A);
    
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int N;
        scanf("%d",&N);
        if(N<70){
            printf("Not Weird\n");
            continue;
        }
        sovle(N);
    }
    return 0;
}