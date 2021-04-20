#include <stdio.h>
#include <stdlib.h>
#include <solution.h>

int trap_rain(int *buf, size_t len)
{
    size_t l = 0;
    size_t lmax = 0;
    size_t r;
    size_t rmax = 0;
    int total = 0;

    if (len == 0) {
        return 0;
    }

    r = len - 1;

    while (l < r) {
        if (buf[lmax] < buf[l]) {
            lmax = l;
        }

        if (buf[rmax] < buf[r]) {
            rmax = r;
        }

        if (buf[lmax] < buf[rmax]) {
            total += buf[lmax] - buf[l];
            l += 1;
        } else {
            total += buf[rmax] - buf[r];
            r -= 1;
        }
    }

    return total;
}
