//
// Created by sooglejay on 17/5/10.
//

#include <iostream>
using namespace std;
long func(string s){
    int base = 1;
    long sum = 0;
    for(int i= (int) (s.size() - 1); i >= 0; i--){
        sum += (s[i]-'A'+1)*base;
        base*=26;
    }
    return sum;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        cout<<func(s)<<endl;
    }
}