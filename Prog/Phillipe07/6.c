#include <stdio.h>
#include <stdlib.h>

int main() {

    float *y = malloc(sizeof(float));
    *y = 3.14;
    float **x = &y;
    free(y);

    return 0;
}