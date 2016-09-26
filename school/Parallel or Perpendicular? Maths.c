/**
Given two force vectors, find out whether they are parallel, perpendicular or neither. Let the first vector be A = a1 i +a2 j + a3 k and the second vector be B = b1 i + b2 j + b3 k.

A.B = a1*b1 + a2*b2 + a3*b3

A x B = (a2*b3 - a3*b2) i - (a1*b3 - b1*a3) j + (a1*b2 - a2*b1) k

|A|^2 = a1^2 + a2^2 + a3^2

If A.B = 0, then A and B are perpendicular.

If |A X B|^2 = 0, then A and B are parallel.

Input:

The first line of input takes the number of test cases, T. Then T test cases follow. Each test case has 2 input lines.The first line of each test case takes 3 space separated integers representing the components of the first force vector in x, y and z directions. The second line of each test case takes 3 space separated integers representing the components of the second force vector in x, y and z directions.

Output:

Print 1 if the 2 vectors are parallel, 2 in case they are perpendicular, 0 otherwise.

Constraints:

1<=T<=100

-100<=Component<=100

Example:

Input:
3
3 2 1
6 4 2
4 6 1
1 -1 2
10 9 5
2 6 1

Output:
1
2
0

**For More Examples Use Expected Output**
 **/

#include<stdio.h>
int power(int a){
    return a*a;
}
int judge(int A[],int B[])
{
    if(A[0]*B[0]+A[1]*B[1]+A[2]*B[2] == 0){
        return 2;
    }
    if( power(A[1]*B[2]-A[2]*B[1])
       -power(A[0]*B[2]-A[2]*B[0])
       +power(A[0]*B[1]-A[1]*B[0]) ==0){
        return 1;
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    int i,j;
    int A[3],B[3];
    for(i=0;i<T;i++){
        for(j=0;j<3;j++){
            scanf("%d",&A[j]);
        }
        for(j=0;j<3;j++){
            scanf("%d",&B[j]);
        }
        printf("%d\n",judge(A,B));
    }
    return 0;
}