


#Quem Ganhou A Partida?

porto_golos = int(input("Quantos golos Marcou o Porto? "))
benfica_golos = int(input("Quantos golos Marcou o Benfica? "))

if porto_golos < benfica_golos:
    print(f"O Benfica venceu por {benfica_golos}-{porto_golos}")
elif porto_golos == benfica_golos:
    print(f"Empate entre o Porto e o Benfica")
else:
    print(f"O Porto venceu por {porto_golos}-{benfica_golos}")

    
        
