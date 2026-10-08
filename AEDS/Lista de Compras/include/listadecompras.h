#ifndef LISTADECOMPRAS_H
#define LISTADECOMPRAS_H

typedef struct {
    int id;
    double preco;
    char nome[50];
} ListaCompras;

int set_listacompras(ListaCompras *ponteiro, int id, double preco, char nome[50]);
int get_id(ListaCompras *ponteiro);
int get_preco(ListaCompras *ponteiro);
void get_nome(ListaCompras *ponteiro);

#endif