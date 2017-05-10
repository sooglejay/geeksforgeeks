//
// Created by sooglejay on 17/5/3.
//

//// A C++ program to find strongly connected components in a given
//// directed graph using Tarjan's algorithm (single DFS)
//#include<iostream>
//#include <list>
//#include <stack>
//#define NIL -1
//using namespace std;
//
//// A class that represents an directed graph
//class Graph
//{
//    int V;    // No. of vertices
//    list<int> *adj;    // A dynamic array of adjacency lists
//
//    // A Recursive DFS based function used by SCC()
//    void SCCUtil(int u, int disc[], int low[],
//                 stack<int> *st, bool stackMember[]);
//public:
//    Graph(int V);   // Constructor
//    void addEdge(int v, int w);   // function to add an edge to graph
//    void SCC();    // prints strongly connected components
//};
//
//Graph::Graph(int V)
//{
//    this->V = V;
//    adj = new list<int>[V];
//}
//
//void Graph::addEdge(int v, int w)
//{
//    adj[v].push_back(w);
//}
//
//// A recursive function that finds and prints strongly connected
//// components using DFS traversal
//// u --> The vertex to be visited next
//// disc[] --> Stores discovery times of visited vertices
//// low[] -- >> earliest visited vertex (the vertex with minimum
////             discovery time) that can be reached from subtree
////             rooted with current vertex
//// *st -- >> To store all the connected ancestors (could be part
////           of SCC)
//// stackMember[] --> bit/index array for faster check whether
////                  a node is in stack
//void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
//                    bool stackMember[])
//{
//    // A static variable is used for simplicity, we can avoid use
//    // of static variable by passing a pointer.
//    static int time = 0;
//
//    // Initialize discovery time and low value
//    disc[u] = low[u] = ++time;
//    st->push(u);
//    stackMember[u] = true;
//
//    // Go through all vertices adjacent to this
//    list<int>::iterator i;
//    for (i = adj[u].begin(); i != adj[u].end(); ++i)
//    {
//        int v = *i;  // v is current adjacent of 'u'
//
//        // If v is not visited yet, then recur for it
//        if (disc[v] == -1)
//        {
//            SCCUtil(v, disc, low, st, stackMember);
//
//            // Check if the subtree rooted with 'v' has a
//            // connection to one of the ancestors of 'u'
//            // Case 1 (per above discussion on Disc and Low value)
//            low[u]  = min(low[u], low[v]);
//        }
//
//            // Update low value of 'u' only of 'v' is still in stack
//            // (i.e. it's a back edge, not cross edge).
//            // Case 2 (per above discussion on Disc and Low value)
//        else if (stackMember[v] == true)
//            low[u]  = min(low[u], disc[v]);
//    }
//
//    // head node found, pop the stack and print an SCC
//    int w = 0;  // To store stack extracted vertices
//    if (low[u] == disc[u])
//    {
//        while (st->top() != u)
//        {
//            w = (int) st->top();
//            cout << w << " ";
//            stackMember[w] = false;
//            st->pop();
//        }
//        w = (int) st->top();
//        cout << w << "\n";
//        stackMember[w] = false;
//        st->pop();
//    }
//}
//
//// The function to do DFS traversal. It uses SCCUtil()
//void Graph::SCC()
//{
//    int *disc = new int[V];
//    int *low = new int[V];
//    bool *stackMember = new bool[V];
//    stack<int> *st = new stack<int>();
//
//    // Initialize disc and low, and stackMember arrays
//    for (int i = 0; i < V; i++)
//    {
//        disc[i] = NIL;
//        low[i] = NIL;
//        stackMember[i] = false;
//    }
//
//    // Call the recursive helper function to find strongly
//    // connected components in DFS tree with vertex 'i'
//    for (int i = 0; i < V; i++)
//        if (disc[i] == NIL)
//            SCCUtil(i, disc, low, st, stackMember);
//}
//
//// Driver program to test above function
//int main()
//{
//    cout << "\nSCCs in first graph \n";
//    Graph g1(5);
//    g1.addEdge(1, 0);
//    g1.addEdge(0, 2);
//    g1.addEdge(2, 1);
//    g1.addEdge(0, 3);
//    g1.addEdge(3, 4);
//    g1.SCC();
//
//    return 0;
//}

