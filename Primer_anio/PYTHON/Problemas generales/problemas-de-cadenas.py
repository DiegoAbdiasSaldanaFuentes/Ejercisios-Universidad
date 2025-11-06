#Pagina https://aprendeconalf.es/docencia/python/ejercicios/cadenas/


#ejercisio: Escribir un programa que pregunte el nombre del usuario
#  en la consola y un número entero e imprima por pantalla en líneas distintas 
# el nombre del usuario tantas veces como el número introducido.

#Mi respuesta
#nombre = input("ingrese su nombre:")
#numero = int(input("ingrese un numero que multiplara las veces el nombre:"))
#print((nombre + "\n") * numero)

#respuesta de la pagina
#nombre = input("¿Cómo te llamas? ")
#n = input("Introduce un número entero: ")
#print((nombre + "\n") * int(n))

#ejercisio: Escribir un programa que pregunte el nombre completo del usuario en la consola
#  y después muestre por pantalla el nombre completo del usuario tres veces, una con todas las letras minúsculas, 
# otra con todas las letras mayúsculas y otra solo con la primera letra del nombre y de los apellidos en mayúscula. 
# El usuario puede introducir su nombre combinando mayúsculas y minúsculas como quiera.

#MI RESPUESTA
#nombre = input("ingrese su nombre completo:")
#print((nombre.lower()+"\n")+ (nombre.upper()+"\n")+(nombre.title()))

#RESPUESTA DE LA PAGINA
#name = input("¿Cómo te llamas? ")
#print(name.lower())
#print(name.upper())
#print(name.title())

#EJERCISIO: Escribir un programa que pregunte el nombre del usuario en la consola
#  y después de que el usuario lo introduzca muestre por pantalla <NOMBRE> tiene <n> letras,
#  donde <NOMBRE> es el nombre de usuario en mayúsculas y <n> es el número de letras que tienen el nombre.

#MI RESPUESTA

#nombre = input("introduzca su nombre:")
#print(f"{nombre.upper()} tiene { str(len(nombre))} letras")

#RESPUESTA  DE LA PAGINA
#nombre = input("¿Cómo te llamas? ")
#print(nombre.upper() + " tiene " + str(len(nombre)) + " letras")

#EJERCISIO: Los teléfonos de una empresa tienen el siguiente 
# formato prefijo-número-extension donde el prefijo es el código del país +34,
#  y la extensión tiene dos dígitos (por ejemplo +34-913724710-56).
#  Escribir un programa que pregunte por un número de teléfono con este formato 
# y muestre por pantalla el número de teléfono sin el prefijo y la extensión.

#MI RESULTADO
#numero = list(input("ingrese su numero:"))
#print(numero[2:10])

#RESPUESTA DE LA PAGINA
#tel = input("Introduce un número de teléfono con el formato +xx-xxxxxxxxx-xx: ")
#print('El número de teléfono es ', tel[4:-3])

#ejercisio: Escribir un programa que pida al usuario que introduzca una frase en la consola
#y muestre por pantalla la frase invertida

#MI RESPUESTA
#frase = input("ingresa una frase:")
#print(frase[::-1])

#la respuesta es la misma



