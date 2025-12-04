

import re


str = 'python'
# length = len(str)
# print(length)  # 6

# print(str[0])   

# print(str[:2])

# print(str[::2])

# print(str[::-1])

# check = 'thon' in str
# print(check)

# print(str.index('t'))

# print(str.count('y'))

# for i in str:
    # print(i)

# for i in str:
#     i >= '0' and i <= '9'
#     print(i)

def formulario():
    
    #Validação do nome
    nome = input('Digite seu primeiro e ultimo nome: ')

    if len(nome) < 6 or re.search(r'[^A-Za-z0-9\s]', nome):
        print('Nome deve ter mais de 6 caracteres e caracteres especiais')
        return formulario()
    for i in nome:
        if i >= '0' and i <= '9':
            print('Nome não pode conter números')
            return formulario()
    if " " not in nome:
        print('Nome deve conter um espaço')
        return formulario()
   
    
    email = input('Digite seu email: ')
    formato = '@formacao.iefp.pt'

    if not email.split('@')[0].isdigit():
        print('Identificador Invalido')
        return formulario()
    
    if formato not in email:
        print('Email deve terminar com @formacao.iefpt.pt')
        return formulario()
    
    # if not email.endswith(formato):
    #     print('Email deve terminar com @formacao.iefpt.pt')
    #     return formulario()

    telefone = int(input('Digite seu nº de Telefone: '))

    if len(telefone) < 9:
        print('Telefone deve ter 9 digitos')
        return formulario()
    
    if 9 not in telefone[0] or 2 not in telefone[0]:
        print('Nº Telefone deve começar com 9 ou 2')
        return formulario()
    
    print(f"Nome: {nome}\n Email: {email}\n Email: {telefone}")

# formulario()



def esbn():
    esbn_num = input('Digite o seu esbn: ')
    esbn_num = esbn_num.replace('-', '')
    
    if len(esbn_num) != 13:
        print('Esbn deve ter 13 digitos')
        return 0
    if not esbn_num.isdigit():
        print('Esbn deve conter apenas digitos')
        return 0
    if esbn_num[:3] not in ('978', '979'):
        print('Esbn deve começar com 978 ou 979')
        return 0
    
    sum_total = 0
    for i in range(13):
        digit = int(esbn_num[i])
        if i % 2 == 0:
            sum_total += digit * 1
        else:
            sum_total += digit * 3
    
    if sum_total % 10 != 0:
        print('Esbn inválido: soma de verificação incorreta')
        return 0
    
    print(f'ESBN válido: {esbn}')
    return 1 
    

esbn()

