#include <stdio.h>
#include <math.h>

void func(float w, float *x, float *y) {
    *x = w * w;
    *y = sqrt(w);
}