n = int(input())
nome = []
preco = []
quant = []
total = 0

for i in range(n):
    nm = str(input())
    pc = float(input())
    it = int(input())
    nome.append(nm)
    preco.append(pc)
    quant.append(it)

for i in range(len(preco)):
    total = preco[i]*quant[i]
    total_brl = total*5.65
    print("Produto: %s" % nome[i])
    print("Valor total da compra: R$ %.2f (US$ %.2f)" % (total_brl, total))