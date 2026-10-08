#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int cont = 0;

    if (n == 0) {
        cont = 1;
    } else {
        if (n < 0) {
            n = n * (-1);
        }
        
        while (n > 0) {
            n = n / 10;
            cont++;
        }
    }
    
    printf("%d\n", cont);

    return 0;
}