#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct {
    int id;
    char cliente[50];
    int cpf[11];
    char tipo[20];
    int ano;
    double saldo;
} ContaBancaria;

int inicializacao(ContaBancaria *res);
int imprime(ContaBancaria *res);
int saque(double valor, ContaBancaria *res);
int deposito(double valor, ContaBancaria *res);
int avalia(ContaBancaria *res);
void getCliente(ContaBancaria *res, char *nome);
void setCliente(ContaBancaria *res, char *nome);
void getTipo(ContaBancaria *res, char *tipo);
void setTipo(ContaBancaria *res, char *tipo);

#endif