#include<stdio.h>
int countBit(int n){
    int bits=0;
    while (n) {
        bits += n&1;
        n=n>>1;
    }
    return bits;
    
}
void sort(int A[],int B[],int N){
    int i,j,key,kA;
    for(j=0;j<N;j++){
        B[j]=countBit(A[j]);
    }
    for(j=1;j<N;j++){
        i=j-1;
        key=B[j];
        kA = A[j];
        
        while (B[i]<key&&i>=0) {
            A[i+1] = A[i];
            B[i+1]=B[i];
            i--;
        }
        B[i+1] = key;
        A[i+1] = kA;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int n= 0,N,j;
    for(n=0;n<T;n++){
        scanf("%d",&N);
        int A[N],B[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
            B[j] = A[j];
        }
        sort(A, B, N);
        for(j=0;j<N;j++){
            printf("%d ",A[j]);
        }
        printf("\n");
    }
    return 0;
}