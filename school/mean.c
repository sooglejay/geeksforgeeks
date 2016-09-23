/*
Given the marks of all students, calculate the mean.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case consists of an integer N denoting the number of students. The second line of each test case consists of N space separated integers denoting the marks of all the students.

Output:
Corresponding to each test case, print the floor value of the mean in a new line.

Constraints:
1<=T<=100
1<=N<=100
1<=Marks<=100

Example:

Input:
3
4
56 67 30 79
4
78 89 67 76
5
90 100 78 89 67

Output:
58
77
84

**For More Examples Use Expected Output**


*/

#include <stdio.h>

int main() {
	//code
	int T;
	scanf("%d",&T);
 int result[T];
 int N;
	int mean;

	int i,j,k,z;
 for(i=0;i<T;i++){
					scanf("%d",&N);
					mean = 0;
					int testCase[N];
					for(z=0;z<N;z++){
							scanf("%d",&testCase[z]);
					}
					for(j=0;j<N;j++){
								mean += testCase[j];
					}
					result[i] = (mean/N);
 }
 for(k = 0 ; k<T;k++){
 	 printf("%d\n", result[k]);
 }
	return 0;
}