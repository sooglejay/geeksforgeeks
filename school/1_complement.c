#include <stdio.h>
int main() {
	//code
	int T;
	scanf("%d",&T);
 char *result;
 int N;
	int i,j;
	int array[2000];
	int rr[2000];
	int base=0;
 for(i=0;i<T;i++){
	 scanf("%d",&N);
	 for (j= 0; j < N; ++j)
	 {
		 scanf("%d",array+j);
	 }
	 for(j=0;j<N;j++)
	 {
			*(result+base+j) = array[j]>0?'0':'1';
	 }
	 *(rr+i) = N;
	 base += N;
 }
 j=0;
 base = 0;
 for (i = 0; *(result+i)!='\0'; ++i)
 {
	 
	 printf("%c ",*(result+i));
	 if (i+1==*(rr+j) + base)
	 {
		 base=i+1;
		 j++;
		 printf("\n");
	 }
	 
 }
	return 0;
}