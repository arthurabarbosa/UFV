v = []
k = []
s = []

for i in range(5):
    n = int(input())
    v.append(n)

for i in range(5):
    x = int(input())
    k.append(x)

for i in range(5):
    s.append(v[i]+k[i])

print(s)