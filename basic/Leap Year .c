#include <stdio.h>
#include <math.h>
void func(int n){
    int flag =0;
    flag = n%400==0;
    flag = !flag?n%4==0&&n%100!=0:1;
    printf("%s\n",flag?"Yes":"No");
}
int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        func(N);
    }
    return 0;
}