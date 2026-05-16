#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

unsigned long long final_sum = 0;

void fib_sum_recursive(int target_n, int current_n, unsigned long long a, unsigned long long b, unsigned long long current_sum) {
    if (current_n > target_n) {
        final_sum = current_sum;
        longjmp(env, 1);
    }

    fib_sum_recursive(target_n, current_n + 1, b, a + b, current_sum + a);
}

static int zad14() {
    int n;

    printf("Enter the number of Fibonacci terms (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    if (setjmp(env) == 0) {
        fib_sum_recursive(n, 1, 1, 1, 0);
    }
    else {
        printf("\n[INFO] Non-local jump executed! Stack unwinding bypassed successfully.\n");
        printf("Sum of the first %d Fibonacci numbers: %llu\n", n, final_sum);
    }

    return 0;
}