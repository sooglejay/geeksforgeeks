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
double getD(double lat1,double lat2,double long1,double long2){
    double res = 2 *6378.137 * asin (sqrt (pow(sin((M_PI*lat1/180 - M_PI*lat2/180)/2),2) + cos(M_PI*lat1/180)*cos(M_PI*lat2/180) *pow(sin((M_PI*long1/180 - M_PI*long2/180)/2),2)));
    return res;
}
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

int getTimeFromStr(char *str){
    int  day = 0,month,year = 0,minutes = 0,second =0;
    month = (str[0]-'0')*10+(str[1]-'0');
    day = (str[3]-'0')*10+(str[4]-'0');
    year = (str[6]-'0')*1000+(str[7]-'0')*100+(str[8]-'0')*10+(str[9]-'0');
    minutes =(str[11]-'0')*10+(str[12]-'0');
    second =(str[14]-'0')*10+(str[15]-'0');
    int sumTime =day+month+year+second+minutes;
    return sumTime;
}
int main(){
    double lat1,lon1,r;
    scanf("%lf,%lf",&lat1,&lon1);
    scanf("%lf",&r);
    char header[42];
    getline_ex(header,42);
    
    int i = 0,j=0;
    char **headerSonArray = (char**)malloc(sizeof(char*)*4);
    memset(headerSonArray,0,sizeof(char*)*4);
    for(j=0;j<4;j++){
        headerSonArray[j] =  (char*)malloc(sizeof(char)*15);
        memset(headerSonArray[j],0,sizeof(char)*15);
    }
    int k=0;
    int arrayI[] = {0,0,0,0};
    for(j=0;j<4;j++){
        k=0;
        if(header[i]=='\0'){
            break;
        }else if(header[i]==','){
            i++;
        }
        while (header[i]!=','&&header[i]!='\0') {
            headerSonArray[j][k++] = header[i];
            i++;
        }
        switch (k) {
            case 11:
                arrayI[3] = j;
                break;
            case 9:
                if(headerSonArray[j][0]=='D'){
                    arrayI[0] = j;
                }else{
                    arrayI[2] = j;
                }
                break;
            case 8:
                arrayI[1] = j;
                break;
            default:
                break;
        }
        headerSonArray[j][k] = '\0';
        
    }
    
    free(headerSonArray);
    size_t cou = 0;
    priority_queue<size_t, vector<size_t>, greater<size_t> >arrayOfPhone;
    while(true){
        
        char inputStr[80];
        int size = getline_ex(inputStr,80);
        if(size<1){
            break;
        }
        
        char **itemSonArray = (char**)malloc(sizeof(char*)*4);
        memset(itemSonArray,0,sizeof(char*)*4);
        for(j=0;j<4;j++){
            itemSonArray[j] =  (char*)malloc(sizeof(char)*18);
            memset(itemSonArray[j],0,sizeof(char)*18);
        }
        i=0;
        for(j=0;j<4;j++){
            k=0;
            if(inputStr[i]=='\0'){
                break;
            }else if(inputStr[i]==','){
                i++;
            }
            while (inputStr[i]!=','&&inputStr[i]!='\0') {
                itemSonArray[j][k++] = inputStr[i];
                i++;
            }
            itemSonArray[j][k] = '\0';
        }
        double lat2 = atof(itemSonArray[arrayI[1]]);
        double lon2 = atof(itemSonArray[arrayI[2]]);
        char*phone =itemSonArray[arrayI[3]];
        double res = getD(lat1,lat2,lon1,lon2);
        if(res<r){
            if(0.99 * r<= res&&res<=1.01 *r);
            else{
                arrayOfPhone.push(atof(phone));
                cou++;
            }
        }
        free(itemSonArray);
        
    }
    size_t temp = 0;
    for(j=0;j<cou;j++){
        
        if(arrayOfPhone.top()==temp){
            arrayOfPhone.pop();
            continue;
        }
        if(j>0){
            cout<<',';
        }
        cout<<arrayOfPhone.top();
        temp = arrayOfPhone.top();
        arrayOfPhone.pop();
    }
    
    
    
    
    
}
