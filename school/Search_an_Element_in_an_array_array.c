/**

#include <stdio.h>

int main() {
	//code
	int T;
	scanf("%d",&T);
	int A[T];
	int i=0,j,N,value;
	for(;i<T;i++){
	    A[i]=0;
	    j=0;
	    scanf("%d",&N);
	    int array[N];
	    for(;j<N;j++){
	        scanf("%d",&array[j]);
	    }
	    scanf("%d",&value);
	     for(j=0;j<N;j++){
	        if(array[j]==value){
	            A[i] = j;
	            break;
	        }
	    }
	    if(j==N){
	        A[i] = -1;
	    }
	}
	
    for(i=0;i<T;i++){
        printf("%d\n",A[i]);
	}
	return 0;
}

*/

#include <stdio.h>
int main() {
	//code
	int T;
	scanf("%d",&T);
	int A[T];
	int i=0,j,N,value;
	for(;i<T;i++){
	    A[i]=0;
	    j=0;
	    scanf("%d",&N);
	    int array[N];
	    for(;j<N;j++){
	        scanf("%d",&array[j]);
	    }
	    scanf("%d",&value);
	     for(j=0;j<N;j++){
	        if(array[j]==value){
	            A[i] = j;
	            break;
	        }
	    }
	    if(j==N){
	        A[i] = -1;
	    }
	}
	
    for(i=0;i<T;i++){
        printf("%d\n",A[i]);
	}
	return 0;
}