#include <stdio.h>

#define LEN 10

int main()
{
    char str1[LEN] = "\0";
    char str3[LEN] = "\0";
    char str2[LEN] = "\0";
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    return 0;
}