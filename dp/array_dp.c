#include <stdio.h>
#include <stdlib.h>
// A Kadane's algorithm based solution to find maximum
// number of 0s by flipping a subarray.
int findMaxZeroCount_ex(int arr[], int n)
{
    // Initialize count of zeros and maximum difference
    // between count of 1s and 0s in a subarray
    int orig_zero_count = 0;
    
    // Initiale overall max diff for any subarray
    int max_diff = 0;
    
    // Initialize current diff
    int curr_max = 0;
    
    for (int i=0; i<n; i++)
    {
        // Count of zeros in original array (Not related
        // to Kadane's algorithm)
        if (arr[i] == 0)
            orig_zero_count++;
        
        // Value to be considered for finding maximum sum
        int val = (arr[i] == 1)? 1 : -1;
        
        // Update current max and max_diff
        curr_max = val>(curr_max + val)?val:curr_max + val;
        max_diff = max_diff>curr_max?max_diff:curr_max;
    }
    max_diff = 0>max_diff?0:max_diff;
    
    return orig_zero_count + max_diff;
}



// A Kadane's algorithm based solution to find maximum
// number of 0s by flipping a subarray.
int findMaxZeroCount(int arr[], int n)
{
    // Initialize max_diff = maximum of (Count of 0s -
    // count of 1s) for all subarrays.
    int max_diff = 0;
    
    // Initialize count of 0s in original array
    int orig_zero_count = 0;
    
    // Consider all Subarrays by using two nested two
    // loops
    for (int i=0; i<n; i++)
    {
        // Increment count of zeros
        if (arr[i] == 0)
            orig_zero_count++;
        
        // Initialize counts of 0s and 1s
        int count1 = 0, count0 = 0;
        
        // Consider all subarrays starting from arr[i]
        // and find the difference between 1s and 0s.
        // Update max_diff if required
        for (int j=i; j<n; j++)
        {
            (arr[j] == 1)? count1++ : count0++;
            max_diff = max_diff>count1 - count0?max_diff:count1 - count0;
        }
    }
    
    // Final result would be count of 0s in original
    // array plus max_diff.
    return orig_zero_count + max_diff;
}

int func(int *A,int N){
    int **table =(int **)malloc(sizeof(int*)*N);
    int i=0,j=0;
    for(i=0;i<N;i++){
        table[i] = (int*)malloc(sizeof(int)*N);
    }
    
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            int a = A[j];
            table[j][j] = a;
            if(j>0)
            {
                table[i][j] = table[i][j-1]+A[j];
            }
            
        }
    }
    int temp1=0,temp0=0,tempSum=0,t=0;
    for(i=0;i<N;i++){
        temp1=0,temp0=0;
        for(j=i;j<N;j++){
            if(A[j]==1){
                temp1++;
            }else{
                temp0++;
            }
            t =temp0>temp1?temp0:temp1;
            if(i>0&&j<N-1){
                t += table[0][i-1]+table[j+1][N-1];
            }else if (i==0&&j<N-1){
                t += table[j+1][N-1];
            }
            if(t>tempSum){
                tempSum = t;
            }
        }
    }
    for(i=0;i<N;i++){
        free(table[i]);
    }
    free(table);
    return  tempSum;
    
}
int main(){
    int T=0,i=0,N=0,j=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        printf("%d\n",findMaxZeroCount_ex(A, N));
        
    }
}