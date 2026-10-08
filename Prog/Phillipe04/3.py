v = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
y = []

n = int(input())

for i in range(len(v)):
    if v[i] == n:
        y.append(i+1)

if len(y) > 0:
    print("O valor se encontra na(s) posiçõe(s): %s" % y)
else:
    print("O valor não foi encontrado.")