//#include <stdio.h>

//int func(int a[], int n) {
//    //首先从小到大排序，这里采用冒泡排序
//    for (int i = 0; i < n; ++i) {
//        //比如 数组是: 3、2、1、 4、5
//        //冒泡的思想，每一次都找到最小的值，把他拿出来放到第一个
//        int minV = a[i], minIndex = i;//第一次循环，minV 是3，minIndex是0
//        for (int j = i + 1; j < n; ++j) {//j从i+1开始，当i是0，j从1开始递增
//            if (minV > a[j]) {//第一次循环，a[j]=2,3>2,会进入if语句
//                minV = a[j];//minV 更新为2
//                minIndex = j;//minIndex 更新为1
//            }
//
//            //第二次循环，2>1 ,更新minV为1，minIndex为2，
//            //最后两次循环，minV是1，都小于4，5，于是不会进入if语句
//        }
//        //则把3 与 1 位置互换
//        //首先 a[2] = a[0], 即 数值1 被3覆盖
//        a[minIndex] = a[i];
//        //然后，注意i此时是0，minV 的值一直都是最小的，目前是1，a[0] = 1
//        a[i] = minV;
//
//        //下一次循环，会把2 这个当前最小值，放到i=1这个位置来，
//        //再下一次循环，i=2,j=i+1=3开始递增循环，3<4,3<5，所以不会进入if语句。
//        //于是 没有变化
//        //同理，最后两个元素,4,5是递增的，不会进入if 语句。
//    }
//    //排序完毕
//    int cur = a[0];//第一个数
//    for (int k = 1; k < n; ++k) {
//        if (a[k] == cur) {//如果相等，那么找到了，直接break 出去，cur保存了我想要的值
//            break;
//        } else {//不等，那么不管，换下一个
//            cur = a[k];
//        }
//    }
//    return cur;
//}
//int main() {
//    int t;
//    scanf("%d", &t);
//    while (t--) {
//        int n;
//        scanf("%d", &n);
//        int A[n];
//        for (int i = 0; i < n; ++i) {
//            scanf("%d", &A[i]);
//        }
//        int ret = func(A, n);
//        printf("%d\n", ret);
//    }
//    return 0;
//}
//

//int getLowerCount() {
//    string ss;
//    cin >> ss;
//    cout << ss << endl;
//
//    int testCase;
//    scanf("%d", &testCase);
//    while (testCase--) {
//        int lowerCount = getLowerCount();
//        printf("%d\n", lowerCount);
//    }
//
//
//    char ch[101];
//    scanf("%s", ch);
//    int sum = 0;
//    int len = strlen(ch);
//    for (int i = 0; i < len; ++i) {
//        if (ch[i] > 'Z')sum++;
//    }
//    return sum;
//}


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> PAIR;

struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
        return lhs.second > rhs.second;
    }
};


vector<int>  topKFrequent(vector<int> &nums, int k) {
    map<int, int> container;
    for (int i = 0; i < nums.size(); ++i) {
        if (container.count(nums[i]) > 0) {
            container[nums[i]]++;
        } else {
            container[nums[i]] = 1;
        }
    }
    vector<PAIR> vec(container.begin(), container.end());
    sort(vec.begin(), vec.end(), CmpByValue());
    vector<int>resV;
    for (int j = 0; j <k; ++j) {
        resV.push_back(vec[j].first);
    }
    return resV;
}

int main() {

    vector<int>n;
    n.push_back(1);
    n.push_back(1);
    n.push_back(1);
    n.push_back(2);
    n.push_back(2);
    n.push_back(3);
    n.push_back(4);
    n.push_back(4);
    n.push_back(5);
    topKFrequent(n,2);
}

