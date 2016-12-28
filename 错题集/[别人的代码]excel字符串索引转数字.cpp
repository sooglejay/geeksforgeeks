//
// Created by sooglejay on 16/12/28.
//

#include<iostream>
using namespace std;
void excel(int no)
{
    if(no<26)
    {
        cout<<(char )(no+64);
        return;
    }
    excel(no/26);
    excel(no%26);
}
int main()
{
    int test,rem,no,i;
    cin>>test;
    for(i=0;i<test;i++)
    {
        cin>>no;
        excel(no);
        cout<<endl;
    }
    //code
    return 0;
}
