#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Test(arg1_, arg2_, exp_)                                     \
    (test_t) {                                                       \
        .args1 = arg1_, .len1 = strlen(arg1_), .args2 = arg2_,       \
        .len2 = strlen(arg2_), .exp = (exp_)                         \
    }

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }
    int hash1[150] = {0};
    int hash2[150] = {0};

    for (int i = 0; i < strlen(s); i++) {
        hash1[(unsigned char)s[i]] += 1;
        hash2[(unsigned char)t[i]] += 1;
    }

    for (int i = 0; i < 150; i++) {
        if (hash1[i] != hash2[i])
            return false;
    }
    return true;
}

typedef struct {
    char* args1;
    size_t len1;
    char* args2;
    size_t len2;
    bool exp;
} test_t;

int main(void) {

    test_t t[2] = {Test("anagram", "nagaram", true),
                   Test("car", "rat", false)};

    for (int i = 0; i < sizeof(t) / sizeof(t[0]); i++) {

        bool ans = isAnagram(t[i].args1, t[i].args2);
        if (t[i].exp == ans) {
            fprintf(stdout,
                    "Test Passed Expected: %d \t Result: %d\n",
                    t[i].exp,
                    ans);
        } else {
            fprintf(stderr,
                    "Test Failed!!! Expected: %d \t Result: %d\n",
                    t[i].exp,
                    ans);
            exit(-1);
        }
        // assert(t[i].exp == isAnagram(t[0].args1, t[0].args2));
    }

    return 0;
}
