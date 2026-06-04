#include <stdlib.h>
int** matrixReshape(int** mat,
                    int matSize,
                    int* matColSize,
                    int r,
                    int c,
                    int* returnSize,
                    int** returnColumnSizes) {

    int rows = matSize;
    int cols = matColSize[0];

    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** ans = malloc(r * sizeof(int*));
    *returnColumnSizes = malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        ans[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    int pos = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ans[pos / c][pos % c] = mat[i][j];
            pos++;
        }
    }

    *returnSize = r;
    return ans;
}
