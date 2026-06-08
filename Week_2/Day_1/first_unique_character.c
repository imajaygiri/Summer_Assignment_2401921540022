#include <assert.h>
#include <stddef.h>
#include <string.h>
int firstUniqChar(char* s) {
    int hash[150] = {0};

    int len = strlen(s);
    for (size_t i = 0; i < len; i++) {
        hash[(unsigned char)s[i]] += 1;
    }

    for (size_t i = 0; i < len; i++) {
        if (hash[(unsigned char)s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char* s = "loveleetcode";
    assert(firstUniqChar(s) == 2);
    return 0;
}
