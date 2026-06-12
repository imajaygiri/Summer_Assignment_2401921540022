#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isequal(const int* a, const int* b) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

char*** groupAnagrams(char** strs,
                      int strsSize,
                      int* returnSize,
                      int** returnColumnSizes) {
    char*** groups = malloc(sizeof(char**) * strsSize);

    for (int i = 0; i < strsSize; i++) {
        groups[i] = malloc(sizeof(char*) * strsSize);
    }

    int* colssize = calloc(strsSize, sizeof(int));

    int occ[26];
    int* hash = malloc(sizeof(int[26]) * strsSize);

    int ihash = 0;

    for (int i = 0; i < strsSize; i++) {
        memset(occ, 0, sizeof(occ));

        char* s = strs[i];

        for (int j = 0; s[j]; j++) {
            occ[s[j] - 'a']++;
        }

        int group = -1;

        for (int j = 0; j < ihash; j++) {
            if (isequal(occ, hash + j * 26)) {
                group = j;
                break;
            }
        }

        if (group == -1) {
            memcpy(hash + ihash * 26, occ, sizeof(occ));
            group = ihash++;
        }

        groups[group][colssize[group]++] = s;
    }

    free(hash);

    *returnSize = ihash;
    *returnColumnSizes = colssize;

    return groups;
}
