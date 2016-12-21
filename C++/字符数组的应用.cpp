//
// Created by sooglejay on 16/12/19.
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//这一道题目是要  把  addefc  换成  accefd  你想起来了么
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    while (n--) {
        char A[1001];
        cin >> A;
        int size = strlen(A);
        int local[26] = {0,};

        for (int i = 0; i < size; ++i) {
            local[A[i] - 'a'] = 1;
        }



        int indexOfA = 0;
        int firstCh = 0,secondCh = 0;
        for (int j = 0; j < 26; ++j) {
            if(local[j]==0){
                continue;
            }
            firstCh = j +'a';
            if(A[indexOfA]!=firstCh){
                secondCh = A[indexOfA];
                break;
            }
            indexOfA++;
        }

        char B[size + 1];
        for (int k = 0; k < size; ++k) {
            if (A[k] == firstCh) {
                B[k] = secondCh;
            } else if (A[k] == secondCh) {
                B[k] = firstCh;
            } else {
                B[k] = A[k];
            }
        }
        B[size+1]='\0';
        cout<<B<<endl;


    }
    return 0;
}
