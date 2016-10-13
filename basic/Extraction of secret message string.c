/***
Extraction of secret message
string  

Mridushi likes to play with strings. One day Vaibhav challenged her and gave her some strings. Each string contains some secret message. Vaibhav mixed the secret message with some specified substring "LIE" .

For eg. "I AM COOL" is given as "LIELIEILIEAMLIECOOL".

But Mridushi has to leave for some urgent work. So in the absence of her, help to find out the secret message.
 

Input:

First line contains the number of test cases, T.
First line of each test case contains the string, M.

Output:

Print the secret message.
 

Constraints:

1<=T<=10
Length of string doesnt exceed 200 characters.


Example:

Input

2
LIELIEILIEAMLIECOOL
LIELIEABCLIELIELIE
 

Output
I AM COOL
ABC

**For More Examples Use Expected Output**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //code
    int T,j,i,flag;
    scanf("%d",&T);
    char A[201]="";
    for(i=0;i<T;i++){
        char B[201]="";
        scanf("%s",A);
        j=0;
        flag=-1;
        int k=0;
        int len = 0;
        while (A[len]!='\0') {
            len++;
        }
        while (j<len) {
            if (A[j]=='L') {
                if (j<=len-3&&A[j+1]=='I'&&A[j+2]=='E') {
                    j = j+3;
                    if (flag>=0) {
                        if(k>0&&B[k-1]!=' '){
                            B[k++] = ' ';
                        }
                    }
                    continue;
                }else{
                    flag++;
                    B[k++] = A[j];
                }
            }else{
                flag++;
                B[k++] = A[j];
            }
            j++;
        }
        k--;
        while(B[k]==' '){
            k--;
        }
        flag=k;
        k=0;
        while (k<=flag) {
            printf("%c",B[k++]);
        }
        printf(" \n");
    }
    return 0;
}


//另一个版本
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main() {
//     //code
//     int T,j,i,flag;
//     scanf("%d",&T);
//     char A[201]="";
//     for(i=0;i<T;i++){
//         scanf("%s",A);
//         j=0;
//         flag=0;
//         int k=0;
//         int len = 0;
//         while (A[len]!='\0') {
//             len++;
//         }
//         while (j<len) {
//             if (A[j]=='L') {
//                 if (j<=len-3&&A[j+1]=='I'&&A[j+2]=='E') {
//                     j = j+3;
//                     flag=0;
//                     continue;
//                 }else{
//                     if(flag==0&&k==1){
//                        printf(" ");
//                     }
//                     k=1;
//                     flag=1;
//                     printf("%c",A[j]);
//                 }
//             }else{
//                 if(flag==0&&k==1){
//                     printf(" ");
//                 }
//                 k=1;
//                 flag=1;
//                 printf("%c",A[j]);
//             }
//             j++;
//         }
//         printf(" \n");
//     }
//     return 0;
// }