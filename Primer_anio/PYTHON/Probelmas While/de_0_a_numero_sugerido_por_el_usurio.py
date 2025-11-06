"""numero = int(input("ingrese un numero:"))
contador = 0
while contador <= numero:
    print(contador)
    contador  += 1"""

"""numero = int(input("ingrese un numero:"))
while  0 <= numero:
    print(numero)
    numero -= 1
"""


palabra = input("ingrese una palabra:").lower()
abc = "aeiou"

frase = ''

for char in palabra:
   if char not in abc:
    frase += char
print(frase)

      
    


    