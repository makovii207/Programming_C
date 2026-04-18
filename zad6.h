#pragma once
#include <stdio.h>

static int zad6() {
    FILE *fin = fopen("people.txt", "r");
    FILE *fout = fopen("filtered_people.txt", "w");

    char f[50], i[50], o[50];
    int year;

    if (f_in == NULL) return 1;

    while (fscanf(fin, "%s %s %s %d", f, i, o, &year) != EOF) {
        if (year > 1980) {
            fprintf(fout, "%s %s %s %d\n", f, i, o, year);
        }
    }

    // Закрываем файлы
    fclose(fin);
    fclose(fout);

    return 0;
}
