//
// Created by sooglejay on 17/3/24.
//



//#include "deploy.h"
//#include "lib_io.h"
//#include "lib_time.h"
//#include "stdio.h"
//
//#define LOCAL 23
//
//int main(int argc, char *argv[])
//{
//    print_time("Begin");
//    char *topo[MAX_EDGE_NUM];
//    int line_num;
//
//#ifdef LOCAL
//    const char *const topo_file = "/Users/sooglejay/StudyC/projectXcode/HW/HW/cases/case0.txt";
//    const char *const result_file = "/Users/sooglejay/StudyC/projectXcode/HW/HW/output.txt";
//
//#else
//    const char * const topo_file = argv[1];
//    const char * const result_file = argv[2];
//#endif
//
//
//    line_num = read_file(topo, MAX_EDGE_NUM, topo_file);
//
//    printf("line num is :%d \n", line_num);
//    if (line_num == 0)
//    {
//        printf("Please input valid topo file.\n");
//        return -1;
//    }
//
//
////    deploy_server(topo, line_num, result_file);
//    deploy_server_ex(topo_file, result_file);
//
//    release_buff(topo, line_num);
//
//    print_time("End");
//
//	return 0;
//}
//

/**
 *
 *
 用例
 3
CoderAcodEr
coder
code
CoderAcodEr
coder
code

 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {

    vector<string> sV;
    int n;
    cin >> n;
    string target = "coder";
    std::locale loc;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>que;
    for (int i = 0; i < n; ++i) {
        string s1;
        cin >> s1;
        sV.push_back(s1);
        int in = 0;
        for(auto elem : s1){
            s1[in++]=std::tolower(elem,loc);
        }
        int len = s1.size();
        int c = 0;
        for (int l = 0; l < len; ++l) {
            int kk = l;
            int m =0;
            for (; m < 5&&kk<len; ++m) {
                if(s1[kk]==target[m]){
                    kk++;
                }else{
                    break;
                }
            }
            if(m==5){
                c++;
                l = kk-1;
            }
        }
        que.push(make_pair(c,i));
    }
    vector<string>res;
    while (!que.empty()){
        pair<int,int>p = que.top();que.pop();
        res.push_back(sV[p.second]);
    }
    int len = res.size();
    for (int l = 0; l < len; ++l) {
        cout<<res[l]<<endl;
    }
    return 0;



}

//STL

#include <string>
#include <algorithm>
#include <iostream>

int main (int argc, char* argv[])
{
    std::string sourceString = "Abc";
    std::string destinationString;

    // Allocate the destination space
    destinationString.resize(sourceString.size());

    // Convert the source string to lower case
    // storing the result in destination string
    std::transform(sourceString.begin(),
                   sourceString.end(),
                   destinationString.begin(),
                   ::tolower);

    // Output the result of the conversion
    std::cout << sourceString
              << " -> "
              << destinationString
              << std::endl;
}