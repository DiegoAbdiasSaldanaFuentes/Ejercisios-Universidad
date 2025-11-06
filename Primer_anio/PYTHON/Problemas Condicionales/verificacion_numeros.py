#comprueba si el numero entregado es negativo, positivo o es  cero

numero= float(input("ingresa un numero:"))

if numero <0:
    print("negativo")
elif numero==0:
    print("es cero")
else:
    print("positivo")