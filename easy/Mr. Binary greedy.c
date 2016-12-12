/**
Mr. Binary is a very greedy person. He always finds a path to do a job with minimum expense. This time his mother has asked him to go to a grocery store to buy some food items. Path to grocery store is represented by a string s containing lower case English alphabets. He can only jump to some other location j (j>i) only if s[j] = s[i]+1. He wants to find out the maximum distance he can reach, i.e., maximum index of the string he can reach.

Note: First character of the string is always 'a'.He can only go 'a'->'b','b'->'c','c'->'d' and so on. 'a'->'c','b'->'d','a'->'a' is not a valid move.Indexing is zero based.

Input:
First line contains single integer defining the number of test cases T.Each of the next T lines contain a single string s containing only lower case english letters.


Output:
For each test case in a new line print a single integer denoting the answer for each test case.

Constraints:
1<=T<=30
1<=|s|<=10^5

Example:
Input
2
aaabbcdbdt
aabcb

Output:
8
4

Explanation:
For first test case
He can start from 'a' at index 0 or 1 or 2 and then move to 'b' at index 3 or 4, then jump to 'c' at index 5 and then go to  'd' at greater index than 6 which is 8. Thus the answer is 8.

For second test case
In second test case, again he starts from 'a' and proceed to 'b' and then 'c'. But we have 'b' at the highest index also, so he will not go to 'c' and from 'a', we will directly jump to 'b'.

**For More Examples Use Expected Output**
**/


#include <stdio.h>

#include<string.h>
#include<stdlib.h>
void t2() {
    int n;
    int max = 100002;
    scanf("%d", &n);
    while (n--) {
        char *A;
        int *B;
        A = (char *) malloc(sizeof(char) * max);
        B = (int *) malloc(sizeof(int) * 26);
        memset(A,0, sizeof(A));
        memset(B,0, sizeof(B));
        scanf("%s",A);
        int len = strlen(A),i;
        for(i=0;i<len;i++){
            B[A[i]-'a'] = i;
        }
        int sum = 0;
        for(i=1;i<26;i++){
            if(B[i]==0){
                break;
            }
            sum = sum>B[i]?sum:B[i];
        }
        printf("%d\n",sum);




    }
}

int main() {
//    void uva_1583();
//    uva_1583();
    t2();
    return 0;
}