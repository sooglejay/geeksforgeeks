
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
#define  INF 100000
typedef pair<int, int> P;
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
void bfs_tag(char **table, int i,int j,int tag,int N,int M,int **d){
    if(i<0||j<0){
        return;
    }
    if(i>=N||j>=M){
        return;
    }
    if(table[i][j]=='O'&&d[i][j]==INF){
        d[i][j] = tag;
        bfs_tag(table,i+1,j,tag,N,M,d);
        bfs_tag(table,i,j+1,tag,N,M,d);
        bfs_tag(table,i-1,j,tag,N,M,d);
        bfs_tag(table,i,j-1,tag,N,M,d);
        
        bfs_tag(table,i+1,j+1,tag,N,M,d);
        bfs_tag(table,i+1,j-1,tag,N,M,d);
        bfs_tag(table,i-1,j+1,tag,N,M,d);
        bfs_tag(table,i-1,j-1,tag,N,M,d);
    }
    
}

int dx[8]= {1,0,-1,0,  1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
int  bfs(char ** table ,int **d,int **tags,int sx,int sy,int gx,int gy,int N,int M){
    queue<P>que;
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            d[i][j]=INF;
            tags[i][j]=INF;
        }
    }
    que.push(P(sx,sy));
    d[sx][sy] =0;
    



    int tag_ = 1;
    while (que.size()) {
        P p = que.front();
        que.pop();
        if(tag_==1)
        {
            bfs_tag(table,p.first,p.second,tag_,N,M,tags);
        }
        tag_ ++;

        if(p.first==gx&&p.second==gy)break;
        for(i=0;i<8;i++){
            int nx = p.first+dx[i],ny = p.second+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&d[nx][ny]==INF){
                que.push(P(nx,ny));
                char nextCh = table[nx][ny];
                char currentCh =table[p.first][p.second];
                if(nextCh==currentCh){
                    d[nx][ny]=d[p.first][p.second];
                }
                else if(nextCh=='~'&&currentCh=='O'){
                    d[nx][ny]=d[p.first][p.second];
                }else if(nextCh=='O'&&currentCh=='~'){
                    d[nx][ny]=d[p.first][p.second]+1;
                    if(tags[nx][ny]==tags[p.first][p.second]){
                        d[nx][ny]++;
                    }
                }else{
                    return -1;
                }
            }
        }
    }
    
    return d[gx][gy];
    
}
int main(){
    
    int rows,column,q;
    scanf("%d",&rows);
    scanf("%d",&column);
    scanf("%d",&q);
    int i;
    char **table = (char**)malloc(sizeof(char*)*(rows+1));
    int **d=(int **)malloc(sizeof(int *)*rows);
    int **tags=(int **)malloc(sizeof(int *)*rows);

    for(i=0;i<rows;i++){
        table[i] = (char*)malloc(sizeof(char)*(column+1));
        d[i] = (int*)malloc(sizeof(int)*(column));
        tags[i] = (int*)malloc(sizeof(int)*(column));

    }
    for(i=0;i<rows;i++){
        getline_ex(table[i], column+1);
    }
    for(i=0;i<q;i++){
        int sx,sy,gx,gy;
        scanf("%d",&sx);
        scanf("%d",&sy);
        scanf("%d",&gx);
        scanf("%d",&gy);
        int res = bfs(table,d,tags,sx-1,sy-1,gx-1,gy-1,rows,column);
        printf("%d\n",res);
    }
    for(i=0;i<rows;i++){
        free(table[i]);
        free(d[i]);
        free(tags[i]);
    }
    free(table);
    free(d);
    free(tags);


}

