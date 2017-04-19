#include <iostream>
#include <string.h>

#define MAX 100
using namespace std;

//这里有两道题目，通过这两道题目，可以完全理解BFS的本质及遍历技巧


//我发现bfs只是一个手段，我发明一个称谓，叫做目标变量，比如下面的maxV和numbers，他们俩才是bfs服务的对象，是核心的王者
//我们遇到的一切可以用bfs解决的问题，都隐含着一个目标变量，只是它放置的位置不同，代表的含义就会不一样

// visit-ed 用于作为 访问过的 元素

//arr 用于存储 r*c 矩阵元素

//核心算法
void bfs(int arr[MAX][MAX], bool visited[MAX][MAX], int r, int c, int i, int j, int &maxV) {
    if (i >= r || j >= c || i < 0 || j < 0)return;
    if (visited[i][j] || !arr[i][j])return;
    visited[i][j] = true;
    maxV++;//这个存储的就是这个bfs 遍历的领地 长度（1's length）

    //8个方向 可以拿出去作为全局变量
    int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};
    int dy[] = {0, -1, 1, -1, 1, 0, 1, -1};

    for (int k = 0; k < 8; ++k) {
        bfs(arr, visited, r, c, i + dx[k], j + dy[k], maxV);
    }
}

//http://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0
//bfs的父方法
int walk(int arr[MAX][MAX], bool visited[MAX][MAX], int r, int c) {
    int maxTemp = 0;
    int maxRes = 0;
    for (int k = 0; k < r; ++k) {
        for (int i = 0; i < c; ++i) {
            if (visited[k][i] || !arr[k][i])continue;
            bfs(arr, visited, r, c, k, i, maxTemp);
            maxRes = max(maxTemp, maxRes);
            maxTemp = 0;
        }
    }
    return maxRes;
}


void bfsEx(int A[MAX][MAX], bool visited[MAX][MAX], int dx[8], int dy[8], int N, int M) {
    if (N >= MAX || M >= MAX || N < 0 || M < 0)return;
    if (visited[N][M] || !A[N][M])return;//这里!A[N][M]表示，如果是0，就退出，如果是1，说明它属于一个集合

    //能够到达这里的，说明是一个新的领地，并且没有被访问过，并且A[N][M]=1
    visited[N][M] = true;
    for (int i = 0; i < 8; ++i) {
        bfsEx(A, visited, dx, dy, N + dx[i], M + dy[i]);
    }
}

//http://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
/*you are required to complete this method*/
int findIslands(int A[MAX][MAX], int N, int M) {
//Your code here
    int numbers = 0;
    bool visited[MAX][MAX];
    int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};
    int dy[] = {0, -1, 1, -1, 1, 0, 1, -1};
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            //如果!A[N][M]说明是0，不用管。只有1而且它没有被访问到过，说明是一个新的领地
            if (!A[i][j] || visited[i][j])continue;
            bfsEx(A, visited, dx, dy, i, j);
            numbers++;//这个就是目标变量，统计 集合的个数
        }
    }
    return numbers;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        int arr[MAX][MAX];
        bool visited[MAX][MAX];
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << findIslands(arr, r, c) << endl;
//        cout << walk(arr,visited, r, c) << endl;
    }
}