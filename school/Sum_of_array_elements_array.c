/**
Given an integer array, find sum of elements in it.

Input:

First line contains an integer denoting the test cases 'T'. Every test case contains an integer value depicting size of array 'N' and N integer elements are to be inserted in the next line with spaces between them.

Output:

Print the sum of all elements of the array in separate line.

Constraints:

1 <= T <= 100

1 <= N<= 100

1 <= Arr[i] <= 100

Example:

Input:
2
3
3 2 1
4
1 2 3 4

Output:
6
10

**For More Examples Use Expected Output***

*/

#include<stdio.h>
int main(){
		int T;
		scanf("%d",&T);
		int A[T];
		int i=0,j,N,temp;
		for(;i<T;i++){
		   A[i]=0;
		   j=0;
		   scanf("%d",&N);
		   for(;j<N;j++){
		   			scanf("%d",&temp);
		   			A[i] += temp;
		   }
		}
		for(i=0;i<T;i++){
					printf("%d\n",A[i]);
		}
	 return 0;
}