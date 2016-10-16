/***
The OR Gate
bit  
Construct an N input OR Gate. An OR Gate returns 0 if all its inputs are 0, otherwise 1.

Input:

The first line of input takes the number of test cases, T. Then T test cases follow.

Each test case consists of 2 lines.

The first line of each test case takes the number of inputs to the OR Gate, N. The second line of each test case takes N space separated integers denoting the inputs to the OR Gate. Note that the inputs can be either 1's or 0's.

Output:

Print the output of the N input OR Gate for each test case on a new line.

Constraints:

1<=T<=100

1<=N<=100

Example:

Input:

3
2
1 1
3
0 0 0
4
1 1 1 0

Output:

1
0
1
**For More Examples Use Expected Output**
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    //code
    int T,kk,N,j,t;
    scanf("%d",&T);
    for(kk=0;kk<T;kk++){
        scanf("%d",&N);
        int sum=0;
        for(j=0;j<N;j++){
            scanf("%d",&t);
            if(t>0){
                sum = 1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}