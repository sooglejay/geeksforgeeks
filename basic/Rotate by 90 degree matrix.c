/***
Rotate by 90 degree
matrix      Microsoft
Given an square matrix, turn it by 90 degrees in anti-clockwise direction without using any extra space.

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of the square matrix.The second line of each test case contains NxN space separated values of the matrix M.

Output:

Corresponding to each test case, in a new line, print the rotated array.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 50

Example:

Input
1
3
1 2 3 4 5 6 7 8 9

Output
3 6 9 2 5 8 1 4 7

**For More Examples Use Expected Output**
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void sort(int A[],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        i = j-1;
        k=A[j];
        while(i>=0&&k<A[i]){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = k;
    }
}
int main() {
    //code
    int T,kk;
    int N,j,k;
    scanf("%d",&T);
    for(kk=0;kk<T;kk++){
        scanf("%d",&N);
        int A[N][N];
        for(j=0;j<N;j++){
            for(k=0;k<N;k++)
            {
                scanf("%d",&A[j][k]);
            }
        }
        for(j=N-1;j>=0;j--){
            for(k=0;k<N;k++)
            {
                printf("%d ",A[k][j]);
            }
        }
        printf("\n");
    }
    return 0;
}