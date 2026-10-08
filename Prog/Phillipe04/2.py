v = []

for i in range(10):
    n = int(input())
    v.append(n)

x = int(input())

for i in range(len(v)):
    if v[i] < x:
        print(v[i], end=" ")