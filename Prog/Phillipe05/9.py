import random

v = [random.randint(1, 30) for i in range(30)]

for i in range(len(v)):
    if i%2 == 0:
        v[i] = 0

print(v)