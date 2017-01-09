//
// Created by sooglejay on 17/1/8.
//



//这道题我其实做对了，但是我没有想出来dp解法，和一般解法，所以，我找到几个同学的代码，来参考学习

// http://www.practice.geeksforgeeks.org/problem-page.php?pid=158
//这题的答案就是： N/2 +1
//下面首先是dp算法，其实还是在对已知的 数列作dp

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n+1];
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;

        for (int i = 3; i <= n; ++i)
        {
            if(i%2 == 0)
                a[i] = a[i-1]+1;
            else
                a[i] = a[i-1];
        }

        cout << a[n] << endl;
    }

    return 0;
}
// 0 1 2 3 4 5 6 7 8 9 10
// 0 1 2 2 3 3 4 4 5 5 6

//下面这位同学不依赖 测试用例，直接根据 题意，暴力求解，想法挺好的！1和2的个数都从0开始递增，这样肯定不会有重复

int main() {int i,j,t,n,count=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<=n;i++){
            for(j=0;j<=n/2;j++){
                if(i+2*j ==n){count++;}
                //printf("%d %d %d\n",i,j,count);
            }
        }
        printf("%d\n",count);
        count=0;
    }
    //code
    return 0;
}
