#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helper(size_t n,
            size_t open,
            size_t close,
            char** ans,
            size_t* idx,
            char* string,
            size_t i) {
    if (open > n || close > n)
        return;
    if (close > open)
        return;

    if (i == 2 * n) {
        string[i] = '\0';
        ans[(*idx)++] = strdup(string);
        return;
    }

    string[i] = '(';
    helper(n, open + 1, close, ans, idx, string, i + 1);
    string[i] = ')';
    helper(n, open, close + 1, ans, idx, string, i + 1);
}

char** generateParenthesis(int n, int* returnSize) {
    size_t size = 1 << (n * 2);
    char** ans = malloc(size * sizeof(char*));
    size_t idx = 0;
    char* string = calloc(2 * n + 1, sizeof(char));
    helper(n, 0, 0, ans, &idx, string, 0);
    free(string);
    *returnSize = idx;
    return ans;
}
int main(void) {
    int returnSize = 0;
    int n = 3;
    char** ans = generateParenthesis(n, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        puts(ans[i]);
        free(ans[i]);
    }
    printf("number: %d", returnSize);
    free(ans);
    return 0;
}
