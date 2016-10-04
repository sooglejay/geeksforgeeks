/**
John works in RS Software and today he is supposed to receive his salary. RS Software pays its employees in cash. However, John's wallet has one drawback. His wallet can contain no more than M notes or coins. Taking his case into consideration, his boss pays him his salary by the minimum notes possible. However John may have to leave out some money. Tell John how much money will he have to lose.

Note: The values of notes or coins available are 1000, 500, 100, 50, 20, 10, 5, 2 and 1.
 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing two space separated integers N and M denoting John's salary and the maximum number of notes his wallet can hold, respectively.

Output:

Corresponding to each test case, print the desired output in a single line.

Constraints:
1<=T<=20
1<=N<=100000
1<=M<=1000


Example:
Input:
3
1712 4
1023 2
2341 3

Output:
12
3
241

**For More Examples Use Expected Output**


*/


#include<stdio.h>
int func(int A[],int N,int M){
    
    int j=0,i=0;
    int temp=0,result=0;
    while (j<M) {
        temp += A[i];
        if (temp<N) {
            j++;
        }
        else if(temp>N){
           	temp = temp -A[i];
            i++;
            if(i==9){
                i=i-1;
            }
        }else{
            return 0;
        }
    }
    result = N - temp;
    return result;
}
int main(){
    int T;
    scanf("%d",&T);
    int i,N,M;
    int A[9]={1000,500,100,50,20,10,5,2,1};
    for(i=0;i<T;i++){
        scanf("%d",&N);
        scanf("%d",&M);
        printf("%d\n",func(A,N,M));
    }
}