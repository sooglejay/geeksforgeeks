#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char name[20];
    int T,i;
    scanf("%d",&T);
    getchar();
    scanf("%[^\n]s",name);
    printf("%s\n", name);
    return 0;
}