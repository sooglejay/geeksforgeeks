/**
Missing ranges of numbers
array  
Given an array A[ ] of N positive integers, print out the missing elements in the range [0 - 999].If
there are more than one missing, collate them using hyphen ( - ), otherwise just print the number.

Example:
 Input:   {88 3, 2, 400, 0, 10}
 Output:   [ 1 4-9 11-87 89-399 401-999 ]

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. 
The first line of each test case contains a positive integer N, denoting the length of the array A[ ].
The second line of each test case contains a N space separated positive integers, denoting the
elements of the array A[ ].   

Output
Print out the range of missing number or the number itself  separated by space enclosed in square
brackets : [ n1 n2 n3-n6 n8-n9 ]

Constraints
1 <= T <= 100
0 <   N <= 30
0 <= A[ ] < 1000

Examples 

Input
3
5
62 8 34 5 332 
4
13 0 32 500
5
2 0 9 15 999

Output
[ 0-4 6-7 9-33 35-61 63-331 333-999 ]
[ 1-12 14-31 33-499 501-999 ]
[ 1 3-8 10-14 16-998 ]

**For More Examples Use Expected Output**



***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void func(int A[],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        i = j-1;
        k = A[j];
        while(i>=0&&k<A[i]){
            A[i+1]=A[i];
            i--;
        }
        A[i+1] = k;
    }
}
int main() {
    //code
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        func(A,N);
        
        printf("[ ");
        
        for(j=0;j<N;j++){
            if (j==0) {
                if (N>0&&A[0]==1) {
                    printf("0 ");
                    continue;
                }
            }
            if (A[j]==j) {
                continue;
            }else if(j>0&&(A[j-1]+1)==A[j]){
                continue;
            }
            else if ((j-1)>=0&&A[j-1]+1==A[j]-1) {
                printf("%d ",A[j-1]+1);
            }
            else if((j-1>=0)&&A[j-1]==A[j]){
                continue;
            }
            else{
                printf("%d-%d ",(j-1)<0?0:(A[j-1]+1),A[j]-1);
            }
        }
        
        if (A[N-1]<999) {
            if (A[N-1]==998) {
                printf("999 ");
            }else{
                printf("%d-999 ",A[N-1]+1);
            }
        }
        printf("]\n");
        
        
    }
    return 0;
}