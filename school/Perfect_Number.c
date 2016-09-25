/**
23 is not because 2!+ 3!  = 8 != 23
145 is perfect
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N_MAX 500
int  factorial(int a){
    if (a==0) {
        return 1;
    }else return a * factorial(a-1);
}
int main() {
    int T,j,N;
    scanf("%d",&T);
    int A[T];
    for (j=0; j<T; j++) {
        scanf("%d",&N);
        int sum=0,temp = N;
        while (temp) {
            sum += factorial(temp%10);
            temp = temp/10;
        }
        A[j] = sum==N;
        
    }
    
    for(j=0;j<T; j++) {
        if (!A[j]) {
            printf("Not Perfect\n");
        }
        else printf("Perfect\n");
    }
    return 0;
}