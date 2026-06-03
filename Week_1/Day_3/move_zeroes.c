#include <assert.h>
#include <string.h>

void moveZeroes(int* nums, int numsSize) {
    int w = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            // copy to first
            nums[w++] = nums[i];
        }
    }
    while (w < numsSize) {
        nums[w++] = 0;
    }
}

int main() {

    struct {
        int* args;
        size_t args_len;
        int* exp;
        size_t exp_len;
    } test[] = {
        {.args = (int[]){0, 1, 0, 3, 12},
         .args_len = 5,

         .exp = (int[]){1, 3, 12, 0, 0},
         .exp_len = 5},
        {.args = (int[]){0}, .args_len = 1, .exp = (int[]){0}, .exp_len = 1}};

    for (int i = 0; i < 1; i++) {
        moveZeroes(test[i].args, test[i].args_len);
        assert(memcmp(test[i].args,
                      test[i].exp,
                      sizeof(int) * test[i].exp_len) == 0);
    }
}
