/***
Punish the Students
sorting  
A Professor conducts a Computer Science paper for all students. He had strictly ordered all students to sit according to their roll numbers. However when he started checking the papers, he found out that all the papers were randomly ordered. The students had sat randomly during the exam instead of sitting according to their roll numbers. Professor was very angry and he wanted to teach the students a lesson. He decides to sort the papers by Bubble Sort, count the number of swaps required for each and every student and deduct as many marks of a student as were the number of swaps required for that student. However he also has to maintain a class average of atleast M else he may lose his job. The Professor wants to know whether he should punish the students or save his job.

Input:

The first line of input takes an integer T denoting the total number of test cases. Then T test cases follow. Each test case has 3 input lines.

The first line of each test case takes the number of students, N and the minimum average to be maintained,M.

The second line of each test case takes N space separated integers, the ith integer denoting the roll number of the student sitting in i th seat during exam.

The third line of each test case takes N space separated integer, the i th integer denoting the marks obtained by the student having roll number i.

Output:

Print 1 if he can teach the students a lesson without putting his job at risk, else print 0.

Constraints:

1<=T<=100
1<=N<=1000
1<=M<=100
1<=Marks<=100

Example:

Input:
2
5 68
3 2 4 1 5
50 67 89 79 58
6 67.5
5 4 1 3 2 6
78 98 86 67 78 79

Output:
0
1

Explanation:

Test Case#1

Iteration

     1                         2 3 1 4 5                  -                       Array

                                1 1 1 1 0                  -                      Swaps

     2                         2 1 3 4 5                   -                       Array

                                1 2 2 1 0                   -                      Swaps

     3                         1 2 3 4 5                    -                       Array

                                3 2 2 1 0                   -                      Swaps


Marks of 1st student = 50 - 3 = 47

Marks of 2nd student = 67 - 2 = 65

Marks of 3rd student = 89 - 2 = 87

Marks of 4th student = 79 - 1 = 78

Marks of 5th student = 58 - 0 = 58

Class Average = 67<68

Hence, Professor decides to save his job and O/P is 0.

The remaining test cases follow from the same logic.

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
        double average,sum=0;
        scanf("%d",&n);
        scanf("%lf",&average);
        int A[n],bit[n];
        memset(A, 0, n);
        memset(bit, 0, n);
        int k=0,j=0;
        for(k=0;k<n;k++){
            scanf("%d",&A[k]);
        }
        for(k=0;k<n;k++){
            scanf("%d",&bit[k]);
        }
        
        for (k=0; k<n; k++) {
            int min = A[k];
            int index = k;
            for(j=k+1;j<n;j++){
                if (min>A[j]) {
                    min = A[j];
                    index = j;
                }
            }
            A[index] = A[k];
            A[k] = min;
            
            bit[index]--;
            bit[k]--;
                
        }
        
        for(k=0;k<n;k++){
            sum+=bit[k];
        }
        sum = sum/n;
        printf("%d\n",sum>average);
        
    }
}
