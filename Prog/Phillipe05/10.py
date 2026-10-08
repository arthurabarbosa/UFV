import random

v = [random.randint(1, 100) for i in range(1000)]
n = int(input("Insira um valor entre 1 e 100"))
contador = 0

if 1 <= n <= 100:
    for i in range(len(v)):
        if v[i] == n:
            contador += 1
    if contador == 0:
        print("O número %d não aparece no vetor" % n)
    else:
        print("O número %d aparece no vetor %d vezes" % (n, contador))
else:
    print("Valor inválido")