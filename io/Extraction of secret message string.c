//输入字符串数组 直接使用scanf("%s",A);只是A是使用数组的形式
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //code
    int T,j,i,flag;
    scanf("%d",&T);
    char A[201]="";
    for(i=0;i<T;i++){
        scanf("%s",A);
        char B[201]="";

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