//
// Created by sooglejay on 16/12/21.
//


#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    int c=6;
    cin>>c;
    int index = 1;
    for (int i = 0; i < c; ++i) {
        int e = c - index;
        while (e--){
            cout<<' ';
        }
        for (int j = 0; j < index; ++j) {
            cout<<'#';
        }
        index ++;
        cout<<endl;
    }

    return 0;
}