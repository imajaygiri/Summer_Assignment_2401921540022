#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int* findAnagrams(char* s, char* p, int* returnSize) {
//     int slen = strlen(s);
//     int plen = strlen(p);
//     int* ans = malloc(sizeof(int) * slen);
//
//     if (plen > slen) {
//         *returnSize = 0;
//         return ans;
//     }
//
//     int hashedP[26] = {0};
//     int hashedS[26] = {0};
//
//     for (int i = 0; p[i] != '\0'; i++) {
//         hashedP[(unsigned char)p[i] - 'a'] += 1;
//     }
//     for (int i = 0; s[i] != '\0'; i++) {
//         hashedP[(unsigned char)s[i] - 'a'] += 1;
//     }
//
//     int first = 0;
//     int last = first + plen - 1;
//     int ansIndex = 0;
//
//     while (last < slen) {
//         printf("Window: \n");
//         for (int i = first; i < first + plen; i++) {
//             printf("%c", s[i]);
//         }
//         printf("\n");
//
//         int* hashedWindowS = hash_str(s + first, plen);
//         bool cmpResult = cmp_hashed(hashedWindowS, hashedP);
//         if (cmpResult) {
//             ans[ansIndex++] = first;
//         }
//
//         free(hashedWindowS);
//         first++;
//         last++;
//     }
//
//     *returnSize = ansIndex;
//     return ans;
// }

int* hash_str(char* s, int len) {
    int* hashed = malloc(sizeof(int) * 26);
    memset(hashed, 0, sizeof(int) * 26);
    for (int i = 0; i < len; i++) {
        hashed[(unsigned char)s[i] - 'a'] += 1;
    }
    return hashed;
}
//
bool cmp_hashed(int* hash1, int* hash2) {
    for (int i = 0; i < 26; i++) {
        if (hash1[i] != hash2[i]) {
            return false;
        }
    }
    return true;
}

int* findAnagrams(char* s, char* p, int* returnSize) {
    int slen = strlen(s);
    int plen = strlen(p);

    int* ans = malloc(sizeof(int) * slen);

    if (plen > slen) {
        *returnSize = 0;
        return ans;
    }

    int hashP[26] = {0};
    int hashWindow[26] = {0};

    for (int i = 0; i < plen; i++) {
        hashP[p[i] - 'a']++;
    }

    for (int i = 0; i < plen; i++) {
        hashWindow[s[i] - 'a']++;
    }

    int first = 0;
    int last = plen - 1;
    int ansIndex = 0;

    while (last < slen) {
        if (cmp_hashed(hashWindow, hashP)) {
            ans[ansIndex++] = first;
        }

        if (last + 1 < slen) {
            hashWindow[s[first] - 'a']--;
            hashWindow[s[last + 1] - 'a']++;
        }

        first++;
        last++;
    }

    *returnSize = ansIndex;
    return ans;
}

int main(void) {
    // char* s = "cbaebabacd";
    // char* p = "abc";

    // char* s = "abab";
    // char* p = "ab";

    char* s = "aa";
    char* p = "bb";
    int returnSize = 0;
    int* ans = findAnagrams(s, p, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    free(ans);

    return 0;
}
