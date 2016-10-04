/**
Given a array A with N elements and array B with M elements. You have to insert (N-M) zeroes in between array B such that the dot product of array A and array B is maximum. 

Definition of Dot Product : A.B = A[0]*B[0] + A[1]*B[1]+....A[N]*B[N].

Input :
The first line will contain T which denotes the number of test cases. The first line of each test case will contain integer N and M, denoting the length of array A and array B respectively. The second line of each test case will contain N integers denoting the elements of array A. The third line of each test case will contain M integers denoting the elements of array B.
 

Output:
For each test case, Output the maximized dot product in a new line .
 

Constraints :
1<=T<=10
1<= N,M<=1000
0<=A[i],B[i]<=10^7
 

Example
Input : 

1

3 1 

1 2 3

4

Output :
12 

**For More Examples Use Expected Output**

*/

#include<stdio.h>
#include<stdlib.h>

void solve(size_t **table,int N,int M){
    int i=0,j=0,k=0;
    size_t temp=0;
    int p=0;
    for(j=M-1;j>=1;j--){
        for(i=N-1-(M-j-1);i>=j;i--){
            temp=table[j][i];
            for(k=i;k<N-p;k++){
                if (temp<table[j][k]) {
                    temp=table[j][k];
                }
            }
            table[j-1][i-1] = table[j-1][i-1]+temp;
        }
        p++;
    }
    temp=table[0][0];
    for(i=1;i<=N;i++){
        if (temp<table[0][i]) {
            temp = table[0][i];
        }
    }
    printf("%ld\n",temp);
    for(j=0;j<M;j++){
        free(table[j]);
    }
    free(table);
}
void func(size_t aN[],size_t aM[],int N,int M){
    size_t **table=(size_t**) malloc( sizeof( size_t* ) * M);
    int i=0;
    int j=0;
    for(j=0;j<M;j++){
        table[j]=(size_t*)malloc(sizeof(size_t)*N);
        for(i=0;i<N;i++){
            table[j][i] = aM[j]*aN[i];
        }
    }
    solve(table,N,M);
}

int main(){
    int T,i,j;
    scanf("%d",&T);
    int N,M;
    for(i=0;i<T;i++){
        scanf("%d",&N);
        scanf("%d",&M);
        size_t aN[N],aM[M];
        for(j=0;j<N;j++){
            scanf("%ld",&aN[j]);
        }
        for(j=0;j<M;j++){
            scanf("%ld",&aM[j]);
        }
        if (M>N) {
            printf("0\n");
        } else {
            func(aN,aM,N,M);
        }
    }
    return 0;
}