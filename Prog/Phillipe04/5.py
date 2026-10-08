v = []
soma = 0
n = int(input())

for i in range(n):
    x = int(input())
    v.append(x)

for j in range(len(v)):
    if j%2 == 0:
        soma += v[j]

print(soma)