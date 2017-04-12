//
// Created by sooglejay on 17/4/12.
//

#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <stack>
//http://practice.geeksforgeeks.org/problems/decode-the-string/0
using namespace std;

bool isNum(char ch) {
    return ch >= '0' && ch <= '9';
}
//思路：使用stack 一直存，直到遇到']'就停止存，开始处理stack。并将处理结果逆序存入stack。迭代之。最后逆序读取stack中的字符，输出结果
string getInnerStr(string str) {
    stack<char> srcSta;
    string sub;
    int size = int(str.size());

    for (int i = 0; i < size; ++i) {
        if (str[i] == ']') {
            //如果是一个完整的字符串的
            string res;
            while (!srcSta.empty()) {
                char ch = srcSta.top();
                srcSta.pop();
                if (ch == '[') {
                    continue;
                }
                //下面都是频率数值
                if (isNum(ch)) {
                    //然后添加进去
                    int repeat = ch-'0';
                    int base = 10;
                    while (!srcSta.empty()&&isNum(srcSta.top())) {
                        char r = srcSta.top();
                        srcSta.pop();
                        repeat = (r-'0')*base + repeat;
                        base *=10;
                    }
                    //最后一个不是数字，那么就结束了
                    for (int j = 0; j < repeat; ++j) {
                        for (int k = int(res.size()-1); k >= 0; --k) {
                            srcSta.push(res[k]);
                        }
                    }
                    break;
                }
                res += ch;

            }
        } else {
            srcSta.push(str[i]);
        }
    }

    while (!srcSta.empty()) {
        sub = srcSta.top() + sub;
        srcSta.pop();
    }
    return sub;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        string str;
        cin >> str;
        cout << getInnerStr(str) << endl;
    }
}



//下面是比较好的其它人的实现

#include <iostream>
using namespace std;

string decode(string pattern, int &start) {
    string result = "";
    while(start < pattern.length() && pattern[start] != ']') {
        if (!isdigit(pattern[start])) {
            result = result + pattern[start];
            start++;
        } else {
            int count = 0;
            while(isdigit(pattern[start])) {
                count = count * 10 + (pattern[start] - '0');
                start++;
            }
            
            start++;  // skip '['
            string temp = decode(pattern, start);
            start++;  // skip ']'
            
            while(count > 0) {
                result = result + temp;
                count--;
            }
        }
    }
    
    return result;
}

int main() {
    //code
    int tests;
    cin >> tests;
    while(tests) {
        string pattern;
        cin >> pattern;
        int start = 0;
        cout << decode(pattern, start) << endl;
        tests--;
    }
    return 0;
}
