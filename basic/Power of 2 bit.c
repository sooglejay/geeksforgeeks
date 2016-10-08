/***
Power of 2
bit  maths  
Given a positive integer N, check if N is a power of 2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each testcase contains a single positive integer N.


Output:
Print "YES" if it is a power of 2 else "NO". (Without the double quotes)


Constraints:
1<=T<=100
0<=N<=10^18

Example:
Input :
2
1
98

Output :
YES
​NO

Explaination:  (2^0 == 1)

**For More Examples Use Expected Output**
**/

#include <stdio.h>
int main() {
    //code
    int T,i;
    long long result,n;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        result=1;
        scanf("%lld",&n);
        if(n==result){
            printf("YES\n");
        }else{
            while(result<n){
                result *=2;
            }
            if (result==n) {
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        
    }
    return 0;
}