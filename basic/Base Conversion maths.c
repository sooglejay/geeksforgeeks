
#include<stdio.h>
#include<math.h>
int main()
{
   
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int A=0,B=0,C=0,D=0;
        char erA [10] ="";
        char erB [7] ="";
        scanf("%d", &A);
        
        int k=0;
        int i=0;
        while(A>0){
            char ch = (A&1)==1?'1':'0';
            erA[k++] = ch;
            A >>= 1;
        }
        k--;
        while(i<k){
            char ch = erA[k];
            erA[k] = erA[i];
            erA[i]=ch;
            i++;
            k--;
        }
        
        scanf("%s", erB);
        i=0;
        while (erB[i++]!='\0');
        k=0;
        i--;
        while(--i>=0){
            B += (erB[i]=='1'?pow(2,k):0);
            k++;
        }
        scanf("%d", &C);
        scanf("%x", &D);
        printf("%s %d %X %d\n",erA,B,C,D);
    }
}
