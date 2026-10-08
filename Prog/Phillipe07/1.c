#include <stdio.h>

int main() {

    int x;
    int* p = &x;

    x = 10;

    printf("%d", *p);

    return 0;
}