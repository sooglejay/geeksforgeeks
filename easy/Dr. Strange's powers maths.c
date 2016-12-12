/***
Dr. Strange has developed some new powers since he has started programming. Now if a villan throws a 1 at him, he absorbs it and add it to his already existing binary string s. There are n villans and each of them throws a '1' at him. At each point you have to detemine the resulting string s.
 

Input:
First line of input contains n denoting the number of enemies. Each of the next n lines contain an integer l and a string s denoting the length of the existing binary string and the string itself.

Output:
For each of the n lines print a string denoting the resulting binary string at each steps.


Constraints:
1<=n<=20
1<=l<=100
 

Example:
Input:
2
4
1010
5
11100

Output
1011
11101

Explanation:
For test case 1 : 1010+1 = 1011 as he absorbs 1 and add to the existing string

**For More Examples Use Expected Output**


**/


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void t4() {
     int n;
    scanf("%d", &n);
    while (n--) {
        int len;
        scanf("%d", &len);
        char A[len],B[len+1];
        memset(B,0, sizeof(B));
        scanf("%s", A);
        int i=len,c = 1;
        B[len+1]='\0';
        while (i--){
            if (A[i]-'0'){
                c = 1+c;
            }else{
                c = 0+c;
            }
            B[i+1] = c%2?'1':'0';
            c /= 2;
        }
        B[0]=c?'1':'0';
        // 如果第一个元素是进位，则从第一个开始输出；否则从第二个元素开始输出
        for(i=1-c;i<len+1;i++){
            printf("%c",B[i]);
        }
        printf("\n");
    }
}

int main() {
//    void uva_1583();
//    uva_1583();
    t4();
    return 0;
}