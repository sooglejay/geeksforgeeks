/***
 
 Given the marks of all students, calculate the median.
 
 Input:
 The first line of input takes the number of test cases, T. Then T test cases follow. Each of the T test cases takes 2 input lines.The first line of each test case takes the number of students, N.The second line of each test case takes N space separated integers denoting the marks of all the students.
 
 Output:
 
 Print the floor value of the median for each test case on a new line.
 
 Constraints:
 
 1<=T<=100
 
 1<=N<=100
 
 1<=Marks<=100
 
 Example:
 
 Input:
 3
 4
 56 67 30 79
 4
 78 89 67 76
 5
 90 100 78 89 67
 
 Output:
 61
 77
 89
 
 **For More Examples Use Expected Output**
 
 **/

#include<stdio.h>
void sort(int array[],int count){
    int j,i,key;
    for(j=1;j<count;j++){
        i=j-1;
        key = array[j];
        while(i>=0&&array[i]>=key){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    int A[T];
    int i,j,N,temp,sum;
    for(i=0;i<T;i++){
        A[i]=0;
        temp=0,sum=0;
        scanf("%d",&N);
        int array[N];
        for(j=0;j<N;j++){
            scanf("%d",&array[j]);
        }
        sort(array,N);
        if(N%2==1){
            A[i] = array[N/2];
        }else{
            A[i] = (array[N/2-1]+array[N/2])/2;
        }
    }
    for(i=0;i<T;i++){
        printf("%d\n",A[i]);
    }
    return 0;
}



