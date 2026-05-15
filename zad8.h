#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX_PEOPLE 100
#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    int birthYear;
    char gender[10];
    float height;
} Person;

int priorities[4];
int priorityCount = 0;

int compare(const void* a, const void* b) {
    Person* p1 = (Person*)a;
    Person* p2 = (Person*)b;

    for (int i = 0; i < priorityCount; i++) {
        int result = 0;
        switch (priorities[i]) {
            case 1:
                result = p1->birthYear - p2->birthYear;
                break;
            case 2: // Name
                result = strcmp(p1->name, p2->name);
                break;
            case 3: // Gender
                result = strcmp(p1->gender, p2->gender);
                break;
            case 4: // Height
                if (p1->height < p2->height) result = -1;
                else if (p1->height > p2->height) result = 1;
                break;
        }
        if (result != 0) return result;
    }
    return 0;
}

static int zad8() {
    FILE* file = fopen("people.txt", "r");
    if (!file) {
        printf("Error: Could not open people.txt\n");
        return 1;
    }

    Person people[MAX_PEOPLE];
    int count = 0;

    while (count < MAX_PEOPLE && fscanf(file, "%s %d %s %f",
           people[count].name, &people[count].birthYear,
           people[count].gender, &people[count].height) != EOF) {
        count++;
    }
    fclose(file);

    printf("Select sorting fields in order of priority (e.g., '1 4 0'):\n");
    printf("1: Year, 2: Name, 3: Gender, 4: Height (0 to finish)\n");

    int choice;
    while (priorityCount < 4) {
        if (scanf("%d", &choice) != 1 || choice == 0) break;
        priorities[priorityCount++] = choice;
    }

    qsort(people, count, sizeof(Person), compare);

    printf("\n%-20s | %-5s | %-6s | %-5s\n", "Name", "Year", "Gender", "Height");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s | %-5d | %-6s | %-5.2f\n",
               people[i].name, people[i].birthYear, people[i].gender, people[i].height);
    }

    return 0;
}