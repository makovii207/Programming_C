#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void normalize_expression(char* src, char* dest) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '+' || src[i] == '-') {
            dest[j++] = ' ';
            dest[j++] = src[i];
            dest[j++] = ' ';
        } else if (src[i] != '\n' && src[i] != '\r') {
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
}

static int zad9() {
    char input[MAX_LEN];
    char normalized[MAX_LEN * 2];

    printf("Enter expression (e.g., -123.5 + 4 - 456 + 56):\n");
    if (fgets(input, MAX_LEN, stdin) == NULL) {
        return 1;
    }

    normalize_expression(input, normalized);

    char* token = strtok(normalized, " ");
    
    double total = 0.0;
    int current_op = 1;

    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            current_op = 1;
        } 
        else if (strcmp(token, "-") == 0) {
            current_op = -1;
        } 
        else {
            total += current_op * atof(token);
        }

        token = strtok(NULL, " ");
    }

    printf("Result: %.2f\n", total);

    return 0;
}