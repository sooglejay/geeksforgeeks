/***
Sharad  is fond of Mathematics and thought of playing with it. He assumes an even digit number, then partition the number into multiple numbers of two digits. For ex: if he chooses 1345 then he parts the number into 13 and 45. Now, he wants to calculate the product of these two digit numbers. The product for the above example is 585. He challenges you to do this work through a program. 

Input:.
First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing an even digit number N.

Output:
Corresponding to each test case, in a new line, print the desired output modulo 10^9 + 7

Constraints: 
1 ≤ T ≤ 100
1 ≤ N ≤ 10^20


Example:

Input:
3
2222
11
1010

Output:
484
11
100

Example: In first case 2222 it can be divided into 22 and 22..so the result is 484

                  In Second case 11 it can divide into only 11 so our result is 11

                  In third case 1010 it can be divided into 10 and 10 .. so outcome is 100

**For More Examples Use Expected Output**


Contributor: karan kumar
*/


#include <stdio.h>
long long func(char *A){
    int i=0;
    while (A[i]!='\0') {
        i++;
    }
    
    int k=i/2;
    if (i==2) {
        k=i;
    }
    int j;
    long long  a=0;
    for(j=0;j<k;j++){
        a = a*10;
        a += (A[j]-'0');
    }
    if(k==i){
        return a;
    }
//    a = a%1000000007;
    long long b=0;
    for(j=i/2;j<i;j++){
        b = b*10;
        b += (A[j]-'0');
    }
//    b = b%1000000007;
    return a*b;
    
}
int main() {
    //code
    int T,i;
    char numbers[21];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%s",numbers);
        printf("%lld\n",func(numbers));
    }
    return 0;
}