/***
Maximize sum after K negations
array  
Given an array of size n and a number k. We must modify array K number of times. Here modify array means in each operation we can replace any array element arr[i] by -arr[i]. We need to perform this operation in such a way that after K operations, sum of array must be maximum?

Examples:

Input : arr[] = {-2, 0, 5, -1, 2} 
        K = 4
Output: 10
// Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}
// Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}
// Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
// Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}

Input : arr[] = {9, 8, 8, 5} 
        K = 3
Output: 20
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consist of three lines . The first line of each test case contains an integer N.The second line of each test case contains N space separated integers denoting elements of the array. Third line contains value of k.

Output:
For each test case in a new line print maximum possible sum.

Constraints:
1 ≤ T ≤ 500
1 ≤ N ≤ 1000

Example:
Input:
2
5
1 2 -3 4 5
1
10
5 -2 5 -4 5 -12 5 5 5 20
5

Output:
15
68

**For More Examples Use Expected Output*****/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void sort(int *A,int n){
    int i,j,k;
    for (i=1; i<n; i++) {
        j = i - 1;
        k = A[i];
        while (j>=0&&k<A[j]) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = k;
    }
}
int main() {
    
    size_t T;
    cin>>T;
    int N;
    while(T--){
        cin>>N;
        int A[N];
        for(int i = 0;i<N;i++){
            cin>>A[i];
        }
        int k;
        cin>>k;
        sort(A,N);
        int res = 0;
        
        for(int i=0;i<N;i++){
            if(A[i]<0){
                res++;
                A[i] *= -1;
                if(res==k){
                    break;
                }
            }
            else{
                break;
            }
        }
        sort(A,N);
        if(res==k){
            res = 0;
            for(int i=0;i<N;i++){
                res+=A[i];
            }
        }else{
            sort(A,N);
            res = k-res;
            if(res%2==1){
                A[0] *= -1;
            }
            res = 0;
            for(int i=0;i<N;i++){
                res+=A[i];
            }
        }
        
        printf("%d\n",res);
        
    }
    
}
