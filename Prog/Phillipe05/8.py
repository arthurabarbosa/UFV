import random

v = [random.randint(1, 75) for i in range(75)]
k = [random.randint(1, 75) for i in range(75)]
p = []
aux = 0

for i in range(len(v)):
    aux = v[i] + k[i]
    p.append(aux)
    aux = 0

print(p)