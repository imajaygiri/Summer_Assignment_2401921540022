#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    char* ans = s;
    int len = 1;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        int l = i;
        int r = i;

        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > len) {
                len = r - l + 1;
                ans = s + l;
            }
            l--;
            r++;
        }

        l = i;
        r = i + 1;

        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > len) {
                len = r - l + 1;
                ans = s + l;
            }
            l--;
            r++;
        }
    }

    char* ret = malloc(len + 1);

    memcpy(ret, ans, len);
    ret[len] = '\0';

    return ret;
}
