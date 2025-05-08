import math

def combinacao(n,x):
    return math.factorial(n) // (math.factorial(n - x) * math.factorial(x))

def func_binomial(n, x, p):
    q = 1 - p
    P = combinacao(n, x) * (p ** x) * (q ** (n - x))
    return P

def probabilidade_acumulada(n, x, p):
    return sum(func_binomial(n, i, p) for i in range(x + 1))

def probabilidade_maior_ou_igual_x(n, x, p):
    if x == 0:
        return 1.0  # porque P(X >= 0) = 1 sempre
    return 1 - probabilidade_acumulada(n, x - 1, p)

def ler_tipo_calculo():
    while True:
        escolha = input(
            "\nDeseja calcular:\n"
            "1 - Probabilidade individual (P = x)\n"
            "2 - Probabilidade acumulada (P <= x)\n"
            "3 - Probabilidade de x ou mais sucessos (P >= x)\n"
            "Escolha 1, 2 ou 3: "
        )
        if escolha in ("1", "2", "3"):
            return escolha
        else:
            print("Escolha inválida. Digite 1, 2 ou 3.")

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


tipo = ler_tipo_calculo()
n = ler_int("Insira o número total de tentativas (n): ")
x = ler_int("Insira o número de sucessos desejados (x): ")

while x > n:
    print("O número de sucessos (x) não pode ser maior que o número de tentativas (n).")
    x = ler_int("Insira novamente o número de sucessos desejados (x): ")

p = ler_probabilidade("Insira a probabilidade de sucesso (p) de cada tentativa [entre 0 e 1, ex: 40% = 0.4]: ")

P = func_binomial(n, x, p)

if tipo == "1":
    P = func_binomial(n, x, p)
    print(f"\nA probabilidade de ocorrerem exatamente {x} sucessos em {n} tentativas é de {P * 100:.2f}%")
elif tipo == "2":
    P = probabilidade_acumulada(n, x, p)
    print(f"\nA probabilidade de ocorrerem no máximo {x} sucessos em {n} tentativas é de {P * 100:.2f}%")
else:
    P = probabilidade_maior_ou_igual_x(n, x, p)
    print(f"\nA probabilidade de ocorrerem pelo menos {x} sucessos em {n} tentativas é de {P * 100:.2f}%")
