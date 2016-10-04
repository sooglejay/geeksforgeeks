
/**
Number of matches
array  
A knockout tournament is going on. A total of N number of players are participating. Each match will have two players. Every player has a distinct rating associated with him. The player with the more rating wins in a match. In one round, the 1st player will play a match against 2nd player, 3rd player will play a match against 4th player and so on. If there is odd number of players, last one will qualify to the next round without playing a match. Since it is a knockout tournament, whoever loses a match leaves the tournament. Your task is to find out the number of matches each player wins in the tournament. The tournament ends when there is only one player remaining in the end.

 

Input: 
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line contains N. In the next line are N space separated positive integers denoting the ratings of the N players.


Output:

Corresponding to each test case, in a new line, print the number of wins of each player with a single space between consecutive values.


Constraints:

1 ≤ T ≤ 100

1 ≤ N ≤ 103  

0 ≤ rating of player ≤ 105


Example:

Input

1
5
7 1 5 3 9

Output

3 1 2 1 1

Explanation:

players: 7 1 5 3 9

The first round: (7 has a match with 1), (5 has a match with 3), (9 has no matches automatically qualifies)

players: 7 5 9

The second round: (7 has a match with 5), (9 has no matches automatically qualifies)

players: 7 9

The third round: (7 has a match with 9).

The player with rating 7 played 3 matches. The player with rating 1 played 1 match. The player with rating 5 played 2 matches. The player with rating 3 played 1 match.  The player with rating 9 played 1 match. 

 

 

**For More Examples Use Expected Output**

思路是  使用两个辅助数组，一个用于输出，一个用于记录上一次优胜者的下标
*/


#include<stdio.h>
void func(int A[],int N){
    int B[N],C[N],i=0,j=0;
    for(i=0;i<N;i++){
        
        C[i]=i;
        B[i]=0;
    }
    i=1;
    int k=0;
    j=(int)(N/2.0 +0.5);
    int kk=N;
    while(j-->0){
        for(k=0;k<kk;k=k+2){
            int ii =C[k];
            if (k+1>=kk) {
                C[k/2] = ii;
                break;
            }
            int jj=C[k+1];
            int a =A[ii],b=A[jj];
            if(a>b){
                A[jj]=-1;
                C[k/2]=ii;
            }else{
                A[ii]=-1;
                C[k/2]=jj;
            }
            B[ii]=B[ii]+1;
            B[jj]=B[jj]+1;
        }
        kk=(kk%2==1?kk/2+1:kk/2);
    }
    for(i=0;i<N;i++){
        printf("%d ",B[i]);
    }
    printf("\n");
    
    
}
int main(){
    int T,i,N,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        int A[N];
        for(j=0;j<N;j++){
            scanf("%d",&A[j]);
        }
        func(A, N);
    }
    return 0;
}