/****

Good String
string  
Given a string S of length N, you have to tell whether it is good or not. A good string is one where the distance between every two adjacent character is exactly 1. Here distance is defined by minimum distance between two character when alphabets from 'a' to 'z' are put in cyclic manner. For example distance between 'a' to 'c' is 2 and distance between 'a' to 'y' is also 2. The task is to print "YES" or "NO" (without quotes) depending on whether the given string is Good or not.


Input:
First line of the input contains T denoting the number of test cases.Then T lines follow. Each line contains a string S.


Output:
Print  the answer for each testcase in a separate line.


Constraints:

1≤T≤50
1≤|S|≤50

Note: S contains only lowercase alphabetic characters


Input:
3
aaa
cbc
bcd

Output:
NO
YES
YES

**For More Examples Use Expected Output**
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    //code
    int T,kk,flag=1;
    scanf("%d",&T);
    for(kk=0;kk<T;kk++){
        char A[51] = "0";
        scanf("%s",A);
        int i=1,ch=A[0];
        while (A[i]!='\0') {
            ch = ((A[i]-ch)<0?(ch-A[i]):(A[i]-ch))%24;
            if (ch==1||ch==-1) {
                ch = A[i];
                flag=1;
            }
            else{
                flag=0;
                break;
            }
            i++;
        }
        if (i==1&&A[1]=='\0') {
            printf("YES\n");
        }else{
            printf("%s\n",flag==1?"YES":"NO");
        }
    }
    return 0;
}