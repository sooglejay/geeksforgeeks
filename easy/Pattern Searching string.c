/**
Pattern Searching
string      MAQ Software    Payu
Given a text and a pattern, Find whether the pattern exist in the text or not. If it is present print "found" without quotes else print "not found"
without quotes.

Input:

The first line of input contains an integer T denoting the number of test cases. Each test case consist of a string in 'lowercase' only in a
separate line.

Output:

Print "found" or "not found" in a separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ |s| ≤ 100


Example:

Input
1
geeksforgeeks
geeks
Output
found

**For More Examples Use Expected Output***/

#include<stdio.h>
void func(char *A,char *B){
    int i=0,j=0,len=0;
    while(B[j++]!='\0')len++;
    j=0;
    int kk=0;
    
    while(A[i]!='\0'){
        if(A[i]==B[j]){
            j++;
            i++;
            if(j==len){
                printf("found\n");
                return;
            }
        }else{
            kk++;
            i=kk;
            j=0;
        }
    }
    if (j<len) {
        printf("not found\n");
    }
}
int main(){
    int T,i;
    scanf("%d",&T);
    char A[100],B[100];
    for(i=0;i<T;i++){
        scanf("%s",A);
        scanf("%s",B);
        func(A,B);
    }
    return 0;
}