////
//// Created by sooglejay on 16/12/19.
////
//
//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
////这一道题目是要  把  addefc  换成  accefd  你想起来了么
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int n;
//    cin >> n;
//    while (n--) {
//        string A;
//        cin >> A;
//        int size = A.size();
//        int local[26] = {0,};
//
//        for (int i = 0; i < size; ++i) {
//            local[A[i] - 'a'] = 1;
//        }
//
//
//
//        int indexOfA = 0;
//        int firstCh = 0,secondCh = 0;
//        for (int j = 0; j < 26; ++j) {
//            if(local[j]==0){
//                continue;
//            }
//            firstCh = j +'a';
//            if(A[indexOfA]!=firstCh){
//                secondCh = A[indexOfA];
//                break;
//            }
//            indexOfA++;
//        }
//
//        char B[size + 1];
//        for (int k = 0; k < size; ++k) {
//            if (A[k] == firstCh) {
//                B[k] = secondCh;
//            } else if (A[k] == secondCh) {
//                B[k] = firstCh;
//            } else {
//                B[k] = A[k];
//            }
//        }
//        B[size+1]='\0';
//        cout<<B<<endl;
//
//
//    }
//    return 0;
//}


#include <iostream>

using namespace std;

//将字母与'a'的距离作为下标，字母的出现位置作为值

int main() {
    int n;
    cin >> n;
    while (n--) {
        string A;
        cin >> A;
        int local[26];
        for (int j = 0; j < 26; ++j) {
            local[j] = -1;
        }
        for (int i = 0; i < A.size(); ++i) {
            if (local[A[i] - 'a'] == -1)
                local[A[i] - 'a'] = i;
        }
        int flag = 0;
        char change = 0;
        char target = 0;
        int k = 0;
        for (; k < A.size(); ++k) {
            for (int i = 0; i < A[k] - 'a'; ++i) {
                if (local[i] > local[A[k] - 'a']) {
                    flag = 1;
                    change = char(i + 'a');
                    target = A[k];
                    break;
                }
            }
            if (flag > 0) {
                break;
            }
        }
        if (k == A.size()) {
            cout << A << endl;
        } else {
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] == change) {
                    cout << target;
                } else if (A[i] == target) {
                    cout << change;
                } else {
                    cout << A[i];
                }
            }
            cout << endl;
        }

    }
}