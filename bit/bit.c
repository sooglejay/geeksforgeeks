#include <stdio.h>
int rangeBitwiseAnd(int m, int n) {
    int bit = 0;
    while(m!=n) {
        m>>=1;
        n>>=1;
        bit++;
    }
    return m<<bit;
}
int main()
{
    printf("%d",rangeBitwiseAnd(9,11));
    return 0;
}
