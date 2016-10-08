#include <stdio.h>
#define STUDENTS_NUMBER 10
struct student{
    char name[50];
    char cardNumber[50];
    float chineseScore;
    float mathScore;
    float englishScore;
    float total;
    float average;
};
int main() {
    //code
    int T,i,m,n;
    scanf("%d",&T);
    struct student students[STUDENTS_NUMBER];
    int totalArray[STUDENTS_NUMBER],B[STUDENTS_NUMBER];
    int temp=0;
    for(i=0;i<T;i++){
        for(m=0;m<STUDENTS_NUMBER;m++){
            temp = 0;
            scanf("%s",students[m].cardNumber);
            scanf("%s",students[m].name);
            scanf("%f %f %f",&students[m].chineseScore,&students[m].mathScore,&students[m].englishScore);
            temp=students[m].chineseScore+students[m].mathScore+students[m].englishScore;
            students[m].total=temp;
            B[m] = temp;
            students[m].average=temp/3.0;
        }
        int tempIndex=0;
        for(m=0;m<STUDENTS_NUMBER;m++){
            tempIndex = m;
            temp=0;
            for (n=m; n<STUDENTS_NUMBER; n++) {
                if (temp < B[m]) {
                    temp = B[m];
                    tempIndex = n;
                }
            }
            int k =B[tempIndex];
            B[tempIndex] = B[m];
            B[m] = k;
            totalArray[m] = tempIndex;
        }
        
        int highest = 0;
        int medium = STUDENTS_NUMBER/2;
        int lowest = STUDENTS_NUMBER-1;
        
        
        printf("highest:%s %s %.1f %.1f %.1f %.1f %.1f\n",students[totalArray[highest]].cardNumber,students[totalArray[highest]].name,students[totalArray[highest]].chineseScore,students[totalArray[highest]].mathScore,students[totalArray[highest]].englishScore,students[totalArray[highest]].total,students[totalArray[highest]].average);
        
        
        
        printf("medium:%s %s %.1f %.1f %.1f %.1f %.1f\n",students[totalArray[medium]].cardNumber,students[totalArray[medium]].name,students[totalArray[medium]].chineseScore,students[totalArray[medium]].mathScore,students[totalArray[medium]].englishScore,students[totalArray[medium]].total,students[totalArray[medium]].average);
        
        
        printf("lowest:%s %s %.1f %.1f %.1f %.1f %.1f\n",students[totalArray[lowest]].cardNumber,students[totalArray[lowest]].name,students[totalArray[lowest]].chineseScore,students[totalArray[lowest]].mathScore,students[totalArray[lowest]].englishScore,students[totalArray[lowest]].total,students[totalArray[lowest]].average);
        
    
    }
    return 0;
}