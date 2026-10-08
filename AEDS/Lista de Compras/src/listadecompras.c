#include <stdio.h>
#include <string.h>
#include "listadecompras.h"

int set_listacompras(ListaCompras *ponteiro, int id, double preco, char nome[50]) {
    ponteiro->id = id;
    ponteiro->preco = preco;
    strcpy(ponteiro->nome, nome);
    return 0;
}
int get_id(ListaCompras *ponteiro){
    return ponteiro->id;
}
int get_preco(ListaCompras *ponteiro){
    return ponteiro->preco;
}
void get_nome(ListaCompras *ponteiro, char destino[50]){
    strcpy(destino, ponteiro->nome);
}