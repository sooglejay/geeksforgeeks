#include <stdio.h>
#include <stdlib.h>
int main(){
    //    int A[4] ={0,0,0,0};
    //     while(scanf("%d%d%d%d", &A[0],&A[1],&A[2],&A[3]) != EOF){
    //        int sum = 0;
    //        int latest= -1,t0=0,t1=0,t2=0,t3=0;
    //        int i,j,k,p;
    //        for( i=0;i<4;i++){
    //            for( j=0;j<4;j++){
    //                if(j==i)continue;
    //                for( k=0;k<4;k++){
    //                    if(k==j||k==i){
    //                        continue;
    //                    }
    //                    for( p=0;p<4;p++){
    //                        if(p==k||p==j||p==i)continue;
    //
    //                        sum = 1000*A[i]+100*A[j]+10*A[k]+A[p];
    //                        if(sum>2359){
    //                            sum = -2;
    //                        }else if((sum%100)>59){
    //                            sum=-2;
    //                        }
    //                        if(sum>latest){
    //                            latest = sum;
    //                            t0=A[i];
    //                            t1=A[j];
    //                            t2=A[k];
    //                            t3=A[p];
    //                        }
    //                    }
    //                }
    //            }
    //        }
    //        if(latest<0){
    //            printf("NOT POSSIBLE\n");
    //        }
    //        else printf("%d%d:%d%d\n",t0,t1,t2,t3);
    //    }
    //    return  0;
    
    
    
    int N;
    while(scanf("%d", &N) != EOF) {
        int i,A[N];
        for(i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        int ten = A[0],index1=-1,index2 = -1;
        int open = 0;
        int res = 0;
        for(i=1;i<N;i++){
            if(A[i]<ten){
                if(open==0)
                {index1 =i;open = 1;}
            }else{
                if(open==1){
                    index2 = i-1;
                }
                ten = A[i];
            }
            if(i==N-1&&open==1&&A[i]<ten){
                index2 = i;
            }
            
            if(open==1&&index2>0){
                //关闭开关
                open = 0;
                //找出这里面的最小的数
                int p = index1,min=100000002;
                for(;p<=index2;p++){
                    if(A[p]<min){
                        min = A[p];
                    }
                }
                //从数组的左边开始找第一个大于min的数的下标
                int q = 0;
                for(p=0;p<N;p++){
                    if (A[p]<=min) {
                        continue;
                    }else if(A[p]>min){
                        q=p;
                        break;
                    }
                }
                res = (index2 - q + 1)>res?(index2 - q + 1):res;
                index2 = 0;
                
            }
            
            
        }
        
        printf("%d\n",res);
    }
    return 0;
    
}