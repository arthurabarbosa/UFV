v = []

for i in range(3):
    n = int(input())
    v.append(n)

for i in range(len(v)):
    for j in range(len(v) - 1):
        if v[j] > v[j+1]:
            var = v[j+1]
            v[j+1] = v[j]
            v[j] = var

print("Vetor ordenado de forma crescente:", end=" ")
print(v)