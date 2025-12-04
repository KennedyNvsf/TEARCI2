num = int(input("Insert a number: "))

while num > 1:  # Stop when num reaches 1
    mult = num * (num - 1)
    print(f"{num} * {num - 1} = {mult}")
    num -= 1
