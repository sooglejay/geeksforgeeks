/**
Poisioned Sweet
maths  
An enemy spy has poisoned one out of N sweets in a bakery. Even a bite of the poisoned sweet has potency to kill. However, the effects of the poison show only in 30 days. The managers asks the jailor to identify the poisoned sweet within 30 days. What is the least number of prisoners the jailor must employ to identify the poisoned sweet?
 

Note: A sweet can be eaten by any number of prisoners.
 

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case consists of a single integer N (Denoting number of total sweets)

Constraints:
1≤T≤100
1≤N≤10^4

Output
Corresponding to each test case, print in a new line the number of the prisoners.
Input
1
3

Output
2

**For More Examples Use Expected Output**


Contributor: Siddharth Dungarwal

*/


#include <stdio.h>
int func(int n){
    if (n==1) {
        return 0;
    }
    int i=2,j=1;
    while(i<n){
        i = 2*i;
        j++;
    }
    return j;
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