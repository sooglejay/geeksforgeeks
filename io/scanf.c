#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char name[20];
    int T,i;
    scanf("%d",&T);
    getchar();
    scanf("%[^\n]s",name);
    printf("%s\n", name);
    return 0;
}
//终极大招
//可以输入 lim 个字符，如果是空行，强制性让  字符数组存储 lim个空格；
//不足lim个字符，也补全空格来达到lim个
int getline2_(char s[],int lim){
    int c,i;
    i=0;
    while((c=getchar())!=EOF&&c!='\n')
        s[i++]=c;
    while (i<lim) {
        s[i++] = ' ';
    }
    s[i]='\0';
    return i;
}

//从终端输入一个字符，参数是字符指针
void  getch2_(char * s){
    int c=getchar();
   	int i=0;
    do{
        if (c!='\n'&&c>0) {
            s[i++] = c;
        }
        if(i>0){
            break;
        }
    }
    while((c=getchar())!=EOF&&c!='\n');
}