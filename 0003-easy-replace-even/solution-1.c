#include <stdio.h>
#include <stdlib.h>
#include <solution.h>

void replace_even(int *buf, size_t ninput, size_t ntotal)
{
    int *in;
    int *out;

    if (!ninput || !ntotal || !buf) {
        return;
    }

    in = &buf[ninput - 1];
    out = &buf[ntotal - 1];

    while (in >= buf) {
        if (*in & 1) {
            *out-- = *in--;
        } else {
            *out-- = *in;
            *out-- = *in--;
        }
    }
}
