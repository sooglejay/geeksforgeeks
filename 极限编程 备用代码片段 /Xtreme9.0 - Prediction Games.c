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
#define C 1000
#define P 20

typedef  struct pp {
    char name[31];
    int predict[C][2];
    int totalScore;
} person;
typedef struct competition{
    int whoSuccess;
    int team1;
    int team2;
} com;
void printPerson(person p)
{
    int i;
    printf("\nname:%s\n",p.name);
    for(i=0;i<3;i++){
        printf("%d  %d\n",p.predict[i][0],p.predict[i][1]);
    }
}
int getline2_(char s[],int lim){
    int c = getchar(),i;
    i=0;
    do{
        if(c!=EOF&&c!='\n')
        {
            s[i++]=c;
        }
    }
    while((c=getchar())!=EOF&&c!='\n'&&i<lim);
    
    s[i]='\0';
    return i;
}
int main(){
    
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int p=0,c;
        scanf("%d",&p);
        scanf("%d",&c);
        int j,g;
        person persons[p];
        for(j=0;j<p;j++){
            scanf("%s",persons[j].name);
            for(g=0;g<c;g++){
                scanf("%d",&persons[j].predict[g][0]);
                scanf("%d",&persons[j].predict[g][1]);
            }
            persons[j].totalScore = 0;
            //            printPerson(persons[j]);
        }
        com scores[c];
        int unkown[c],unknowIndex = 0;
        
        for(g=0;g<c;g++){
            char s[8];
            unkown[g] = 0;
            getline2_(s, 8);
            if (s[0]!='?') {
                int t = 0;
                int sum=0;
                while(s[t]!=' '&&s[t]!='\0')
                {
                    sum *= 10;
                    sum += (s[t] - '0');
                    t++;
                }
                scores[g].team1 = sum;
                t++;
                sum = 0;
                while(s[t]!='\0')
                {
                    sum *= 10;
                    sum += (s[t] - '0');
                    t++;
                }
                scores[g].team2 = sum;
                if(scores[g].team2 >scores[g].team1)
                {
                    scores[g].whoSuccess = 2;
                }
                else if(scores[g].team2 <scores[g].team1){
                    scores[g].whoSuccess = 1;
                }
                else{
                    scores[g].whoSuccess = 0;
                }
            }else{
                scores[g].team1 = -1;
                scores[g].team2 = -1;
                scores[g].whoSuccess = -1;
                unkown[unknowIndex++]=g;
            }
        }
        int p1,p2;
        int s1,s2;
        for(g=0;g<c;g++){
            for(j=0;j<p;j++){
                p1 = persons[j].predict[g][0];
                p2 = persons[j].predict[g][1];
                
                s1 = scores[g].team1;
                s2 = scores[g].team2;
                
                switch(scores[g].whoSuccess) {
                    case -1:
                        
                        break;
                    case 0:
                        if (p1==p2) {
                            persons[j].totalScore += 10;
                        }
                        persons[j].totalScore += max(0, 5-abs(s1-p1));
                        persons[j].totalScore += max(0, 5-abs(s2-p2));
                        persons[j].totalScore += max(0, 5-abs(p1-p2+s2-s1));
                        
                        break;
                    case 1:
                        if(p1>p2){
                            persons[j].totalScore +=10;
                        }
                        persons[j].totalScore += max(0, 5-abs(s1-p1));
                        persons[j].totalScore += max(0, 5-abs(s2-p2));
                        persons[j].totalScore += max(0, 5-abs(p1-p2+s2-s1));
                        
                        break;
                    case 2:
                        if(p1<p2){
                            persons[j].totalScore +=10;
                        }
                        persons[j].totalScore += max(0, 5-abs(s1-p1));
                        persons[j].totalScore += max(0, 5-abs(s2-p2));
                        persons[j].totalScore += max(0, 5-abs(p1-p2+s2-s1));
                        
                        
                        break;
                }
                
                
            }
        }
        
        g = persons[0].totalScore;
        int indexs[p];
        
        for(j=0;j<p;j++){
            indexs[j] = 0;
            if (g<persons[j].totalScore) {
                g =persons[j].totalScore;
            }
        }
        
        for(j=0;j<p;j++){
            if(persons[j].totalScore==g){
                indexs[j] = g;
            }
        }
        
        if(unknowIndex==0){
            int dd,ff;
            person temp;
            for(dd=1;dd<p;dd++){
                ff = dd-1;
                temp = persons[dd];
                while (ff>=0&&temp.name[0]<persons[ff].name[0]) {
                    persons[ff + 1] = persons[ff];
                    ff--;
                }
                persons[ff+1] = temp;
            }
            
            for(j=0;j<p;j++){
                if(persons[j].totalScore==g){
                    printf("%s ",persons[j].name);
                }
            }
        }else{
            int s1,s2;
            int p1,p2;
            int ff;
            int un = 0;
            for(;un<unknowIndex;un++){
                for(j=0;j<p;j++){
                    p1 = persons[j].predict[unkown[un]][0];
                    p2 = persons[j].predict[unkown[un]][1];
                    
                    s1 = p1;
                    s2 = p2;
                    int ts =persons[j].totalScore;
                    ts+=25;
                    persons[j].totalScore = ts;
                    
                    for(ff = 0;ff<p;ff++){
                        if (ff==j||indexs[ff]==0) {
                            continue;
                        }
                        int pp1 = persons[ff].predict[unkown[un]][0];
                        int pp2 = persons[ff].predict[unkown[un]][1];
                        
                        if((pp1-pp2)*(s1-s2)>0){
                            persons[ff].totalScore +=10;
                        }
                        persons[ff].totalScore += max(0, 5-abs(s1-pp1));
                        persons[ff].totalScore += max(0, 5-abs(s2-pp2));
                        persons[ff].totalScore += max(0, 5-abs(pp1-pp2+s2-s1));
                        
                        if (persons[j].totalScore>=persons[ff].totalScore) {
                            indexs[j] = 100;
                        }
                    }
                    
                    
                }
            }
            
            
            int dd,fff;
            person temp;
            for(dd=1;dd<p;dd++){
                fff = dd-1;
                temp = persons[dd];
                while (fff>=0&&temp.name[0]<persons[fff].name[0]) {
                    persons[fff + 1] = persons[fff];
                    fff--;
                }
                persons[fff+1] = temp;
            }
            
            for(j=0;j<p;j++){
                if(indexs[j]>0){
                    printf("%s ",persons[j].name);
                }
            }
            
        }
        printf("\n");
        
        
    }
    
    
}

