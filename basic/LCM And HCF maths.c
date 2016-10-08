/**
LCM And HCF
maths  
For 2 given numbers find out their LCM and HCF.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, there are two numbers a and b.


Output:
Find LCM and HCF. 


Constraints:
1 <= T <= 30
1 <= a <= 1000
1 <= b <= 1000


Example:
Input:
2

5 10

14 8

Output:
10 5
56 2

**For More Examples Use Expected Output**
*/
#include <stdio.h>
void func(int a,int b){
    int i=0;
    int ta=a,tb=b;
    while(b>0){
        i=b;
        b=a%b;
        a=i;
    }
    printf("%d %d\n",ta*tb/i,i);
    
    
}
int main() {
    //code
    int T,i,N,M;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        scanf("%d",&M);
        
        func(N,M);
    }
    return 0;
}