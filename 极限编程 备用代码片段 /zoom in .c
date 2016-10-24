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
using namespace std;
int getline_(char s[],int lim){
    int c=getchar();
    int i=0;
    do{
        if (c>=32&&c<=126) {
            s[i++] = c;
        }
        c=getchar();
        if (c=='\n'||c==EOF) {
            break;
        }
    }
    while(i<lim);
    
    while (i<lim) {
        s[i++] = ' ';
    }
    s[i]='\0';
    return i;
}
int getline_ex(char s[],int lim){
    int c=getchar();
    int i=0;
    do{
        if (c>=32&&c<=126) {
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
void  getch_(int* s){
    char c=getchar();
   	int i=0;
    do{
        if (c>=32&&c<=126) {
            s[i++] = c;
        }
        if(i>0){
            break;
        }
        c=getchar();
    }
    while(1);
   
}

int main(){
    
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    int i,j;
    map<int,char **>maps;
    for(i=0;i<k;i++){
        char **chs = (char**)malloc(sizeof(char*)*m);
        for(j=0;j<m;j++){
            chs[j] = (char*)malloc(sizeof(char)*n);
        }
        int *keys = (int*)malloc(sizeof(int)*2);
        
        getch_(keys);
        for (j=0;j<m;j++) {
            getline_(chs[j],n);
        }
        maps.insert(pair<char,char**>(keys[0], chs));
    }
    
    int x,g;
    scanf("%d",&x);
    for(i=0;i<x;i++){
        g=0;
        int ll = 0,pp=0;
        char *xStr =(char*)malloc(sizeof(char)*2100);
        int size = getline_ex(xStr, 2100);
        char **res = (char**)malloc(sizeof(char*)*m);
        for(ll=0;ll<m;ll++){
            res[ll] = (char*)malloc(sizeof(char)*(n*size));
        }
        while(g<size){
            int key = xStr[g];
            char **temp = maps[key];
            for(ll=0;ll<m;ll++){
                for(pp=g*n;pp<g*n+n;pp++){
                    res[ll][pp] = temp[ll][pp%n];
                }
            }
            g++;
        }
        for(ll=0;ll<m;ll++){
            for(pp=0;pp<size*n;pp++){
                printf("%c",res[ll][pp]);
            }
            printf("\n");
        }
        free(xStr);
        for(ll=0;ll<m;ll++){
            free(res[ll]);
        }
        free(res);
    }
}

