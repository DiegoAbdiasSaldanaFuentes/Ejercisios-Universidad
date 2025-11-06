"""#Problema que me dio Julio

numeros = [1,2,3,4,5,6,7,8,9]
pares = []
impares = []

for i in numeros:
    if i % 2 == 0:
        pares.append(i)
    else:
        impares.append(i)

print(f"los numero pares son: {pares} y los impares son: {impares}")
"""

"""conjunto = ["AAAA", "IIHIANVIDJV", 12123, 12312,3.0,"SASAS",12123, ]

letras = ""
enteros = []
letras = []
flotantes = []

for i in conjunto:
    if isinstance (i,str):
        letras.append(i)
    elif isinstance (i,int):
        enteros.append(i)
    elif isinstance (i,float):
        flotantes.append(i)
    

print(enteros,letras,flotantes)"""

conjunto = ["Hola", 45, 3.1416, True, "Mundo", False, 100, 2.718, "Python", 0,True]

letras = []
numeros_enteros = []
numeros_decimales = []
boliviano =[]

for i in conjunto:
    if isinstance(i,str):
        letras.append(i)
    if isinstance(i,int):
        numeros_enteros.append(i)
    if isinstance(i,float):
        numeros_decimales.append(i)
    if isinstance(i,bool):
        boliviano.append(i)


print(letras, numeros_enteros, numeros_decimales, boliviano)