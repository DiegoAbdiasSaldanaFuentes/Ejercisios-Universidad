#un programa para clasificar edades y que retorne si es un bebé, niño, adolecente o un anciano

edad= int(input("ingrese la edad que desea clasificar:")) 

if edad <= 2:
    print("es un bebé")
elif edad <= 12:
    print("es un niño")
elif edad <=17:
    print("es un adolecente")
elif edad <= 64:
    print("es un adulto")
else:
    print("es un anciano")