/*
Construct a 6 input gate which performs the following logical operation:
 (not(A)).B + C.D +E.(not(F))
where A, B, C, D, E and F are the inputs to the 6 input gate.

 

Input:
The first line of input takes the number of test cases, T. Then T test cases follow. Each test case takes 6 space separated integers denoting the inputs to the 6 input gate, A, B, C, D,E and F.

Note: the inputs can be either 1's or 0's.
 

Output:
Print the output of the 6 input gate for each test case on a new line.
 

Constraints:
1<=T<=100
0<=A,B,C,D<=1
 

Example:
Input:
3
1 1 0 0 1 1
1 1 1 1 1 1
1 0 0 1 1 1

Output:
0
1
0

Explanation:

In the first test case, A=1, B=1, C=0, D=0, E=1, F=1 so (not(A)).B + C.D +E.(not(F)) = 0.1 + 0.0 + 1.0 = 0 + 0 + 0 = 0

In the second test case, A=1, B=1, C=1, D=1, E=1, F=1. so (not(A)).B + C.D +E.(not(F)) = 0.1 + 1.1 + 1.0 = 0 + 1 + 0 = 1

In the third test case, A=1, B=0, C=0, D=1, E=1, F=1. so (not(A)).B + C.D +E.(not(F)) = 0.0 + 0.1 + 1.0 = 0 + 0 + 0 = 0

**For More Examples Use Expected Output**
*/

#include<stdio.h>
int main(){
		int T;
		scanf("%d",&T);
		int result[T];
		int i,j;
		int numbers[6];
		for(i=0;i<T;i++){
					for(j=0;j<6;j++){
									scanf("%d",&numbers[j]);
					}
					if(!numbers[0]&&numbers[1]||numbers[2]&&numbers[3]||numbers[4]&&!numbers[5])
						{
							result[i]=1;
						}
					else{
							result[i]=0;
					}
		}
		for(i=0;i<T;i++){
				printf("%d\n", result[i]);
		}
		return 0;
}