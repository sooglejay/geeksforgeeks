/***
Given an array A[ ] of N integers, calculate the sum of "A[i] & A[j]" of all the pairs formed by the given array, where & is the bitwise AND operator.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positve integer N, denoting the length of the array A[ ].
The second line of each test case contains a N space seprated positve integers, denoting the elements of the array A[ ].


Output
Print out the sum of products of all pairs formed by the array.

Constraints
1 <= T <= 100
2 <= N <=30
0 <= A[ ] <= 100

Examples 

Input
3
3
5 10 15
4
10 20 30 40
5
20 16 32 50 64

Output
15
46
80

Explanation:
For the above test case 
Required Value = (5 & 10) + (5 & 15) + (10 & 15) 
                             = 0 + 5 + 10 
                             = 15

Expected Complexity
Time: O(N)
 

**For More Examples Use Expected Output**
*/

#include <stdio.h>

int main() {
	//code
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        int k=0,sum=0;
        while(k<N){
            for(j=k+1;j<N;j++){
                sum+=A[k]&A[j];
            }
            k++;
        }
        printf("%d\n",sum);
        
    }
	return 0;
}