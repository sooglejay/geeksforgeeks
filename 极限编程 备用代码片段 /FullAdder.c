
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#define MAX 10000000
using namespace std;
int getline_ex(char s[],int lim){
    int c=getchar();
    int i=0;
    do{
        if (c!='\n'&&c!=EOF) {
            s[i++] = c;
        }
        c=getchar();
        if (c=='\n'||c==EOF) {
            break;
        }
    }
    while(i<lim);
    s[i]='\0';
    return i;
}
int main(){
    int t;int columnAlign = 0;
    char ** chS = (char**)malloc(sizeof(char*)*5);
    int *pass=(int *)malloc(sizeof(int)*256);
    int *inToCh=(int *)malloc(sizeof(int)*256);
    for(t=0;t<256;t++){
        pass[t] = 0;
        inToCh[t]=0;
    }
    for(t=0;t<5;t++){
        chS[t] = (char*)malloc(sizeof(char)*MAX);
    }
    for(t=0;t<5;t++){
        getline_ex(chS[t],MAX);
    }
    t=0;
    int base = 0;
    while(chS[0][t]!=' '){
        base *= 10;
        base += chS[0][t]-'0';
        t++;
    }
    t++;
    size_t k=0;
    while(chS[0][t]!='\0'){
        pass[chS[0][t]] = k;
        inToCh[k] = chS[0][t];
        k++;
        t++;
    }
    
    k=0;
    t=0;
    while(chS[1][t]!='\0'){
        if(chS[1][t]==' '){
            t++;
            continue;
        }
        k *= base;
        int temp = pass[chS[1][t]];
        int resTem = 0;
        while (temp>0) {
            resTem *= base;
            resTem += temp%base;
            temp/=base;
        }
        k += resTem;
        columnAlign = t;
        t++;
        
    }
    t=0;
    size_t otherK = 0;
    
    while(chS[2][t]!='\0'){
        if(chS[2][t]==' '||chS[2][t]=='+'){
            t++;
            continue;
        }
        otherK *= base;
        int temp = pass[chS[2][t]];
        int resTem = 0;
        while (temp>0) {
            resTem *= base;
            resTem += temp%base;
            temp/=base;
        }
        otherK += resTem;
        t++;
    }
    size_t res = k+ otherK;
    
    t=0;
    char *resS = (char*)malloc(sizeof(char)*MAX);
    memset(resS,0,sizeof(char)*20);
    int size = 0;
    while (size<columnAlign) {
        resS[size++] = ' ';
    }
    size =columnAlign;
    while(res>0){
        resS[columnAlign--]=(res%base) +'0';
        res/=base;
    }
    t=0;
    
    for(t=0;t<4;t++){
        cout<<chS[t]<<endl;
    }
    t=0;
    while(t<=size){
        if(resS[t]==' '){
            cout<<' ';
            t++;
            continue;
        }
        char ch= inToCh[resS[t]-'0'];
        cout<<ch;
        t++;
    }
    cout<<endl;
    t=0;
    for(t=0;t<5;t++){
        free(chS[t]);
    }
    free(chS);
    free(pass);
    free(inToCh);
    
}