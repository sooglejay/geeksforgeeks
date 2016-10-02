#include <stdio.h>
#define MAX 15+1
int func(int table[MAX][MAX],int i,int j,int M,int N){
    if (table[i][j]>0) {
        return table[i][j];
    }
    if (i==M&&j==N) {
        table[i][j]= 0;
    }else if(i==M){
       table[i][j]= 1;
    }else if(j==N){
       table[i][j]= 1;
    }else {
        table[i][j]=func( table,i+1,j, M, N)+func(table,i,j+1, M, N);
    }
    return table[i][j];
}
int main(){
    int T;
    scanf("%d",&T);
    int i=0,M,N;
    int m,n;
    int table[MAX][MAX];

    for(i=0;i<T;i++){
        scanf("%d",&M);
        scanf("%d",&N);
        for(m=0;m<MAX;m++){
            for(n=0;n<MAX;n++){
                table[m][n]=0;
            }
        }
        int a =func(table,1,1, M, N);
        printf("%d\n",a);
    }
}