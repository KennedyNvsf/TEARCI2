#CALCULAR O ANO BISEXTO

ano = int(input("Escolha um ano: "))

if ano % 400 == 0:
    print(f"{ano} é um ano Bisexto")

elif ano % 100 == 0:
    print(f"{ano} não é um ano Bisexto")

elif ano % 4 == 0:
    print(f"{ano} é um ano Bisexto")

else:
    print(f"{ano} não é um ano Bisexto")
      


