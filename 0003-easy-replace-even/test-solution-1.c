#include <stdio.h>
#include <solution.h>

#define ARRAY_COUNT(x) (sizeof(x)/sizeof(x[0]))

static void print_buf(int *buf, size_t ntotal)
{
    size_t i;

    for (i = 0; i < ntotal; ++i) {
        printf("%d ", buf[i]);
    }
    printf("\n");
}

static int check_buf(int *buf, size_t ninput, size_t ntotal)
{
    size_t i;

    printf("before: ");
    print_buf(buf, ntotal);

    replace_even(buf, ninput, ntotal);

    printf("after:  ");
    print_buf(buf, ntotal);

    for (i = 0; i < ntotal; ++i) {
        if ((buf[i] & 1) == 0) {
            if ((i + 1) == ntotal) {
                return 1;
            }
            if (buf[i] != buf[i+1]) {
                printf("%lu: %d != %d\n", i, buf[i], buf[i+1]);
                return 1;
            }
            ++i;
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int buf1[] = {1,2,5,6,8,-1,-1,-1};
    int buf2[] = {1,5,7,13,15,9};
    int buf3[] = {2,4,6,10,-1,-1,-1,-1};
    int buf4[] = {22,-1};
    int buf5[] = {21};
    int buf6[] = {22};

    if (check_buf(buf1, 5, ARRAY_COUNT(buf1))) {
        fprintf(stderr, "buf1 failed\n");
        return 1;
    }

    if (check_buf(buf2, 6, ARRAY_COUNT(buf2))) {
        fprintf(stderr, "buf2 failed\n");
        return 1;
    }

    if (check_buf(buf3, 4, ARRAY_COUNT(buf3))) {
        fprintf(stderr, "buf3 failed\n");
        return 1;
    }

    if (check_buf(buf4, 1, ARRAY_COUNT(buf4))) {
        fprintf(stderr, "buf4 failed\n");
        return 1;
    }

    if (check_buf(buf5, 1, ARRAY_COUNT(buf5))) {
        fprintf(stderr, "buf5 failed\n");
        return 1;
    }

    if (!check_buf(buf6, 1, ARRAY_COUNT(buf6))) {
        fprintf(stderr, "buf6 failed\n");
        return 1;
    }

    return 0;
}
