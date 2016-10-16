/*
Minimum sum
array  
Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements.

Output:

Corresponding to each test case, in a new line, print the minimum possible sum of two numbers formed from digits of the array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 30
1 ≤ A[i] ≤ 9

Example:

Input
1
5
5 3 0 7 4

Output
82

**For More Examples Use Expected Output**

*/
#include <stdio.h>
void sort(int A[],int n){
    int i,j,key;
    for(j=1;j<n;j++){
        i=j-1;
        key = A[j];
        while(i>=0&&key<A[i]){
            A[i+1]=A[i];
            i--;
        }
        A[i+1] = key;
    }
    
}
int main() {
    //code
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        sort(A,N);
        j=0;
        long long a=0,b=0;
        while (j<N) {
            if (j%2==0) {
                a= 10*a;
                a += A[j];
            }else{
                b=10*b;
                b+=A[j];
            }
            j++;
        }
        printf("%lld\n",a+b);
    }
    return 0;
}