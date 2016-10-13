
/***
Binary number to decimal number
maths      Adobe
Given a Binary Number, Print its decimal equivalent.
 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains a single Binary number. 
 

Output: 

Print each Decimal number in new line.
 

Constraints:

1< T <100
1<=Digits in Binary<=8
 

Example:

1
10001000
136

**For More Examples Use Expected Output**
*/
#include <stdio.h>
int main() {
    //code
    int T,i;
    scanf("%d",&T);
    int data[]={1,2,4,8,16,32,64,128,256};
    for(i=0;i<T;i++){
        char digits[10]="";
        scanf("%s",digits);
        int a=0,i=0,j=0;
        while(digits[i]!='\0')i++;
        while(--i>=0){
            a = a+(digits[i]=='1'?data[j]:0);//注意运算 优先级
            j++;
        }
        printf("%d\n",a);
        
        
    }
    return 0;
}