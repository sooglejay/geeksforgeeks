/**
Given an array, reverse every sub-array formed by consecutive k elements.
Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.The second line of each test case contains N space separated integers denoting array elements.The third line of each test case consists of an integer K.
Output:
Corresponding to each test case, in a new line, print the modified array.
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 500
Example:
Input
1
5
1 2 3 4 5
3
Output
3 2 1 5 4
For More Examples Use Expected Output
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N_MAX 500
void exchange(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void  reverseByK(int *result,int *a,int count,int k){
    int i,j;
    int time = 0;
    i = time*k;
    j = i+k -1;
    while (i<count) {
        if (j>=count) {
            j = count-1;
        }
        for (;j>=i;i++,j--) {
            exchange(a+i, a+j);
        }
        time++;
        i = time*k;
        j = i+k -1;
    }
    for (i=0;i<count; i++) {
        *(result+i) = *(a+i);
    }
    *(result+i) = 0;
}

int main() {
int T,i,j,N,k;
scanf("%d",&T);
int A[T][N_MAX];
for (j=0; j<T; j++) {
    scanf("%d",&N);
    int B[N];
    for(i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    scanf("%d",&k);
    reverseByK(A[j],B,N,k);
}

for(j=0;j<T ; j++) {
    int i=0;
    while (*(A[j]+i) >0) {
        printf("%d ",*(A[j]+i));
        i++;
    }
    printf("\n");
}

return 0;
}