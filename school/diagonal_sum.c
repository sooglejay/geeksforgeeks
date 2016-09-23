/*
Given a square matrix of size M×M . Your task is to calculate the sum of its diagonals.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case contains a single integer M denoting the size of the square matrix. The next  line contains M*M space separated values of the matrix A.

Output:
For each test case in a new line print the sum of diagonals of the matrix.

Constraints:
1 ≤ T ≤ 20
2 ≤ N ≤ 10
1 ≤ A[i] ≤ 20

Example:

Input:

1
3
1 1 1 1 1 1 1 1 1

Output:
6

**For More Examples Use Expected Output**


*/

#include<stdio.h>
int main(){
	int T;
	int N;
	scanf("%d",&T);
	int result[T];
	int i,j;
	int temp;
	for(i=0;i<T;i++){
				temp =	 0;
				scanf("%d",&N);
				int array [N*N];
				for(j=0;j<N*N;j++){
						scanf("%d",&array[j]);
				}
				int k,p;
				for(k=1;k<=N;k++){
							temp += array[(k-1)*N+k-1];
				}
				for(k=0;k<N;k++){
							temp += array[N*k + N-k-1];
				}
				// if (N%2)
				// {
				// 			temp -= array[(N+1)*(N/2)];
				// }
				result[i] = temp;
	}
	for(i=0;i<T;i++){
		 printf("%d\n", result[i]);
	}

}