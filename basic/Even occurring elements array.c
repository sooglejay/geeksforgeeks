/***
Even occurring elements
array  bit  
Given an array that contains odd number of occurrences for all numbers except for a few elements which are present even number of times. Find the elements which have even occurrences in the array in O(n) time complexity and O(1) extra space.

Note: In some array, array contains only odd number then you have to print only a blank new line.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements.

Output:

Corresponding to each test case, in a new line, print the elements which have even occurrences in the array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ A[i] ≤ 63

Example:

Input
3
11
9 12 23 10 12 12 15 23 14 12 15
5
23 12 56 34 32
4
10 34 10 56

Output
12 23 15

10 
**For More Examples Use Expected Output**

*/
#include <stdio.h>

int main() {
	//code
	int T,i,N,j;
	scanf("%d",&T);
	for(i=0;i<T;i++){
	    scanf("%d",&N);
	    int A[201],B[N],temp;
	    for(j=0;j<201;j++){
	        A[j]=0;
	        if(j<N){
	            B[j]=0;
	        }
	    }
	    for(j=0;j<N;j++){
	        scanf("%d",&temp);
	        B[j]=temp;
	        A[temp]++;
	    }
	    for(j=0;j<N;j++){
	        if(A[B[j]]>0&&A[B[j]]%2==0){
	            printf("%d ",B[j]);
	            A[B[j]]=0;
	        }
	    }
	    printf("\n");
	}
	return 0;
}