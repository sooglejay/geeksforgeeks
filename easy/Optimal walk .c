//#include<stdio.h>
//int  solve(int table[],int A,int B,int N){
//    if (table[N]>0) {
//        return table[N];
//    }
//    if (N==0) {
//        return 0;
//    }
//    if (N%2==0) {
//        int a = solve(table, A, B, N/2) + B;
//        int b = solve(table, A, B, N-1) + A;
//        table[N]=a>b?b:a;
//    }else{
//        int a = solve(table, A, B, N/2) + B + A;
//        int b = solve(table, A, B, (N+1)/2) + B + A;
//        int c = solve(table, A, B, N-1) + A;
//        int d = a>b?b:a;
//        table[N]=d>c?c:d;
//    }
//    return table[N];
//}
//int main()
//{
//    int T;
//    scanf("%d",&T);
//    int n;
//    int N,A,B,j;
//    for(n=0;n<T;n++){
//        scanf("%d",&N);
//        scanf("%d",&A);
//        scanf("%d",&B);
//        int table[N+1];
//        for(j=0;j<N+1;j++){
//            table[N]=0;
//        }
//        printf("%d\n",solve(table,A, B, N));
//    }
//    return 0;
//}

#include<stdio.h>

int  solve(int table [],int A,int B,int N){
    if (table[N]>0) {
        return table[N];
    }
    
    if (N==1) {
        return A;
    }
    if (N==0) {
        return 0;
    }
    if(N%2==1){
        int a =solve(table,A, B, N-1)+A;
        int b =solve(table,A, B, (N+1)/2)+B+A;
        int c =solve(table,A, B, N/2)+B+A;
        int d = a>b?b:a;
        table[N]=d>c?c:d;
    }else{
        int a =solve(table,A,B,N/2)+B;
        int b =solve(table,A,B,N-1)+A;
        table[N]= a>b?b:a;

    }
    return table[N];
}
int main()
{
    int T;
    scanf("%d",&T);
    int n;
    int N,A,B,j;
    int table[100000+1];
    
    for(n=0;n<T;n++){
        scanf("%d",&N);
        scanf("%d",&A);
        scanf("%d",&B);
        for(j=0;j<=100000;j++){
            table[j]=0;
        }
        printf("%d\n",solve(table,A, B, N));
    }
    return 0;
}

