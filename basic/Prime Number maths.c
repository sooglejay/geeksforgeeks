/**
Prime Number
maths  
For a given number chack if it is prime or not. A prime number is a number which is only divisible by 1 and itself.
 

Input:
First line contains an integer, the number of test cases 'T'. Each test case should contain a positive integer N.


Output:
Print "Yes" if it is a prime number else print "No".


Constraints:
1<= T <=30
1<= N <=100


Example: 

Input:
1
5

Output:
Yes

**For More Examples Use Expected Output**
***/

#include <stdio.h>
void func(int N){
    if(N==1){
        printf("No\n");
        return;
    }
    int i=N/2,j=1;
    while(i>0){
        if(N%i==0){
            j++;
        }
        i--;
    }
    if(j<3){
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