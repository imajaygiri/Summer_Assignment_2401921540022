#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *decodeString(char *s) {
    int n = strlen(s);

    int count_stack[100];
    char *string_stack[100];

    int top = -1;

    int num = 0;

    char *curr = calloc(100000, 1);

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        else if (ch == '[') {
            count_stack[++top] = num;
            string_stack[top] = strdup(curr);

            curr[0] = '\0';
            num = 0;
        }

        else if (ch == ']') {
            int repeat = count_stack[top];

            char *prev = string_stack[top--];

            int needed =
                strlen(prev) +
                strlen(curr) * repeat +
                1;

            char *temp = calloc(needed, 1);

            strcat(temp, prev);

            for (int j = 0; j < repeat; j++) {
                strcat(temp, curr);
            }

            free(prev);
            free(curr);

            curr = temp;
        }

        else {
            int len = strlen(curr);
            curr[len] = ch;
            curr[len + 1] = '\0';
        }
    }

    return curr;
}

int main() {
    char s[] = "3[a2[c]]";

    char *ans = decodeString(s);

    printf("%s\n", ans);

    free(ans);

    return 0;
}
