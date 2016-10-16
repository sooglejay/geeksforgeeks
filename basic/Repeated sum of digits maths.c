/***
Repeated sum of digits
maths  number theory  
Given an integer N, recursively sum digits of N until we get a single digit.  The process can be described below

If N < 10    
    digSum(N) = N
Else         
    digSum(N) = Sum(digSum(N))
Example:

Input : 1234
Output : 1
Explanation : The sum of 1+2+3+4 = 10, 
              digSum(x) == 10
              Hence ans will be 1+0 = 1
Input:

The first line contains an integer T, total number of test cases. Then following T lines contains an integer N.

Output:

Repeated sum of digits of N.

Constraints:

1 ≤ T ≤ 100

1 ≤ N ≤ 1000000

Example:

Input
2
123
9999

Output
6
9

**For More Examples Use Expected Output**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int func(int n)
{
    if (n<10) {
        return n;
    }else {
        return func(func(n/10)+n%10);
    }
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