#pragma once
#include <stdio.h>
#include <string.h>

int count_long_bits(long num) {
    int count = 0;
    unsigned long u_num = (unsigned long)num;

    while (u_num > 0) {
        if (u_num & 1) {
            count++;
        }
        u_num >>= 1;
    }
    return count;
}

int count_double_bits(double num) {
    int count = 0;
    unsigned char bytes[sizeof(double)];

    memcpy(bytes, &num, sizeof(double));

    for (size_t i = 0; i < sizeof(double); i++) {
        unsigned char b = bytes[i];
        while (b > 0) {
            if (b & 1) {
                count++;
            }
            b >>= 1;
        }
    }
    return count;
}

static int zad16() {
    long long_val;
    double double_val;

    printf("Enter a long integer value: ");
    if (scanf("%ld", &long_val) != 1) {
        printf("Invalid input for long.\n");
        return 1;
    }

    printf("Enter a double value: ");
    if (scanf("%lf", &double_val) != 1) {
        printf("Invalid input for double.\n");
        return 1;
    }

    int long_ones = count_long_bits(long_val);
    int double_ones = count_double_bits(double_val);

    printf("\n=== Results ===\n");
    printf("Long value: %ld\n", long_val);
    printf("Number of 1-bits in long: %d (out of %zu bits)\n\n", long_ones, sizeof(long) * 8);

    printf("Double value: %le\n", double_val);
    printf("Number of 1-bits in double: %d (out of %zu bits)\n", double_ones, sizeof(double) * 8);

    return 0;
}