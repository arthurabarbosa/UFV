import random

v = [random.randint(1, 10) for i in range(100)]
n = int(input())

existe = False

for i in range(len(v)):
    if n == v[i]:
        existe = True
        break

if existe:
    print("Valor existe dentro do vetor")
else:
    print("Valor não existe dentro do vetor")