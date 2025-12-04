
#Exercicio 1

# Defenir uma var "a", atribuir o valor de 5 e fazer print da var
a = 5
# print(a)

# Defenir uma var "b", atribuir o valor de 7 e fazer print da var
b = 7
# print(b)

# Defenir uma var "c", atribuir o valor de a + b e fazer print da var
c = a + b
# print(c)

# exercicio 2
"""
Perguntar uma idade (número inteiro) ao utilizador 
Fazer print de “É maior de idade” ou “É menor de idade” conforme as circunstâncias 
"""

def idade():
    idade = int(input("Quantos anos tens? "))

    if idade < 18:
        print("Tu és Menor de idade")
        return idade
    else:
        print("Tu és Maior de idade")
        return idade
    
# idade()

#Exercicio 3
"""
Pedir ao utilizador o número de kms efetuados numa viagem, o gasto médio do carro 
(l/100kms) e o preço do litro de combustível (em €). 
 Dar como resultado os litros consumidos e o valor gasto na viagem.
"""

def viagem_calc():

    km_percorridos = float(input("Quantos Kilometros percorreste na viagem? "))
    gasto_medio = float(input("Insira o consumo médio do carro (litros/100 km): ")) 
    preco_litro = float(input("Insira o preço do litro de combustível (€): "))

    litros_consumidos = (km_percorridos * gasto_medio) / 100
    custo_total = litros_consumidos * preco_litro

    print(f"\nLitros consumidos: {litros_consumidos:.2f} L")
    print(f"Custo total da viagem: €{custo_total:.2f}")

    return
    
# viagem_calc()

#Exercicio 4
"""
“ler” um peso e uma altura. Calcular o IMC. 
Apresentar resultado com a indicação
"""

def imc_calc():
    peso = float(input("Quanto é que pesas em kg? "))
    altura = float(input("Qual é a tua altura em metros? "))
    IMC = float(peso) /  float(altura) **2

    if IMC < 18.5:
        print("Baixo Peso")
    elif IMC >= 18.5 and IMC < 25:
        print("Peso adequado")
    elif IMC >= 25 and IMC < 30:
        print("Sobrepeso")
    elif IMC >= 30 and IMC < 34.9:
        print("Obesidade")
    return IMC

# imc_calc()

#EXERCICIO 5 CALC FACTORIAL

#Factorial While
# num = int(input("Insert a number: "))
# factorial = 1

# while num > 1:
#     factorial *= num
#     num -= 1

# print(f"The factorial is: {factorial}")

# Factorial For Loop
# def calcular_fatorial(n):
#     if n < 0:
#         return "Fatorial não é definido para números negativos."
    
#     fatorial = 1
#     for i in range(1, n + 1):
#         fatorial *= i
    
#     return fatorial


# numero = int(input("Insira um número para calcular o fatorial: "))
# resultado = calcular_fatorial(numero)
# print(f"O fatorial de {numero} é: {resultado}")


#CHALLENGE

def challenge_01(min_num, max_num):
    if min_num > max_num:
        return "O valor minimo deve ser maior do que o valor maximo."
    
    total = 0
    current = min_num
    
    while current <= max_num:
        total += current 
        current += 1     
    
    print(f"A soma total é: {total}")
    return total


min_num = int(input("valor Minimo: "))
max_num = int(input("Valor Maximo: "))

challenge_01(min_num, max_num)




