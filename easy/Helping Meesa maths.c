/**
A Lucky number is a number which has only the digits 4 and 7. Meesa makes a special function F(n) for a positive integer n  that returns all good digits of number n from the left to the right. For example, the the output for number 147 is number 47. Meesa has two numbers :

An integer a 
A Lucky number b.
Help Meesa to find the minimum number c (c > a) such that  F(c) = b.

Input:

The first line contain T denoting the number of Test cases. Then T test cases follow . Each test case has only line contains two integers a and b. It is guaranteed that number b is lucky.
 

Output:

Print the number c in a new line  that Meesa needs to find.


Constraints:

1 ≤ T≤ 50

1 ≤ a, b ≤ 105

Sample Input:

1

1 7

Sample Output:

7

Explanation:

The minimum number x greater than 1 such that F(x) = 7 is 7 & so it is the answer.

**For More Examples Use Expected Output**


Contributor: Siddharth Dungarwal

*/

#include<stdio.h>
#include<stdlib.h>

int  getLuckyNumber(int n){
    int temp=n;
    int count=0;
    
    while (temp>0) {
        temp = temp/10;
        
        count++;
    }
    int *A;
    A = (int*) malloc ( sizeof( int ) * count );
    temp = n;
    count=0;
    while (temp>0) {
        A[count++]=temp%10;
        temp = temp/10;
    }
    int j=0;
    int sum=0;
    for(j=count-1;j>=0;j--){
        if(A[j]==4||A[j]==7){
            sum = sum*10+A[j];
        }
    }
    free(A);
    return sum;
}
void func(int a,int b){
    int x=getLuckyNumber(++a);
    while (x!=b) {
        a++;
        x=getLuckyNumber(a);
    }
    printf("%d\n",a);
}

int main(){
    int T,i;
    scanf("%d",&T);
    int a,b;
    for(i=0;i<T;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        func(a,b);
    }
}