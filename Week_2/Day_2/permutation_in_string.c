#include <stdbool.h>
#include <string.h>

bool isFreqSame(int freq1[26], int freq2[26]) {
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int size = strlen(s1);

    int freq[26] = {0};

    for (int i = 0; i < size; i++) {
        freq[s1[i] - 'a']++;
    }

    int windSize = size;

    for (int i = 0; i < strlen(s2); i++) {

        int windIdx = 0;
        int idx = i;

        int windFreq[26] = {0};

        while (windIdx < windSize && idx < strlen(s2)) {
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq)) {
            return true;
        }
    }

    return false;
}
