/*
 Given an N bit binary number, find the 1's complement of the number. The ones' complement of a binary number is defined as the value obtained by inverting all the bits in the binary representation of the number (swapping 0s for 1s and vice versa).
 
 Input:
 
 The first line of input takes the number of test cases, T. Then T test cases follow. The first line of each test case takes the number of bits, N. The second line of each test case takes N space separated integers denoting the N bits of the binary number.
 
 Output:
 
 Print the 1's complement for each test case in a new line.
 
 Constraints:
 
 1<=T<=100
 
 1<=N<=100
 
 Example:
 
 Input:
 
 3
 2
 1 0
 2
 1 1
 3
 1 0 1
 
 Output:
 0 1
 0 0 0 1 0
 
 **For More Examples Use Expected Output**
*/
#include <stdio.h>
#define MAX 100
int main() {
	//code
	int T;
	scanf("%d",&T);
    char result[MAX * MAX];
    int N;
	int i,j;
	int array[MAX];
	int base=0;
    for(i=0;i<T;i++){
	 scanf("%d",&N);
	 for (j= 0; j < N; ++j)
	 {
		scanf("%d",&array[j]);
	 }
	 for(j=0;j<N;j++)
	 {
		*(result+base+j) = array[j]>0?'0':'1';
	 }
	 *(result+base+j) = '\n';
	 base++;
	 base += N;
 }
 for (i=0; *(result+i)!='\0'; i++) {
	 if ( *(result+i)=='\n') {
		 	printf("\n");
	 }
		else 	  printf("%c ",*(result+i));
 }
	return 0;
}