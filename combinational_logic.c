#include<stdio.h>
int main(){
		int T;
		scanf("%d",&T);
		int result[T];
		int i,j;
		int numbers[6];
		for(i=0;i<T;i++){
					for(j=0;j<6;j++){
									scanf("%d",&numbers[j]);
					}
					if(!numbers[0]&&numbers[1]||numbers[2]&&numbers[3]||numbers[4]&&!numbers[5])
						{
							result[i]=1;
						}
					else{
							result[i]=0;
					}
		}
		for(i=0;i<T;i++){
				printf("%d\n", result[i]);
		}
		return 0;
}