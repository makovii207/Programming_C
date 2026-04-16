#pragma once
#include <stdio.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};
static int zad7(){
    int n;

    printf("number of people: ");
    scanf("%d", &n);

    struct humen a[n];
    struct humen b[n];
    struct humen temp;

    printf("FIY:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        scanf("%s %s %d", a[i].name, a[i].surname, &a[i].year);
        b[i] = a[i];
    }

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