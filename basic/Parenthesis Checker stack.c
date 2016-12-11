#include <stdlib.h>
#include <string.h>
#include<stdio.h>
void func() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char c[101];
        char *stack = (char *) malloc(sizeof(char) * 105);
        memset(stack, 0, sizeof(stack));
        scanf("%s", c);
        int l = strlen(c);
        int i = 0, flag = 1;
        int le = 0;
        for (i = 0; i < l; i++) {
            char ch = c[i];
            if (ch == '{' || ch == '[' || ch == '(') {
                stack[le] = ch;
                le++;
            } else if (ch == '}' || ch == ']' || ch == ')') {
                le--;
                if (le < 0) {
                    flag = 0;
                    break;
                }
                if (ch == '}' && stack[le] == '{' || ch == ']' && stack[le] == '[' || ch == ')' && stack[le] == '(') {
                    flag = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag > 0 ? "balanced" : "not balanced");


    }

}

int main() {
//    void uva_1583();
//    uva_1583();
    func();
    return 0;
}


