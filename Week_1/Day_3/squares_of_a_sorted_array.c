#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sq(x) ((x) * (x))

static void sort(int* arr, int len) {
    if (!arr) {
        perror("Error arr is null");
        exit(-1);
    }
    for (int i = 1; i < len; i++) {
        int key = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            // swap key and arr[j]
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int* sortedSquares(int* nums, int numsSize) {
    int* ans = (int*)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        ans[i] = sq(nums[i]);
    }

    sort(ans, numsSize);
    return ans;
}

int main() {

    struct {
        int* args;
        size_t args_len;
        int* exp;
        size_t exp_len;
    } test[2] = {{.args = (int[]){-4, -1, 0, 3, 10},
                  .args_len = 5,

                  .exp = (int[]){0, 1, 9, 16, 100},
                  .exp_len = 5},
                 {.args = (int[]){-7, -3, 2, 3, 11},
                  .args_len = 5,
                  .exp = (int[]){4, 9, 9, 49, 121},
                  .exp_len = 5}};

    for (int i = 0; i < 2; i++) {
        int* res = sortedSquares(test[i].args, test[i].args_len);
        assert(memcmp(res, test[i].exp, sizeof(int) * test[i].exp_len) == 0);
    }
}
