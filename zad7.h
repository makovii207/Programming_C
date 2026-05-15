#pragma once
#include <stdio.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};
static int zad7(){
    int n;
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error1\n");
        return 1;
    }

    if (fscanf(file, "%d", &n) != 1) {
        printf("Error2\n");
        fclose(file);
        return 1;
    }

    struct humen a[n];
    struct humen b[n];
    struct humen temp;

    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %s %d", a[i].name, a[i].surname, &a[i].year);
        b[i] = a[i];
    }
    fclose(file);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (b[j].year > b[j + 1].year) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d - %s %s\n",b[i].year, b[i].surname, b[i].name);
    }

    return 0;
}