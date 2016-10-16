/**
Automorphic Number
maths  
Write a program to check whether a given number is Automorphic number or not.
A number is called Automorphic number if and only if its square ends in the same digits as the number itself.

For example, 762 = 5776 which ends with 76 therefore it is a automorphic number.

Input:

The first line of the input contains T denoting the total number of testcases. Each of the next T lines contains a positive integer N denoting the value of a number.


Output:

Output "Automorphic" if given number is Automorphic else "Not Automorphic" .


Constraints:

1<=T<=100
1<=N<=1000


Example:

Input:
2
1
16

Output:
Automorphic
Not Automorphic

**For More Examples Use Expected Output**


**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    //code
    int T,kk,N,j;
    
    scanf("%d",&T);
    for(kk=0;kk<T;kk++){
        scanf("%d",&N);
        int sum = N*N;
        int flag=1;
        while (sum>0&&N>0) {
            int a = sum%10;
            int b = N%10;
            if (a!=b) {
                flag=0;
                break;
            }
            sum/=10;
            N/=10;
            
        }
        printf("%s\n",flag==1?"Automorphic":"Not Automorphic");
        
    }
    return 0;
}