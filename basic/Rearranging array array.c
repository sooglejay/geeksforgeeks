/***
Rearranging array
array  
Given a list of integers, rearrange the list such that it consists of alternating minimum maximum elements using only list operations. The first element of the list should be minimum and second element should be maximum of all elements present in the list. Similarly, third element will be next minimum element and fourth element is next maximum element and so on. Use of extra space is not permitted

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.The second line of each test case contains N space separated integers denoting array elements.
 

Output:
Corresponding to each test case, in a new line, print the modified list.
 

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ A[i] ≤ 500

Example:

Input
2
5
4 5 1 2 3
4
1 2 3 4

Output
1 5 2 4 3
1 4 2 3

**For More Examples Use Expected Output**
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void sort(int A[],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        i = j-1;
        k=A[j];
        while(i>=0&&k<A[i]){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = k;
    }
}
int main() {
    //code
    int T,kk;
    int N,j;
    scanf("%d",&T);
    for(kk=0;kk<T;kk++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        sort(A, N);
        j=0;
        int k=N-1;
        while(j<k){
            printf("%d %d ",A[j++],A[k--]);
        }
        if(N%2){
            printf("%d",A[k]);
        }
        printf("\n");
        
    }
    return 0;
}