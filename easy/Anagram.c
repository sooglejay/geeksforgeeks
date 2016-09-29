#include<stdio.h>
#define MAX 100
int main(){
    int T,i,j;
    scanf("%d",&T);
    char s1[MAX];
    char s2[MAX];
    
    int a1[129];
    

    for(i=0;i<T;i++){
        for(j=0;j<129;j++){
            a1[j]=0;
        }
        scanf("%s",s1);
        scanf("%s",s2);
        j=0;
        while (s1[j]!='\0') {
            a1[s1[j++]]++;
        }
        j=0;
        
        while (s2[j]!='\0') {
            a1[s2[j++]]--;
        }
        for(j=0;j<129&&a1[j]==0;j++){
            
        }
        if (j==129) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }
    return 0;
    
}