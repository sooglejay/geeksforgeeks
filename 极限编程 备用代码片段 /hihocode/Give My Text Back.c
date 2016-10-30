#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

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
    char c = 1;
    char last = 1;
    while(~scanf("%c",&c)&c){
        last = c;
        if(c>='a'&&c<='z'){
            printf("%c",c-32);
            while(~scanf("%c",&c)&&c!='\n'){
                if(c<='Z'&&c>='A'){
                    c = c+32;
                    if(last==','||last=='.'||last ==32){
                        printf(" ");
                    }
                    printf("%c",c);
                    last = c;
                }else if(c<='z'&&c>='a'){
                    if(last==','||last=='.'||last == 32){
                        printf(" ");
                    }
                    printf("%c",c);
                    last = c;
                }
                else if(c==32){
                    last=32;
                    continue;
                }else if(c==','||'.'){
                    printf("%c",c);
                    last = c;
                }
                
            }
            
        }else if(c<='Z'&&c>='A'){
            printf("%c",c);
            while(~scanf("%c",&c)&&c!='\n'){
                if(c<='Z'&&c>='A'){
                    c = c+32;
                    if(last==','||last=='.'||last ==32){
                        printf(" ");
                    }
                    printf("%c",c);
                    last = c;
                }else if(c<='z'&&c>='a'){
                    if(last==','||last=='.'||last == 32){
                        printf(" ");
                    }
                    printf("%c",c);
                    last = c;
                }
                else if(c==32){
                    last=32;
                    continue;
                }else if(c==','||'.'){
                    printf("%c",c);
                    last = c;
                }
                
            }

        }
    }
}