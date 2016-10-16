/**
Mega Sale
array  sorting  
LALU wanted to purchase a laptop so he went to a nearby sale.There were n Laptops at a sale. Laptop with index i costs ai rupees. Some Laptops have a negative price — their owners are ready to pay LALU if he buys their useless Laptop. LALU can buy any Laptop he wants. Though he's very strong, he can carry at most m Laptops, and he has no desire to go to the sale for the second time. Please, help LALU find out the maximum sum of money that he can earn.

Input:

First line of the input contains T denoting the number of test cases.Each test case has 2 lines :

first line has two spaced integers n m.
second line has n integers [a0...ai...an-1].
Output:

The maximum sum of money that LALU can earn, given that he can carry at most m Laptops.


Constraints:

1≤T≤10

1≤n,m≤100

-1000≤ai≤1000
 

Sample Input:

1

 5 3

-6 0 35 -2 4

Sample Output:

8

Explanation:

LALU takes the laptops with -6 and -2 and thus earns 8 rupees.

**For More Examples Use Expected Output**
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void sort(int A[],int n){
    int i,j,k;
    for(j=1;j<n;j++){
        i=j-1;
        k=A[j];
        while (i>=0&&k>A[i]) {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=k;
    }
    
}
int main() {
    //code
    int T,i,N,M,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        scanf("%d",&M);
        int A[N],k=0,sum=0;
        for(j=0;j<N;j++){
            scanf("%d",&A[k]);
            if (A[k]<0) {
                A[k] = -1*A[k];
                k++;
            }
        }
        sort(A,k);
        for(j=0;j<k;j++){
            if (j<M) {
                sum +=A[j];
            }
            
        }
        printf("%d\n",sum);
        
    
    }
    return 0;
}