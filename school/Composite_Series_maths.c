// Composite Series
// maths  
// Given a number N, print all the composite numbers less than or equal to N. The number should be printed in ascending order.

// Input:
// The first line contain an Integer T denoting the number of  test cases . Then T test cases follow. Each test case consist of an single integer N.

// Output:
// Print all the composite Number form 0 to N.

// Constraints:

// 1 ≤ T ≤ 50
// 4 ≤ N ≤ 10000

// Example:
// Input:
// 2
// 10
// 6
// Output:
// 4 6 8 9 10
// 4 6

// **For More Examples Use Expected Output**


#include <stdio.h>
#include <string.h>
#include <math.h>
int isPrime(int n){
    if (n==2) {
        return 1;
    }
    int s = sqrt(n);
    int i;
    for(i=2;i<=s;i++){
        if (n%i==0) {
            return 0;
        }
    }
    return 1;
}int main() {
    int T,i,j,N;
    scanf("%d",&T);
    int A[T][10000];
    int z=0;
    for (j=0; j<T; j++) {
        scanf("%d",&N);
        for(i=2;i<=N;i++){
            if (!isPrime(i)) {
                *(A[j]+z) = i;
                z++;
                
            }
        }
         *(A[j]+z) = -1;
        z++;
    }
       for(j=0;j<T ; j++) {
        i=0;
        while (*(A[j]+i)!=-1) {
            if (*(A[j]+i)==0) {
                i++;
                continue;
            }
            printf("%d ",*(A[j]+i));
            i++;
            if(*(A[j]+i)==-1){
                printf("\n");
                break;
            }
        }
    }
    return 0;
}