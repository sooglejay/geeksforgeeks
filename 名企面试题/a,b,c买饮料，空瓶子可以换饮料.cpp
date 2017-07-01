//
// Created by sooglejay on 17/5/17.
//



#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<vector>
using namespace std;
int main()
{
    //两种饮料，a，b；买b有c的补贴，一共n元。问总共能喝多少瓶饮料
    long long n,a,b,c,ans;
    while(scanf("%lld",&n)!=EOF){
        scanf("%lld%lld%lld",&a,&b,&c);
        long long cnt=b-c,ans=0;
        if(a<b-c){
            ans=n/a;
        }
        else {
            if(b<=n){
                long long num=(n-b)/cnt+1;
                long long last=c+(n-b)%cnt;
                ans+=last/a;ans+=num;
            }
            else {
                ans=n/a;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
