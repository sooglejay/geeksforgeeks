/**
 Given two positive integers num1 and num2, the task is to find the product of the two numbers on a 12 hour clock rather than a number line.
 
 Input
 First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing two integers separated by a space .
 
 
 Output
 Corresponding to each test case, print the difference in a new line.
 
 
 
 Constraints:
 1<=T<=100
 1<=num1<=1000
 1<=num2<=1000
 
 Example:
 
 input:-
 1
 2 3
 3 5
 
 output:-
 6
 3
 
 
 
 **For More Examples Use Expected Output**
 */
#include<stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int i,a,b;
    for(i=0;i<T;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        printf("%d\n",(a*b)%12);
    }
    return 0;
}