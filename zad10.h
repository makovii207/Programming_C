#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GET_MAX(array, count, output) do {       \
if (count > 0) {                             \
output = array[0];                       \
for (int i = 1; i < count; i++) {        \
if (array[i] > output) {             \
output = array[i];               \
}                                    \
}                                        \
}                                            \
} while (0)

#define STR_LEN 2048
static int zad10() {
    char input[STR_LEN];
    double *numbers = NULL;
    int n = 0;

    printf("Enter count followed by numbers \n");
    if (fgets(input, STR_LEN, stdin) == NULL) {
        return 1;
    }

    char *token = strtok(input, " \t\n");
    if (token != NULL) {
        n = atoi(token);
    }

    if (n <= 0) {
        printf("Invalid count of elements.\n");
        return 1;
    }

    numbers = (double *)malloc(n * sizeof(double));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int actual_count = 0;
    while (actual_count < n) {
        token = strtok(NULL, " \t\n");
        if (token == NULL) break;

        numbers[actual_count] = atof(token);
        actual_count++;
    }

    if (actual_count > 0) {
        double max_val;

        GET_MAX(numbers, actual_count, max_val);

        printf("Maximum value: %.2f\n", max_val);
    } else {
        printf("No numbers found after the count.\n");
    }

    free(numbers);
    return 0;
}