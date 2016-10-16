/***
Maximum Area
maths  
Given the maximum possible area of the right angle triangle for a fixed length of hypotenuse. The task is to find the length of hypotenuse.

Input:

The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case consists of a single integer N (Denoting the area of the right angle triangle)
Output:

Corresponding to each test case, print in a new line the length of hypotenuse if output is in decimal return floor value.
Constraints:

1≤T≤100
1≤N≤1010

Sample Input
1
25

Sample Output
10

**For More Examples Use Expected Output*****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    //code
    int T,kk;
    size_t N,sum;
    scanf("%d",&T);
    for(kk=0;kk<T;kk++){
        scanf("%ld",&N);
        N = 4*N;
        sum = sqrt(N);
        printf("%ld\n",sum);
    }
    return 0;
}