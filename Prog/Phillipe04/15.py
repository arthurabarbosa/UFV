numero = []
agencia = []
saldo = []

for i in range(100):
    n = int(input())
    a = str(input())
    s = float(input())
    numero.append(n)
    agencia.append(a)
    saldo.append(s)

for i in range(len(numero)):
    print("Conta número %d: saldo de %.2f." % (numero[i], saldo[i]))
    if saldo[i] > 0:
        print("Saldo positivo")
    else:
        print("Saldo negativo")
    
agencias_processadas = []

for i in range(len(agencia)):
    agencia_atual = agencia[i]
    
    if agencia_atual not in agencias_processadas:
        total_clientes = 0
        negativos = 0
        
        for j in range(len(agencia)):
            if agencia[j] == agencia_atual:
                total_clientes += 1
                if saldo[j] < 0:
                    negativos += 1
        
        porcentagem_negativos = (negativos / total_clientes) * 100
        
        print("Agência %s: %d clientes no total." % (agencia_atual, total_clientes))
        print("Porcentagem de clientes com saldo negativo: %.2f%%" % porcentagem_negativos)
        
        agencias_processadas.append(agencia_atual)