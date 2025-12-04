
#Recursividade Factorial
def fact(n):
    print(n)
    if n == 1:
        return 1
    return (n * fact(n - 1))


# print(fact(5))

#soma entre 2 numeros
def soma_n_r(lim_inf, lim_sup):
    if lim_inf == lim_sup:
        return lim_inf
    return lim_inf + soma_n_r(lim_inf + 1, lim_sup)

# print(soma_n_r(1, 5))

#multiplicação entre 2 numeros
def mult_r(mult1, mult2):
    if mult1 == 1:
        return mult2
    return mult2 + mult_r(mult1 - 1, mult2)

# print(mult_r(6, 5))

def mult_n(mult1, mult2):
    if mult2 == 1:
        return mult1
    return mult1 + mult_n(mult1, mult2 - 1 )

# print(mult_n(6, 5))

#potenciação
def pot_r(base, exp):
    if exp == 1:
        return base
    return base * pot_r(base, exp - 1)

# print(pot_r(2, 3))


def fib(n):
    if n == 0 or n == 1:
        return n
    return fib(n - 1) + fib(n - 2)

# print(fib(6))


def mover_caixa(n, origem, destino, auxiliar):

    if n == 1:
        print(f"Mover caixa {n} de {origem} para {destino}")
        return
    
    mover_caixa(n - 1, origem, auxiliar, destino)
    print(f"Mover caixa {n} de {origem} para {destino}")
    mover_caixa(n - 1, auxiliar, destino, origem)


print(mover_caixa(3, "Guimarães", "Braga", "Famalicão"))