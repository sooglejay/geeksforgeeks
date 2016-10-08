#include <stdio.h>
#include <stdlib.h>
int func(int A[],int N){
    int **table = (int **)malloc(sizeof(int*)*N);
    int i,j;
    for(i=0;i<N;i++){
        table[i] = (int *)malloc(sizeof(int)*N);
        for(j=0;j<N;j++){
            table[i][j]=0;
        }
    }
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if(A[j]==1)
            {
            	table[j][j] = 1;
            }else{
                table[j][j] = 0;
            }
            if(j>0)
            {
                table[i][j] = table[i][j-1]+1;
            }
        }
    }
    
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            printf(" %d ",table[i][j]);
        }
        printf("\n");
    }
    return  0;
    
}
int main(){
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
            func(A, N);
        }
        
    }
}