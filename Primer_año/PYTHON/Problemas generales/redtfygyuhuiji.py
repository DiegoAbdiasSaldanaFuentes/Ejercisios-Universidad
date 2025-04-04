'''if __name__ : '__main__'
nument = int(input('ingrese un numero entero:'))
for n in range(nument):
    if n % 2 == 1:
        print(n, end=',')'''

''''numuser = int(input('introduzca un numero:'))
cont  = 1
n = '*'
while cont != numuser:
    print(n * cont)
    cont= cont + 1'''

'''def esprimo(numuser):
    if numuser % 2 ==1:
        print(f'el numero {numuser} es primo')

def noesprimo(numuser):
    if numuser % 2 ==0:
        print(f'el numero {numuser} no es primo')


if __name__ : '__main__'
numuser = int(input('ingrese un numero entero:'))
esprimo(numuser)
noesprimo(numuser)'''

#if numuser % 2 ==1:
#    print('tu numero es un primo')
#else:
#    print('tu numero no es un numero primo')

def letfra(a,b):
    cont =  0
    cont2 =  0
    while cont < len(a):
        carasepar = a[cont]
        for comparar in carasepar:
            if comparar == b:
                cont2 = cont2 + 1
        cont = cont + 1
    print(f'la letra "{b}" coincide {cont2} veces')

if __name__:'__main__'
fraseuser = input('ingrese una frase:')
letuser = input('ingrese una letra:')
letfra(fraseuser,letuser)


'''while True:
    frase = input('introduzca su frase:')
    if frase == 'end':
        break
    print(frase)'''

'''def notasigna(asignatura):
    cont = 0
    notpasada = []
    notreproba = []
    while cont < len(asignatura):
        notas = float(input(f'que nota te sacaste en: {asignatura[cont]}: '))
        if notas >= 5:
            notpasada.append(notas)
        else:
            notreproba.append(notas)
        cont = cont + 1
    print(f'tus notas reprobdas son en: {notreproba}')

if __name__ : '__main__'
asignaturas = input('ingrese sus asignaturas:').split(' ')
notasigna(asignaturas)
'''