#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void t2(){
    int n;
    scanf("%d",&n);
    while(n--){
        int len,i;
        scanf("%d",&len);
        int *A,max=0,tem=0,d=0;
        A = (int *)malloc(sizeof(int)*len);
        memset(A,0, sizeof(A));
        scanf("%d",&A[0]);
        tem = A[0];
        for(i=1;i<len;i++){
            scanf("%d",&d);
            A[i] = d;
            if(d>A[i-1]){
                tem += d;
            }else {

                max = max>tem?max:tem;
                tem = d;
            }
        }
        printf("%d\n",max>tem?max:tem);

    }
}
int main() {
//    void uva_1583();
//    uva_1583();
    t2();
    return 0;
}
