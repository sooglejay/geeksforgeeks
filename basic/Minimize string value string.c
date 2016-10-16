/***
Minimize string value
string      Amazon
Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters.  The value of a string is defined as sum of squares of count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1,e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^1 + 2^2 = 9.

Input:
The first line of input contains the number T denoting the no of test cases . Then T test cases follow. .Each test case contains two lines.The first line of each test case contains a string str. The second line of each test case consist of an integer k .

Output:
The output for each test case will be an integer denoting the min possible value of the string.

Constraints:
1<=T<=100 
1<=str<=50
1<=k<=50

Example:
Input
2
abccc
1
aaab
2
Output
6
2
 

**For More Examples Use Expected Output**


***/

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
    int T,kk;
    
    scanf("%d",&T);
    char A[51]="";
    for(kk=0;kk<T;kk++){
        scanf("%s",A);
        int B[26],j=0;
        for(j=0;j<26;j++){
            B[j]=0;
        }
        j=0;
        while (A[j]!='\0') {
            B[A[j]-'a']++;
            j++;
        }
        sort(B, 26);
    	int k;
        scanf("%d",&k);
        while (k>0) {
            B[25]--;
            sort(B, 26);
            k--;
        }
        int sum=0;
        for(j=0;j<26;j++){
            if (B[j]>0) {
                sum += (B[j]*B[j]);
            }
        }
        printf("%d\n",sum);
        
    }
    return 0;
}