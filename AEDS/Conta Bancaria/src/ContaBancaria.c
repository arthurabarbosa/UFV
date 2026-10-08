#include <stdio.h>
#include <string.h>
#include "ContaBancaria.h"

int inicializacao(ContaBancaria *res) {
    char cpf_temp[12];

    printf("Insira o id da conta: \n");
    scanf("%d", &res->id);

    printf("Insira seu nome: \n");
    scanf(" %[^\n]", res->cliente);

    printf("Insira os 11 digitos do CPF: \n");
    scanf("%s", cpf_temp);

    for (int i = 0; i < 11; i++) {
        res->cpf[i] = cpf_temp[i] - '0'; 
    }

    printf("Insira o tipo de Conta (Corrente ou Poupanca): \n");
    scanf("%s", res->tipo);

    printf("Insira o ano de abertura: \n");
    scanf("%d", &res->ano);

    printf("Insira o saldo da conta: \n");
    scanf("%lf", &res->saldo);

    return 0;
}

void getCliente(ContaBancaria *res, char *nome) {
    strcpy(nome, res->cliente);
}

void setCliente(ContaBancaria *res, char *nome) {
    strcpy(res->cliente, nome);
}

void getTipo(ContaBancaria *res, char *tipo) {
    strcpy(tipo, res->tipo);
}

void setTipo(ContaBancaria *res, char *tipo) {
    strcpy(res->tipo, tipo);
}

int imprime(ContaBancaria *res) {
    printf("Numero da conta: %d\n", res->id);
    printf("Nome do cliente: %s\n", res->cliente);
    
    printf("CPF do cliente: ");
    for (int i = 0; i < 11; i++) {
        printf("%d", res->cpf[i]);
    }
    printf("\n");

    printf("Tipo de conta: %s\n", res->tipo);
    printf("Ano de abertura da conta: %d\n", res->ano);
    printf("Saldo: %.2lf\n", res->saldo);
    
    return 0;
}

int saque(double valor, ContaBancaria *res) {
    res->saldo = res->saldo - valor;
    return 0;
}

int deposito(double valor, ContaBancaria *res) {
    res->saldo = res->saldo + valor;
    return 0;
}

int avalia(ContaBancaria *res) {
    int ano_atual = 2026;
    if ((ano_atual - res->ano) > 2) {
        printf("Cliente elegivel para emprestimo.\n");
    } 
    else {
        printf("Cliente inelegivel para emprestimo.\n");
    }
    return 0;
}