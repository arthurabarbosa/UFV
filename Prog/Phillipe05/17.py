import random

matriz = []

for i in range(10):
    vetor = []
    for j in range(10):
        valor = random.randint(1, 100)
        vetor.append(valor)
    matriz.append(vetor)

aux = 0

for k in range(10):
    aux = matriz[1][k]
    matriz[1][k] = matriz[k][7]
    matriz[k][7] = aux