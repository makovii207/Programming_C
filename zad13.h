#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t keep_running = 1;


void handle_signal(int sig) {
    switch (sig) {
        case SIGABRT:
            printf("\n[LOG] Caught SIGABRT (Abort signal)\n");
            break;
        case SIGFPE:
            printf("\n[LOG] Caught SIGFPE (Floating-point exception)\n");
            break;
        case SIGILL:
            printf("\n[LOG] Caught SIGILL (Illegal instruction)\n");
            break;
        case SIGINT:
            printf("\n[LOG] Caught SIGINT (Terminal interrupt - Ctrl+C)\n");
            break;
        case SIGSEGV:
            printf("\n[LOG] Caught SIGSEGV (Segmentation fault / Invalid memory access)\n");
            break;
        case SIGTERM:
            printf("\n[LOG] Caught SIGTERM (Termination request)\n");
            keep_running = 0;
            break;
        default:
            printf("\n[LOG] Caught unknown signal: %d\n", sig);
    }

    signal(sig, handle_signal);
}

static int zad13() {

    if (signal(SIGABRT, handle_signal) == SIG_ERR) printf("Error registering SIGABRT\n");
    if (signal(SIGFPE,  handle_signal) == SIG_ERR) printf("Error registering SIGFPE\n");
    if (signal(SIGILL,  handle_signal) == SIG_ERR) printf("Error registering SIGILL\n");
    if (signal(SIGINT,  handle_signal) == SIG_ERR) printf("Error registering SIGINT\n");
    if (signal(SIGSEGV, handle_signal) == SIG_ERR) printf("Error registering SIGSEGV\n");
    if (signal(SIGTERM, handle_signal) == SIG_ERR) printf("Error registering SIGTERM\n");

    printf("Signal Handler Tool Initialized.\n");
    printf("You can also press Ctrl+C in the console to trigger SIGINT naturally.\n\n");

    int choice;
    while (keep_running) {
        printf("=== Select a signal to raise ===\n");
        printf("1: SIGABRT\n");
        printf("2: SIGFPE\n");
        printf("3: SIGILL\n");
        printf("4: SIGINT\n");
        printf("5: SIGSEGV\n");
        printf("6: SIGTERM\n");
        printf("0: Exit Program\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1: raise(SIGABRT); break;
            case 2: raise(SIGFPE);  break;
            case 3: raise(SIGILL);  break;
            case 4: raise(SIGINT);  break;
            case 5: raise(SIGSEGV); break;
            case 6: raise(SIGTERM); break;
            default:
                printf("Unknown option. Please try again.\n\n");
        }
        printf("\n");
    }

    printf("Program exited cleanly.\n");
    return 0;
}