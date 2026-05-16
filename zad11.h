#pragma once
#include <stdio.h>
#include "11stats.h"

static int zad11() {
    double s = get_sum(4, 67.0, 42.0, 52.0, 228.0);
    double mx = get_max(4, 67.0, 42.0, 52.0, 228.0);
    double mn = get_min(4, 67.0, 42.0, 52.0, 228.0);
    double avg = get_average(4, 67.0, 42.0, 52.0, 228.0);

    printf("Sum: %.2f\n", s);
    printf("Max: %.2f\n", mx);
    printf("Min: %.2f\n", mn);
    printf("Average: %.2f\n", avg);

    return 0;
}