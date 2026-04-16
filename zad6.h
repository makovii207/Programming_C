#pragma once
#include <stdio.h>

static int zad6() {
    FILE *f_in = fopen("people.txt", "r");
    FILE *f_out = fopen("filtered_people.txt", "w");

    char f[50], i[50], o[50];
    int year;

    if (f_in == NULL) return 1;

    while (fscanf(f_in, "%s %s %s %d", f, i, o, &year) != EOF) {
        if (year > 1980) {
            fprintf(f_out, "%s %s %s %d\n", f, i, o, year);
        }
    }

    // Закрываем файлы
    fclose(f_in);
    fclose(f_out);

    return 0;
}
