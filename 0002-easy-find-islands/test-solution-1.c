#include <stdio.h>
#include <solution.h>

int main(int argc, char *argv[])
{
    int islands;
    int matrix1[][5] = {{1, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0},
                        {1, 0, 1, 0, 1}};
    int matrix2[][1] = {{0}};
    int matrix3[][1] = {{1}};
    int matrix4[][2] = {{0, 1},
                        {1, 0}};
    int matrix5[][2] = {{0, 1},
                        {1, 1}};

    islands = count_islands(&matrix1[0][0], 5, 5);

    if (6 != islands) {
        fprintf(stderr, "6 != %d\n", islands);
        return -1;
    }

    islands = count_islands(&matrix2[0][0], 1, 1);

    if (0 != islands) {
        fprintf(stderr, "0 != %d\n", islands);
        return -1;
    }

    islands = count_islands(&matrix3[0][0], 1, 1);

    if (1 != islands) {
        fprintf(stderr, "1 != %d\n", islands);
        return -1;
    }

    islands = count_islands(&matrix4[0][0], 2, 2);

    if (2 != islands) {
        fprintf(stderr, "2 != %d\n", islands);
        return -1;
    }

    islands = count_islands(&matrix5[0][0], 2, 2);

    if (1 != islands) {
        fprintf(stderr, "1 != %d\n", islands);
        return -1;
    }

    return 0;
}
