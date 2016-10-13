
/***
Series GP
maths  
Given the first 2 terms of Geometric Series tell the nth term of the series. Ex. floor(2.3) =2 and floor(-2.3) = -3.

Input:
First line contains an integer, the number of test cases 'T'. Each test case in its first line should contain two positive integer a and b (First 2 terms of GP). In the second line of every test case it contains of an integer N.


Output:
In each seperate line print the Nth term of the Geometric Progression. Print the floor of the answer.


Constraints:
1<=T<=30
-100<=a<=100
-100<=b<=100
1 <= N <= 5


Example:
Input:
2
2 3
1
1 2
2

Output:
2
2

**For More Examples Use Expected Output**

*/

#include <stdio.h>

int main() {
	//code
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
	    int a,b,k;
	    double c;
	    scanf("%d",&a);
	    scanf("%d",&b);
	    scanf("%d",&k);
	    c = a;
	    while(--k){
	        c = c*b/a;
	    }
	    printf("%d\n",(int)c);
	}
	return 0;
}