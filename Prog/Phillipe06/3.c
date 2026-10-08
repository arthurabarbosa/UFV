#include <stdio.h>

int main() {

    int mes;
    scanf("%d", &mes);
    switch(mes) {
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Março");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        default:
        printf("Mês inválido");
    }
    
    return 0;
}