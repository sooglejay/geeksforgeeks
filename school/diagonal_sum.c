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
				int array [N*N];
				for(j=0;j<N*N;j++){
						scanf("%d",&array[j]);
				}
				int k,p;
				for(k=1;k<=N;k++){
							temp += array[(k-1)*N+k-1];
				}
				for(k=0;k<N;k++){
							temp += array[N*k + N-k-1];
				}
				// if (N%2)
				// {
				// 			temp -= array[(N+1)*(N/2)];
				// }
				result[i] = temp;
	}
	for(i=0;i<T;i++){
		 printf("%d\n", result[i]);
	}

}