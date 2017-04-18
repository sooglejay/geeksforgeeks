//
// Created by sooglejay on 17/4/18.
//

//http://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0

#include <iostream>
#include <string.h>

using namespace std;
bool visited[51][51];//用于作为 访问过的 元素
int arr[51][51];//用于存储 r*c 矩阵元素

//8个方向
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int dy[] = {0, -1, 1, -1, 1, 0, 1, -1};

//核心算法
void bfs(int r, int c, int i, int j, int &maxV) {
    if (i >= r || j >= c || i < 0 || j < 0)return;
    if (visited[i][j] || !arr[i][j])return;
    visited[i][j] = true;
    maxV++;//这个
    for (int k = 0; k < 8; ++k) {
        bfs(r, c, i + dx[k], j + dy[k], maxV);
    }
}

int walk(int r, int c) {
    int maxTemp = 0;
    int maxRes = 0;
    for (int k = 0; k < r; ++k) {
        for (int i = 0; i < c; ++i) {
            if (visited[k][i] || !arr[k][i])continue;
            bfs(r, c, k, i, maxTemp);
            maxRes = max(maxTemp, maxRes);
            maxTemp = 0;
        }
    }
    return maxRes;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << walk(r, c) << endl;
    }
}