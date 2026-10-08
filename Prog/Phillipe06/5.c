#include <stdio.h>

int main() {

    int m[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            m[i][j] = (i)*(j);
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}