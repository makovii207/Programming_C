#include "11stats.h"
#include <stdarg.h>
#include <float.h>

double get_sum(int count, ...) {
    va_list args;
    va_start(args, count);
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum;
}

double get_max(int count, ...) {
    if (count <= 0) return 0;
    va_list args;
    va_start(args, count);
    double max_val = va_arg(args, double); // Initialize with first argument
    for (int i = 1; i < count; i++) {
        double current = va_arg(args, double);
        if (current > max_val) max_val = current;
    }
    va_end(args);
    return max_val;
}

double get_min(int count, ...) {
    if (count <= 0) return 0;
    va_list args;
    va_start(args, count);
    double min_val = va_arg(args, double); // Initialize with first argument
    for (int i = 1; i < count; i++) {
        double current = va_arg(args, double);
        if (current < min_val) min_val = current;
    }
    va_end(args);
    return min_val;
}

double get_average(int count, ...) {
    if (count <= 0) return 0;
    va_list args;
    va_start(args, count);
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, double);
    }
    va_end(args);
    return sum / count;
}