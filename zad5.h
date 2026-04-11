#pragma once
#include <stdio.h>
#include <stdlib.h>
double** calculate(double** A, double** B, int n, char op);

void free_matrix(double **matrix, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
}

static int zad5() {
    int n;
    char op;

    printf("n: ");
    scanf("%d", &n);
    double** A = (double**)malloc(n * sizeof(double*));
    double** B = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
        B[i] = (double*)malloc(n * sizeof(double));
    }

    printf("elements A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%lf", &A[i][j]);

    printf("elements B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%lf", &B[i][j]);

    printf("oper (+, -, *): ");
    scanf(" %c", &op);

    double** R = calculate(A, B, n, op);

    printf("\nResult:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%8.2lf ", R[i][j]);
        printf("\n");
    }

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(A, n);

    return 0;
}