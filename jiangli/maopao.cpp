#include <stdio.h>
#define N 10
void maopao(int score[]) {
    for (int i = 0; i < N - 1; ++i) {
   //之所以可以写N-1,是因为i最后一次取值为i = N-2
 // 此时j = i+1 = N-2 +1 = N-1 也是j取值的最后一次。

 //换句话说，如果上面写成i<N，那么i最后一次取值N-1,j=i+1 = N-1+1 = N
 //此时第二层for 循环 j<N 是不成立的。所以实质上，第二层for循环语句不会进入
//于是，i=N-2，j=i+1=N-2 +1=N-1  才是整个程序最后一次执行

        int m = i;
        for (int j = i + 1; j < N; ++j) {
            if (score[j] < score[m]) {
                m = j;
            }
        }
        int temp = score[m];
        score[m] = score[i];
        score[i] = temp;
    }
}

void print(int score[]) {
    for (int i = 0; i < N; ++i) {
        printf(" %d ", score[i]);
    }
    printf("\n");
}

int main() {
    int score[N] = {67, 98, 75, 63, 82, 79, 81, 91, 66, 84};
    printf("排序前:\n");
    print(score);
    maopao(score);
    printf("排序后:\n");
    print(score);
    return 0;
}