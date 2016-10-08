/**
Palindrome String
string  
Given a string s check if it is palindrome or not.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string s.


Output:
Print "Yes" if it is a palindrome else "No". (Without the double quotes)


Constraints:
1<=T<=30
1<=N<=100


Example:
Input:
1
4
abba

Output:
Yes

**For More Examples Use Expected Output***/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void func(char *s,int N){
    if(N==1){
        printf("Yes\n");
        return;
    }
    int i=0,j=0,flag=1;
    
    char *B = (char*)malloc(sizeof(char)*N);
    int k=N%2;
    while(s[i]!='\0'){
        if(i<N/2){
            B[j]=s[i];
            j++;
        }else {
            i=i+k;
            k=0;
            if(B[--j]!=s[i]){
                flag=0;
            }
            k=0;
        }
        i++;
    }
    free(B);
    if(flag){
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
        char s[N];
        scanf("%s",s);
        func(s,N);
    }
    return 0;
}