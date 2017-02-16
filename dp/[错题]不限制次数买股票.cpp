
//
// Created by sooglejay on 17/1/11.
//

#include <iostream>

using namespace std;

//因为不限制次数，自己想想吧
void func(int *A, int n) {
    int i = 0;
    int flag = 0;
    while (i < n - 1) {
        while ((i + 1) < n && A[i + 1] <= A[i]) {
            i++;
        }
        if (i == n - 1)
            break;
        if (flag) {
            cout << ' ';
        }
        cout << '(' << i << ' ';
        i++;
        while ((i + 1) < n && A[i + 1] >= A[i]) {
            i++;
        }
        cout << i << ')';
        flag = 1;
    }
    if (!flag) {
        cout << "No Profit" << endl;
    }
    else{
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        func(A, n);
    }

}