/**
Set Bits
bit      Adobe    Brocade    Cisco    Juniper Networks
Given a positive integer N, print count of set bits in it. For example, if the given number is 6, output should be 2 as there are two set bits in it.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The next T lines will contain an integer N.

Output:
Corresponding to each test case, in a new line, print count of set bits in it.

Constraints:

1 ≤ T ≤ 100

1 ≤ N ≤ 1000000


Example:

Input:

2
6
11
 

Output:
2
3

**For More Examples Use Expected Output**
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void func(){
    
}
int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int sum = 0;
        while (N>0) {
            sum += 1&N;
            N=N>>1;
        }
        printf("%d\n",sum);
    }
    return 0;
}