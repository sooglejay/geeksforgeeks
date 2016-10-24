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
    int T,t;
    scanf("%d",&T);
    for(t=0;t<T;t++){
        int initNum;
        scanf("%d",&initNum);
        map<string,int>initMap;

        int j=0;
        for(j=0;j<initNum;j++)
        {
            char *line=(char*)malloc(sizeof(char)*18);
            memset(line, 0, sizeof(char)*18);
            getline_ex(line,18);
            int tI = 0;
            string str="";
            while(line[tI]!=' '){
                str[tI] = line[tI];
                tI++;
            }
            tI++;
            int sum = 0;
            while(line[tI]!='\0'){
                sum *= 10;
                sum += (line[tI] - '0');
                tI++;
            }
            initMap.insert(pair<string,int>(str,sum));
            free(line);
        }
        
        int m;
        int B[m];//
        int A[m];

        map<string,map<string,int>>destMap;
        scanf("%d",&m);
        for(j=0;j<m;j++){
            B[j] = 0;
            A[j]=0;
            char *line=(char*)malloc(sizeof(char)*100);
            memset(line, 0, sizeof(char)*100);
            getline_ex(line,100);
            int tI = 0;
            string island1="";
            while(line[tI]!=' '){
                island1[tI] = line[tI];
                tI++;
            }
            tI++;
            
            string island2="";
            while(line[tI]!=' '){
                island2[tI] = line[tI];
                tI++;
            }
            tI++;
            
            int sum = 0;
            while(line[tI]!='\0'){
                sum *= 10;
                sum += (line[tI] - '0');
                tI++;
            }
            map<string,int> islMap1,islMap2;
            islMap1.insert(pair<string ,int>(island1,sum));
            islMap2.insert(pair<string ,int>(island2,sum));
            destMap.insert(pair<string,map<string,int>>(island1,islMap2));
            destMap.insert(pair<string,map<string,int>>(island2,islMap1));
            free(line);
        }
        
        map<string,int> startMap = destMap["start"];
        map<string,int> ::iterator startIter = startMap.begin();
        int k=0;
        for(;startIter!=startMap.end();startIter++){
            string nextIsLand = startIter->first;
            int sum = startIter->second;
            A[k] = sum;
            B[k] = initMap[nextIsLand];
            k++;
        }
        
        for(j=0;j<m;j++){
            cout<<A[j]<<endl;
        }
        
    }
    
}