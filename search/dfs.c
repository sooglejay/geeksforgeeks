#include <stdio.h>
int dfs(int A[],int sum,int i,int n){
    if (sum<0||(i>=n&&sum>0)) {
        return 0;
    }
    else if(sum==0&&i<=n){
        return 1;
    }else if(dfs(A,sum-A[i],i+1,n)==1){
        return 1;
    }else{
        return dfs(A,sum,i+1,n);
    }
}


int main()
{
    int T,N;
    int i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N],k;
        for(j=0;j<N;j++)
        {
            scanf("%d",&A[j]);
        }
        scanf("%d",&k);
        printf("%d\n",dfs(A,k,0,N));

    }
    return 0;
}
