#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define Max(a, b) ((a) > (b)) ? (a) : (b)
#define Min(a, b) ((a) < (b)) ? (a) : (b)

// int maxArea(int* height, int heightSize) {
//     int maxWater = 0;
//     for (int i = 0; i < heightSize; i++) {
//         int leftHeight = height[i];
//         for (int j = 0; j < heightSize; j++) {
//             int rightHeight = height[j];
//             int currWater = Min(leftHeight, rightHeight) * abs(j - i);
//             printf("currWater: %d\n", currWater);
//             maxWater = Max(maxWater, currWater);
//         }
//     }
//     return maxWater;
// }

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxWater = 0;

    while (left < right) {
        int minHeight =
            (height[left] < height[right]) ? height[left] : height[right];

        int currWater = minHeight * (right - left);

        if (currWater > maxWater)
            maxWater = currWater;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main(void) {

    assert(49 == maxArea((int[]){1, 8, 6, 2, 5, 4, 8, 3, 7}, 9));

    assert(1 == maxArea((int[]){1, 1}, 2));
}
