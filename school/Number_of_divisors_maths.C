/**
Two friends are playing a game. One gives an integer N  to other and asks: What is the number of divisors of N that are divisible by 3? The task is to help the other friend in finding the number of divisors.

Input:
The first line of input contains an integer T denoting the number of test cases.Then T test cases follow .Each test case consist of an integer N.

Output:
For each test case in a new line print the  number of divisors.

Constraints:

1 ≤ T ≤ 50

1 ≤ N ≤ 100000


Example:

Input:

2

6

10

Output:

2

0

Explanation:

6 has three divisors 1, 3 and 6 out of which two are divisible by 3.
10 has four divisors 1,2,5 and 10 none of which is divisible by 3

**For More Examples Use Expected Output**


*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N_MAX 500
int  factorial(int a){
    if (a==0) {
        return 1;
    }else return a * factorial(a-1);
}
int main() {
    int T,j,i,N;
    scanf("%d",&T);
    int A[T];
    for (j=0; j<T; j++) {
        A[j]=0;
        scanf("%d",&N);
        int array [N+1];
        for (i=0; i<=N; i++) {
            array[i] = 0;
        }
        for (i=1;i<=N; i++) {
            if (N%i==0) {
                array[i]=1;
            }
        }
        for (i=1;i<=N; i++) {
            if (array[i]==1&&i%3==0) {
                A[j]+=1;
            }
        }
    }
    
    for(j=0;j<T ; j++) {
    	printf("%d\n",A[j]);
    }
    return 0;
}