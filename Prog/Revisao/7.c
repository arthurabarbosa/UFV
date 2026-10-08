#include <stdio.h>

int pot(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int calc = a*pot(a, b-1);

    return calc;
}

int main() {

    int A = 2;
    int B = 10;

    int res = pot(A, B);

    printf("%d", res);

    return 0;
}