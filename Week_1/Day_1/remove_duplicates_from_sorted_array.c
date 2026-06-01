int removeDuplicates(int* nums, int numsSize) {
    int unique = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) continue;
        nums[unique] = nums[i];
        unique++;
    }
    return unique;
}
