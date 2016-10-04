/**
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:

Print the maximum gap between the successive elements.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 1000
1 ≤ A[i] ≤ 1000


Example:

Input
1
3
1 10 5
Output
5

**For More Examples Use Expected Output**
*/

#include<stdio.h>
void insertSort(int A[],int N){
    int i,j,key;
    for(j=1;j<N;j++){
        i=j-1;
        key=A[j];
        while (i>=0&&A[i]>key) {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
int func(int A[],int N){
    insertSort(A, N);
    int j;
    int temp=0,result=0;
    
    for(j=1;j<N;j++){
        temp = A[j]-A[j-1];
        result = temp>result?temp:result;
    }
    return result;
}
int main(){
    int T;
    scanf("%d",&T);
    int i,N,j;
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        printf("%d\n",func(A,N));
    }
}