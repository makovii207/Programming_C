#pragma once
#include <stdio.h>
static void zad2() {
    double matrix3x3[3][3];
    double sum_main_diag = 0, sum_secondary_diag = 0;
    printf("elements of 3x3:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%lf", &matrix3x3[i][j]);
        }
    }
    for(int i = 0; i < 3; i++) {
        sum_main_diag += matrix3x3[i][i];
        sum_secondary_diag += matrix3x3[i][2 - i];
    }
    printf("\nsum main diagonal: %.2lf\n", sum_main_diag);
    printf("sum secondary diagonal: %.2lf\n\n", sum_secondary_diag);
    int matrix2x2[2][2];
    int result[2][2];
    printf("elements of 2x2 matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix2x2[i][j]);
        }
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                result[i][j] += matrix2x2[i][k] * matrix2x2[k][j];
            }
        }
    }
    printf("\nSquare of 2x2 matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}