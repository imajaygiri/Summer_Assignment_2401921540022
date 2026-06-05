#include <stdlib.h>
int* spiralOrder(int** matrix,
                 int matrixSize,
                 int* matrixColSize,
                 int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int row = matrixSize;
    int col = matrixColSize[0];

    *returnSize = row * col;
    int* ans = malloc(sizeof(int) * (*returnSize));

    int idx = 0;

    int srow = 0;
    int erow = row - 1;
    int scol = 0;
    int ecol = col - 1;

    while (srow <= erow && scol <= ecol) {

        for (int j = scol; j <= ecol; j++) {
            ans[idx++] = matrix[srow][j];
        }
        srow++;
        if (srow > erow)
            break;

        for (int i = srow; i <= erow; i++) {
            ans[idx++] = matrix[i][ecol];
        }
        ecol--;
        if (scol > ecol)
            break;

        for (int j = ecol; j >= scol; j--) {
            ans[idx++] = matrix[erow][j];
        }
        erow--;

        for (int i = erow; i >= srow; i--) {
            ans[idx++] = matrix[i][scol];
        }
        scol++;
    }

    return ans;
}
