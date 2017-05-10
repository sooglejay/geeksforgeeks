//
// Created by sooglejay on 17/4/19.
//



//
//    Travelling Salesman Problem
//            bit  dp  graph      Google    Microsoft    Opera
//            Given a matrix M of size N where M[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.
//
//    Input:
//            The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix then in the next line are N*N space separated values of the matrix M.
//
//    Output:
//            For each test case print the required result denoting the min cost of the tour in a new line.
//
//    Constraints:
//    1<=T<=15
//    1<=N<=12
//    1<=M[][]<=10000
//
//    Example:
//            Input:
//    2
//    2
//    0 111 112 0
//    3
//    0 1000 5000 5000 0 1000 1000  5000  0
//    Output:
//    223
//    3000
//
//    **For More Examples Use Expected Output**

//旅行商问题 这道题能够AC 我也是非常惊喜

//我只是想学习bfs 的写法。

#include <iostream>
#include <string.h>
#include <climits>

#define MAX 101
using namespace std;

void bfs(int arr[MAX][MAX], bool visited[MAX], int n, int i, int j, int spend, int &minV) {
    if (visited[j])return;
    visited[j] = true;//1
    //来到一个新的城市，就加上它的价格
    spend += arr[i][j];//1
    for (int k = 0; k < n; ++k) {
        if (visited[k] || k == j)continue;
        //1,2; 接下来是1,3
        bfs(arr, visited, n, j, k, spend, minV);
        //下面要处理visited[k]复位，这样就达到了回滚的效果
        visited[k] = false;
        // 注意一个技巧，就是bfs退出后，spend就自动回滚了。这样的效果是通过传值达到的。
        // 如果是传引用，就无法实现
    }

    //判断是否走到头
    int l = 0;
    for (; l < n; ++l) {
        if (!visited[l])break;
    }
    //这里的逻辑是 要从0一直走，走到头了，再统计价格，价格放在spend里面，使用一个minV做最小处理
    if (l == n)minV = min(spend + arr[j][0], minV);

}

int walk(int arr[MAX][MAX], int n) {
    bool visited[MAX];
    int spend = 0;
    int res = INT_MAX;
    //从0开始走，它可以选择任意一个城市作为下一个城市。除了它自己
    for (int j = 1; j < n; ++j) {
        int minV = INT_MAX;
        memset(visited, false, sizeof(visited));
        visited[0] = true;
        bfs(arr, visited, n, 0, j, spend, minV);
        res = min(res, minV);
        spend = 0;
        memset(visited, false, sizeof(visited));
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int arr[MAX][MAX];
        memset(arr, 0, sizeof(arr));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << walk(arr, n) << endl;
    }
}


//看到一个很牛逼的代码实现

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t; cin >> t; while(t--){
        int n; cin >> n;
        vector< vector<int> > M(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> M[i][j];
            }
        }
        //let DP[mask][i] be visited cities ending with i
        vector< vector<int> > DP(1<<n,vector<int>(n,1e9));
        for (int i = 0; i < n; i++){
            DP[1<<i][i] = M[0][i];
        }
        for (int mask = 1; mask < (1<<n); mask++){
            for (int j = 0; j < n; j++){
                if (mask&(1<<j)){
                    for (int k = 0; k < n; k++){
                        if (!(mask&(1<<k))){
                            DP[mask|(1<<k)][k] = min(DP[mask|(1<<k)][k],DP[mask][j]+M[j][k]);
                        }
                    }
                }
            }
        }
        cout << DP[(1<<n) - 1][0] << endl;
    }
    return 0;
}

