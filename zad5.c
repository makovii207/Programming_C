#include <stdlib.h>

double** calculate(double** A, double** B, int n, char op) {
    double** R = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        R[i] = (double*)malloc(n * sizeof(double));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (op == '+') {
                R[i][j] = A[i][j] + B[i][j];
            } else if (op == '-') {
                R[i][j] = A[i][j] - B[i][j];
            } else if (op == '*') {
                R[i][j] = 0;
                for (int k = 0; k < n; k++) R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return R;
}