#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    // if s is subseq of t return true
    int slen = strlen(s);
    int tlen = strlen(t);

    if (slen == 0)
        return true;
    if (slen > tlen || tlen == 0) {
        return false;
    }

    int sidx = 0;
    int tidx = 0;

    for (int i = 0; i < tlen; i++) {
        // if both matches moves tidx++ sidx++
        // if not matches move tidx only

        if (s[sidx] == t[i]) {
            sidx++;
        }
        if (sidx == slen) {
            return true;
        }
    }
    return false;
}

int main(void) {
    // char *s = "abc", *t = "ahbgdc";

    char *s = "axc", *t = "ahbgdc";
    bool res = isSubsequence(s, t);
    printf("res: %d", res);
}
