
/**
Armstrong Numbers
maths  
For a given 3 digit number, find whether it is armstrong number or not. An Armstrong number of three digits is an integer such that the sum of the cubes of its digits is equal to the number itself. For example, 371 is an Armstrong number since 3**3 + 7**3 + 1**3 = 371

Input:
First line contains an integer, the number of test cases 'T' Each test case should contain a positive integer N.


Output:
Print "Yes" if it is a armstrong number else print "No".


Constraints:
1<=T<=31
100<= N <1000


Example:
Input:
1
371

Output:
Yes

**For More Examples Use Expected Output**

*/

#include <stdio.h>
void func(int N){
    if(N==1){
        printf("Yes\n");
        return;
    }
    int i=0,j=0;
    int temp=N;
    while(N>0){
        i=N%10;
        j+=i*i*i;
        N/=10;
    }
    if(temp==j){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
   
}
int main() {
    //code
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        func(N);
    }
    return 0;
}