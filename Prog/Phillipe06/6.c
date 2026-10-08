#include <stdio.h>

int main() {

    int v[25];
    int aux;

    for (int i = 0; i < 25; i++){
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < (25/2); i++){
        aux = v[i];
        v[i] = v[24-i];
        v[24-i] = aux;
        
    }

    return 0;
}