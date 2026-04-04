#include "lab4triug.h"
#include <math.h>

double perimeter(double a, double b, double c) {
    return a + b + c;
}

double area(double a, double b, double c) {
    double p = perimeter(a, b, c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int is_valid_triangle(double a, double b, double c) {
    if(a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }

    if((a + b > c) && (a + c > b) && (b + c > a)) {
        return 1;
    }

    return 0;
}