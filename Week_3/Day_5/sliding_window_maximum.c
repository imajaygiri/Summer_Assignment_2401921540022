#include <stdlib.h>

int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize) {
    *returnSize = numsSize - k + 1;

    int *result = malloc((*returnSize) * sizeof(int));
    int resultPos = 0;

    int windowDeque[k];
    int left = 0, right = 0;

    for (int i = 0; i < numsSize; i++) {

        if (left < right && windowDeque[left % k] <= i - k) {
            left++;
        }

        while (left < right &&
               nums[windowDeque[(right - 1) % k]] <= nums[i]) {
            right--;
        }

        windowDeque[(right++) % k] = i;

        if (i >= k - 1) {
            result[resultPos++] = nums[windowDeque[left % k]];
        }
    }

    return result;
}
