#include <stdlib.h>
#include <stdio.h>
#include <solution.h>

static void visit_island(size_t row, size_t col,
                         int *matrix, size_t nrows, size_t ncols)
{
    if (1 != matrix[row*ncols + col]) {
        return;
    }

    matrix[row*ncols + col] = -1;

    if (col+1 < ncols) {
        visit_island(row, col+1, matrix, nrows, ncols);
    }

    if (row+1 < nrows) {
        visit_island(row+1, col, matrix, nrows, ncols);
    }

    if (row > 0) {
        visit_island(row-1, col,   matrix, nrows, ncols);
    }

    if (col > 0) {
        visit_island(row, col-1, matrix, nrows, ncols);
    }
}

int count_islands(int *matrix, size_t nrows, size_t ncols)
{
    int count = 0;
    size_t i = 0;
    size_t j = 0;

    for (i = 0; i < nrows; ++i) {
        for (j = 0; j < ncols; ++j) {
            if (1 == matrix[i*ncols + j]) {
                visit_island(i, j, matrix, nrows, ncols);
                ++count;
            }
        }
    }

    return count;
}
