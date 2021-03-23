#pragma once

struct pair {
    int x;
    int y;
};

struct pair *find_2sum(int sum, int *arr, size_t nelems);
