#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

static bool canConstruct(char* r, char* m) {
    int hm[150] = {0};
    int hr[150] = {0};

    for (size_t i = 0; i < strlen(m); i++) {
        hm[(unsigned char)m[i]] += 1;
    }

    for (size_t i = 0; i < strlen(r); i++) {
        hr[(unsigned char)r[i]] += 1;
    }

    for (int i = 0; i < strlen(r); i++) {
        if (hm[(unsigned char)r[i]] < hr[(unsigned char)r[i]]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char r[] = "fihjjjjei";
    char m[] = "hjibagacbhadfaefdjaeaebgi";
    assert(false == canConstruct(r, m));
    return 0;
}
