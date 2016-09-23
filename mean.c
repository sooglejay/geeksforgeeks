#include <stdio.h>

int main() {
	//code
	int T;
	scanf("%d",&T);
 int result[T];
 int N;
	int mean;

	int i,j,k,z;
 for(i=0;i<T;i++){
					scanf("%d",&N);
					mean = 0;
					int testCase[N];
					for(z=0;z<N;z++){
							scanf("%d",&testCase[z]);
					}
					for(j=0;j<N;j++){
								mean += testCase[j];
					}
					result[i] = (mean/N);
 }
 for(k = 0 ; k<T;k++){
 	 printf("%d\n", result[k]);
 }
	return 0;
}