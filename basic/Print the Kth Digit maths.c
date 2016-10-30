/****
 Given two numbers a and b, find kth digit from right of a^b.
 
 Input:
 
 The first line of the input contains T denoting the number of testcases.Each of the next T lines contains three space separated positive integers denoting the value of a , b and k respectively.
 
 
 Output:
 
 For each testcase, output the kth digit from right of a^b in new line.
 
 
 Constraints:
 
 1<=T<=100
 1<=a , b <=15
 1<=k<=|totaldigits in a^b|
 
 
 Example:
 
 Input:
 2
 3 3 1
 5 2 2
 
 Output:
 7
 2
 
 **For More Examples Use Expected Output**
 ***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bfs(int *A,int sum,int N,int i,int k){
    if(i>=k){
        return sum==N;
    }
    if(bfs(A, sum, N, i+1,k))return 1;
    if(bfs(A, sum+A[i+1],N,i+1, k))return 1;
    return 0;
}
void sovle(int N){
    int *A = (int *)malloc(sizeof(int)*N);
    memset(A, 0, sizeof(int)*N);
    int i=0,k=0;
    A[0]=1;
    k=1;
    for(i=2;i<N;i++){
        if(N%i==0){
            A[k++] = i;
        }
    }
    
    int sum = 0;
    for(i=0;i<k;i++){
        sum += A[i];
    }
    if (sum>N&&bfs(A, 0, N,0, k)<1){
        printf("Weird\n");
    }else {
        printf("Not Weird\n");
    }
    
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        int i=0;
        long sum=1;
        
        for(i=0;i<b;i++){
            sum *= a;
        }
        int res = 0;
        while (k-->0) {
            res = sum%10;
            sum/=10;
        }
        printf("%d\n",res);
       
    }
    return 0;
}