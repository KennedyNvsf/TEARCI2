#Kennedy Freitas
#TEARCI

#Uma função que diz se o numero é par ou impar
def par_impar(x):
    if x % 2 == 0:
        print(f"{x} é um número par.")
        return True
    else:
        print(f"{x} é um numero ímpar.")
        return False

#Remover comentario para executar a função
# par_impar(3) 

#Calc IMC
def imc_calc(peso, altura):
    IMC = float(peso) /  float(altura) **2
    print(f"O Valor IMC é de {IMC:.2f}")
    return IMC

#Remover comentario para executar a função
#imc_calc(90, 1.83)

#Resultado do jogo
def totobola(x, y):
    Golo_equipa_casa = int(x)
    golo_equipa_adver = int(y)

    if Golo_equipa_casa < golo_equipa_adver:
        print(f"O jogo ficou por {golo_equipa_adver}-{Golo_equipa_casa}")
        return "Vitoria"
    elif Golo_equipa_casa == golo_equipa_adver:
        print(f"Empate")
        return "empate"
    else:
        print(f"A equipa adversaria ganhou {Golo_equipa_casa}-{golo_equipa_adver}")
        return "Derrota"

#Remover comentario para executar a função
#totobola(3, 5)

#Conversão de Temperatura para Farhenheit
def conv_temp(temp):
    cent = int(temp)
    farh = (cent * 1.8) + 32

    print(f"{cent}º equivale á {farh} Fahrenheit")
    return farh

#Remover comentario para executar a função
#conv_temp(18)

#Função para a tabuada de um certo numero
def tabuada(a):
    mult = 0
    for i in range(1, 12, 1): 
        mult = a * i
        print(mult)

    return a

#Remover comentario para executar a função
#tabuada(6)

#Calcular o ano Bisexto
def bis_calc(ano):
    if ano % 400 == 0:
        print(f"{ano} é um ano Bisexto")
    elif ano % 100 == 0:
        print(f"{ano} não é um ano Bisexto")
    elif ano % 4 == 0:
        print(f"{ano} é um ano Bisexto") 
    else:
        print(f"{ano} não é um ano Bisexto")
        
    return ano

#Remover comentario para executar a função   
#bis_calc(1998)

#calcuLAR Pascoa dia ano
def calc_dia(ano):
    X  = 24
    Y = 5

    a = ano % 19
    b = ano % 4
    c = ano % 7
    d = ((19 * a ) + X) % 30
    e = ((2*b)+(4*c)+(6*d)+Y) % 7

    if (d+e) < 10:
        dia = d + e + 22
        mes = "Março"
        print(f"Dia {dia} de {mes} ")

        return (f"{dia} + {mes}")
    else:
        dia = d + e - 9
        mes = "Abril"
        print(f"Dia {dia} de {mes}")

        return (f"{dia} + {mes}")
 
#Remover comentario para executar a função     
#calc_dia(2001)