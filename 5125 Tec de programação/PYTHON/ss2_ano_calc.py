
X  = 24
Y = 5

ano = int(input("Digite o ano a calcular "))

a = ano % 19
b = ano % 4
c = ano % 7
d = ((19 * a ) + X) % 30
e = ((2*b)+(4*c)+(6*d)+Y) % 7

if (d+e) < 10:
    dia = d + e + 22
    mes = "Março"
    print(f"Dia {dia} de {mes} ")
else:
    dia = d + e - 9
    mes = "Abril"
    print(f"Dia {dia} de {mes}")
