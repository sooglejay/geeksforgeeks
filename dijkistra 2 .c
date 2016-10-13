#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
// 邻接矩阵
typedef struct _graph
{
    int *vexs;       // 顶点集合
    int vexnum;           // 顶点数
    int **matrix; // 邻接矩阵
}Graph;

void dijkstra(Graph G, int vs, int prev[], int *dist,int N)
{
    int i,j,k=0;
    int min;
    int tmp;
    int flag[N];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
    
    // 初始化
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G.matrix[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }
    
    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;
    
    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.vexnum; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G.vexnum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;
        
        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G.vexnum; j++)
        {
            tmp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
    
    
}
int main() {
    int T,i,N,M,j;
    int v1,v2,r,s;
    scanf("%d",&T);
    
    for(i=0;i<T;i++){
        scanf("%d",&N);
        scanf("%d",&M);
        Graph* pG=(Graph*)malloc(sizeof(Graph));
        memset(pG, 0, sizeof(Graph));
        pG->vexs = (int*)malloc(sizeof(int)*N);
        pG->matrix = (int**)malloc(sizeof(int*)*N);
        for(j=0;j<N;j++){
            pG->matrix[j] = (int*)malloc(sizeof(int)*N);
        }
        pG->vexnum = N;
        for (i = 0; i < pG->vexnum; i++)
        {
            for (j = 0; j < pG->vexnum; j++)
            {
                if (i==j)
                    pG->matrix[i][j] = 0;
                else
                    pG->matrix[i][j] = INF;
            }
        }
        int prev[N];
        int dist[N];
        for(j=0;j<N;j++){
            prev[j]=0;
            dist[j]=0;
        }
        for(j=0;j<N;j++){
            pG->vexs[j] = j;
        }
        for (j=0; j<M; j++) {
            scanf("%d",&v1);
            scanf("%d",&v2);
            scanf("%d",&r);
            pG->matrix[v1-1][v2-1]=r;
            pG->matrix[v2-1][v1-1]=r;
        }
        scanf("%d",&s);
        dijkstra(*pG, s-1, prev, dist,N);
        for (i = 0; i < pG->vexnum; i++){
            if(i==s-1){
                continue;
            }
            printf("%d ", dist[i]);
        }
        printf("\n");
        for(j=0;j<N;j++){
            free(pG->matrix[j]);
        }
        free(pG->vexs);
        free(pG->matrix);
        free(pG);
        
    }
    return 0;
}
