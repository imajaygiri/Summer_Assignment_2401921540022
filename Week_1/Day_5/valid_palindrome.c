#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define Test(args_, exp)                                             \
    ((test_t){.args = (args_),                                       \
              .args_len = strlen((args_)),                           \
              .expected = (exp)})

#define bool unsigned char
#define true 1
#define false 0

static bool isAlphaNum(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9');
}

static bool isPalindrome(char* s) {
    size_t len = strlen(s);
    size_t prev = 0;
    for (size_t i = 0; i < len; i++) {
        if (isAlphaNum(s[i])) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                // uppercase make it lowercase
                s[prev++] = (char)(s[i] + 32);
            } else {
                s[prev++] = s[i];
            }
        }
    }

    int right = prev - 1;
    for (int i = 0; i < right; i++) {
        if (s[i] != s[right]) {
            return false;
        }
        right--;
    }

    return true;
}

typedef struct {
    char* args;
    size_t args_len;
    bool expected;
} test_t;

int main(void) {

    test_t tests[] = {Test("A man, a plan, a canal: Panama", true),
                      Test("race a car", false),
                      Test(" ", true)};

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        char* buf = strdup(tests[i].args);
        bool got = isPalindrome(buf);
        assert(got == tests[i].expected);
        free(buf);
    }
    return 0;
}
