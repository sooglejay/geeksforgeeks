/**
Class Average
maths  
There is this renowned University named Fibonacci University. It is perfect in all aspects. However it has a rule which is completely different from any other school or University - its marking system. The rule says:

1) Allot marks to each and every student based on his/her perfomance.

2) Multiply the marks of those students whose roll numbers are belong to fibonacci number.

3) In case the marks of any student crosses 100, divide it by 100 and take the remainder.

Professor Basu teaches Logic Design in this University. Exams are over and all the teachers are required to submit the class average of students in their particular course. However Professor Basu is sick and wants you to do the task on his behalf.

Input:

The first line of input takes the number of test case, T. Then T test cases follow .
Each test case consist of 2 lines .
The first line  of each test takes has an integer N where N is the number of students.
The second line takes N space separated integers, where  i th integer denoting the marks obtained by the student with roll number i.
 

Output:
For each test case print the class average (floor value) for each test case in a new line.
 

Constraints:
1<=T<=100

1<=N<=100

1<=Marks<=100
 

Example:

Input:
3
5
34 78 80 91 99
7
30 20 67 90 23 34 53
10
78 87 89 90 67 78 65 56 99 35

Output:
63
37
66

Explanation:

In the first test case, there are 5 students.
Roll No 1 gets 34. 1 is a fibonacci number and hence 34 is multiplied by 1.
Roll No 2 gets 78. 2 is a fibonacci number and hence 78 is multiplied by 2 and becomes 156 which being greater than 100 is reduced to 56.
Roll No 3 gets 80. 3 is a fibonacci number and hence 80 is multiplied by 3 and it becomes 240 which being greater than 100 is reduced to 40.
Roll No 4 gets 91. 4 is not a fibonacci number and hence 91 is kept as it is.
Roll No 5 gets 99. 5 is a fibonacci number and hence 99 is multiplied by 5 and becomes 495 which being greater than 100 is reduced to 95. The class total becomes 316 and an average of 63.2 floor of which is 63 .

The other test cases follow from the same logic.

**For More Examples Use Expected Output**


***/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
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
#include <map>
#include <string.h>
using namespace std;
void   fabo(int table[],int n){
    int j=0;
    table[1]=1;
    table[2]=1;
    table[3]=2;
    int a=table[1],b=table[2],c=0;
    for(j=3;c<=100;j++){
        c = b + a;
        a = b;
        b = c;
        table[c] = 1;
    }
   
    
}
int main(){
    int t,i;
    scanf("%d",&t);
    int table[101];
    fabo(table,101);
    for(i=0;i<t;i++){
        int N,j=0;
        scanf("%d",&N);
        int sum = 0;
        int tem = 0;
        while (j<N) {
            scanf("%d",&tem);
            if(table[j+1]==1){
                tem=tem*(j+1);
                tem%=100;
            }
            sum +=tem;
            j++;
        }
        printf("%d\n",sum/N);
        
        
    }
}