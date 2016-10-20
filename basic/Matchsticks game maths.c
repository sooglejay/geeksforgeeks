/***
Matchsticks game
maths  
A game of matchsticks is played by two friends A and B . In this game a group of matchsticks is placed on the table and then it is reduced  by each player turn vise by removing from the group at least 1 but not more than 4 matchsticks. The player who takes the last match stick is the winner .
What move should A take to win the game if A starts the first.

Note : Consider the game is played optimally.
Input
The first line of input contains an integer T denoting the number of test cases. The next T lines contains N values i.e. total number of matchsticks  present on table.

Output
For each test case print in a new line  the no of matchsticks a player needs to remove if he is given first turn .If its not possible for A to win the game print -1 .

Constraints:
1<=T<=100
1<=N<=100

Example
Input : 
3
48
71
15

Output : 
3
1
-1
 

 

**For More Examples Use Expected Output**
***/


#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set> 
#include <string.h>
using namespace std;

int sum(int bit[],int i){
    int s = 0;
    while(i>0){
        s += bit[i];
        i -= i& -i;
    }
    return s;
}
void add(int bit[],int i,int x,int n){
    while (i<=n) {
        bit[i] += x;
        i += i&-i;
    }
}
int main()
{
   
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int i=n%5==0?-1:n-5*(n/5);
        
        printf("%d\n",i);
        
       
    }
}
