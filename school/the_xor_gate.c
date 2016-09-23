#include<stdio.h>
int main(){
	int T;
	int N;
	scanf("%d",&T);
	int result[T];
	int i,j;
	int temp;
	for(i=0;i<T;i++){
				temp =	 0;
				scanf("%d",&N);
				int array [N];
				for(j=0;j<N;j++){
						scanf("%d",&array[j]);
				}
				int k;
				for(k=0;k<N;k++){
							temp+=array[k];
				}
					result[i] = temp%2;
	}
	for(i=0;i<T;i++){
		 printf("%d\n", result[i]);
	}

}