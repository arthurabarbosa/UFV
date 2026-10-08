#include <stdio.h>
#include <string.h>
#include "bdsaviao.h"

int setaviao (aviao *ptr, int identificacao, char name[20], double efc) {
    ptr->id = identificacao;
    strcpy(ptr->nome, name);
    ptr->eficiencia = efc;

    return 0;
}

int get_id (aviao *ptr) {
    return ptr->id;
}
void get_nome (aviao *ptr, char name[20]) {
    strcpy(name, ptr->nome);
}
double get_efc (aviao *ptr) {
    return ptr->eficiencia;
}
