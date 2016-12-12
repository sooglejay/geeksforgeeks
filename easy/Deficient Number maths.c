/***

Given a number x, your task is to find if this number is Deficient number or not. A number x is said to be Deficient Number if sum of all the divisors of the number denoted by divisorsSum(x) is less than twice the value of the number x. And the difference between these two values is called the deficiency.

Mathematically, if below condition holds the number is said to be Deficient:
divisorsSum(x) < 2*x
deficiency = (2*x) - divisorsSum(x)
 

Examples:

Input: 21
Output: YES
Divisors are 1, 3, 7 and 21. Sum of divisors is 32.
This sum is less than 2*21 or 42.

Input: 12
Output: NO

Input: 17
Output: YES
 

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each line contains an integer x.

Output:
For each test case in a new line print 1 if the no is a Deficient number else print 0.

Constraints:
1<=T<=10000
1<=x<=10000


Example:
Input:
3
21
12
17
Output:
1
0
1

**For More Examples Use Expected Output**



***/


#include <stdio.h>
int getSum(int l){
    if (l==1){
        return 1;
    }
    int i = l/2;
    int sum = 0;
    while(i){
        if (l%i==0){
            sum += i;
        }
        i--;
    }
    return  sum+l;
}
void t5(){
    int n;
    scanf("%d",&n);
    while (n--){
        int l;
        scanf("%d",&l);
        int sum = getSum(l);
        printf("%d\n",sum<2*l);
    }
}
int main() {
//    void uva_1583();
//    uva_1583();
    t5();
    return 0;
}

