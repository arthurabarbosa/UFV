v = []

while len(v) < 5:
    n = int(input())
    if 0 <= n <= 10:
        v.append(n)
    else:
        print("Valor inválido")

print("Vetor final preenchido:", v)