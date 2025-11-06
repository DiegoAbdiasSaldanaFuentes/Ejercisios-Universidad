#Autor: Diego Saldaña
#Fecha: 24/08/2024


#Algoritmo que cuente del 1 al 10

"""for numero in range(1,11):
    print(numero)"""

#Algoritmo que adivine el numero  secreto

"""numero_usuario = int(input("ingrese un numero del 1 al 10:"))
numero_ganador = 7

while numero_usuario != numero_ganador:
    incorrecto = int(input("incorrecto ingrese otra vez:"))

print("correcto")"""

#Algoritmo que cuente del 1 la 10 pero con While

"""numero = 10
contador = 1
while contador <= 10:
    print(contador)
    contador += 1"""


#Algoritmo que cuente del 1 al 20 pero solo los numeros pares
for numero in range(1,21):
    if numero % 2 != 1:
        print(numero)

#Algoritmo que calcule el factorial de "n" numero

"""n = 3
resultado = 1

for i in range(1,n+1):
    resultado *= i

print(f"el Factorial de {n} es: {resultado}")"""
                            
"""i = "ABC123"

for char in i:
    print(char)"""