# Autor: Diego Saldaña
# Fecha de inicio: 14/08/2024

import os

"""
contador =  0
while contador <= 100:
    print(contador)
    contador += 1"""

"""# tabla de multiplicar con bucle for
numero = int(input("ingrese un numero:"))
for i in range(1,11):
    print(f"{numero} x {i} = {numero * i}")"""


"""#tabla de multiplicar pero con While
numero = int(input("ingrese un numero:"))
contador = 1

while contador <=10:
    print(f"{numero} x {contador} = {numero * contador}")
    contador += 1"""

"""#cuenta regresiva
numero = int(input("ingrese su numero:"))
while numero  != 0:
    print(numero)
    numero -= 1
print("DESPEGUEN")"""

"""
palabra = input("Ingresa una palabra: ")
indice = 0

while indice < len(palabra):
    print(palabra[indice])
    indice += 1
"""


"""#cuenta el numero de vocales que hay en una palabra
palabra = input("Ingresa una palabra: ").lower()
indice = 0
contador_vocales = 0
vocales = "aeiou"

while indice < len(palabra):
    if palabra[indice] in vocales:
        contador_vocales += 1
    indice += 1

print("El número de vocales en la palabra es:",contador_vocales)"""

"""
#algoritmo que cuenta la cantidad de consonantes
palabra = input("ingrese una palabra:").lower()
indice = 0
contador_consonantes = 0
vocales = "aeiou"
while indice < len(palabra):
    if palabra[indice] not in vocales:
        contador_consonantes += 1
    indice += 1
print(f"El numero de consonantes son: {contador_consonantes}")"""


#algoritmo que cuente las letra y los numeros
#cadena_txt = input("ingrese una cadena  de texto, incluyendo numeros:")
#indice = 0
#contador_txt = 0
#contador_num = 0
#while indice < len(cadena_txt):
   # if cadena_txt[indice].isalpha():
    #    contador_txt += 1
    #elif cadena_txt[indice].isdigit():
   #     contador_num += 1
   # indice += 1
#print(f"""la cantidad de caracteres y numeros son:
#numeros:{contador_num} 
#caracteres:{contador_txt}""")


"""# bucle infinito que diga la palabra "sexo"
palabra_magica = "sexo"
indice = 0
while indice < len(palabra_magica):
    print(palabra_magica)
    indice += 1

"""
