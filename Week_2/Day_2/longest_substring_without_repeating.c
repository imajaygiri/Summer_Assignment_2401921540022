#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);

    int freq[256] = {0};

    int first = 0;
    int ans = 0;

    for (int last = 0; last < len; last++) {

        freq[(unsigned char)s[last]]++;

        while (freq[(unsigned char)s[last]] > 1) {
            freq[(unsigned char)s[first]]--;
            first++;
        }

        int windowSize = last - first + 1;

        if (windowSize > ans) {
            ans = windowSize;
        }
    }

    return ans;
}
