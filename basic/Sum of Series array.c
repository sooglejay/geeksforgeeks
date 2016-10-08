/***
Sum of Series
array  maths  
Write a program to find the sum of the given series 1+2+3+ . . . . . .(N terms) 

Input:
First line contains an integer, the number of test cases 'T' Each test case should contain a positive integer N.


Output:
Print the sum in a seperate line.


Constraints:
1<=T<=30
1<=N<=100


Example:
Input:
1
1

Output:
1

**For More Examples Use Expected Output**
**/

#include <stdio.h>
int main() {
    //code
    int T,i,n;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        printf("%d\n",n*(n+1)/2);
    }
    return 0;
}