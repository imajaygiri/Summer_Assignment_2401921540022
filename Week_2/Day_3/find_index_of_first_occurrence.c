#include <assert.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
    int haylen = strlen(haystack);
    int needlen = strlen(needle);

    if (needlen > haylen)
        return -1;

    int nidx = 0;

    for (int i = 0; i <= haylen - needlen; i++) {
        int nidx = 0;
        while (nidx < needlen && haystack[i + nidx] == needle[nidx]) {
            nidx++;
        }

        if (nidx == needlen) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    char* haystack = "leetcode";
    char* needle = "tco";
    assert(strStr(haystack, needle) == 3);
}
