/**
Multiply 2 matrices
maths  matrix  
For 2 given matrix of size 3*3 multiply them and print the matrix.

Input:
The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, it consists of six lines and each line has three integers. First three line denoted the first matrix and then next three line denotes the second matrix.

 
Output:
Print three lines and in each line three integers which is resultant matrix after multiplication of 2 matrices.


Constraints:
1<=T<=30
1<=Number<=100


Example:
Input:
1
1 1 1 
1 1 1 
1 1 1 
1 1 1 
1 1 1 
1 1 1 

Output:
3 3 3
3 3 3
3 3 3

**For More Examples Use Expected Output**
*/

#include <stdio.h>
int main() {
    //code
    int T,i,m,n;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        
        int A[3][3],B[3][3],C[3][3];
        for(m=0;m<3;m++){
            for(n=0;n<3;n++){
                scanf("%d",&A[m][n]);
                C[m][n]=0;
            }
        }
        for(m=0;m<3;m++){
            for(n=0;n<3;n++){
                scanf("%d",&B[m][n]);
            }
        }
        int k=0;
        int temp=0;
        for(m=0;m<3;m++){
            for(n=0;n<3;n++){
                temp=0;
                for(k=0;k<3;k++){
                    temp+=A[m][k]*B[k][n];
                }
                C[m][n]=temp;
            }
        }
        for(m=0;m<3;m++){
            for(n=0;n<3;n++){
                printf("%d ",C[m][n]);
            }
            printf("\n");
        }
    }
    return 0;
}