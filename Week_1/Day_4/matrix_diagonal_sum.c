#include <assert.h>
#include <stdlib.h>

int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    for (int i = 0; i < matSize; i++) {
        // primary diagonal
        sum += mat[i][i];
        sum += mat[i][matSize - 1 - i];
    }

    if ((1 & matSize) == 1) {
        // vevn
        int mid = matSize / 2;
        sum -= mat[mid][mid];
    }
    return sum;
}

int main(void) {

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rowSize = 3;
    int colSize = 3;
    int** mat = (int**)malloc(rowSize * sizeof(int*));

    for (int i = 0; i < rowSize; i++) {
        mat[i] = (int*)matrix[i];
    }

    assert(25 == diagonalSum((int**)mat, rowSize, &colSize));
    return 0;
}
