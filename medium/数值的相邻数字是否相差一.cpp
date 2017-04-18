//
// Created by sooglejay on 17/4/14.
//

#include <iostream>
using namespace std;
bool is(int n){
    if(n<=10)return true;
    while(n){
        if( abs(n%10-(n/10)%10)==1){
            n/=10;
            if(n<10){
                return true;
            }
        }else{
            return false;
        }
    }
    return true;
}
int func(int n,int m){
    int sum = 0;
    for (int i = n; i <=m; ++i) {
        if(is(i)){
            sum++;
        }
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        cout<<func(n,m)<<endl;
    }

}

