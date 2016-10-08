/**
Gifts! Gifts! Gifts!
array  
There is an orphanage which offers home to hundreds of children who have no parents. They are given gifts on the birthday of the owner. However the orphanage has its own unique way of distributing gifts. Exactly one gift is bought for every child. All the children are then told to submit a list of gifts ordered according to their preference. The children were then given ranks based on their behaviour throughout the year. The gifts were then distributed based on the ranks of the children and their preferences. In other words, the preference of a child with a better rank was given more importance. The task is to write a program that tells about the gifts which children get.

Input:

The first line of input takes an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two input lines.
The first line of each test case takes an integer N denoting the number of children, which is also equal to the number of gifts.
The second line of each test case takes N*N space separated integers, the first N integers denoting the choices filled in by child with rank 1, the second N integers denoting the choices filled in by child with rank 2 and so on.

Output:
Corresponding to each test case, print N space separated integers, ith integer denoting the gift received by child with rank i.

Constraints:
1<=T<=100
1<=N<=1000

Example:

Input:

3
2
1 2 1 2
3
1 3 2 2 1 3 3 1 2
3
1 2 3 3 2 1 1 2 3
Output:

1 2 
1 2 3 
1 3 2
**For More Examples Use Expected Output**


Correct
Execution Time:0.053


*/


#include <stdio.h>
long long func(char *A){
    return  0;
}
int main() {
    //code
    int T,i,j,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N*N];
        int B[N+1],C[N+1];
        for(j=0;j<N+1;j++){
            B[j]=0;
            C[j]=0;
        }
        int k=0;
        int p=0;
        for(j=1;j<=N;j++){
            for(k=(j-1)*N;k<j*N;k++){
                scanf("%d",&A[k]);
                if(p==j-1&&C[A[k]]==0){
                    B[p] = A[k];
                    C[A[k]] = 1;
                    p++;
                }
            }
            
        }
        for(j=0;j<N;j++){
            printf("%d ",B[j]);
        }
        printf("\n");
        
        
        
    }
    return 0;
}