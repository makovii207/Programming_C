#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *DAYS[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char *MONTHS[] = {"January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December"};
int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int get_day_of_week(int y, int m, int d) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y -= 1;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void print_month(int y, int m) {
    printf("\n  ------------ %s %d ------------\n", MONTHS[m-1], y);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int days = DAYS_IN_MONTH[m-1];
    if (m == 2 && is_leap(y)) days = 29;

    int start_day = get_day_of_week(y, m, 1);

    for (int i = 0; i < start_day; i++) printf("     ");

    for (int d = 1; d <= days; d++) {
        printf("%5d", d);
        if ((d + start_day) % 7 == 0) printf("\n");
    }
    printf("\n");
}

static int zad12() {
    char input[20];
    printf("Enter date (yyyy.mm.dd, yyyy.mm, yyyy, or 'now'): ");
    scanf("%s", input);

    if (strcmp(input, "now") == 0) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Current date: %04d.%02d.%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
        printf("Day of the week: %s\n", DAYS[tm.tm_wday]);
    }
    else {
        int y, m, d;
        int parsed = sscanf(input, "%d.%d.%d", &y, &m, &d);

        if (parsed == 3) {
            if (m < 1 || m > 12 || d < 1 || d > 31) {
                printf("Invalid date format.\n");
            } else {
                int dw = get_day_of_week(y, m, d);
                printf("Result: %s\n", DAYS[dw]);
            }
        }
        else if (parsed == 2) {
            if (m < 1 || m > 12) printf("Invalid month.\n");
            else print_month(y, m);
        }
        else if (parsed == 1) {
            printf("\n======= YEAR %d =======\n", y);
            for (int i = 1; i <= 12; i++) {
                print_month(y, i);
            }
        }
        else {
            printf("Unknown format.\n");
        }
    }

    return 0;
}