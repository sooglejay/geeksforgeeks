/**
 You are given the sequence: 0123456789101112131415...
 
 The 0th digit of this sequence is 0, the 1st digit of this sequence is 1, the 2nd digit of this sequence is 2 and so on.
 
 You will be given some queries. Each query will ask you to print the digit at the ith position for some i.
 
 Input:
 
 The first line of the input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of one line which contains a positive integer i, which asks you to print the ith digit in the sequence given.
 
 Output:
 
 Corresponding to each test case, in a new line, print the digit at that position.
 
 Constraints:
 
 1 ≤ T ≤ 2000
 1 ≤ Query Value ≤ 100000
 
 Example:
 
 Input
 3
 186
 190
 5
 
 Output
 9
 1
 5
 
 **For More Examples Use Expected Output**
 
 */


#include <stdio.h>

int main(){
    int T,i,N;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        if (N<10) {
            printf("%d\n",N);
        }else if(N<190){
            int q = (N-10)/2;
            int n =  (N-10)%2;
            int k = q+10;
            
            int i=2-n;
            int m=0;
            while (i>0) {
                m= k%10;
                k/=10;
                i--;
            }
            printf("%d\n",m);

            
        }else if(N<2890){
            int q = (N-190)/3;
            int n =  (N-190)%3;
            int k = q+100;
            
            int i=3-n;
            int m=0;
            while (i>0) {
                m= k%10;
                k/=10;
                i--;
            }
            printf("%d\n",m);
        }else if(N<38890){
            
            int q = (N-2890)/4;
            int n =  (N-2890)%4;
            int k = q+1000;
            
            int i=4-n;
            int m=0;
            while (i>0) {
                m= k%10;
                k/=10;
                i--;
            }
            printf("%d\n",m);
            
            
        }else if(N<488980){
            int q = (N-38890)/5;
            int n =  (N-38890)%5;
            int k = q+10000;
            
            int i=5-n;
            int m=0;
            while (i>0) {
                m= k%10;
                k/=10;
                i--;
            }
            printf("%d\n",m);
        }
    }
}