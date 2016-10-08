#include <stdio.h>
#define MAX 18+1
long long  func(long long table[],int n){
    if(table[n]>0){
        return table[n];
    }
    if(n==0||n==1){
        table[n]=1;
    }else{
        table[n]=n*func(table,n-1);
    }
    return table[n];
}
int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    long long table[MAX];
    for(i=0;i<MAX;i++){
        table[i]=0;
    }
    i=0;
    for(i=0;i<T;i++){
        scanf("%d",&N);
        printf("%lld\n",func(table,N));
    }
    return 0;
}