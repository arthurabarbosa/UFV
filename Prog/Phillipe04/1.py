v = []

a = float(input())

for i in range(30):
    n = int(input())
    v.append(n)

for i in range(len(v)):
    produto = a*v[i]
    print(produto)