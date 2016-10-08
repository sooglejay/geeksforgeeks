
/**
Given a string, find the maximum occurring character in the string. If more than one character occurs maximum number of time then print the lexicographically smaller character.

Input:

The first line of input contains an integer T denoting the number of test cases. Each test case consist of a string in 'lowercase' only in a separate line.

Output:

Print the lexicographically smaller character which occurred the maximum time.

Constraints:

1 ≤ T ≤ 30

1 ≤ |s| ≤ 100

Example:

Input:
2
testsample
geeksforgeeks

Output:
e
e

**For More Examples Use Expected Output**

*/

#include <stdio.h>
char  func(char *A){
    int i=0;
    char count[26];
    for(i=0;i<26;i++){
        count[i]=0;
    }
    i=0;
    while(A[i]!='\0'){
        count[A[i++]-'a']++;
    }
    int sum=0;
    char resultCh=0;
    for(i=25;i>=0;i--){
        if(count[i]>=sum){
            sum = count[i];
            resultCh = 'a'+i;
        }
    }
    return  resultCh;
}
int main() {
    //code
    int T,i;
    scanf("%d",&T);
    char s[101];
    for(i=0;i<T;i++){
        scanf("%s",s);
        printf("%c\n",func(s));
    }
    return 0;
}