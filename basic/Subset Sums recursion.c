/***

Subset Sums
recursion  
Given an array of integers, print sums of all subsets in it. Output should be printed in increasing order of sums.

Input : arr[] = {2, 3}
Output: 0 2 3 5

Input : arr[] = {2, 4, 5}
Output : 0 2 4 5 6 7 9 11
Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case is N, N is the size of array. The second line of each test case contains N space separated values of the array arr[].

Output:

Output for each test case should be space separated sums in increasing order.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 10
0 ≤ A[i] ≤ 100

Input:
2
2
1 2
3
5 2 1

Output:

0 1 2 3 
0 1 2 3 5 6 7 8 
**For More Examples Use Expected Output**
*****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(int A[],int n){
    int i,j,key;
    for(j=1;j<n;j++){
        i=j-1;
        key = A[j];
        while(i>=0&&key<A[i]){
            A[i+1]=A[i];
            i--;
        }
        A[i+1] = key;
    }
}
void subsetSums(int arr[], int B[],int n)
{
    long long total = 1<<n,i=0;
    int k=0;
    for (; i<total; i++)
    {
        int sum = 0,j=0;
        for (; j<n; j++)
            if (i & (1<<j))
                sum += arr[j];
        B[k++]=sum;
    }
}


int main() {
    //code
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        int *B = (int*)malloc(sizeof(int)*(1<<N));
        memset(B, 0, sizeof(int *));
        for (j=0;j<101;j++) {
            B[j]=-1;
            if (j<N) {
                scanf("%d",&A[j]);
            }
        }
        sort(A,N);
        subsetSums(A,B,N);
//        sort(B,1<<N);
        for (j=0;j<1<<N;j++) {
            if (B[j]==-1) {
                continue;
            }
            printf("%d ",B[j]);
        }
        printf("\n");
    }
    return 0;
}