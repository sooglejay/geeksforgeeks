#include<stdio.h>
#define MAX 100
int main(){
    int T,i,j,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        
        int carry=1;
        for(j=N-1;j>=0;j--){
            A[j] = A[j]+carry;
            carry= A[j]/10;
            A[j] = A[j]%10;
        }
        if (carry) {
            printf("%d ",carry);
        }
        for(j=0;j<N;j++){
            printf("%d ",A[j]);
        }
        printf("\n");

      

    }
    return 0;
    
}