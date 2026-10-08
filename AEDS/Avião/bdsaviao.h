#ifndef BDSAVIAO_H
#define BDSAVIAO_H

typedef struct {
    int id;
    char nome[20];
    double eficiencia;
} aviao;

int setaviao (aviao *ptr, int identificacao, char name[20], double efc);
int get_id (aviao *ptr);
void get_nome (aviao *ptr, char name[20]);
double get_efc (aviao *ptr);

#endif