/**
You will be given two positive numbers M and N. Your task is to print the greatest common divisor of Fib(M) and Fib(N) where Fib(x) means the xth Fibonacci numbers defined as:

Fib(0) = 0

Fib(1) = 1

for n > 1, Fib(n) = Fib(n-1) + Fib(n-2)

Input: 
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of exactly one line. This line consists of two space separated positive integers N and M.


Output:

Corresponding to each test case, in a new line, print the value of gcd( Fib(M), Fib(N) ) modulo 100.


Constraints:

1 ≤ T ≤ 1000

1 ≤ M, N ≤ 1000


Example:

Input

2
3 6
7 8

Output

2
1
 

Explanation:

Fib(3) = 2 and Fib(6) = 8

GCD(2,8)%100 = 2

Fib(7) = 13 and Fib(8) = 21

GCD(13,21)%100 = 1

**For More Examples Use Expected Output**
*/

#include <stdio.h>
long long getGCD(long long a,long long b){
    long long i=1;
    while(b>0){
        i= b;
        b = a%i;
        a = i;
    }
    return a;
}
int main() {
    //code
    int T,i,M,N;
    scanf("%d",&T);
    long long table[1001];
    table[0]=0;
    table[1]=1;
    for(i=2;i<1001;i++){
        table[i]=table[i-1]+table[i-2];
        table[i] %= 100;
    }
    for(i=0;i<T;i++){
        scanf("%d",&N);
        scanf("%d",&M);
        printf("%lld\n",table[getGCD(M, N)]);
    }
    return 0;
}