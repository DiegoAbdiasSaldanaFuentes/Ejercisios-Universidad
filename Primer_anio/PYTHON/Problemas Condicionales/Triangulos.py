#programa para determinar si los lados de los triangulos son equilatéro, isóceles o escaleno

lado1 = float(input("ingrese el primer lado: "))
lado2 = float(input("ingrese el segundo lado: "))
lado3 = float(input("ingrese el tercer lado: "))

if lado1==lado2==lado3:
    print("Es un triangulo equilatéro")
elif lado1==lado2!=lado3 or lado1!= lado2 or lado2!=lado1:
    print("Es un isóceles")
else:
    print("es un escaleno")