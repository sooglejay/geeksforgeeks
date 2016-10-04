/**
Print Pattern
pattern  recursion      Microsoft
Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N.

Input:
First line contains number of test cases T. Then following T lines contains an integer N.

Output:
Single line with pattern . 

Constraints:
0< N < 10000

Example:
Input:
2
16
10

Output: 
16 11 6 1 -4 1 6 11 16
10 5 0 5 10

Explanation:
We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one by one add 5 until we reach N.

**For More Examples Use Expected Output**
*/

#include<stdio.h>
void func2(int a,int b);
void func(int a,int b);
void func(int n,int a){
    printf("%d ",n);
    if (n>0) {
        func(n-5,a);
    }else{
        func2(n+5,a);
        return;
    }
}
void func2(int n,int a){
    printf("%d ",n);

    if (n>0) {
        if (n==a) {
            return;
        }
        
    }
    func2(n+5,a);
    
}
int main(){
    int T,i;
    scanf("%d",&T);
    int a;
    for(i=0;i<T;i++){
        scanf("%d",&a);
        func(a,a);
        printf("\n");
    }
    return 0;
}