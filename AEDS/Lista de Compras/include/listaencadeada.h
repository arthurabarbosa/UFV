#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "listadecompras.h"

typedef struct Aux{
    ListaCompras Listinha;
    struct Aux* proximo;
} Celula;

typedef Celula* Apontador;

typedef struct {
    Apontador primeiro;
    Apontador ultimo;
} ListaEncadeada;

int inicializar_lista(ListaEncadeada *ponteiro);
int inserir_lista(ListaEncadeada *ponteiro, ListaCompras *lista);
int remover_lista_ultimo(ListaEncadeada *ponteiro, ListaCompras *lista);
int remover_lista_por_id(ListaEncadeada *ponteiro, int id);
ListaCompras* buscar_lista(ListaEncadeada *ponteiro, int id);
int imprimir_lista(ListaEncadeada *ponteiro);

#endif