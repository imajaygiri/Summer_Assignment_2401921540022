#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);

    for (int l = 1; l <= len / 2; l++) {
        if (len % l)
            continue;

        bool ans = 1;

        for (int i = l; i < len; i++) {
            if (s[i] != s[i % l]) {
                ans = 0;
                break;
            }
        }

        if (ans)
            return true;
    }
    return false;
}
