#include <stdio.h>
#include <math.h>
int func(int n){
    int j=n/2,sum=0;
    while(j>0){
        if(n%j==0){
            sum++;
        }
        j--;
    }
    return sum+1;

}
int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        printf("%d\n",func(N));
    }
    return 0;
}