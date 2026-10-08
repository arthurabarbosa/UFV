#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"

int inicializar_lista(ListaEncadeada *ponteiro) {
    ponteiro->primeiro = (Apontador) malloc(sizeof(Celula));
    ponteiro->ultimo = ponteiro->primeiro;
    ponteiro->primeiro->proximo = NULL;
    return 0;
}
int inserir_lista(ListaEncadeada *ponteiro, ListaCompras *lista){
    ponteiro->ultimo->proximo = (Apontador) malloc(sizeof(Celula));
    ponteiro->ultimo = ponteiro->ultimo->proximo;
    ponteiro->ultimo->Listinha = *lista;
    ponteiro->ultimo->proximo = NULL;
    return 0;
}
int remover_lista_ultimo(ListaEncadeada *ponteiro, ListaCompras *lista) {
    if (ponteiro->primeiro == ponteiro->ultimo) {
        printf("Lista vazia! Nada a ser removido.\n");
        return 0;
    }

    Apontador auxiliar = ponteiro->primeiro;
    while(auxiliar->proximo != ponteiro->ultimo) {
        auxiliar = auxiliar->proximo;
    }

    Apontador alvo_remocao = ponteiro->ultimo;
    
    ponteiro->ultimo = auxiliar;
    ponteiro->ultimo->proximo = NULL;

    free(alvo_remocao);
    return 1;
}
int remover_lista_por_id(ListaEncadeada *ponteiro, int id) {
    if (ponteiro->primeiro == ponteiro->ultimo) {
        printf("Lista vazia! Nada a ser removido.\n");
        return 0;
    }

    Apontador anterior = ponteiro->primeiro;
    while(anterior->proximo != NULL && anterior->proximo->Listinha.id != id) {
        anterior = anterior->proximo;
    }

    if (anterior->proximo == NULL) {
        printf("ID %d nao encontrado\n", id);
        return 0;
    }

    Apontador alvo = anterior->proximo;
    anterior->proximo = alvo->proximo;

    if (alvo == ponteiro->ultimo) {
        ponteiro->ultimo = anterior;
    }

    free(alvo);
    return 1;
}
ListaCompras* buscar_lista(ListaEncadeada *ponteiro, int id) {
    if (ponteiro->primeiro == ponteiro->ultimo) {
        printf("Lista vazia!");
        return NULL;
    }
    
    Apontador auxiliar;
    auxiliar = ponteiro->primeiro->proximo;
    while(auxiliar != NULL && auxiliar->Listinha.id != id) {
        auxiliar = auxiliar->proximo;
    }

    if (auxiliar == NULL) {
        printf("ID %d não encontrado", id);
        return NULL;
    }

    return &(auxiliar->Listinha);
}
int imprimir_lista(ListaEncadeada *ponteiro) {
    if (ponteiro->primeiro == ponteiro->ultimo) {
        printf("Lista vazia!");
        return 0;
    }

    Apontador auxiliar;
    auxiliar = ponteiro->primeiro->proximo;
    while(auxiliar != NULL) {
        printf("%d %.2f %s", auxiliar->Listinha.id, auxiliar->Listinha.preco, auxiliar->Listinha.nome);
        auxiliar = auxiliar->proximo;
    }
    return 0;
}