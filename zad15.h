#pragma once
#include <stdio.h>

void print_normal(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    print_normal(n / 10);
    printf("%d ", n % 10);
}

void print_reverse(int n) {
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    printf("%d ", n % 10);
    print_reverse(n / 10);
}

static int zad15() {
    int n;

    printf("Enter a natural number N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printf("Normal order: ");
    print_normal(n);
    printf("\n");

    printf("Reverse order: ");
    print_reverse(n);
    printf("\n");

    return 0;
}