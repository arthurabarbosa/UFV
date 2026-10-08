#include <stdio.h>

void func(char **v, char c) {
    char *string = *v;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == c) {
            string[i] = ' ';
        }
    }
}