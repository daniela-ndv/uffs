import math

def combinacao(n,x):
    return math.factorial(n) // (math.factorial(n - x) * math.factorial(x))

def func_binomial(n, x, p):
    q = 1 - p
    P = combinacao(n, x) * (p ** x) * (q ** (n - x))
    return P

def probabilidade_acumulada(n, x, p):
    soma = 0
    for i in range(x + 1):
        soma += func_binomial(n, i, p)
    return soma

def probabilidade_maior_ou_igual_x(n, x, p):
    if x == 0:
        return 1.0  # porque P(X >= 0) = 1 sempre
    return 1 - probabilidade_acumulada(n, x-1, p)

def ler_int(mensagem):
    while True:
        try:
            valor = int(input(mensagem))
            if valor < 0:
                print("Por favor, insira um número inteiro positivo.")
                continue
            return valor
        except ValueError:
            print("Entrada inválida. Insira um número inteiro.")

def ler_probabilidade(mensagem):
    while True:
        try:
            valor = float(input(mensagem))
            if not (0 <= valor <= 1):
                print("Por favor, insira um valor entre 0 e 1.")
                continue
            return valor
        except ValueError:
            print("Entrada inválida. Insira um número decimal entre 0 e 1.")

n = ler_int("Insira o número total de tentativas (n): ")
x = ler_int("Insira o número de sucessos desejados (x): ")

if x > n:
    print("O número de sucessos (x) não pode ser maior que o número de tentativas (n).")
    x = ler_int("Insira novamente o número de sucessos desejados (x): ")
4
p = ler_probabilidade("Insira a probabilidade de sucesso (p) de cada tentativa [entre 0 e 1, ex: 40% = 0.4]: ")
 
P = func_binomial(n, x, p)
P_acumulada = probabilidade_acumulada(n, x, p)
P_maior_que_x = probabilidade_maior_ou_igual_x(n, x, p)

print(f"\nA probabilidade de ocorrerem {x} sucessos em {n} tentativas é de {P*100:.2f}%")
print(f"A probabilidade de ocorrerem até {x} sucessos em {n} tentativas é de {P_acumulada*100:.2f}%")
print(f"A probabilidade de ocorrerem no mínimo {x} sucessos em {n} tentativas é de {P_maior_que_x*100:.2f}%")