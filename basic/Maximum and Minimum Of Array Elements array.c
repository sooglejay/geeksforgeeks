#include <stdio.h>

int main(){
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int max=0,min =100;
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
            max = max>A[j]?max:A[j];
            min = min<A[j]?min:A[j];
        }
        printf("%d %d\n",max,min);
        
    }
}
