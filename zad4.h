#pragma once
#include <stdio.h>
#include "lab4triug.h"
static int zad4() {
    double a, b, c;
    printf("side a: ");
    if(scanf("%lf", &a) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }
    printf("Side b: ");
    if(scanf("%lf", &b) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }
    printf("Side c: ");
    if(scanf("%lf", &c) != 1) {
        printf("Error: Invalid input!\n");
        return 1;
    }
    if(!is_valid_triangle(a, b, c)) {
        printf("\nError: Invalid triangle!\n");
        printf("The triangle inequality is not satisfied or sides are not positive.\n");
        return 1;
    }

    double p = perimeter(a, b, c);
    double s = area(a, b, c);
    printf("\nResults\n");
    printf("Sides: %.2f, %.2f, %.2f\n", a, b, c);
    printf("Perimeter: %.2f\n", p);
    printf("Area: %.2f\n", s);

    return 0;
}