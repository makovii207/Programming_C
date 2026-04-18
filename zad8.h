#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int year;
    char gender[10];
    float height;
} Person;

int sort_order[4];
int sort_count = 0;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;

    for (int i = 0; i < sort_count; i++) {
        int res = 0;
        switch (sort_order[i]) {
            case 1: res = p1->year - p2->year; break;
            case 2: res = strcmp(p1->name, p2->name); break;
            case 3: res = strcmp(p1->gender, p2->gender); break;
            case 4: if (p1->height < p2->height) res = -1;
            else if (p1->height > p2->height) res = 1; break;
        }
        if (res != 0) return res;
    }
    return 0;
}

static int zad8() {
    FILE *f = fopen("data.txt", "w");
    fprintf(f, "Ivan_Ivanov 1990 male 1.85\nAnna_Sidorova 1995 female 1.70\n");
    fprintf(f, "Petr_Petrov 1990 male 1.75\nElena_Kozlova 1995 female 1.65\n");
    fclose(f);

    Person people[10];
    int n = 0;
    f = fopen("data.txt", "r");
    while (fscanf(f, "%s %d %s %f", people[n].name, &people[n].year, people[n].gender, &people[n].height) != EOF) {
        n++;
    }
    fclose(f);

    printf("Sort by: 1-Year, 2-Name, 3-Gender, 4-Height (e.g. 1 4 0):\n");
    int choice;
    while (scanf("%d", &choice) && choice != 0 && sort_count < 4) {
        sort_order[sort_count++] = choice;
    }

    qsort(people, n, sizeof(Person), compare);

    printf("\nSorted Results:\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s | %d | %-7s | %.2f m\n",
               people[i].name, people[i].year, people[i].gender, people[i].height);
    }
    return 0;
}