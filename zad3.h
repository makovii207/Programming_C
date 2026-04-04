#pragma once
#include <stdio.h>
#include <string.h>
static void zad3() {
    char str[81];
    int i;

    printf("Enter a string (max 80 characters):\n");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'a') {
            str[i] = 'A';
        }
        else if(str[i] == 'b') {
            str[i] = 'B';
        }
    }
    printf("string:\n%s\n", str);
}
