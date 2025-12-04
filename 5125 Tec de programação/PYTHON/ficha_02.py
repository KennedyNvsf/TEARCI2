
#Kennedy Freitas
#TEARCI

# Exercício 1 | Par ou ímpar
def par_ou_impar():
    # Solicita ao usuário um número inteiro
    numero = int(input("Digite um número qualquer: "))

    # Verifica se o número é par ou ímpar
    if numero % 2 == 0:
        print(f"{numero} é um número par.")
    else:
        print(f"{numero} é um numero ímpar.")

# par_ou_impar()

# Exercício 2 | Semáforo
def semaforo(cor):
    if cor == "vermelho":
        print("Passagem proibida!")
    elif cor == "amarelo":
        print("Transição para Vermelho!")
    elif cor == "verde":
        print("Passagem Autorizada")
    else:
        print("Cor inválida!")

# semaforo("vermelho")

# Exercício 3 | Fatorial While
def fact_w(n):
    if n < 0:
        print("O número deve ser um inteiro positivo.")
    
    resultado = 1
    while n > 1:
        resultado *= n
        n -= 1
    return resultado

# Exemplo de uso:
# print(fact_w(5))  # Saída: 120

#Exercicio 4 | Fatorial For
def fact_f(n):
    if n < 0:
        print("O número deve ser um inteiro positivo.")
    
    resultado = 1
    for i in range(2, n + 1):
        resultado *= i
    return resultado

# Exemplo de uso:
# print(fact_f(5))  # Saída: 120

#exercicio 5 | Fatorial Recursivo
def fact_r(n):
    if n < 0:
        print("O número deve ser um inteiro positivo.")
    if n == 0 or n == 1:
        return 1
    return n * fact_r(n - 1)

# Exemplo de uso:
# print(fact_r(5))  # Saída: 120


def analisa_lista(lista):
    contador = 0
    soma = 0
    
    for numero in lista:
        contador += 1
        soma += numero
    
    media = soma / contador if contador > 0 else 0  # Evita divisão por zero
    return contador, soma, media

# Exemplo de uso:
numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9]
# resultado = analisa_lista(numeros)
# print(resultado)  # Saída: (9, 45, 5.0)


def nif_ver():
    nif_num = input('Digite o seu NIF: ').replace('-', '').strip()

    if not nif_num.isdigit():
        print('Erro: O NIF deve conter apenas dígitos.')
        return False
    
    if len(nif_num) != 9:
        print('Erro: O NIF deve ter exatamente 9 dígitos.')
        return False
    
    if nif_num[0] not in '125689':  # Números válidos para iniciar um NIF português
        print('Erro: O primeiro dígito do NIF é inválido.')
        return False

    soma = 0
    for i in range(9):
        soma += int(nif_num[i]) * (9 - i)

    if soma % 11 <= 2:
        print('NIF válido!')
    else:
        print('NIF inválido!')

    return True

# Testar a função
nif_ver()

