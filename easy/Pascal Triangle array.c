#include<stdio.h>
#define MAX 25
int getNum(int r[MAX][MAX],int i,int j){
    if (r[i][j]) {
        return r[i][j];
    }
    if(!j){
        return 1;
    }
    else if (!i) {
        return !j?1:0;
    }else return getNum(r,i-1,j)+getNum(r,i-1, j-1);
}
int main(){
    int T,i,j,N,k,temp;
    int r[MAX][MAX];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        
        for(k=0;k<MAX;k++){
            for(j=0;j<MAX;j++)
            {
                r[k][j]=0;
            }
        }
        j=0;
        temp = 0;
        
        for (j=0;j<=N/2; j++) {
            A[j] = temp = getNum(r,N-1, j);
            if (A[j]) {
                printf("%d ",temp);
            }
        }
        int step =N%2==1?1:2;
        for (j=N/2-step; j>=0; j--) {
            printf("%d ",A[j]);
        }
        
        printf("\n");
    }
    return 0;
    
}