#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	//code
	int n;
	scanf("%d",&n);
	while(n--){
	    int l;
	    scanf("%d",&l);
	    int *A = (int *)malloc(sizeof(int)*10000006);
	    memset(A,0,sizeof(A));
	    int i;
	    for(i=0;i<l;i++){
	        int d;
	        scanf("%d",&d);
	        A[d] = i;
	    }
	    int k;
	    scanf("%d",&k);
	    printf("%d\n",A[0]==k?0:(A[k]==0?-1:A[k]));
	    free(A);
	}
	return 0;
}