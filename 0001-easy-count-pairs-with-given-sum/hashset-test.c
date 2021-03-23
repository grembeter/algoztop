#include <stdio.h>
#include <hashset.h>

int main(int argc, char *argv[])
{
    struct pair *pair;
    int sum;
    int arr1[] = {6, 3, 5, 2, 1, 7};
    int arr2[] = {60, 30, 50, 20, 10, 70};

    sum = 4;
    pair = find_2sum(sum, arr1, sizeof(arr1)/sizeof(arr1[0]));

    if (pair->x + pair->y != sum) {
        fprintf(stderr, "%d + %d != %d\n", pair->x, pair->y, sum);
        return 1;
    }

    sum = 40;
    pair = find_2sum(sum, arr2, sizeof(arr2)/sizeof(arr2[0]));

    if (pair->x + pair->y != sum) {
        fprintf(stderr, "%d + %d != %d\n", pair->x, pair->y, sum);
        return 1;
    }

    return 0;
}
