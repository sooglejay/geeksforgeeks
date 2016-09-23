/*
Construct an N input XOR Gate. An XOR Gate returns 1 if odd number of its inputs are 1, otherwise 0.

Input:
The first line of input takes the number of test cases, T. Then T test cases follow.Each test case consists of 2 lines. The first line of each test case takes the number of inputs to the XOR Gate, N. The second line of each test case takes N space separated integers denoting the inputs to the  XOR Gate. Note that the inputs can be either 1's or 0's.


Output:
For each test case on a new line print the output of the N input XOR Gate.

Constraints:

1<=T<=100
1<=N<=100

Example:

Input:

3
2
1 1
3
1 0 1
4
1 1 1 0

Output:
0
0
1

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
				int array [N];
				for(j=0;j<N;j++){
						scanf("%d",&array[j]);
				}
				int k;
				for(k=0;k<N;k++){
							temp+=array[k];
				}
					result[i] = temp%2;
	}
	for(i=0;i<T;i++){
		 printf("%d\n", result[i]);
	}

}