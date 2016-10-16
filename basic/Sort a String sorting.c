/***
Sort a String
sorting  string  
Given a string S consisting of lowercase latin letters, arrange all its letters in ascending order. 

Input:

The first line of the input contains T denoting number of testcases.Then follows description of each testcase.The first line of the testcase contains positive integer N denoting the length of string.The second line contains the string S.


Output:

For each testcase,output the sorted string.


Constraints:

1<=T<=100
1<=N<=100


Example:

Input:
1
5
edcab

Output:
abcde

**For More Examples Use Expected Output**
****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void sort(int A[],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        i = j-1;
        k=A[j];
        while(i>=0&&k<A[i]){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = k;
    }
}
int main() {
    //code
    int T,kk,N,j;
    
    scanf("%d",&T);
    char A[101];
    for(kk=0;kk<T;kk++){
        scanf("%d",&N);
        int B[26];
        for(j=0;j<26;j++){
            B[j]=0;
        }
        scanf("%s",A);
        j=0;
        while(A[j]!='\0'){
            B[A[j]-'a']++;
            j++;
        }
        char ch;
        for(j=0;j<26;j++){
            ch = 'a' + j;
            while (B[j]-->0) {
                printf("%c",ch);
            }
        }
        printf("\n");
    }
    return 0;
}