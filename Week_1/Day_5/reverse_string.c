#include <assert.h>
#include <string.h>
void reverseString(char* s, int sSize) {
    int right = sSize - 1;
    for (int i = 0; i < right; i++) {
        // swap left with right
        char temp = s[i];
        s[i] = s[right];
        s[right--] = temp;
    }
}

int main(void) {
    char str[] = {'h', 'e', 'l', 'l', 'o'};
    reverseString(str, sizeof(str) / sizeof(str[0]));
    assert((memcmp(str,
                   (char[]){'o', 'l', 'l', 'e', 'h'},
                   sizeof(str))) == 0);
}
