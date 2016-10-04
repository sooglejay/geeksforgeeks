/**
You are given an array A containing 2*N+2 positive numbers, out of which N numbers are repeated exactly twice and the other two numbers occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.
 

Input :
The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

Output :
Print in a new line the two numbers in ascending order.

Constraints :
1<=T<=100
1<=N<=10^6
1<=A[i]<=5*10^8

Example:
Input :
2
2
1 2 3 2 1 4
1
2 1 3 2

Output :
3 4
1 3

**For More Examples Use Expected Output**

*/

#include<stdio.h>
void insertSort(int A[],int N){
    int i,j,key;
    for(j=1;j<N;j++){
        i=j-1;
        key=A[j];
        while (i>=0&&A[i]>key) {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

void  func(int A[],int N){
    insertSort(A,N);
    int i=0;
    int a=0,b=0;
    for(i=0;i<N;){
        if(i==N-1){
            if(a==0){
                a=A[i];
            }else if(b==0){
                b=A[i];
            }
            printf("%d %d\n",a,b);
            break;
        }
        if(A[i]==A[i+1]){
            i=i+2;
        }else{
            if(i+2<N&&A[i+1]==A[i+2]){
                if(a==0){
                    a=A[i];
                }else if(b==0){
                    b=A[i];
                }
            }else if(i==N-2){
                a=A[N-2];
                b=A[N-1];
                printf("%d %d\n",a,b);
                break;
            }
            i=i+3;
        }
        if (a>0&&b>0) {
            printf("%d %d\n",a,b);
            break;
        }
    }
}
int main(){
    int T,i;
    scanf("%d",&T);
    size_t j;
    int N;
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[2*N+2];
        for(j=0;j<2*N+2;j++){
            scanf("%d",&A[j]);
        }
        func(A,2*N+2);
    }
}