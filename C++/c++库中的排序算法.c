//排序算法
//https://www.freebsd.org/cgi/man.cgi?query=mergesort&sektion=3

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

int cmp(const int *a, const int *b) {
    if (*a > *b) {
        return 1;
    } else if (*a == *b) {
        return 0;
    } else
        return -1;
}

void t6() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int l, i = 0;
        scanf("%d", &l);
        int A[l];
        while (i < l) {
            scanf("%d", &A[i]);
            i++;
        }

        //用法 https://www.freebsd.org/cgi/man.cgi?query=mergesort&sektion=3
        qsort(A, l, sizeof(int), (int (*)(const void *, const void *)) cmp);
        i = 0;
        printf("\n");
        while (i < l) {
            printf(" %d ", A[i]);
            i++;

        }

    }
}

int main() {
//    void uva_1583();
//    uva_1583();
    t6();
    return 0;
}



